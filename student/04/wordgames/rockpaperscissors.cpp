#include "rockpaperscissors.hh"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



RockPaperScissors::~RockPaperScissors()
{

}

void RockPaperScissors::printGameName() const
{
    cout<<"Rock-Paper-Scissors Game"<<endl;
}

unsigned int RockPaperScissors::roundWinner(const std::string &word1, const std::string &word2) const
{
    std::string words[3] = {"rock", "paper", "scissors"};


    auto w1 = find(std::begin(words),std::end(words),word1);
    auto w2 = find(std::begin(words),std::end(words),word2);



    if(word1==word2){
        return 0;
    }



    if(w1!=std::end(words) && w2==std::end(words)){
        return 1;
    }

    if(w1==std::end(words) && w2!=std::end(words)){

        return 2;
    }

    if(word1==word2){
        return 0;
    }
    if(word1==words[0] && word2==words[1]){
        return 2;
    }
    if(word1==words[1] && word2==words[0]){
         return 1;
    }

    if(word1==words[0] && word2==words[2]){
        return 1;
    }
    if(word1==words[2] && word2==words[0]){
        return 2;
    }

    if(word1==words[1] && word2==words[2]){
        return 2;
    }
    if(word1==words[2] && word2==words[1]){
        return 1;
    }

    else{
        return 0;
    }


}
