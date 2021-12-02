#include <iostream>

using std::cout;
using std::endl;

// Person 클래스 선언 및 정의를 한 파일에 합니다.
class Person {
private:
	char* name;			// char형 포인터 변수이자 char 배열입니다.
	int age;
	double height;
public:
	Person(int age, double height, const char* myname) : age(age), height(height) {
		/*
		Person 클래스 타입의 객체를 생성할 때 인자를 넘긴다면 해당 생성자가 호출됩니다.
		이 생성자에서는 Person 데이터 변수인 name을 myname의 길이만큼(null포함) 동적할당하여 값을 복사합니다.
		*/
		int len = strlen(myname) + 1;		// strlen은 문자열의 길이를 반환합니다. 이 때 문자열의 끝을 의미하는 null은 포함하지 않습니다. ex) strlen("Hello") -> 5
		name = new char[len];				// null 길이까지 포함한 len만큼의 메모리 공간을 동적할당합니다. 
		strcpy_s(name, len, myname);		// strcpy_s 는 문자열의 값을 복사해주는 함수입니다.
		cout << "Person object's constructor was called" << endl;	// 생성자를 알리는 문구 출력합니다.
	}
	Person(const Person& copy) {
		/*
		디폴트 복사 생성자가 아닌 사용자가 정의한 복사 생성자입니다.
		객체를 함수 인수로 받습니다. 함수 인수로 들어오는 copy는 수정할 일이 없기 때문에 const로 받습니다.
		각 멤버별 복사를 명시적으로 합니다.
		*/
		age = copy.age; height = copy.height;		//현재 Person 클래스이며 copy 또한 Person 클래스이므로  private 데이터 변수에 바로 접근이 가능합니다.
		// 아래는 복사받으려는 객체의 데이터 변수 중 name을 동적할당하여 '메모리 공간을 할당'받습니다.
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy_s(name, len, copy.name);

	}
	void ShowPersonInfo() const {
		/*
		Person 클래스의 데이터 변수를 모두 출력하는 함수입니다.
		*/
		cout << "Name : " << name << " Age : " << age << " Height : " << height << endl;
	}
	~Person() {
		// Person 클래스의 소멸자입니다. 동적할당을 한 name 변수의 메모리 해제를 합니다.
		delete[] name;	// name 변수의 메모리 해제를 합니다.
		cout << "Person object's destructor was called" << endl;	// 소멸자를 알리는 문구 출력합니다.
	}
	void printAddr(const char* obj_name) {
		/*
		name 변수가 가리키는 메모리 주소를 출력하는 함수입니다.
		shallow copy가 이뤄졌다면 name 변수만 주소가 동일할 것입니다.
		*/
		printf("%s's object\n", obj_name);
		printf("address of name variable : %X\n", name);		// 아래 변수와 다르게 &을 붙이지 않고 변수 그대로 넣는 이유는 name이 포인터 변수이기 때문에 포인터 변수 안에는 주소가 있기 때문입니다.
		printf("address of age variable : %X\n", &age);			// 변수 앞에 &을 붙이면 해당 변수의 메모리 주소를 반환합니다. 포인터 변수 앞에 &을 붙인다면 포인터 변수가 가리키고 있는 메모리 주소가 아닌 
		printf("address of height variable : %X\n", &height);	// '포인터 변수'의 메모리 주소를 반환합니다. 
	}
};

int main() {
	Person man1(20, 180.0, "John");	// man1 객체는 정상적으로 생성이 됩니다.
	Person man2 = man1;				// Person man2(man1); 와 동일하며 복사생성자를 호출하여 생성하는 방법입니다.


	man1.ShowPersonInfo();			// 각 객체의 데이터 변수를 출력했을 때 마치 개별적으로 메모리 공간을 잡고 복사가 이뤄진 것처럼 보입니다.
	man2.ShowPersonInfo();

	man1.printAddr("man1");			// 앞선 예제와 달리 디폴트 복사 생성자가 아닌 사용자 정의 복사 생성자를 통해 직접 메모리 공간을 할당하여
	man2.printAddr("man2");			// deep copy를 하여 두 객체의 name 변수가 가리키고 있는 메모리 주소가 다릅니다. 따라서 소멸자 역시 2번 호출되며 2개의 동적할당 받은 메모리 공간이 정상적으로 해제됩니다.

	return 0;
}