#ifndef STUDENT_HH
#define STUDENT_HH
#include "person.hh"
#include <iostream>
#include <string>
#include <vector>

class Student : public Person
{
public:
    Student(const std::string& name, int age,const std::string& studen_num);

    virtual ~Student();

    void complete_course(const std::string& course);

    void print(std::ostream& output);

private:
   const std::string studen_num_;
   std::vector<std::string> suoritetut;
};

#endif // STUDENT_HH
