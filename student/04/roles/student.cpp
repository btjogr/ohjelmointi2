#include "student.hh"

Student::Student(int from_year, int student_number): Role(from_year), student_num_(student_number) {}

Student::~Student()
{

}

void Student::print(std::ostream &output) const
{

    output<<"Student number: "<<student_num_<<std::endl;
}
