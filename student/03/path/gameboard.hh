#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <set>

using namespace std;

// Gameboard size
const unsigned int ROWS = 5;
const unsigned int COLUMNS = 4;

//luokka jossa on mahdolliset värit
enum class COLOR {
    RED = 'R',
    GREEN = 'G',
    EMPTY = 'o'
};

//Sijainti -luokka jolla on pelilaudan koordinaatti
struct Location
{
    //rakentaja joka antaa argumentit x_ ja y_ arvot jäsenmuuttujille x ja y
    Location(unsigned int x_, unsigned int y_) : x(x_), y(y_), piece(COLOR::EMPTY) {}

    unsigned int x;          //pelilaudan x -kordinaatti
    unsigned int y;         //pelilaudan y -kordinaatti
    COLOR piece;            //sijainnissa oleva mahdollinen pelinappula

};


class GameBoard
{
public:
    // Constructor
    GameBoard();

    // Destructor
    virtual ~GameBoard();

    // Fill the gameboard initially: all green buttons are put on the top row
    // and all red buttons on the bottom rows, other locations are nullptrs.
    void initialFill();

    // Print the gameboard.
    void print() const;

    // Return true, if the game is over, i.e. if all red buttons are on the
    // top row and all green buttons are on the bottom row.
    bool isGameOver() const;

    // Check the validity of given locations. To be valid, a location must be
    // inside the gameboard, it must not be an unused location, and the start
    // must have a button, and the destination must not have a button.
    // (Implicitly also check that p1 and p2 are not the same points.)
    // Returns true, if both the given locations are valid.
    bool isValidLocations(const Location& start,
                          const Location& destination) const;

    // If possible, move a button from the start location to the destination
    // one. A move may consists of horizontal and vertical steps.
    // Return true, if move is possible, i.e. if there is a path between
    // the given locations.
    bool move(const Location& start, const Location& destination);


    //palauttaa true jos polku löytyy lähtö- ja kohdekordinaattien välillä
    bool is_Path(const string &start_name, const string& destination_name, std::set<string> &visited) const ;

private:

    //lista kaikista lokaatioista pelilaudalla
    std::map<string,std::shared_ptr<Location>> locations;


};

#endif // GAMEBOARD_HH
