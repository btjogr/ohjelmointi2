
/*
 * Ohjelman kirjoittajat:
 * Nimi: Joona-Jussi Grönmark
 * Opiskelijanumero: 152042071
 * Käyttäjätunnus: btjogr
 * E-Mail: joona-jussi.gronmark@tuni.fi
*/



#include "mainwindow.hh"
#include "chess.hh"
#include <QApplication>
#include <iostream>
#include <string>

using namespace std;




int char_to_int(char c){//ei tarkista oikeellisuutta


    return int(c-48)-1;


}






void run_in_console(){

    Chess peli;
    peli.start_game(WHITE);
    peli.print_board();

    string input;//muoto on sijainti koordinaatit ja kohde koordinaatit. välilyönti erotuksena esim. 0 1 2 2


    while(true){// luupataan peliä

        std::getline(cin,input);

        if(input =="q"){//jos q niin lopetetaan peli
            break;
        }

        if(input!="" ){


            //siirretään nappulaa
            auto piece = peli.get_board().get_piece_at({ char_to_int( input.at(0)) , char_to_int(input.at(2)) });

            if (piece != nullptr) {
                bool success = peli.make_move(piece, { char_to_int(input.at(4)) , char_to_int(input.at(6)) });

                if (success) {
                    std::cout << "Siirto onnistui!\n";
                } else {
                    std::cout << "Siirto epäonnistui!\n";
                }

                peli.print_board();
            } else {
                std::cout << "Nappulaa ei löytynyt annetusta paikasta!\n";
            }
        }





    }




}



int main(int argc, char *argv[])
{
    run_in_console();
   // QApplication a(argc, argv);
    //MainWindow w;
   // w.show();

    //return a.exec();
    return 0;
}

