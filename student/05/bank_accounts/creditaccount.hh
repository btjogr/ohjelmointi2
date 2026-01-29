#ifndef CREDITACCOUNT_HH
#define CREDITACCOUNT_HH

#include "account.hh"

class CreditAccount : public Account
{
public:
    CreditAccount(const std::string& owner);
    virtual ~CreditAccount();

    virtual bool take_money(double amount) override;
    virtual void print() const override;
    void set_credit_limit(double limit);
    double get_credit_limit() const;

private:
    double credit_limit_;
};

#endif // CREDITACCOUNT_HH
