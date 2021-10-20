int MyFunc(int num)
{
    num++;
    return num;
}

int MyFunc(int a, int b)
{
    return a + b;
}

int main(void)
{
    MyFunc(20);     // MyFunc(int num) 함수의 호출
    MyFunc(30, 40); // MyFunc(int a, int b) 함수의 호출
    return 0;
}