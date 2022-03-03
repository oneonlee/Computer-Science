#ifndef DATE_H
#define DATE_H

class Date // 월, 일, 년 정보를 데이터 멤버로 포함하는 클래스
{
private:
    int month;
    int day;
    int year;

public:
    Date(int m, int d, int y); // 세 데이터 멤버를 초기화하기 위해 세 매개 변수를 사용하는 생성자 제공

    void setMonth(int m);
    int getMonth();
    void setDay(int d); // 제공되는 '일' 값이 정확하다고 가정
    int getDay();
    void setYear(int y); // 제공되는 '연도' 값이 정확하다고 가정
    int getYear();
    void displayDate(); // 월,일,년을 슬래시로 구분하여 출력하는 멤버함수
};

#endif