#include "gameboard.hh"


// Constructor
GameBoard::GameBoard()
{
//alustetaan pelilauta asettamalla locations listaan pelilaudan kaikki mahdolliset koordinaatit. muotoa: [koordinaatti : pointer]

    for(unsigned int i=1;i<=ROWS;i++){ //rivit
        //sarakkeet
        if(i==1 || i==ROWS){           // jos i on 1 tai ROWS eli(päädyssä), lisätään tarvittavat sarakkeet COLUMNS
            for(unsigned int j=1;j<=COLUMNS;j++){
                shared_ptr<Location> ptr = make_shared<Location>(j,i);
                string name = to_string(j)+","+to_string(i);
                locations[name]=ptr;
            }
        }
        else{
            shared_ptr<Location> ptr = make_shared<Location>(2,i); // jos i on jokin muu, niin lisätään myös (i,2)
            string name = to_string(2)+","+to_string(i);
            locations[name]=ptr;

            if(i==3){               // jos i=3, niin lisätään myös (3,3)
                shared_ptr<Location> ptr = make_shared<Location>(3,i);
                string name = to_string(3)+","+to_string(i);
                locations[name]=ptr;
            }
        }
    }
}

GameBoard::~GameBoard()
{}

void GameBoard::initialFill() //lisätään nappulat pelilautaan
{
    COLOR color = COLOR::GREEN;
    for(unsigned int i=1;i<=ROWS;i=i+ROWS-1){//lisätään nappulat kumpaankin päätyyn

        for(unsigned int j=1;j<=COLUMNS;j++){
            string name = to_string(j)+","+to_string(i);
            locations[name]->piece = color; //lisätään listaan
        }

        color = COLOR::RED; //vaihdetaan väri punaiseksi
    }
}

void GameBoard::print() const
{
    //tulostaa pelilaudan
    for(int i=0;i<15;i++){ // tulostaa =======================
        cout<<"=";
    }
    cout<<endl;
    cout<<"|   | 1 2 3 4 |"<<endl;

    for(int i=0;i<15;i++){//tulostaa --------------------------
        cout<<"-";
    }
    cout<<endl;

    for(unsigned int i=1;i<=ROWS;i++){ //rivit
        cout<<"| "<<to_string(i)<<" |";

        for(unsigned int j=1;j<=COLUMNS;j++){        //sarakkeet

            string name = to_string(j)+","+to_string(i);

            if (locations.find(name) != locations.end()) {
                char color = static_cast<char>(locations.at(name)->piece);
                std::cout <<" "<< color;
            }
            else{
                std::cout << "  ";
            }
        }
        cout<<" |"<<endl;
    }

    for(int i=0;i<15;i++){ // tulostaa =======================
        cout<<"=";
    }
    cout<<endl;
}

bool GameBoard::isGameOver() const
{
    //tarkistaa onko peli ohi
    for(unsigned int i = 1; i<=COLUMNS;i++){

        string top_row_name = to_string(i)+","+to_string(1);
        string bottom_row_name = to_string(i)+","+to_string(5);

        //katsoo onko ylhäällä punaiset ja alhaalla viheät
        if(locations.at(top_row_name)->piece != COLOR::RED ||
            locations.at(bottom_row_name)->piece != COLOR::GREEN ){

            return false;
        }
    }
    return true;
}

bool GameBoard::isValidLocations(const Location &start, const Location &destination) const
{
    // tehdään koordinaateista nimi, jolla haetaan samanniminen locations -mapista
    string start_name = to_string(start.x+1)+","+to_string(start.y+1);
    string destination_name = to_string(destination.x+1)+","+to_string(destination.y+1);


    if(locations.find(start_name) == locations.end() || locations.find(destination_name) == locations.end()){ //kohteita ei löydy
        return false;
    }

    //onko sama nimi startilla ja destinationilla?
    if(start_name == destination_name){
        return false;
    }
    //katsoo onko pelilaudan ulkopuolella
    if(locations.find(start_name)==locations.end() || locations.find(destination_name)==locations.end() ){
        return false;
    }
    //katsoo onko lähtöruudussa pelinappulaa
    if(locations.at(start_name)->piece == COLOR::EMPTY){
        return false;
    }
    //katsoo onko kohteessa pelinappulaa
    if(locations.at(destination_name)->piece != COLOR::EMPTY){
        return false;
    }

    return true;
}

bool GameBoard::move(const Location &start, const Location &destination)
{

    // tehdään koordinaateista nimi, jolla haetaan samanniminen locations -mapista
    string start_name = to_string(start.x+1)+","+to_string(start.y+1);
    string destination_name = to_string(destination.x+1)+","+to_string(destination.y+1);
    std::set<string> visited;  // Luodaan uusi joukko tallentamaan käydyt solmut.

    if(locations.find(start_name) == locations.end() || locations.find(destination_name) == locations.end()){ //kohteita ei löydy
        return false;
    }

    //jos polkua ei löydy palautetaan false
    if(!is_Path(start_name,  destination_name, visited)){
        return false;
    }

    COLOR color = locations.at(start_name)->piece; //etsitään pelinappulan väri, joka on aloitus kohdassa
    locations.at(destination_name)->piece = color; //kopioidaan pelinappula kohteeseen
    locations.at(start_name)->piece = COLOR::EMPTY; //poistetaan pelinappula aloitus kohdasta

    return true;

}


bool GameBoard::is_Path(const string &start_name, const string& destination_name, std::set<string> &visited) const{//etsii polun

    if(start_name==destination_name){ //palauutaa true jos ollaan halutussa kohteessa, eli polku löytyy
        return true;
    }
    if (visited.find(start_name) != visited.end()) {
        return false;  // jos täällä on jo käyty, lopetetaan rekursio.
    }

    visited.insert(start_name);//lisätään polku listaan

    int start_x = locations.at(start_name)->x; //alustetaan arvot
    int start_y =locations.at(start_name)->y;
    string next_pos_name = to_string(start_x)+","+to_string(start_y+1); //muunnetaan seuraava askel

    //onko ylhäällä tilaa?
    if(locations.find(next_pos_name) != locations.end() && locations.at(next_pos_name)->piece == COLOR::EMPTY ){

        if(is_Path(next_pos_name, destination_name, visited))//onko sen yläpuolella tilaa?
        {
            return true;
        }
    }

    next_pos_name = to_string(start_x)+","+to_string(start_y-1); //muunnetaan seuraava askel

    //onko alapuolella tilaa?
    if(locations.find(next_pos_name) != locations.end() && locations.at(next_pos_name)->piece == COLOR::EMPTY ){

        if(is_Path(next_pos_name, destination_name,visited))//onko sen alapuolella tilaa?
        {
            return true;
        }
    }


    next_pos_name = to_string(start_x+1)+","+to_string(start_y); //muunnetaan seuraava askel

    //onko oikealla tilaa?
    if(locations.find(next_pos_name) != locations.end() && locations.at(next_pos_name)->piece == COLOR::EMPTY ){

        if(is_Path(next_pos_name, destination_name,visited))//onko sen oikealla tilaa?
        {
            return true;
        }
    }

    next_pos_name = to_string(start_x-1)+","+to_string(start_y); //muunnetaan seuraava askel

    //onko vasemmalla tilaa?
    if(locations.find(next_pos_name) != locations.end() && locations.at(next_pos_name)->piece == COLOR::EMPTY ){

        if(is_Path(next_pos_name, destination_name,visited))//onko sen vasemmalla tilaa?
        {
            return true;
        }
    }

    return false;
}
