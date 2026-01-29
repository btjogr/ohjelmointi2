#ifndef TEACHER_HH
#define TEACHER_HH
#include "person.hh"
#include <list>

class Teacher : public Person
{
public:
    Teacher(const std::string& name, int age, const std::string office_num);

    virtual ~Teacher();

    void change_room(const std::string& new_room);

    void add_new_course(const std::string& course);
    void remove_course(const std::string& course);
    void print(std::ostream& output);

private:
    std::string office_num_;
    std::list<std::string> courses;
};

#endif // TEACHER_HH
