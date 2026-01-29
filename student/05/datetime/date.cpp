#include "date.hh"
#include "dateexception.hh"
#include <sstream>
#include <iomanip>
Date::Date(int year, int month, int day) {


    if(isLegal(day,month,year)){

        day_=day;
        month_=month;
        year_=year;

    }else {


        std::ostringstream oss;
        oss << "Illegal date "
            << std::setw(2) << std::setfill('0') << day << "."
            << std::setw(2) << std::setfill('0') << month << "."
            << year;


        throw DateException(oss.str().c_str());

    }

}

int Date::getYear()
{
    return year_;
}

int Date::getMonth()
{
    return month_;
}

int Date::getDay()
{
    return day_;
}

std::string Date::toString()
{
    std::string day;
    std::string month;

    if(day_<=9){
        day="0"+std::to_string(day_);
    }else{
        day=std::to_string(day_);
    }
    if(month_<=9){
        month="0"+std::to_string(month_);
    }
    else {
        month=std::to_string(month_);
    }


    return day+"."+month+"."+std::to_string(year_);


}



bool Date::isLeapYear(int year) const
{
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

bool Date::isLegal(int day,int month,int year) const
{


    if(year<=LAST_YEAR && year>=FIRST_YEAR){

        if(month>=FIRST_MONTH && month<= 12){


            int ly=0;

            if(isLeapYear(year)){
                ly=1;
            }

            if(day>=FIRST_DAY && day<=MONTH_SIZES[month-1]+ly){
                return true;

            }
        }
    }


    return false;


}
