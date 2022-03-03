#include <iostream>
#include "quick sort.h"

using namespace std;

template <typename E>
class QuickSort
{
public:
    QuickSort(int, ArrayVector<E>); // QuickSort 클래스의 생성자
    void qsort(int, int);
    int partition(int, int);
    void display();

private:
    int nElem;             // elements의 개수를 나타내는 변수
    ArrayVector<E> myData; // ArrayVector 자료형의 myData
};

template <typename E>
QuickSort<E>::QuickSort(int size, ArrayVector<E> myVector) // QuickSort 클래스의 생성자
{
    nElem = size;
    myData = myVector;
}

template <typename E>
void QuickSort<E>::display() // myData의 모든 원소를 출력하는 함수
{
    for (int i = 0; i < nElem; i++)
    {
        cout << myData.at(i) << "\t";
    }
    cout << endl;
}

template <typename E>
void QuickSort<E>::qsort(int a, int b)
{
    if (a < b) // 적어도 2개 이상의 원소가 있을 때에만 정렬하도록 예외처리
    {
        int p = partition(a, b);
        display(); // 매 정렬 단계마다 현재 element들을 출력하기 위해 사용

        // pivot 기준으로 좌우를 나누어 재귀적으로 qsort를 호출
        qsort(a, p - 1);
        qsort(p + 1, b);
    }
}

template <typename E>
int QuickSort<E>::partition(int a, int b)
{
    E pivot = myData[b]; // 맨 오른쪽 값을 pivot 값으로 설정
    int l = a;
    int r = b - 1;
    E temp; // swap 하기 위한 임시 변수

    while (l <= r)
    {
        while (l <= r && myData[l] <= pivot)
            l++;
        while (l <= r && myData[r] >= pivot)
            r--;
        if (l < r)
        {
            // l이 r보다 작으면, myData[l]와 myData[r]를 swap
            temp = myData[l];
            myData[l] = myData[r];
            myData[r] = temp;
        }
    }

    // l이 r보다 커졌을 때, 즉, l과 r이 교차되었을 때만, myData[b]와 myData[l]를 swap
    temp = myData[l];
    myData[l] = myData[b];
    myData[b] = temp;

    return l; // 정렬 후 pivot의 index를 반환하여 Data를 partition함
}

int main()
{
    int size;

    ArrayVector<int> intV; // int 타입의 ArrayVector 객체 생성

    cout << "[int]" << endl;

    // 사용자로부터 입력 받을 element 개수 받기
    cout << "How many elements do you want to sort? : ";
    cin >> size;

    // 사용자로부터 intV를 입력받는 부분
    cout << "Enter " << size << " integer elements : ";
    int intTemp = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> intTemp;
        intV.insert(i, intTemp);
    }

    QuickSort<int> intSort(size, intV); // int 타입의 ArrayVector를 정렬하는 QuickSort 객체 생성

    // 퀵정렬
    cout << "Start sorting" << endl;
    intSort.display();
    intSort.qsort(0, size - 1);
    intSort.display();
    cout << "Done sorting" << endl;

    cout << "\n==========================================\n\n";

    ArrayVector<char> charV; // char 타입의 ArrayVector 객체 생성

    cout << "[char]" << endl;

    // 사용자로부터 입력 받을 element 개수 받기
    cout << "How many elements do you want to sort? : ";
    cin >> size;

    // 사용자로부터 charV를 입력받는 부분
    cout << "Enter " << size << " character elements : ";
    char charTemp = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> charTemp;
        charV.insert(i, charTemp);
    }

    QuickSort<char> charSort(size, charV); // char 타입의 ArrayVector를 정렬하는 QuickSort 객체 생성

    // 퀵정렬
    cout << "Start sorting" << endl;
    charSort.display();
    charSort.qsort(0, size - 1);
    charSort.display();
    cout << "Done sorting" << endl;

    return 0;
}