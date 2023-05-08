# String Process Algorithm

## Contents

- [스트링 탐색 알고리즘](#스트링-탐색-알고리즘)
  - [직선적 알고리즘](#직선적-알고리즘)
  - [KMP 알고리즘](#kmp-알고리즘)
  - [보이어-무어 알고리즘](#보이어-무어-알고리즘)
  - [라빈-카프 알고리즘](#라빈-카프-알고리즘)
  - [Levenshtein Distance 편집거리 알고리즘](../05.%20Dynamic%20Programming/README.md/#스트링-편집거리-levenshtein-distance)
- [패턴 매칭 알고리즘](#패턴-매칭-알고리즘)
- [파일 압축 알고리즘](#파일-압축-알고리즘)
  - [허프만 인코딩](#허프만-인코딩-huffman-encoding)
- [암호화 알고리즘](#암호화-알고리즘)
  - [공개 키 암호화 시스템](#공개-키-암호화-시스템)
    - [RSA 알고리즘](#rsarivest-shamir-adleman-알고리즘)

---

## 스트링 탐색 알고리즘

- 문서 작성 시
  - 텍스트(text) : 문서
  - 패턴(pattern) : 탐색할 스트링
  - 스트링(string)
    - 문자가 연속적으로 나열된 것
    - 텍스트(text) 스트링
    - 이진(binary) 스트링

<br>

- 스트링 탐색 알고리즘의 설계 목적
  - 필연적으로 잘못된 시작(false start) 발생
    - (불일치가 발생한 위치까지 비교한 0개 이상의 문자를 의미)
  - 잘못된 시작의 횟수와 길이를 줄이는 것

### 직선적 알고리즘

aka. 무작정 무지성 알고리즘

- 한 글자 또는 한 비트씩 오른쪽으로 진행
- 텍스트의 처음부터 끝까지 모두 비교하며 탐색하는 알고리즘

#### Pseudo Code

```cpp
BruteForce(p[], t[]) // 단순한 algo지만 직접 구현하면 어려울 수 있다.
    M ← 패턴의 길이; N ← 텍스트의 길이;
        for (i ← 0, j ← 0; j < M and i < N; i ← i + 1, j ← j + 1) do {
            if (t[i] ≠ p[j]) then {
                i ← i - j; // i가 1칸 이동
                j ← -1;
            }
        }
    if (j = M) then return i - M;
    else return i;
end ButeForce()
```

#### 시간복잡도

최악의 경우 시간 복잡도는 텍스트의 모든 위치에서 패턴을 비교해야 하므로 `O(MN)`이 됨

### KMP 알고리즘

- KMP : Knuth, Morris and Pratt
- 불일치가 발생했을 경우 텍스트 스트링의 앞 부분에 어떤 문자가 있는지를 미리 알고 있다면, 불일치가 발생한 앞 부분에 대해서는 다시 비교하지 않고 매칭을 수행할 수 있음
- 패턴을 전처리하여 배열 `next[M]`을 구해서 잘못된 시작을 최소화함
  - `next[M]` : 불일치가 발생했을 경우 이동할 다음 위치
    - 얼마만큼 점프할지 점프의 위츠를 `next` 배열에 저장
  - `p[0~i]`의 접미사와 일치한 최장 접두사의 끝자리 위치
    - 단, 최장접두사 != 전체문자열

#### 시간 복잡도

`O(M+N)`

#### Pseudo Code: 재시작 위치 알고리즘

```cpp
InitNext(p[])
    M ← 패턴의 길이;
    next[0] ← -1;
    for (i ← 0, j ← -1; i < M; i ← i + 1, j ← j + 1) do
    {
        next[i] ← j;
        while ((j ≥ 0) and (p[i] ≠ p[j])) do
            j ← next[j];
    }
end InitNext()
```

- `next[]`의 의미
  - `next[i]`는 주어진 문자열의 0~(i-1)까지의 부분 문자열 중에서 prefix == suffix가 될 수 있는 부분 문자열 중에서 가장 긴 것의 길이

#### Pseudo Code: KMP 알고리즘

```cpp
KMP(p[], t[])
    M ← 패턴의 길이; N ← 텍스트의 길이;
    InitNext(p);
    for(i←0,j←0; j <M and i<N; i←i+1,j←j+1) do
        while ((j ≥ 0) and (t[i] ≠ p[j])) do
            j ← next[j];
    if (j = M) then return i - M;
    else return i;
end KMP()
```

#### 패턴이 내장된 KMP 알고리즘

- KMP 알고리즘을 위한 유한 상태 장치
  - 유한 상태 장치 (finite state machine: FSM)
    - 상태(state; 원으로 표시)
    - 전이(transition; 선으로 표시)
      - 일치 전이(match transition; 실선으로 표시) - 오른쪽으로 이동
      - 불일치 전이(non-match transition; 점선으로 표시) - 왼쪽으로 이동
    - 시작점 (왼쪽 끝의 사각형)
    - 종료점 (오른쪽 끝의 사각형)

<img width="484" src="https://user-images.githubusercontent.com/73745836/163907383-bf841d64-402c-4b28-9bba-4ef699859297.png">

- 개선된 유한 상태 장치
  - `InitNext` 알고리즘의 `next[i] ← j;` 변경

```cpp
if (p[i] == p[j]) then next[i] ← next[j];
else next[i] ← j
```

<img width="526" alt="스크린샷 2022-0-19 - ᅩ전 11 24 32" src="https://user-images.githubusercontent.com/73745836/163907674-126b68a7-3e41-437a-87d4-f355735846c4.png">

### 보이어-무어 알고리즘

- 오른쪽에서 왼쪽으로 스트링 탐색을 진행
- 불일치 문자 방책(mismatched character heuristic) 사용
  - 텍스트에 있는 불일치가 발생한 문자가 패턴의 문자가 일치하도록 패턴을 오른쪽으로 이동
- 일치 접미부 방책(good suffix heuristic) 사용
  - 패턴에서 불일치가 발생한 문자의 오른쪽에 있는 최대 접미부가 일치하도록 패턴을 오른쪽을 이동하는 것
- 두 방법 중 패턴을 우측으로 이동하는 거리가 더 긴 것을 선택
- 최선의 경우 시간 복잡도 : `O (m + n /m + |Σ|)`
  - 알파벳이 큰 경우 `O(m+n/m+|Σ|)` 시간에 수행될 가능성이 매우 높음

#### 불일치 문자 방책과 일치 접미부 방책

<img width="526" alt="스크린샷 2022-04-19 오전 11 26 39" src="https://user-images.githubusercontent.com/73745836/163907926-767343c4-b476-4da8-9f65-67100c69ecd0.png">

#### Pseudo Code: 불일치 문자 방책 알고리즘

```cpp
void InitSkip(char *p) {
    int i, M = strlen(p);
    for (i = 0; i < NUM; i++) skip[i] = M;
    for (i = 0; i < M; i++) skip[index(p[i])] = M - i - 1;
}
```

```cpp
MisChar(p[], t[])
    M ← 패턴의 길이; N ← 텍스트의 길이;
    InitSkip(p);
    for (i ← M-1, j ← M-1; j ≥ 0; i ← i - 1, j ← j - 1) do
        while (t[i] ≠ p[j]) do {
            k ← skip[index(t[i])];
            if (M-j > k) then i ← i + M - j;  // M-j = 5-1 = 4
            else i ← i + k;                   // k = 0
            if (i ≥ N ) then return N;
            j ← M - 1;
        }
    return i+1;
end MisChar()
```

<img width="599" src="https://user-images.githubusercontent.com/73745836/163909688-600eb6e4-2b7b-4ca3-82c4-7af76fb22d18.png">

### 라빈-카프 알고리즘

- 스트링을 숫자값으로 바꾼 다음 **해시** 값을 계산하여 매칭하는 알고리즘
- 최악의 시간 복잡도는 `O(MN)`이지만 평균적으로는 선형에 가까운 빠른 속도를 가지는 알고리즘

### Levenshtein Distance 편집거리 알고리즘

[링크 참고](../05.%20Dynamic%20Programming/README.md/#스트링-편집거리-levenshtein-distance)

## 패턴 매칭 알고리즘

### 패턴 매칭 (pattern matching)

- 텍스트 스트링에서 원하는 문자 패턴을 찾아 내는 것
- 패턴 기술
  - 1. 접합 (concatenation)
    - 패턴에서 인접해 있는 두 문자가 텍스트에서 나타나면 매치
  - 2. 논리합 (or)
    - 두 개의 문자 중 하나가 텍스트에 나타나면 매치
  - 3. 폐포 (closure)
    - 특정한 문자가 0개 이상 나타나면 매치

![IMG_AB632FFAE60A-1](https://user-images.githubusercontent.com/73745836/171319390-55c0b77f-7e32-4936-bebf-da8b1ba2ef7d.jpeg)

### 정규식 (regular expression)

- 특정한 규칙을 가진 문자열의 집합을 표현하는데 사용하는 형식 언어
- 세 가지 기본 연산들로 이루어진 심볼들의 스트링
  - 심볼 (symbol)
    - `*` : 괄호 안에 있는 문자들이 **0번 이상** 나타남
    - `?` : 어떤 문자와도 매치됨
    - `+` : 또는 (or) 연산
- 예
  - `?*(ie+ei)?*` : `ie` 또는 `ei`를 가지고 있는 모든 단어
  - `(1+01)*(0+1)` : 연속적으로 두 개의 `0`이 나오지 않는 `0`과 `1`로 이루어진 모든 스트링

### 패턴 매칭 장치 (pattern matching machine)

- 패턴 매칭에 사용되는 장치 패턴
- 결정적(deterministic) 장치
  - 각각의 상태 전이가 다음 입력 문자에 의해 완전하게 결정되는 것
  - 예 : [KMP 알고리즘을 위한 유한 상태 장치](#패턴이-내장된-kmp-알고리즘)
- 비결정적(nondeterministic) 장치
  - 패턴을 매치하기 위해 하나 이상의 방법이 있을 경우, 장치가 올바른 것을 찾아 나가는 것
  - 텍스트 스트링에서, `(A*B+AC)D`와 같은 정규식을 찾는 경우 사용되며, 유일한 시작 상태와 종료 상태를 가진다.

#### 패턴 매칭 장치 구현

- 장치를 구현하는데 가장 적합한 자료구조 : **Deque[데크]** (Double-Ended Queue)
  - 스택과 큐의 특징을 조합
  - 양방향에서 항목을 추가하는 것이 가능
  - 입력은 양방향에서 가능
  - 삭제는 데크의 처음에서만 가능한 '출력-제한 데크 (output-restricted deque)' 사용
  - <img src="https://user-images.githubusercontent.com/73745836/171321018-3a604596-b32f-447a-8441-fa7e3243dfad.jpeg" width = 30%/>

#### 동작 과정

- 개요
  - 1. 문자가 매치됨 → 새로운 상태를 데크의 끝에 삽입 (`insertLast`)
  - 2. 상태가 비어 있음 → 두 개의 가능한 상태를 데크의 처음에 삽입 (`insertionFirst`)
  - 3. `scan`을 만남 → 입력 스트링에 대한 포인터를 다음 문자로 이동
- 종료 조건
  - 입력의 끝까지 갔을 때 (매치되지 않음)
  - 상태 0을 만남 (매치됨)
  - 데크에 `scan` 마크 하나만 남음 (매치되지 않음)

<img src="https://user-images.githubusercontent.com/73745836/171323280-63ef8485-dd51-483a-8c14-61671bfe78d8.jpeg" width = 60%/>

## 파일 압축 알고리즘

### 허프만 인코딩 (Huffman encoding)

with Priority Queue

![](https://postfiles.pstatic.net/MjAxODExMTlfNzUg/MDAxNTQyNjEzMjYxNTE4.WakY5a4l6QM1nxY7Ug6BzTJklxP62-PMhOKoZn-_JQEg.EKLAThhp4wXjo2qjr4Zd1x7fB09nVFrycwyz0q9X5mkg.PNG.stizms/%ED%97%88%ED%94%84%EB%A7%8C_%ED%8A%B8%EB%A6%AC.png?type=w966)

#### 알고리즘

1. 모든 노드를 PQ에 `insert`한다.
2. freq가 가장 작은 두 노드를 PQ에서 빼온다.
3. 그 두 노드를 하나의 노드로 묶는다.
4. 하나로 묶은 노드를 다시 PQ에 넣는다.
5. 2번 ~ 4번의 과정을 계속 반복한다.

## 암호화 알고리즘

### 공개 키 암호화 시스템

#### RSA(Rivest-Shamir-Adleman) 알고리즘

- 1. 서로 다른 두 개의 큰 **소수** `p`, `q` 선택 (100자리)
  - `p*q → r`
- 2. 하나의 큰 숫자 `e` 선택 (**공개 암호화 키**)
  - `p-1`, `q-1`과 각각 **서로소**이어야 함
  - `p`, `q`보다 **큰** 어떤 **소수**이어햐 함
- 3. **비밀 해독키** `d` 계산
  - `(e*d) % {(p-1)*(q-1)} == 1`을 만족하는 `d` 찾기
  - 표기법 : `d*e = 1 modulo (p-1)*(q-1)`
    - `mod` 연산에 대한 표기법 [참고](https://codingram.tistory.com/26)
- 4. 정수 `r`과 `e`는 **공개**하고, `d`는 **비밀**로 유지
- 5. 평문 `P`로부터 암호문 `C = P^e modulo r` 계산
- 6. 암호문 `C`로부터 평문 `P = C^d modulo r` 계산

```python
>>> p = 3
>>> q = 5
>>> r = p*q
>>> r
15
>>> (p-1)*(q-1)
8
>>>
>>> # let e be 11 (prime greater than both p, q)
>>> e = 11
>>>
>>> # find d
>>> # d*e = 1 modulo (p-1)*(q-1)
>>> # d*11 = 1 modulo 8
>>> # so, d = 3
>>> d = 3
>>>
>>> ## Encryption ###
>>> # let P = 13 (Plain text)
>>> P = 13
>>> # C = P^e modulo r
>>> # C = P**e % r
>>> # C = 13*11 % 15
>>> C = P**e % r
>>> C
7
>>>
>>> ### Decryption ###
>>> # P = C^d modulo r
>>> # P = C**d % r
>>> # P = 7**3 % 15
>>> P = C**d % r
>>> P
13
```

#### 발송인 S가 수신인 R에게 메시지 P 전송

발송인 S : <br>
<img src="https://latex.codecogs.com/svg.image?E_R\left&space;(&space;D_S\left&space;(&space;P&space;\right&space;)&space;\right&space;)&space;=&space;C" title="https://latex.codecogs.com/svg.image?E_R\left ( D_S\left ( P \right ) \right ) = C" />

수신인 R : <br>
<img src="https://latex.codecogs.com/svg.image?\begin{align*}&space;E_S\left&space;(&space;D_R\left&space;(&space;C&space;\right&space;)&space;\right&space;)&space;&=&space;E_S\left&space;(&space;D_R\left&space;(E_R\left&space;(&space;D_S\left&space;(&space;P&space;\right&space;)&space;\right&space;)\right&space;)&space;\right&space;)&space;\\&space;&=&space;E_S\left&space;(&space;D_S\left&space;(&space;P&space;\right&space;)&space;\right&space;)&space;\\&space;&=&space;P\end{align*}" title="https://latex.codecogs.com/svg.image?\begin{align*} E_S\left ( D_R\left ( C \right ) \right ) &= E_S\left ( D_R\left (E_R\left ( D_S\left ( P \right ) \right )\right ) \right ) \\ &= E_S\left ( D_S\left ( P \right ) \right ) \\ &= P\end{align*}" />

> S가 메시지 P를 전송하였다는 것을 확인할 수 있음!
