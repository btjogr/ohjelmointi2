#ifndef MAMMAL_HH
#define MAMMAL_HH
#include <animal.hh>
#include <string>
#include <iostream>
class Mammal : public Animal
{
public:
    Mammal();
    void suckle(std::ostream& output);

private:
    //int x_;
    //int y_;


};


#endif // MAMMAL_HH
