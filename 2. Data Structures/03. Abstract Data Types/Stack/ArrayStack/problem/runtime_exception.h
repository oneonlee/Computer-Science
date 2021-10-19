#ifndef ICE2004_WEEK09_HW01_RUNTIME_EXCEPTION_H
#define ICE2004_WEEK09_HW01_RUNTIME_EXCEPTION_H

#include <exception>
#include <iostream>
#include <string>

/**
 * 런타임에서 발생하는 예외
 * @extends std::exception
 */
class RuntimeException : public std::exception {
private:
    /** 예외 메세지 */
    std::string message;

public:
    /**
     * 주어진 예외 메세지로 런타임 예외를 생성합니다.
     * @param message 예외 메세지
     */
    explicit RuntimeException(const std::string& message)
    : message(message) {}

    /**
     * 예외의 오류 메세지를 반환합니다.
     * @return 오류 메세지
     */
    std::string get_message() const {
        return this->message;
    }
};

/**
 * `std::cout` 등을 이용해 오류 메세지를 출력할 수 있도록 `<<` 연산자를 오버로딩합니다.
 * @param out 출력 스트림
 * @param e 예외 객체
 * @return 출력 스트림
 */
std::ostream& operator<<(std::ostream& out, const RuntimeException& e) {
    return out << e.get_message();
}

#endif // ICE2004_WEEK09_HW01_RUNTIME_EXCEPTION_H
