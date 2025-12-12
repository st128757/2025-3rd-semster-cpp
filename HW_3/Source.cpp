#include <iostream>
#include <string>
#include <vector>

class BankAccount {
 private:
  std::string account_number_;
  double balance_;
  std::string account_holder_;

 public:
  // Êîíñòðóêòîð
  BankAccount(const std::string& a = "NONUMBER", const double b = 0.0,
              const std::string& c = "NOHOLDER")
      : account_number_(a), balance_(b), account_holder_(c) {}

  // Ìåòîäû-ìóòàòîðû (èçìåíÿþò ñîñòîÿíèå)
  void Deposit(double cash) {
    // Â C++ ïðîñòûå òèïû (double) ëó÷øå ïåðåäàâàòü ïî çíà÷åíèþ, à íå ïî ññûëêå
    balance_ += cash;
    std::cout << "Operation is completed\n";
  }

  void Withdraw(double amount) {
    if (balance_ - amount < 0) {
      std::cout << "It's not enough money on the balance. Operation wasn't "
                   "completed\n";
    } else {
      balance_ -= amount;
      std::cout << "Operation is completed\n";
    }
  }

  // Ìåòîäû-àêñåññîðû (íå èçìåíÿþò ñîñòîÿíèå) - ïîìå÷åíû êàê const
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
    // Èñïîëüçóåì êîíñòàíòíûå ññûëêè è ïåðåäà÷ó ïî çíà÷åíèþ äëÿ îïòèìèçàöèè
    BankAccount A(acc_number, balance, acc_name);
    accounts_.push_back(A);
  }

  void GetTotalBalance() const {
    double total = 0.0;
    // Èñïîëüçóåì const BankAccount& äëÿ èòåðàöèè, òàê êàê ìû íå ìåíÿåì îáúåêòû
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
  // Ñîçäàåì áàíê
  Bank bank;

  // Äàííûå äëÿ ñ÷åòîâ
  std::string name1 = "John Doe";
  std::string number1 = "123456789";
  std::string name2 = "Jane Smith";
  std::string number2 = "987654321";
  std::string name3 = "Bob Johnson";
  std::string number3 = "555555555";
  double balance1 = 1000.0;
  double balance2 = 2500.0;
  double balance3 = 500.0;

  // Äîáàâëÿåì ñ÷åòà â áàíê
  bank.AddAccount(name1, number1, balance1);
  bank.AddAccount(name2, number2, balance2);
  bank.AddAccount(name3, number3, balance3);

  // Âûâîäèì èíôîðìàöèþ î âñåõ ñ÷åòàõ
  bank.PrintAllAccounts();

  // Ïðîâåðÿåì îáùèé áàëàíñ
  bank.GetTotalBalance();

  // Äåìîíñòðàöèÿ îïåðàöèé ñ îäíèì ñ÷åòîì
  std::cout << "\n=== ACCOUNT OPERATIONS ===\n";
  BankAccount account("111111111", 2000.0, "Alice Brown");
  account.PrintAccountInfo();

  double deposit = 500.0;
  std::cout << "Depositing " << deposit << "...\n";
  account.Deposit(deposit);

  double withdraw = 300.0;
  std::cout << "Withdrawing " << withdraw << "...\n";
  account.Withdraw(withdraw);

  // Ïîïûòêà ñíÿòü ñëèøêîì ìíîãî
  double big_withdraw = 3000.0;
  std::cout << "Attempting to withdraw " << big_withdraw << "...\n";
  account.Withdraw(big_withdraw);

  account.PrintAccountInfo();

  return 0;
}
== == == = private : std::string account_number_;
double balance_;
std::string account_holder_;

public:
// ÃŠÃ®Ã­Ã±Ã²Ã°Ã³ÃªÃ²Ã®Ã°
BankAccount(const std::string& a = "NONUMBER", const double b = 0.0,
            const std::string& c = "NOHOLDER")
    : account_number_(a), balance_(b), account_holder_(c) {}

// ÃŒÃ¥Ã²Ã®Ã¤Ã»-Ã¬Ã³Ã²Ã Ã²Ã®Ã°Ã» (Ã¨Ã§Ã¬Ã¥Ã­Ã¿Ã¾Ã² Ã±Ã®Ã±Ã²Ã®Ã¿Ã­Ã¨Ã¥)
void Deposit(double cash) {
  // Ã‚ C++ Ã¯Ã°Ã®Ã±Ã²Ã»Ã¥ Ã²Ã¨Ã¯Ã» (double) Ã«Ã³Ã·Ã¸Ã¥ Ã¯Ã¥Ã°Ã¥Ã¤Ã Ã¢Ã Ã²Ã¼
  // Ã¯Ã® Ã§Ã­Ã Ã·Ã¥Ã­Ã¨Ã¾, Ã  Ã­Ã¥ Ã¯Ã® Ã±Ã±Ã»Ã«ÃªÃ¥
  balance_ += cash;
  std::cout << "Operation is completed\n";
}

void Withdraw(double amount) {
  if (balance_ - amount < 0) {
    std::cout
        << "It's not enough money on the balance. Operation wasn't completed\n";
  } else {
    balance_ -= amount;
    std::cout << "Operation is completed\n";
  }
}

