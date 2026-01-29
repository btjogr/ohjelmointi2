#include "creditaccount.hh"
#include <iostream>

CreditAccount::CreditAccount(const std::string& owner): Account(owner)
{

}

CreditAccount::~CreditAccount()
{

}

bool CreditAccount::take_money(double amount)
{
    if(get_saldo()-amount < -credit_limit_){
        std::cout<< "ERROR! Cannot take money: credit limit overflow"<<std::endl;
        return false;
    }

    set_saldo(get_saldo()-amount);

    return true;



}

void CreditAccount::print() const
{
    Account::print();
    std::cout<<"  ::: Credit limit : "<<credit_limit_<<std::endl;
}

// bool CreditAccount::transfer_to(Account *other_account, double amount)
// {
//     if (other_account->get_iban() == get_iban()) {
//         return false;  // Ei voi siirtää itselle
//     }

//     if (!take_money(amount)) {  // Käytetään take_money() varmistaaksemme säännöt
//         return false;
//     }

//     other_account->save_money(amount);
//     return true;
// }

void CreditAccount::set_credit_limit(double limit)
{
    credit_limit_=limit;
}

double CreditAccount::get_credit_limit() const
{

    return credit_limit_;

}
