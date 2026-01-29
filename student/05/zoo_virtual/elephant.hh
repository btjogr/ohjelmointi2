#ifndef ELEPHANT_HH
#define ELEPHANT_HH
#include <mammal.hh>

class Elephant : public Mammal
{
public:
    Elephant();
    void vocalize(std::ostream& output);
};

#endif // ELEPHANT_HH
