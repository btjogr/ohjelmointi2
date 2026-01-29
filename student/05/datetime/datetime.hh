#ifndef DATETIME_HH
#define DATETIME_HH

#include <iostream>
#include "date.hh"

class DateTime : public Date
{
public:

    DateTime(int year, int month, int day, int hour, int minute, int second);

    int getHour();
    int getMinute();
    int getSecond();

    std::string toString();


private:

    int hour_;
    int minute_;
    int second_;


};

#endif // DATETIME_HH
