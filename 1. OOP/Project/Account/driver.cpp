#include <iostream>
using namespace std;

#include "account.h"

int main()
{
    int balance1;
    int balance2;
    cout << "account1 balance: $";
    cin >> balance1;
    cout << "account2 balance: $";
    cin >> balance2;

    Account account1(balance1);
    Account account2(balance2);

    // account1에서 인출할 금액을 입력받아 인출
    int amount1;
    cout << "\nEnter withdrawl amount for account1: ";
    cin >> amount1;
    cout << "\nAttempting to substract " << amount1 << " from account1 balance" << endl;
    account1.debit(amount1);

    cout << "\naccount1 balance: $" << account1.getBalance() << endl;
    cout << "account2 balance: $" << account2.getBalance() << endl;

    // account2에서 인출할 금액을 입력받아 인출
    int amount2;
    cout << "\nEnter withdrawl amount for account2: ";
    cin >> amount2;
    account2.debit(amount2);
    cout << "\naccount1 balance: $" << account1.getBalance() << endl;
    cout << "account2 balance: $" << account2.getBalance() << endl;

    // account1에서 입금할 금액을 입력받아 입금
    int amount3;
    cout << "\nEnter deposit amount for account1: ";
    cin >> amount3;
    account1.credit(amount3);

    cout << "\naccount1 balance: $" << account1.getBalance() << endl;
    cout << "account2 balance: $" << account2.getBalance() << endl;

    return 0;
}