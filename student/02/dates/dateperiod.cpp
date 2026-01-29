#include "dateperiod.hh"
#include "date.hh"
#include <iostream>


DatePeriod::~DatePeriod()
{

}

std::string DatePeriod::getStart()
{
    return Start_.toIsoFormat();
}

std::string DatePeriod::getEnd()
{
    return End_.toIsoFormat();
}

unsigned int DatePeriod::getDiff()
{
    if (End_ < Start_) {
        return 0;
    }

    int total_days = 0;

    // Lasketaan vuodet
    for (int i = Start_.getYear(); i < End_.getYear(); i++) {
        total_days += (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) ? 366 : 365;
    }

    // Lasketaan päivät vuoden alkuun asti lähtöpäivälle
    int start_days = 0;
    for (int i = 0; i < Start_.getMonth() - 1; i++) {  // Kuukaudet ovat 1-12
        start_days += MONTH_SIZES[i];
        if (i == 1 && Start_.isLeapYear()) {  // Helmikuun lisäpäivä
            start_days++;
        }
    }
    start_days += Start_.getDay();

    // Lasketaan päivät vuoden alkuun asti päättymispäivälle
    int end_days = 0;
    for (int i = 0; i < End_.getMonth() - 1; i++) {  // Kuukaudet ovat 1-12
        end_days += MONTH_SIZES[i];
        if (i == 1 && End_.isLeapYear()) {  // Helmikuun lisäpäivä
            end_days++;
        }
    }
    end_days += End_.getDay();

    // Vähennetään lähtöpäivän päivämäärän osuus vuodesta
    total_days += end_days - start_days;

    return total_days;
}


