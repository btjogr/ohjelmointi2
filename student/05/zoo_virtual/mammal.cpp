#include "mammal.hh"
#include <iostream>
Mammal::Mammal() {

    set_moving_noise("Kip kop kip kop");

}

void Mammal::suckle(std::ostream &output)
{
    output<<"Mus mus"<<std::endl;
}
