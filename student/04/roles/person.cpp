#include "person.hh"

#include <memory>

Person::Person(const std::string &name): name_(name)
{

}

Person::~Person()
{

    for(auto &r: roles_){
        r=nullptr;
    }


    roles_.clear();



}

void Person::add_role(Role *role)
{

    //std::shared_ptr<Role> pt(role);


    roles_.push_back(role);


}

void Person::print(std::ostream &output) const
{

    for(auto r : roles_){
        r->print(output);
    }






}

void Person::print_name(std::ostream &output) const
{

    output<<name_<<std::endl;
}
