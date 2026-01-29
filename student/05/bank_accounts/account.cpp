#include "account.hh"
#include <iostream>

int Account::running_number_ = 0;

Account::Account(const std::string& owner) : owner_(owner), saldo_(0)
{
    generate_iban();
}

Account::~Account() {}

void Account::save_money(double amount)
{
    saldo_ += amount;
}

bool Account::take_money(double amount)
{
    if (saldo_ < amount)
        return false;
    saldo_ -= amount;
    return true;
}

bool Account::transfer_to(Account* other_account, double amount)
{
    if (this == other_account)
        return true;

    if (!take_money(amount))
        return false;

    other_account->save_money(amount);
    return true;
}

void Account::print() const
{
    std::cout << owner_ << " : " << iban_ << " : " << saldo_ << " euros" << std::endl;
}

void Account::print_iban() const
{
    std::cout << iban_;
}

double Account::get_saldo() const
{
    return saldo_;
}

std::string Account::get_iban() const
{
    return iban_;
}

void Account::set_saldo(double amount)
{
    saldo_ = amount;
}

void Account::generate_iban()
{
    if (++running_number_ > 99)
    {
        std::cerr << "Too many accounts" << std::endl;
        exit(EXIT_FAILURE);
    }
    iban_ = std::string("FI00 1234 ") + (running_number_ < 10 ? "0" : "") + std::to_string(running_number_);

}
