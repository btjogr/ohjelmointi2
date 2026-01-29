#include "teacher.hh"
#include <algorithm>
#include <iostream>
#include <iterator>

Teacher::Teacher(const std::string& name, int age, const std::string office_num) : Person(name,age), office_num_(office_num)
{
    std::cout<<"Teacher created: "<<name<<std::endl;

}

Teacher::~Teacher()
{
     std::cout<<"Teacher destructed: "<<get_name()<<std::endl;
}

void Teacher::change_room(const std::string &new_room)
{
    office_num_=new_room;
}

void Teacher::add_new_course(const std::string &course)
{
    courses.push_back(course);
}

void Teacher::remove_course(const std::string &course)
{
    courses.remove(course);

}

void Teacher::print(std::ostream &output)
{
    Person::print(output);
    output << "*** " << office_num_<<": ";

    if(courses.size()==0){
        output << "No responsibilities" <<std::endl;
        return;
    }

    courses.sort();

    for (auto it = courses.begin(); it != courses.end(); ++it) {
        output << *it;
        if (std::next(it) != courses.end()) { // Tarkistetaan, onko seuraava alkio olemassa
            output << ", ";
        }
    }
    output<<std::endl;

}
