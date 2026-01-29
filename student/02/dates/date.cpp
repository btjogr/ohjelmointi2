#include "date.hh"

//TODO: Implement other functions here


Date::Date(int year, int month, int day)
{
    year_=year;
    month_=month;
    day_=day;
}

Date::~Date()
{

}

int Date::getYear() const
{
    return year_;
}

int Date::getMonth() const
{
    return month_;
}

int Date::getDay() const
{
    return day_;
}

std::string Date::toString() const
{


    return std::to_string(day_)+"."+std::to_string(month_)+"."+std::to_string(year_);



}

std::string Date::toIsoFormat() const
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


    return std::to_string(year_)+"-"+month+"-"+day;


}

bool Date::operator<(const Date &other) const
{

    if(this->getYear()<other.getYear()){
        return true;

    }
    if(this->getMonth()<other.getMonth() && this->getYear()==other.getYear()){
        return true;

    }
    if(this->getDay() < other.getDay() && this->getMonth()==other.getMonth() && this->getYear()==other.getYear()){
        return true;

    }
    else {
        return false;
    }
}

bool Date::operator==(const Date &other) const
{
    if(this->getDay() == other.getDay() && this->getMonth()==other.getMonth() && this->getYear()==other.getYear()){
        return true;

    }
    else {
        return false;
    }
}

bool Date::isLeapYear() const
{
    return (year_ % 4 == 0) and ((year_ % 100 != 0) or (year_ % 400 == 0));
}

bool Date::isLegal() const
{


    if(year_<=LAST_YEAR && year_>=FIRST_YEAR){

        if(month_>=FIRST_MONTH && month_<= 12){


            int ly=0;

            if(isLeapYear()){
                ly=1;
            }

            if(day_>=FIRST_DAY && day_<=MONTH_SIZES[month_-1]+ly){
                return true;

            }
        }
    }


    return false;


}

