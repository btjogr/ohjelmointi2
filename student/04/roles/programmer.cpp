#include "programmer.hh"
#include "person.hh"
#include <algorithm>

Programmer::Programmer(int from_year): Role(from_year)
{

}

Programmer::~Programmer()
{

}

void Programmer::add_skill(const std::string &skill)
{
    skills.push_back(skill);
    skills.sort();
}

void Programmer::print(std::ostream &output) const
{

    if(skills.size()==0){
        output<<"No skills"<<std::endl;
        return;
    }
    output<<"Skills:";



    for(auto it = std::begin(skills); it != std::end(skills); it++){

        output<<" "<<*it;


    }





    output<<std::endl;
}
