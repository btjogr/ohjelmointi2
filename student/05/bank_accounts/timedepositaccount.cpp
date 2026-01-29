#include "timedepositaccount.hh"
#include <iostream>

TimeDepositAccount::TimeDepositAccount(const std::string& owner)
    : Account(owner), deposit_time_(0), days_left_(0) {}

TimeDepositAccount::~TimeDepositAccount() {}

bool TimeDepositAccount::take_money(double amount)
{
    if (days_left_ > 0)
    {
        std::cout << "ERROR! Cannot take money: deposit time has not expired" << std::endl;
        return false;
    }
    return Account::take_money(amount);
}

void TimeDepositAccount::print() const
{
    Account::print();
    std::cout << "  ::: Days left : " << days_left_ << std::endl;
}

void TimeDepositAccount::set_times(int days)
{
    deposit_time_ = days;
}

void TimeDepositAccount::spend_time(int days)
{
    deposit_time_ -= days;
}

int TimeDepositAccount::get_days_left() const
{
    return days_left_;
}
