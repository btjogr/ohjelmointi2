#ifndef SUDOKU_HH
#define SUDOKU_HH
#include <vector>
#include <array>


// Sizes of a block and the whole sudoku
const unsigned int BLOCK_SIZE = 3;
const unsigned int SIZE = 3 * BLOCK_SIZE;

class Sudoku
{
public:
    Sudoku();

    void print();

    void check();


    void set(int i, int j, char c);

private:

    char ruudukko[9][9]={};

};

#endif // SUDOKU_HH
