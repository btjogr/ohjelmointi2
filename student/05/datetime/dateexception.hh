#ifndef DATEEXCEPTION_HH
#define DATEEXCEPTION_HH

#include <iostream>

class DateException : public std::domain_error
{
public:
    DateException(const char* message);

    virtual ~DateException();
};

#endif // DATEEXCEPTION_HH
