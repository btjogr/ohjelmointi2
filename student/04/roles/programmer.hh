#ifndef PROGRAMMER_HH
#define PROGRAMMER_HH
#include "role.hh"
#include <iostream>
#include <vector>
#include <list>
class Programmer : public Role
{
public:
    Programmer(int from_year);
    virtual ~Programmer();
    void add_skill(const std::string& skill);
    void print(std::ostream& output)const;
private:

    std::list<std::string> skills;
};

#endif // PROGRAMMER_HH
