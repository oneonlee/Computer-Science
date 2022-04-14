✩
중요 기호 : `✩`

# 알고리즘과 문제해결

## 알고리즘이란?

- 알고리즘(algorithm)
  - 특정문제를 해결하기 위해 기술한 일련의 명령문
- 프로그램(program)
  - 알고리즘을 컴퓨터가 이해하고 실행할 수 있는 특정 프로그래밍 언어로 표현한 것
- 알고리즘의 요건
  - 완전성과 명확성
    - 수행결과와 순서가 완전하고 명확하게 명세되어야 함
    - 순수하게 알고리즘이 지시하는대로 실행하기만하면 의도한 결과가 얻어져야 함
  - 입력과 출력
    - 입력: 알고리즘이 처리되어야 할 대상으로 제공되는 데이터
    - 출력: 입력데이터를 처리하여 얻은 결과
  - 유한성
    - 유한한 단계 뒤에는 반드시 종료

### 성능 분석

#### 공간 복잡도 (space complexity)

- 알고리즘을 실행시켜 완료하는데 필요한 총 저장 공간
- Sa = Sc + Se
  - Sc :고정공간
    - 명령어 공간, 단순 변수, 복합 데이타 구조와 변수, 상수
  - **Se : 가변 공간 ✩**
    - 크기가 변하는 데이타 구조와 변수들이 필요로 하는 저장 공간
    - 런타임 스택(runtime stack)을 위한 저장 공간
      - 재귀호출과 관련

#### 시간 복잡도 (time complexity)

- 알고리즘을 실행시켜 완료하는데 걸리는 시간
- Ta = Tc + Te
  - Tc: 컴파일 시간
  - Te: 실행 시간
    - 단위 명령문 하나를 실행하는데 걸리는 시간
    - 실행 빈도수 (frequency count)

### 함수 호출의 Mechanism 7단계

1. Instruction pointer를 1 증가 후 스택에 push
   - 1 증가하는 것은 그 다음 명령어를 기억하겠다는 의미
2. return type용 공간을 스택에 push
   - return type : `int` - 4byte, `short` - 2byte, `Person` - 100byte 등
3. 호출된 함수로 제어이동 (Jump)
4. 현 상태의 스택의 top을 stack frame이라는 특수 포인터로 유지 한다. <br>지금부터 리턴할 때까지 스택에 push되는 것을 이 함수의 “local”이라고 볼 수 있다.
5. 함수를 부를때 사용된 인자들을 스택에 push.
6. 함수 실행 시작
7. 함수 내부에 선언된 로컬변수들을 스택에 push

## 점근식 표기법

### Big O 표기법

- 정의 : 점근적 상한 (Asymptotic Upper Bound)

  - 주어진 복잡도 함수 `f(n)`에 대해서 `g(n) ∈ Θ(f(n))` 이면 다음을 만족한다.
    - n >= N인 모든 정수 n에 대해서 `g(n) <= c * f(n)`이 성립하는 실수 c > 0 (계수)와 음이 아닌 정수 N (입력의 크기)이 존재한다.
      - 부등식에 등호 (`=`)가 포함됨에 주목 ✩

- `g(n) ∈ Θ(f(n))` 읽는 방법:
  - `g(n)`은 `f(n)`의 Big O.

### Asymptotic Analysis

- **Big-picture** approach
- 실행시간이 “grows proportionally to `f(n)`” 한다는 사실만으로 충분
- 실제 실행 시간은 `c(constant factor) * f(n)` 이 됨
- 어떤 알고리즘의 worst-case가 `g(N) = 60N^2 + 5N + `이라면
  - `g(N) = Θ(N^2)` : `g(N)`의 growth rate는 `N^2`의 growth rate과 같다.

### 대표적인 복잡도 카테고리

#### Polynomial Time

- `Θ(1)` : constant complexity
  - 입력자료수에 무관
  - 해쉬
- `Θ(loglog n)`
- `Θ(log n)` : logarithmic complexity
  - divide & conquer
  - 이진검색
- `Θ(n)` : linear complexity
  - scan검색
- `Θ(n log n)`
  - 병합정렬, quick정렬...
- `Θ(n^k)` (k >= 1)
  - `Θ(n2)` : quadratic complexity
    - 이중 loop, 삽입정렬, 선택정렬...
  - `Θ(n3)` : cubic complexity
    - 삼중 loop, 행렬의 곱셈

#### Exponential Time

- `Θ(2n)` : exponential complexity
  - Knapsack problem, Fibonacci, Hanoi...

## 순환

## 순환 알고리즘과 점화식
