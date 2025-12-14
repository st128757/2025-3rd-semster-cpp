#include "pch.h"
#include "Bank.h"
#include <iostream>
#include <string>

 /*int main() {
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
*/