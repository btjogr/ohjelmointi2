#include "student.hh"
#include "person.hh"

Student::Student(const std::string& name, int age,const std::string& studen_num): Person(name,age), studen_num_(studen_num) {
    std::cout<<"Student created: "<<name<<std::endl;
}

Student::~Student()
{
    std::cout<<"Student destructed: "<<get_name()<<std::endl;
}

void Student::complete_course(const std::string &course)
{
    suoritetut.push_back(course);
}

void Student::print(std::ostream &output)
{
    Person::print(output);
    output << "+++ " << studen_num_<<": ";

    if(suoritetut.size()==0){
        output << "No courses completed" <<std::endl;
        return;
    }

    for (auto it = suoritetut.begin(); it != suoritetut.end(); ++it) {
        output << *it;
        if (std::next(it) != suoritetut.end()) { // Tarkistetaan, onko seuraava alkio olemassa
            output << ", ";
        }
    }


    output << std::endl;




}
