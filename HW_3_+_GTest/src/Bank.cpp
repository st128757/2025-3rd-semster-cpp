#include "Bank.h"

#include <iostream>

#include "pch.h"

// Реализация методов класса BankAccount
BankAccount::BankAccount(const std::string& a, const double b,
                         const std::string& c)
    : account_number_(a), balance_(b), account_holder_(c) {}

void BankAccount::Deposit(double cash) {
  balance_ += cash;
  std::cout << "Operation is completed\n";
}

void BankAccount::Withdraw(double amount) {
  if (balance_ - amount < 0) {
    std::cout << "It's not enough money on the balance. Operation wasn't "
                 "completed\n";
  } else {
    balance_ -= amount;
    std::cout << "Operation is completed\n";
  }
}

double BankAccount::GetBalance() const { return balance_; }

std::string BankAccount::GetAccountHolder() const { return account_holder_; }

std::string BankAccount::GetAccountNumber() const { return account_number_; }

void BankAccount::PrintAccountInfo() const {
  std::cout << "Your balance is " << balance_ << "\n";
  std::cout << account_holder_ << "\n";
  std::cout << account_number_ << "\n";
}

// Реализация методов класса Bank
void Bank::AddAccount(const std::string& acc_name,
                      const std::string& acc_number, double balance) {
  BankAccount A(acc_number, balance, acc_name);
  accounts_.push_back(A);
}

void Bank::GetTotalBalance() const {
  double total = 0.0;
  for (const BankAccount& account : accounts_) {
    total += account.GetBalance();
  }
  std::cout << "Total balance is: " << total << "\n";
}

void Bank::PrintAllAccounts() const {
  for (const BankAccount& account : accounts_) {
    std::cout << "Holdername: " << account.GetAccountHolder() << "\n"
              << "Accountnumber: " << account.GetAccountNumber() << "\n"
              << "Balance: " << account.GetBalance() << "\n";
  }
}