// ÃŒÃ¥Ã²Ã®Ã¤Ã»-Ã ÃªÃ±Ã¥Ã±Ã±Ã®Ã°Ã» (Ã­Ã¥ Ã¨Ã§Ã¬Ã¥Ã­Ã¿Ã¾Ã² Ã±Ã®Ã±Ã²Ã®Ã¿Ã­Ã¨Ã¥) -
// Ã¯Ã®Ã¬Ã¥Ã·Ã¥Ã­Ã» ÃªÃ Ãª const
double GetBalance() const { return balance_; }

std::string GetAccountHolder() const { return account_holder_; }

std::string GetAccountNumber() const { return account_number_; }

void PrintAccountInfo() const {
  std::cout << "Your balance is " << balance_ << "\n";
  std::cout << account_holder_ << "\n";
  std::cout << account_number_ << "\n";
};

class Bank {
 private:
  std::vector<BankAccount> accounts_;

 public:
  void AddAccount(const std::string& acc_name, const std::string& acc_number,
                  double balance) {
    // ÃˆÃ±Ã¯Ã®Ã«Ã¼Ã§Ã³Ã¥Ã¬ ÃªÃ®Ã­Ã±Ã²Ã Ã­Ã²Ã­Ã»Ã¥ Ã±Ã±Ã»Ã«ÃªÃ¨ Ã¨
    // Ã¯Ã¥Ã°Ã¥Ã¤Ã Ã·Ã³ Ã¯Ã® Ã§Ã­Ã Ã·Ã¥Ã­Ã¨Ã¾ Ã¤Ã«Ã¿ Ã®Ã¯Ã²Ã¨Ã¬Ã¨Ã§Ã Ã¶Ã¨Ã¨
    BankAccount A(acc_number, balance, acc_name);
    accounts_.push_back(A);
  }

  void GetTotalBalance() const {
    double total = 0.0;
    // ÃˆÃ±Ã¯Ã®Ã«Ã¼Ã§Ã³Ã¥Ã¬ const BankAccount& Ã¤Ã«Ã¿ Ã¨Ã²Ã¥Ã°Ã Ã¶Ã¨Ã¨, Ã²Ã Ãª
    // ÃªÃ Ãª Ã¬Ã» Ã­Ã¥ Ã¬Ã¥Ã­Ã¿Ã¥Ã¬ Ã®Ã¡ÃºÃ¥ÃªÃ²Ã»
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
  // Ã‘Ã®Ã§Ã¤Ã Ã¥Ã¬ Ã¡Ã Ã­Ãª
  Bank bank;

  // Ã„Ã Ã­Ã­Ã»Ã¥ Ã¤Ã«Ã¿ Ã±Ã·Ã¥Ã²Ã®Ã¢
  std::string name1 = "John Doe";
  std::string number1 = "123456789";
  std::string name2 = "Jane Smith";
  std::string number2 = "987654321";
  std::string name3 = "Bob Johnson";
  std::string number3 = "555555555";
  double balance1 = 1000.0;
  double balance2 = 2500.0;
  double balance3 = 500.0;

  // Ã„Ã®Ã¡Ã Ã¢Ã«Ã¿Ã¥Ã¬ Ã±Ã·Ã¥Ã²Ã  Ã¢ Ã¡Ã Ã­Ãª
  bank.AddAccount(name1, number1, balance1);
  bank.AddAccount(name2, number2, balance2);
  bank.AddAccount(name3, number3, balance3);

  // Ã‚Ã»Ã¢Ã®Ã¤Ã¨Ã¬ Ã¨Ã­Ã´Ã®Ã°Ã¬Ã Ã¶Ã¨Ã¾ Ã® Ã¢Ã±Ã¥Ãµ Ã±Ã·Ã¥Ã²Ã Ãµ
  bank.PrintAllAccounts();

  // ÃÃ°Ã®Ã¢Ã¥Ã°Ã¿Ã¥Ã¬ Ã®Ã¡Ã¹Ã¨Ã©
  // Ã¡Ã Ã«Ã Ã­Ã±
  bank.GetTotalBalance();

  // Ã„Ã¥Ã¬Ã®Ã­Ã±Ã²Ã°Ã Ã¶Ã¨Ã¿ Ã®Ã¯Ã¥Ã°Ã Ã¶Ã¨Ã© Ã± Ã®Ã¤Ã­Ã¨Ã¬ Ã±Ã·Ã¥Ã²Ã®Ã¬
  std::cout << "\n=== ACCOUNT OPERATIONS ===\n";
  BankAccount account("111111111", 2000.0, "Alice Brown");
  account.PrintAccountInfo();

  double deposit = 500.0;
  std::cout << "Depositing " << deposit << "...\n";
  account.Deposit(deposit);

  double withdraw = 300.0;
  std::cout << "Withdrawing " << withdraw << "...\n";
  account.Withdraw(withdraw);

  // ÃÃ®Ã¯Ã»Ã²ÃªÃ  Ã±Ã­Ã¿Ã²Ã¼
  // Ã±Ã«Ã¨Ã¸ÃªÃ®Ã¬ Ã¬Ã­Ã®Ã£Ã®
  double big_withdraw = 3000.0;
  std::cout << "Attempting to withdraw " << big_withdraw << "...\n";
  account.Withdraw(big_withdraw);

  account.PrintAccountInfo();

  return 0;
}
