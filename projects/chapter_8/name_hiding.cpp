// name_hiding.cpp
// Demonstrates name hiding in inheritance
#include <iostream>
#include <string>

class Account
{
  public:
    virtual void withdraw(int value)
    {
        std::cout << "Account::withdraw(int): " << value << '\n';
    }
    virtual void withdraw(double value)
    {
        std::cout << "Account::withdraw(double): " << value << '\n';
    }
};

class SavingsAccount : public Account
{
  public:
    void withdraw(int value) override
    {
        std::cout << "SavingsAccount::withdraw(std::string): " << value << '\n';
    }
    void withdraw(double value) override
    {
        std::cout << "SavingsAccount::withdraw(std::string): " << value << '\n';
    }
    // using Account::withdraw; // Uncomment to restore base overloads
};

int main()
{
    SavingsAccount objSavingsAccount;

    // Scenario 1: Step 1: compiler finds withdraw(std::string) in SavingsAccount → OK
    // objSavingsAccount.withdraw("note");
    // Scenario 2: Step 1: compiler sees only withdraw(std::string) in SavingsAccount
    objSavingsAccount.withdraw(10);
    // Scenario 2: Step 2: parameter does not match → ERROR
    objSavingsAccount.withdraw(3.5); // Same reason → ERROR
}
