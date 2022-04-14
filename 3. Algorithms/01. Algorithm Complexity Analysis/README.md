# 알고리즘과 문제해결

- Contents
  - [알고리즘이란?](#알고리즘이란)
  - [점근식 표기법](#점근식-표기법)
  - [순환 (recursion)](#순환-recursion)
  - [Master Theorem](#master-theorem)

---

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

  - 주어진 복잡도 함수 `f(n)`에 대해서 `g(n) ∈ O(f(n))` 이면 다음을 만족한다.
    - n ≥ N인 모든 정수 n에 대해서 `g(n) ≤ c⋅f(n)`이 성립하는 실수 c > 0 (계수)와 음이 아닌 정수 N (입력의 크기)이 존재한다.
      - 부등식에 등호 (`=`)가 포함됨에 주목 ✩
  - <img width="334" alt="스크린샷 2022-04-14 오후 9 40 07" src="https://user-images.githubusercontent.com/73745836/163392372-9cac4a85-4223-4e78-9433-220bb94b5aab.png">

    - 위 그래프에서 ❶ `N`은 입력의 개수, ❷ `c`는 계수를 의미한다. ✩

- `g(n) ∈ O(f(n))` 읽는 방법:

  - `g(n)`은 `f(n)`의 Big O.

- 어떤 함수 `g(n)`이 `O(n²)`에 속한다는 말은

  - 그 함수 `g(n)`은 어떤 2차 함수 `cn²` 보다는 궁극적으로 **좋다**고 (기울기가 **낮다**고) 말할 수 있다.

- 어떤 알고리즘의 시간복잡도가 `O(f(n))`이라면

  - 입력의 크기 n에 대해서 이 알고리즘의 수행시간은 **아무리 늦어도** `f(n)`은 된다. (`f(n)`이 상한이다.)
  - 다시 말하면, 이 알고리즘의 수행시간은 `f(n)`보다 절대로 더 느릴 수는 없다는 말이다.
  - “최악의 경우 이 정도 시간이면 된다”

- Tight Upper Bound : 이 알고리즘은 어떠한 경우에도 이 상한을 넘지 않는다.
  - “길어야 `N` 시간이면 된다”가 사실이라면 당연히 “길어야 `N²` 시간이면 된다”라거나 “길어야 `N^3` 시간이면 된다”도 사실
  - 알고리즘의 특성을 표현하는 데는 tight upper bound를 사용해야 함.
  - Say “`2n` is `O(n)`” instead of “`2n` is `O(n²)`”
- Use the simplest expression of the class
  - Say “`3n + 5` is `O(n)`” instead of “`3n + 5` is `O(3n)`”

#### Big O 표기법 : 증명 ✩

1. 부등식을 세워라

- eg, `n²+10n ≤ c⋅n²`

2. 부등식을 만족하는 c, N을 pick!
3. Verify

##### 예시

- `n² + 10n` ∈ `O(n²)`
  - (1) n ≥ 10인 모든 정수 n에 대해서 `n² + 10n ≤ 2n²`이 성립한다. 그러므로, **c = 2 와 N = 10을 선택**하면, “Big O ”의 정의에 의해서 `n² + 10n ∈ O(n²)`이라고 결론 지을 수 있다.
  - (2) n ≥ 1인 모든 정수 n에 대해서 `n² + 10n ≤ n² + 10n² = 11n²`이 성립한다. 그러므로, **c = 11와 N = 1을 선택**하면, “Big O”의 정의에 의해서 `n² + 10n ∈ O(n²)` 이라고 결론 지을 수 있다.

### Asymptotic Analysis

- **Big-picture** approach
- 실행시간이 “grows proportionally to `f(n)`” 한다는 사실만으로 충분
- 실제 실행 시간은 `c(constant factor)⋅f(n)` 이 됨
- 어떤 알고리즘의 worst-case가 `g(N) = 60N² + 5N + `이라면
  - `g(N) = O(N²)` : `g(N)`의 growth rate는 `N²`의 growth rate과 같다.

### 대표적인 복잡도 카테고리

#### Polynomial Time

- `O(1)` : constant complexity
  - 입력자료수에 무관
  - 해쉬
- `O(loglog n)`
- `O(log n)` : logarithmic complexity
  - divide & conquer
  - 이진 검색
- `O(n)` : linear complexity
  - scan 검색
- `O(n log n)`
  - 병합 정렬, quick 정렬...
- `O(n^k)` (k ≥ 1)
  - `O(n2)` : quadratic complexity
    - 이중 loop, 삽입정렬, 선택정렬...
  - `O(n3)` : cubic complexity
    - 삼중 loop, 행렬의 곱셈

#### Exponential Time

- `O(2n)` : exponential complexity
  - Knapsack problem, Fibonacci, Hanoi...

### Ω 표기법

- 정의 : 점근적 하한 (Asymptotic Tight Lower Bound)

  - 주어진 복잡도 함수 `f(n)`에 대해서 `g(n) ∈ Ω(f(n)`이면 다음을 만족한다.
  - n ≥ N인 모든 정수 n에 대해서 `g(n) ≥ c⋅f(n)`이 성립하는 실수 c>0와 음이 아닌 정수 N이 존재한다.

- `g(n) ∈ Ω(f(n))` 읽는 방법:
  - `g(n)`은 `f(n)`의 오메가(omega)

<img width="334" alt="스크린샷 2022-04-14 오후 10 05 25" src="https://user-images.githubusercontent.com/73745836/163396716-7236fc0f-cca6-489c-a835-f82c3756f2ae.png">

- 어떤 알고리즘의 시간복잡도가 `Ω(f(n))`이라면,
  - 입력의 크기 n에 대해서 이 알고리즘의 수행시간은 아무리 빨라도 `f(n)`밖에 되지 않는다. (`f(n)`이 하한이다.)
  - “최소한 이만한 시간은 걸린다”
  - 모든 정렬 알고리즘은 `Ω(N)`. N개의 데이터를 정렬하는데 N개 모두를 읽지 않고 정렬을 완료할 수는 없기 때문. ✩

### Summary ✩

![IMG_5B36BB702193-1](https://user-images.githubusercontent.com/73745836/163398342-b7255be9-0006-4d7c-aad8-399b6c7553d5.jpeg)

- “The running time is `O(f(n))`” => Worst case is `O(f(n))`
- “Running time is `Ω(f(n))`” => Best case is `Ω(f(n))`

## 순환 (recursion)

- 정의하려는 그 개념 자체를 정의 속에 포함
- 종류
  - 직접 순환: 함수가 직접 자신을 호출
  - 간접 순환: 다른 제 3의 함수를 호출하고, 그 함수가 다시 자신을 호출

### 순환 함수의 예

- 이진 탐색
  - 정의 : 주어진 탐색키 key가 저장된 위치(인덱스) 찾아내는 방법
    - key = a[mid] : 탐색 성공, return mid
    - key < a[mid] : a[mid]의 왼편에 대해 탐색 시작
    - key > a[mid] : a[mid]의 오른편에 대해 탐색 시작
  - 순환 함수의 표현

```c
BinarySearch(a[], key, left, right)
    // a[mid] = key인 인덱스 mid를 반환
    if (left ≤ right) then {
        mid ← (left + right) / 2;
        case {
            key = a[mid] : return (mid);
            key < a[mid] : return (BinarySearch(a, key, left, mid-1));
            key > a[mid] : return (BinarySearch(a, key, mid+1, right));
        }
    }
    else return -1; // key 값이 존재하지 않음
end BinarySearch()
```

## Master Theorem

![CodeCogsEqn (1)](https://user-images.githubusercontent.com/73745836/163401823-2a37df87-f0fa-4b69-b3a1-56892faff249.svg)와 같은 모양을 가진 점화식은 마스터 정리에 의해 바로 분석할 수 있다

1. ![CodeCogsEqn (1)](https://user-images.githubusercontent.com/73745836/163401823-2a37df87-f0fa-4b69-b3a1-56892faff249.svg)
2. ![](https://latex.codecogs.com/svg.image?h_n&space;=&space;n^{log_b&space;a}&space;&space;)
3. ![](<https://latex.codecogs.com/svg.image?f(n)>)과 ![](<https://latex.codecogs.com/svg.image?h(n)>) 비교

- if ![](<https://latex.codecogs.com/svg.image?f(n)&space;<&space;h(n)>), then <img src="https://latex.codecogs.com/svg.image?\inline&space;O(f(n))&space;=&space;h(n)" title="https://latex.codecogs.com/svg.image?\inline O(f(n)) = h(n)" />
- if ![](<https://latex.codecogs.com/svg.image?f(n)&space;=&space;h(n)>), then <img src="https://latex.codecogs.com/svg.image?\inline&space;O(f(n))&space;=&space;h(n)&space;\cdot&space;\log&space;n" title="https://latex.codecogs.com/svg.image?\inline O(f(n)) = h(n) \cdot \log n" />
- if ![](<https://latex.codecogs.com/svg.image?f(n)&space;>&space;h(n)>), then <img src="https://latex.codecogs.com/svg.image?\inline&space;O(f(n))&space;=&space;f(n)" title="https://latex.codecogs.com/svg.image?\inline O(f(n)) = f(n)" />

### 제약 조건 ✩

1. ![](<https://latex.codecogs.com/svg.image?f(n)>)은 asymptotically positive function (양의 함수) 이어야 한다.
2. <img src="https://latex.codecogs.com/svg.image?\inline&space;a&space;\geq&space;1" title="https://latex.codecogs.com/svg.image?\inline a \geq 1" /> and <img src="https://latex.codecogs.com/svg.image?\inline&space;b&space;>&space;1"/> 이어야 한다.
3. the regularity condition that <img src="https://latex.codecogs.com/svg.image?\inline&space;af(\frac{n}{b})&space;\leq&space;cf(n)" title="https://latex.codecogs.com/svg.image?\inline af(\frac{n}{b}) \leq cf(n)" /> for some constant <img src="https://latex.codecogs.com/svg.image?\inline&space;c&space;<&space;1"/>

- <img src="https://latex.codecogs.com/svg.image?\inline&space;f(n)" title="https://latex.codecogs.com/svg.image?\inline f(n)" />이 지수함수, cos 함수, sin 함수 등이 되어서는 안 됨

4. <img src="https://latex.codecogs.com/svg.image?\inline&space;\bg{white}T(n)&space;=&space;aT(\frac{n}{b})&space;&plus;&space;n^k&space;\log&space;^p&space;(n)" title="https://latex.codecogs.com/svg.image?\inline \bg{white}T(n) = aT(\frac{n}{b}) + n^k \log ^p (n)" />의 형태일 때는 Adavanced Master Theorem을 적용해야 함

- where <img src="https://latex.codecogs.com/svg.image?\inline&space;\bg{white}a&space;\geq&space;1"/>, <img src="https://latex.codecogs.com/svg.image?\inline&space;\bg{white}b&space;>&space;1"/>, <img src="https://latex.codecogs.com/svg.image?\inline&space;\bg{white}k&space;\geq&space;&space;1"/> and <img src="https://latex.codecogs.com/svg.image?\inline&space;\bg{white}p" title="https://latex.codecogs.com/svg.image?\inline \bg{white}p" /> is a real number
- ![IMG_2141375D9C4F-1](https://user-images.githubusercontent.com/73745836/163408705-fa6a2e11-12de-4df9-a1d1-0ea6f7af7cef.jpeg)
