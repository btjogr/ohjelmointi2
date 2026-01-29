#include <QtTest>
#include "../gameboard.hh"
// add necessary includes here

class pathtest : public QObject
{
    Q_OBJECT

public:
    pathtest();
    ~pathtest();

private slots:


    void correct_moves();//testaa lista laillisista siirroista

    void incorrect_moves();//testaa lista laittomista siirroista
};

pathtest::pathtest() {

}

pathtest::~pathtest() {}


void pathtest::correct_moves() {

    // Alustus
    GameBoard board;
    board.initialFill();

    // Lista mahdollisista laillisista siirroista
    vector<pair<pair<int, int>, pair<int, int>>> correct_move_list ={{{2,1},{3,3}}, {{2,5},{2,1}},{{1,5},{2,2}},{{3,3},{1,5}},{{2,2},{2,5}},{{2,1},{3,3}},{{1,1},{2,4}},{{3,3},{1,1}}, {{2,4},{3,3}},{{2,5},{2,1}}, {{3,5},{2,2}},{{4,5},{2,3}},{{1,5},{4,5}},{{2,3},{1,5}},{{3,3},{3,5}},{{2,2},{2,5}},{{2,1},{2,4}}  };



    for (auto pair : correct_move_list) { // käydään siirrot läpi

        Location start(pair.first.first-1, pair.first.second-1);
        Location destination(pair.second.first-1, pair.second.second-1);

        bool validLoc = board.isValidLocations(start, destination); //katsotaan sijainti

        bool path = board.move(start, destination); // Siirto

        if (!validLoc) {
            qWarning() << "Odotettiin laillista siirtoa, mutta move palautti false.";
        }

        QVERIFY2(path, "Odotettiin laillista siirtoa, mutta move palautti false");

        QVERIFY2(validLoc, "Odotettiin laillista siirtoa, mutta isValidLocations palautti false.");
    }
}

void pathtest::incorrect_moves() {

    // Alustus
    GameBoard board;
    board.initialFill();

    // Lista mahdollisista laittomista siirroista
    vector<pair<pair<int, int>, pair<int, int>>> incorrect_move_list =  {{{1,3},{3,3}}, {{4,2},{2,1}},{{2,5},{2,1}},
    {{3,1},{1,1}},{{2,2},{3,22}},{{2,1},{2,5}},{{0,0},{2,4}},{{1,11111},{4,5}}};


    for (auto pair : incorrect_move_list) {// käydään siirrot läpi

        Location start(pair.first.first-1, pair.first.second-1);
        Location destination(pair.second.first-1, pair.second.second-1);

        bool validLoc = board.isValidLocations(start, destination); //katsotaan sijainti

        bool path = board.move(start, destination); // Siirto


        if (validLoc) {
            QVERIFY2(!path, "Odotettiin laitonta siirtoa, mutta move palautti true.");
        } else {
            QVERIFY2(!validLoc, "Odotettiin laitonta siirtoa, mutta isValidLocations palautti true.");
        }

        // molemmat eivät voi olla totta yhtä aikaa
        QVERIFY2(!(validLoc && path), "Sekä validLoc että isValidLocations eivät voi olla true!");



    }
}
QTEST_APPLESS_MAIN(pathtest)

#include "tst_pathtest.moc"
