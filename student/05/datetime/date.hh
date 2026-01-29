#ifndef DATE_HH
#define DATE_HH

#include <iostream>

// Some bound values
const int FIRST_DAY = 1;
const int FIRST_MONTH = 1;
const int FIRST_YEAR = 1000;
const int LAST_YEAR = 9999;

// Number of days in months
int const MONTH_SIZES[12] = { 31, 28, 31, 30, 31, 30,
                             31, 31, 30, 31, 30, 31 };




class Date
{
public:
    Date(int year, int month, int day);

    int getYear();
    int getMonth();
    int getDay();

    virtual std::string toString();


    bool isLegal(int day,int month,int year) const;
    bool isLeapYear(int year)const;



private:

    int year_;
    int month_;
    int day_;

};

#endif // DATE_HH
