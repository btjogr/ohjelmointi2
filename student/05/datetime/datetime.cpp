#include "datetime.hh"
#include "dateexception.hh"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
    : Date(year,month,day)
{

   if(hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
    {



        std::ostringstream oss;
        oss << "Illegal time "
            << std::setw(2) << std::setfill('0') << hour << ":"
            << std::setw(2) << std::setfill('0') << minute << ":"
            << std::setw(2) << std::setfill('0') <<  second;


        throw DateException(oss.str().c_str());


    }



    hour_=hour;
    minute_=minute;
    second_=second;

}

int DateTime::getHour()
{
    return hour_;
}

int DateTime::getMinute()
{
    return minute_;
}

int DateTime::getSecond()
{
    return second_;
}

std::string DateTime::toString()
{
    std::ostringstream oss;
    oss << Date::toString() << " "  // Kutsutaan periytyvän Date-luokan metodia
        << std::setw(2) << std::setfill('0') << hour_ << ":"
        << std::setw(2) << std::setfill('0') << minute_ << ":"
        << std::setw(2) << std::setfill('0') << second_;
    return oss.str();

}
