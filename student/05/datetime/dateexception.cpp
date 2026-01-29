#include "dateexception.hh"

using namespace std;

DateException::DateException(const char *message): std::domain_error(message)
{


}

DateException::~DateException()
{

}
