#include <iostream>
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
        const std::string& c = "NOHOLDER")
        : account_number_(a), balance_(b), account_holder_(c) {
    }

    // Методы-мутаторы (изменяют состояние)
    void Deposit(double cash) {
        // В C++ простые типы (double) лучше передавать по значению, а не по ссылке
        balance_ += cash;
        std::cout << "Operation is completed\n";
    }

    void Withdraw(double amount) {
        if (balance_ - amount < 0) {
            std::cout
                << "It's not enough money on the balance. Operation wasn't completed\n";
        }
        else {
            balance_ -= amount;
            std::cout << "Operation is completed\n";
        }
    }

    // Методы-аксессоры (не изменяют состояние) - помечены как const
    double GetBalance() const { return balance_; }

    std::string GetAccountHolder() const { return account_holder_; }

    std::string GetAccountNumber() const { return account_number_; }

    void PrintAccountInfo() const {
        std::cout << "Your balance is " << balance_ << "\n";
        std::cout << account_holder_ << "\n";
        std::cout << account_number_ << "\n";
    }
};

class Bank {
private:
    std::vector<BankAccount> accounts_;

public:
    void AddAccount(const std::string& acc_name, const std::string& acc_number,
        double balance) {
        // Используем константные ссылки и передачу по значению для оптимизации
        BankAccount A(acc_number, balance, acc_name);
        accounts_.push_back(A);
    }

    void GetTotalBalance() const {
        double total = 0.0;
        // Используем const BankAccount& для итерации, так как мы не меняем объекты
        for (const BankAccount& account : accounts_) {
            total += account.GetBalance();
        }
        std::cout << "Total balance is: " << total << "\n";
    }

    void PrintAllAccounts() const {
        for (const BankAccount& account : accounts_) {
            std::cout << "Holdername: " << account.GetAccountHolder() << "\n"
                << "Accountnumber: " << account.GetAccountNumber() << "\n"
                << "Balance: " << account.GetBalance() << "\n";
        }
    }
};

int main() {
    // Создаем банк
    Bank bank;

    // Данные для счетов
    std::string name1 = "John Doe";
    std::string number1 = "123456789";
    std::string name2 = "Jane Smith";
    std::string number2 = "987654321";
    std::string name3 = "Bob Johnson";
    std::string number3 = "555555555";
    double balance1 = 1000.0;
    double balance2 = 2500.0;
    double balance3 = 500.0;

    // Добавляем счета в банк
    bank.AddAccount(name1, number1, balance1);
    bank.AddAccount(name2, number2, balance2);
    bank.AddAccount(name3, number3, balance3);

    // Выводим информацию о всех счетах
    bank.PrintAllAccounts();

    // Проверяем общий баланс
    bank.GetTotalBalance();

    // Демонстрация операций с одним счетом
    std::cout << "\n=== ACCOUNT OPERATIONS ===\n";
    BankAccount account("111111111", 2000.0, "Alice Brown");
    account.PrintAccountInfo();

    double deposit = 500.0;
    std::cout << "Depositing " << deposit << "...\n";
    account.Deposit(deposit);

    double withdraw = 300.0;
    std::cout << "Withdrawing " << withdraw << "...\n";
    account.Withdraw(withdraw);

    // Попытка снять слишком много
    double big_withdraw = 3000.0;
    std::cout << "Attempting to withdraw " << big_withdraw << "...\n";
    account.Withdraw(big_withdraw);

    account.PrintAccountInfo();

    return 0;
}