#ifndef MOSTVOWELS_HH
#define MOSTVOWELS_HH

#include "basegame.hh"


class MostVowels : public BaseGame
{
public:
    MostVowels(unsigned int rounds): BaseGame(rounds){}
    virtual ~MostVowels();
private:
    void printGameName() const;
    unsigned int roundWinner(const std::string& word1,
                             const std::string& word2) const;
};

#endif // MOSTVOWELS_HH
