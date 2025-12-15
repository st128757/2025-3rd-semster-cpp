#include <gtest/gtest.h>

#include <iostream>
#include <sstream>

#include "Bank.h"
#include "pch.h"

// Тест 1: Создание банковского счета с дефолтными значениями
TEST(BankAccountTest, DefaultConstructor) {
  BankAccount account;
  EXPECT_EQ(account.GetBalance(), 0.0);
  EXPECT_EQ(account.GetAccountHolder(), "NOHOLDER");
  EXPECT_EQ(account.GetAccountNumber(), "NONUMBER");
}

// Тест 2: Депозит и проверка баланса
TEST(BankAccountTest, DepositOperations) {
  BankAccount account("12345", 1000.0, "John Doe");

  account.Deposit(500.0);
  EXPECT_EQ(account.GetBalance(), 1500.0);

  account.Deposit(250.5);
  EXPECT_EQ(account.GetBalance(), 1750.5);
}

// Тест 3: Снятие средств - успешное и неуспешное
TEST(BankAccountTest, WithdrawOperations) {
  BankAccount account("12345", 1000.0, "John Doe");

  // Успешное снятие
  account.Withdraw(300.0);
  EXPECT_EQ(account.GetBalance(), 700.0);

  // Попытка снять больше, чем на счету
  account.Withdraw(800.0);                 // Должно не сработать
  EXPECT_EQ(account.GetBalance(), 700.0);  // Баланс не должен измениться
}

// Тест 4: Создание и управление банком с несколькими счетами
TEST(BankTest, BankOperations) {
  Bank bank;

  // Добавляем счета
  bank.AddAccount("Alice", "A111", 1000.0);
  bank.AddAccount("Bob", "B222", 2000.0);
  bank.AddAccount("Charlie", "C333", 3000.0);

  // Проверяем общий баланс
  // Для проверки вывода в консоль можно использовать std::stringstream
  testing::internal::CaptureStdout();
  bank.GetTotalBalance();
  std::string output = testing::internal::GetCapturedStdout();
  // Общий баланс должен быть 6000
  EXPECT_TRUE(output.find("6000") != std::string::npos);
}

// Тест 5: Проверка печати информации о счете
TEST(BankAccountTest, PrintAccountInfo) {
  BankAccount account("123456", 1500.75, "John Smith");

  // Захватываем вывод
  testing::internal::CaptureStdout();
  account.PrintAccountInfo();
  std::string output = testing::internal::GetCapturedStdout();

  // Проверяем, что вся информация присутствует
  EXPECT_TRUE(output.find("1500.75") != std::string::npos);
  EXPECT_TRUE(output.find("John Smith") != std::string::npos);
  EXPECT_TRUE(output.find("123456") != std::string::npos);
}

// Тест 6: Проверка целостности данных после операций
TEST(BankAccountTest, DataIntegrity) {
  BankAccount account("ACC001", 500.0, "Test User");

  // Сохраняем исходные данные
  std::string originalHolder = account.GetAccountHolder();
  std::string originalNumber = account.GetAccountNumber();

  // Выполняем операции
  account.Deposit(200.0);
  account.Withdraw(100.0);

  // Проверяем, что номер счета и имя владельца не изменились
  EXPECT_EQ(account.GetAccountHolder(), originalHolder);
  EXPECT_EQ(account.GetAccountNumber(), originalNumber);
  EXPECT_EQ(account.GetBalance(), 600.0);  // 500 + 200 - 100 = 600
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}