#include "mostvowels.hh"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



MostVowels::~MostVowels()
{

}

void MostVowels::printGameName() const
{
    cout<<"Most Vowels Game"<<endl;
}

unsigned int MostVowels::roundWinner(const std::string &word1, const std::string &word2) const
{


    char vokaalit[6]={'a','e','i','o','u','y'};

    int p1=0;
    int p2=0;

    for(int i=0;i<6;i++){

        for(long long unsigned int j=0;j<word1.size();j++){

            if(word1[j]==vokaalit[i]){

                p1++;

            }

        }

        for(long long unsigned int j=0;j<word1.size();j++){

            if(word2[j]==vokaalit[i]){

                p2++;

            }

        }

    }


    if(p1>p2){
        return 1;
    }
    if(p1<p2){
        return 2;
    }
    else{
        return 0;
    }



}
