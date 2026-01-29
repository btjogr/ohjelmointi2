#include "sudoku.hh"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

Sudoku::Sudoku()
{

    for(int i = 0; i<9;i++){

        for(int j = 0; j<9;j++){

            ruudukko[i][j]=' ';


        }

    }



}

void Sudoku::print() {
    for (int i = 0; i < 9; i++) {
        if ((i % 3 == 0 && i != 0 )||i==0) {
            cout << "#####################################" << endl;
        } else {
            cout << "#---+---+---#---+---+---#---+---+---#" << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) cout << "#";
            else cout << "|";
            cout << " " << ruudukko[i][j] << " ";
        }
        cout << "#" << endl;
    }
    cout << "#####################################" << endl;
}

void Sudoku::check() {
    vector<char> nums;
    char min_dup; // Pienin toistuva numero

    // Rivitarkistus
    for (int i = 0; i < 9; i++) {
        nums.clear();
        min_dup = '9' + 1; // Asetetaan suuremmaksi kuin suurin mahdollinen numero
        for (int j = 0; j < 9; j++) {
            char val = ruudukko[i][j];
            if (val == ' ') continue;  // Ohitetaan tyhjät ruudut
            if (find(nums.begin(), nums.end(), val) != nums.end()) {
                min_dup = min(min_dup, val); // Päivitetään pienin toistuva
            }
            nums.push_back(val);
        }
        if (min_dup <= '9') { // Jos löytyi duplikaatti
            cout << "Row " << i << " has multiple " << min_dup << "'s!" << endl;
            return;
        }
    }

    // Saraketarkistus
    for (int j = 0; j < 9; j++) {
        nums.clear();
        min_dup = '9' + 1;
        for (int i = 0; i < 9; i++) {
            char val = ruudukko[i][j];
            if (val == ' ') continue;  // Ohitetaan tyhjät ruudut
            if (find(nums.begin(), nums.end(), val) != nums.end()) {
                min_dup = min(min_dup, val); // Päivitetään pienin toistuva
            }
            nums.push_back(val);
        }
        if (min_dup <= '9') { // Jos löytyi duplikaatti
            cout << "Column " << j << " has multiple " << min_dup << "'s!" << endl;
            return;
        }
    }

    // 3x3-ruudukon tarkistus
    for (int l = 0; l < 9; l += 3) {
        for (int k = 0; k < 9; k += 3) {
            nums.clear();
            min_dup = '9' + 1;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char val = ruudukko[i + l][j + k];
                    if (val == ' ') continue;  // Ohitetaan tyhjät ruudut
                    if (find(nums.begin(), nums.end(), val) != nums.end()) {
                        min_dup = min(min_dup, val); // Päivitetään pienin toistuva
                    }
                    nums.push_back(val);
                }
            }
            if (min_dup <= '9') { // Jos löytyi duplikaatti
                cout << "Block at (" << l << ", " << k << ") has multiple " << min_dup << "'s!" << endl;
                return;
            }
        }
    }
}




void Sudoku::set(int i, int j, char c)
{




        if(i>8 || j>8){


            cout<<"Trying to access illegal cell ("<< i<<", "<<j<<")!"<<endl;
            return;
        }
        if (!(isdigit(c) || c == ' ')) {

            cout<<"Trying to set illegal character "<< c <<" to ("<<i<<", "<<
                j<<")!"<<endl;
            return;
        }

         ruudukko[i][j]=c;














}
