#include <iostream>
using namespace std;

#include "account.h"

Account::Account(int _balance)
{
    initBalance(_balance);
}

void Account::initBalance(int _balance) // 초기잔액을 받아들이고 데이터 멤버를 그 값으로 초기화하는 함수
{
    if (_balance > 0) // 초기잔액이 0보다 크거나 같은지 확인하는 검증
    {
        balance = _balance;
    }
    else
    {
        balance = 0;                                 // 초기잔액이 유효하지 않으므로 잔액을 0으로 설정
        cout << "Balance should be over 0!" << endl; // 값이 유효하지 않음을 가리키는 오류메시지 출력
    }
}

void Account::credit(int amount)
{
    balance += amount;
}

void Account::debit(int amount)
{
    if (amount > balance) // 양이 잔액을 초과하면 잔액은 바뀌지 않고 그대로 유지
    {
        cout << "\nDebit amount exceeded account balance." << endl;
    }
    else
    {
        balance -= amount;
    }
}

int Account::getBalance() // 현재 잔액 반환
{
    return balance;
}
