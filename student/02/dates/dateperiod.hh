#ifndef DATEPERIOD_HH
#define DATEPERIOD_HH

#include <string>
#include "date.hh"

class DatePeriod
{
public:

    DatePeriod(const Date& d1, const Date& d2)
        : Start_(d1), End_(d2) {}

    virtual ~DatePeriod();

    std::string getStart();

    std::string getEnd();

    unsigned int getDiff();

private:


    Date Start_;
    Date End_;
    int Diff_;



};

#endif // DATEPERIOD_HH
