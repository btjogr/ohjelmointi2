#ifndef ACCOUNT_HH
#define ACCOUNT_HH

#include <string>

class Account
{
public:
    Account(const std::string& owner);
    virtual ~Account();

    virtual void save_money(double amount);
    virtual bool take_money(double amount);
    virtual bool transfer_to(Account* other_account, double amount);
    virtual void print() const;
    void print_iban() const;

    double get_saldo() const;
    std::string get_iban() const;
    void set_saldo(double amount);

private:
    void generate_iban();

    std::string owner_;
    std::string iban_;
    double saldo_;

    static int running_number_;
};

#endif // ACCOUNT_HH
