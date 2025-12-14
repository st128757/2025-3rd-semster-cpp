#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>

class BankAccount {
private:
    std::string account_number_;
    double balance_;
    std::string account_holder_;

public:
    // Конструктор
    BankAccount(const std::string& a = "NONUMBER", const double b = 0.0,
        const std::string& c = "NOHOLDER");

    void Deposit(double cash);
    void Withdraw(double amount);

    double GetBalance() const;
    std::string GetAccountHolder() const;
    std::string GetAccountNumber() const;
    void PrintAccountInfo() const;
};

class Bank {
private:
    std::vector<BankAccount> accounts_;

public:
    void AddAccount(const std::string& acc_name, const std::string& acc_number,
        double balance);
    void GetTotalBalance() const;
    void PrintAllAccounts() const;
};

#endif // BANK_H