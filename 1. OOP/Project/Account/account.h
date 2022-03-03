#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account // 은행이 고객의 은행계좌를 표현하는데 사용할 수 있는 클래스
{
private:
    int balance; // 계좌의 잔액을 표현하는 int형의 데이터 멤버

public:
    Account(int _balance); // 생성자

    void initBalance(int _balance); // 초기잔액을 받아들이고 데이터 멤버를 그 값으로 초기화하는 함수
    void credit(int amount);        // 현재 잔액에 일정액을 더하는 멤버 함수
    void debit(int amount);
    int getBalance(); // 현재 잔액 반환
};

#endif