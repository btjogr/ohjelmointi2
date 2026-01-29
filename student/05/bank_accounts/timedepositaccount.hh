#ifndef TIMEDEPOSITACCOUNT_HH
#define TIMEDEPOSITACCOUNT_HH

#include "account.hh"

class TimeDepositAccount : public Account
{
public:
    TimeDepositAccount(const std::string& owner);
    virtual ~TimeDepositAccount();

    virtual bool take_money(double amount) override;
    virtual void print() const override;

    void set_times(int days);
    void spend_time(int days);
    int get_days_left() const;

private:
    int deposit_time_=0;
    int days_left_;
};

#endif // TIMEDEPOSITACCOUNT_HH
