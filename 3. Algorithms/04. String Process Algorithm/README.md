# String Process Algorithm

## Contents

- [스트링 탐색 알고리즘](#스트링-탐색-알고리즘)
  - [직선적 알고리즘](#직선적-알고리즘)
  - [KMP 알고리즘](#kmp-알고리즘)
  - [보이어-무어 알고리즘](#보이어-무어-알고리즘)
  - [라빈-카프 알고리즘](#라빈-카프-알고리즘)
- [패턴 매칭 알고리즘](#패턴-매칭-알고리즘)
- [화일 압축 알고리즘](#화일-압축-알고리즘)
  - [런-길이 인코딩](#런-길이-인코딩)
  - [가변-길이 인코딩](#가변-길이-인코딩)
- [암호화 알고리즘](#암호화-알고리즘)
  - [단순한 기법](#단순한-기법)
  - [공개 키 암호화 시스템](#공개-키-암호화-시스템)

---

## 스트링 탐색 알고리즘

- 문서 작성 시

  - 텍스트(text) : 문서
  - 패턴(pattern) : 탐색할 스트링
  - 스트링(string)
    - 문자가 연속적으로 나열된 것
    - 텍스트(text) 스트링
    - 이진(binary) 스트링

- 스트링 탐색 알고리즘의 설계 목적
  - 필연적으로 잘못된 시작(false start) 발생
    - (불일치가 발생한 위치까지 비교한 0개 이상의 문자를 의미)
  - 잘못된 시작의 횟수와 길이를 줄이는 것

### 직선적 알고리즘

aka. 무작정 무지성 알고리즘

- 한 글자 또는 한 비트씩 오른쪽으로 진행
- 텍스트의 처음부터 끝까지 모두 비교하며 탐색하는 알고리즘

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

#### 재시작 위치 알고리즘

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

#### KMP 알고리즘

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

  <img width="484" alt="스크린샷 2022-04-19 - ᅩ전 11 02 35" src="https://user-images.githubusercontent.com/73745836/163907383-bf841d64-402c-4b28-9bba-4ef699859297.png">

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

#### 불일치 문자 방책 알고리즘

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

<img width="599" alt="스크린샷 2022-04-19 오전 11 32 52" src="https://user-images.githubusercontent.com/73745836/163909688-600eb6e4-2b7b-4ca3-82c4-7af76fb22d18.png">

### 라빈-카프 알고리즘

## 패턴 매칭 알고리즘

## 화일 압축 알고리즘

### 런-길이 인코딩

### 가변-길이 인코딩

## 암호화 알고리즘

### 단순한 기법

### 공개 키 암호화 시스템
