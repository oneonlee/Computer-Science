# Sorting

- Soting Algorithm Properties
  - Complexity
  - In-place
  - Stable

## Contents

1. [Bubble Sort](#bubble-sort) <img src="https://latex.codecogs.com/svg.image?O(n^2)" title="https://latex.codecogs.com/svg.image?O(n^2)" />
2. [Insertion Sort](#insertion-sort) <img src="https://latex.codecogs.com/svg.image?O(n^2)" title="https://latex.codecogs.com/svg.image?O(n^2)" />
3. [Selection Sort](#selection-sort) <img src="https://latex.codecogs.com/svg.image?O(n^2)" title="https://latex.codecogs.com/svg.image?O(n^2)" />
4. [Merge Sort](#merge-sort) <img src="https://latex.codecogs.com/svg.image?O(nlogn)" title="https://latex.codecogs.com/svg.image?O(nlogn)" />
5. [Quick Sort](#quick-sort) <img src="https://latex.codecogs.com/svg.image?O(nlogn)" title="https://latex.codecogs.com/svg.image?O(nlogn)" />
6. [Shell Sort](#shell-sort)
7. [Heap Sort](#heap-sort) <img src="https://latex.codecogs.com/svg.image?O(nlogn)" title="https://latex.codecogs.com/svg.image?O(nlogn)" />
8. [Counting Sort](#counting-sort)
9. [Radix Sort](#radix-sort) <img src="https://latex.codecogs.com/svg.image?O(cn)" title="https://latex.codecogs.com/svg.image?O(cn)" />

<br>
백문이 불여일견.<br>

도움이 되는 사이트 : [visualgo.net](https://visualgo.net/en/sorting)

| Algorithm      |                                               Time                                                | Stable    | In-place  |                                                                                   Notes |
| -------------- | :-----------------------------------------------------------------------------------------------: | --------- | --------- | --------------------------------------------------------------------------------------: |
| Bubble Sort    |                     <img src="https://latex.codecogs.com/svg.image?O(n^2)" />                     | Yes       | Yes       |                                  - Slow (good for small inputs)<br> - Easy to implement |
| Insertion Sort |                     <img src="https://latex.codecogs.com/svg.image?O(n^2)" />                     | Yes       | Yes       |                                  - Slow (good for small inputs)<br> - Easy to implement |
| Selection Sort |                     <img src="https://latex.codecogs.com/svg.image?O(n^2)" />                     | No        | Yes       |        - Slow (good for small inputs)<br> - Easy to implement<br> - Un-stable algorithm |
| Merge Sort     | <img src="https://latex.codecogs.com/svg.image?\inline&space;\bg{black}O(n&space;\log&space;n)"/> | Yes       | No        | - Fast (good for huge inputs)<br> - Sequential data access<br> - Not in-place algorithm |
| Quick Sort     | <img src="https://latex.codecogs.com/svg.image?\inline&space;\bg{black}O(n&space;\log&space;n)"/> | No or Yes | Yes or No |                            - Fastest (good for large inputs)<br> - In-place, randomized |

## Bubble Sort

Bubble Sort는 "Exchange Sort" 라고도 부른다.

```cpp
void exchangesort (int n, keytype S[]) {
    index i, j;
    for (i = 1; i <= n-1; i++)
        for (j = i+1; j <= n; j++)
            if (S[j] < S[i])
                exchange S[i] and S[j];
}
```

- 내림차순을 오름차순으로 바꾸려면 5번 줄의 `if (S[j] < S[i])`의 부등호 방향을 반대로 바꾸면 된다.
- 5번 줄의 `if (S[j] < S[i])`에서 `S[j]`와 `S[i]`는 <img src="https://latex.codecogs.com/svg.image?n^2" /> 번 비교된다.
- 6번 줄의 `exchange` 연산은 아래의 3단계 연산을 거친다.

```cpp
temp = a;
a = b;
b = temp;
```

### Time Complexity

<img width="200" alt="스크린샷 2022-04-15 ᅩ후 9 31 41" src="https://user-images.githubusercontent.com/73745836/163571114-a8acd60b-9b85-40e4-b84b-63d04c974f7e.png">

그러므로 Time Complexity는
<img src="https://latex.codecogs.com/svg.image?O(n^2)" title="https://latex.codecogs.com/svg.image?O(n^2)" /> 이다.

## Insertion Sort

```cpp
void insertionsort(int n, keytype S[])
{
    index i, j;
    keytype x;

    for (i = 2; i < n; i++) {
        x = S[i];
        j = i - 1;
        while (j > 0 && S[j] > x) {
            S[j+1] = S[j];
            j--;
        }
        S[j+1] = x;
    }
}
```

- 6번 줄의 `for (i = 2; i < n; i++)`에서 `i`가 2부터 시작하는 이유는 `i`가 1일 때가 초기값이기 때문이다.
  - 하나만 비교했을 때는 그 하나가 당연히 정렬된 상태임
- 9번 줄의 `while (j > 0 && S[j] > x)`에서 `S[j]`과 `x`는 <img src="https://latex.codecogs.com/svg.image?n^2" /> 번 비교된다.
- 마찬가지로, 10번 줄 (`S[j+1] = S[j];`)은 <img src="https://latex.codecogs.com/svg.image?n^2" /> 번 할당된다.

### Time Complexity

#### Worst Case

주어진 `i`에 대해 `i-1`번의 비교가 이루어진다.

<img width="200" alt="스크린샷 2022-04-15 ᅩ후 9 56 13" src="https://user-images.githubusercontent.com/73745836/163573320-56eff03b-415c-4f71-aa64-93ee9b9db601.png">

그러므로 Time Complexity는
<img src="https://latex.codecogs.com/svg.image?O(n^2)" title="https://latex.codecogs.com/svg.image?O(n^2)" /> 이다.

#### Average Case

주어진 `i`에 대해, `x`가 삽입될 수 있는 장소는 `i`곳이 있다.

 <img width="609" alt="스크린샷 2022-04-15 ᅩ후 9 59 10" src="https://user-images.githubusercontent.com/73745836/163573576-41157c69-75e3-4748-973e-43a30580aa28.png">

따라서 평균 비교 횟수는
<img src="https://latex.codecogs.com/svg.image?\inline&space;\Theta(n^2)&space;" title="\Theta(n^2) " /> 이다.

<img width="663" alt="스크린샷 2022-04-15 ᅩ후 10 01 07" src="https://user-images.githubusercontent.com/73745836/163573757-da374e92-3c01-4624-b2d5-205d5f51f7eb.png">

## Selection Sort

```cpp
void selectionsort(int n, keytype S[])
{
    index i, j, smallest;

    for (i = 0; i < n-1;  i++) {
        smallest = i;
        for (j = i+1; j <= n; j++)
            if (S[j] < S[smallest])
                smallest = j;
        exchange S[i] and S[smallest];
    }
}
```

- 7번 줄의 `for (j = i+1; j <= n; j++)`에서 `j`와 `n`은 <img src="https://latex.codecogs.com/svg.image?n^2" /> 번 비교된다.
- 10번 줄의 `exchange S[i] and S[smallest];`에서는 할당이 <img src="https://latex.codecogs.com/svg.image?3n" /> 번 이루어진다.

### Worst Case

<img src="https://latex.codecogs.com/svg.image?O(n^2)" title="https://latex.codecogs.com/svg.image?O(n^2)" />

### n^2 정렬 알고리즘 비교

| 알고리즘       | 비교횟수                                                                                                                                                                                                                                  | 지정횟수                                                                                                                                                                                                                                      | 추가저장소 사용량 |
| -------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------- |
| Bubble Sort    | <img src="https://latex.codecogs.com/svg.image?\inline&space;T(n)&space;=&space;n^2/2" title="T(n) = n^2/2" />                                                                                                                            | <img src="https://latex.codecogs.com/svg.image?\inline&space;W(n)&space;=&space;3n^2/2&space;" title="W(n) = 3n^2/2 " /> <br><img src="https://latex.codecogs.com/svg.image?\inline&space;A(n)&space;=&space;3n^2/4" title="A(n) = 3n^2/4" /> | 제자리정렬        |
| Insertion Sort | <img src="https://latex.codecogs.com/svg.image?\inline&space;W(n)&space;=&space;n^2/2&space;" title="W(n) = n^2/2 " /> <br><img src="https://latex.codecogs.com/svg.image?\inline&space;A(n)&space;=&space;n^2/4" title="A(n) = n^2/4" /> | <img src="https://latex.codecogs.com/svg.image?\inline&space;W(n)&space;=&space;n^2/2&space;" title="W(n) = n^2/2 " /> <br><img src="https://latex.codecogs.com/svg.image?\inline&space;A(n)&space;=&space;n^2/4" title="A(n) = n^2/4" />     | 제자리정렬        |
| Selection Sort | <img src="https://latex.codecogs.com/svg.image?\inline&space;T(n)&space;=&space;n^2/2" title="T(n) = n^2/2" />                                                                                                                            | <img src="https://latex.codecogs.com/svg.image?\inline&space;T(n)&space;=&space;3n" title="T(n) = 3n" />                                                                                                                                      | 제자리정렬        |

- 삽입정렬은 버블정렬 보다는 항상 최소한 빠르게 수행된다고 할 수 있다.
- 선택정렬이 버블정렬 보다 빠른가?

  - 일반적으로는 선택정렬 알고리즘이 빠르다고 할 수 있다.
  - 그러나 입력이 이미 정렬되어 있는 경우, 선택정렬은 지정이 이루어지지만 버블정렬은 지정이 이루어지지 않으므로 버블정렬이 빠르다.

- 선택정렬 알고리즘이 삽입정렬 알고리즘 보다 빠른가?
  - n의 크기가 크고,키의 크기가 큰 자료구조 일 때는 지정하는 시간이 많이 걸리므로 선택정렬 알고리즘이 더 빠르다.

## Merge Sort

![ezgif com-gif-maker](https://user-images.githubusercontent.com/73745836/146045844-e9a5097e-402c-41ca-92e1-5457b0ebf118.gif)

```cpp
void mergesort (int n, keytype S[]) {
    const int h = n / 2, m = n - h;
    keytype U[1..h], V[1..m];

    if (n > 1) {
        copy S[1] through S[h] to U[1] through U[h];
        copy S[h+1] through S[n] to V[1] through V[m];
        mergesort(h,U);
        mergesort(m,V);
        merge(h,m,U,V,S);
    }
}
```

```cpp
void merge (int h, int m, const keytype U[], const keytype V[], const keytype S[])
{
    index i, j, k;
    i = 1; j = 1; k = 1;
    while (i <= h && j <= m) {
        if (U[i] < V[j]) {
            S[k] = U[i];
            i++;
        } else {
            S[k] = V[j];
            j++;
        }
        k++;
    }
    if (i > h)
        copy V[j] through V[m] to S[k] through S[h+m];
    else
        copy U[i] through U[h] to S[k] through S[h+m];
}
```

- Analysis of Merge-Sort
  - The height `h` of the merge-sort tree is `O(log n)`
    - at each recursive call we divide in half the sequence,
  - The overall amount or work done at the nodes of depth `i` is `O(n)`
    - we partition and merge `2^i` sequences of size `n/2^i`
    - we make 2^(i+1)` recursive calls
  - Thus, the total running time of merge-sort is `O(n log n)`

### 공간복잡도 분석

- in-place sort 알고리즘 (제자리정렬 알고리즘)
  - 입력을 저장하는데 필요한 만큼 저장장소를 사용하지 않고 정렬하는 알고리즘
  - mergesort 알고리즘은 in-place sort 알고리즘이 아니다.
    - 왜냐하면 입력인 배열 S 이외에 U와 V를 추가로 만들어서 사용하기 때문이다.
- 그러면 얼마만큼의 추가적인 저장장소가 필요할까? - mergesort를 재귀호출할 때마다 크기가 S의 반이 되는 U와 V가 추가적으로 필요하다. - merge 알고리즘에서는 U와 V가 주소로 전달이 되어 그냥 사용되므로 추가적인 저장장소를 만들지 않는다. 따라서 mergesort를 재귀호출할 때마다 얼마만큼의 추가적인 저장장소가 만들어져야 하는지를 계산해 보면 된다. - 처음 S의 크기가 n이면 추가적으로 필요한 U와 V의 저장장소 크기의 합은 n이 된다. 다음 재귀호출에는 n의 추가
  적으로 필요한 총 저장장소의 크기는 <img src="https://latex.codecogs.com/svg.image?\inline&space;\bg{white}n&space;&plus;&space;\frac{n}{2}&space;&plus;&space;\frac{n}{4}&space;&plus;&space;\cdots&space;&space;=&space;2n" title="n + \frac{n}{2} + \frac{n}{4} + \cdots = 2n" /> 이다. - 결론적으로 이 알고리즘의 공간복잡도는 <img src="https://latex.codecogs.com/svg.image?\inline&space;\bg{black}2n\in&space;\Theta&space;(n)" title="2n\in \Theta (n)" />이라고 할 수 있다.
- 추가적으로 필요한 저장장소가 n이 되도록, 즉, 공간복잡도가 n이 되도록 알고리즘을 향상시킬 수 있다 (HOW?). 그러나 합병정렬 알고리즘이 제자리정렬 알고리즘이 될 수는 없다.

## Quick Sort

- 빠른 정렬(Quicksort)이란 이름이 오해의 여지가 있다. 왜냐하면 사실 절대적으로 가장 빠른 정렬 알고리즘이라고 할 수는 없기 때문이다. 차라리 “분할교환정렬(partition exchange sort)”라고 부르는 게 더 정확하다.

<img width="248" alt="스크린샷 2022-04-16 -ᅩ후 8 35 39" src="https://user-images.githubusercontent.com/73745836/163673547-0c100a92-c88c-4159-9657-f7783ee7fbd9.png">

- Quick-sort는 divide-and-conquer paradigm을 기반으로 하는 randomized sorting algorithm이다.
  - Divide: pick a random element x (called pivot) and partition S into
    - L elements less than x
    - E elements equal x
    - G elements greater than x
  - Recur: sort L and G
  - Conquer: join L, E and G

```cpp
Algorithm inPlaceQuickSort(S, a, b)
    if a >= b then return
    p = S.elemAtRank(b) // pivotting
    l = a
    r = b-1
    while (l <= r) // partioning
    {
        while (l <= r and S.elemAtRank(l) <= p)
            l++;
        while (l <= r and S.elemAtRank(r) >= p)
            r--;
        if (l < r)
            S.swap(S.atRank(l), S.atRank(r));
    }
    S.swap(S.atRank(l), S.atRank(b));
    inPlaceQuickSort(S, a, l-1)
    inPlaceQuickSort(S, l+1, b)
```

### Worst-case Running Time

- The worst case for quick-sort occurs when the pivot is the unique minimum or maximum element
- One of `L` and `G` has size `n - 1` and the other has size 0
- The running time is proportional to the sum `n + (n - 1) + ... + 2 + 1`
- Thus, the worst-case running time of quick-sort is `O(n^2)`
  - Best-case is `O(n log n)`

### Expected Running Time

- The expected height of the quick-sort tree is `O(log n)`
- The amount or work done at the nodes of the same depth is `O(n)`
- Thus, the expected running time of quick-sort is `O(n log n)`

### 성능 향상 방법

1. 스택을 사용하여 순환을 제거
2. 작은 부분파일의 경우 삽입 정렬 사용
3. 중간값 분할 (Median-of-Three Partioning)

#### 1. 순환 제거

```cpp
void QuickSort(int a[], int l, int r)
{
    int i, j, v;
    for (;;) {
        while (r > l) {
            i = partition(a, l, r);
            if (i-l > r-i) {
                push(&top, l); push(&top, i-1); l = i+1;
            } else {
                push(&top, i+1); push(&top, r); r = i-1;
            }
        }
        if (top < 0) break;
        r = pop(&top);
        l = pop(&top);
    }
}
```

#### 삽입 정렬 사용

- `if (r>l)`을 `if (r-l <= M) { InsertionSort(a, l, r) }`로
  - M 값으로 5 ~ 25 사용

```cpp
void QuickSort(int a[], int l, int r)
{
    int i, j, v;
    if (r-l <= M) // 파티션의 크기가 M보다 작으면
        InsertionSort(a, l, r); // 그냥 n^2을 쓰자
    else {
        // 여기서부터
        v = a[r]; i = l-1; j = r;
        for ( ; ; ) {
            while (a[++i] < v);
            while (a[--j] > v);
            if (i >= j) break;
            swap(a, i, j);
        }
        swap(a, i, r);
        // 여기까지는 동일하다.
        QuickSort(a, l, i-1);
        QuickSort(a, i+1, r);
    }
}
```

- 많은 응용에서 약 20% 정도의 시간 절감 효과가 있음

#### 중간값 분할

- 분할 원소를 선택할 때 왼쪽, 가운데, 오른쪽 원소 중 값이 중간인 원소를 선택
- 왼쪽, 가운데, 오른쪽 원소를 정렬한 후 가장 작은 값을 `a[l]`, 가장 큰 값을 `a[r]`, 중간 값을 `a[r-1]`에 넣고, `a[l+1]`, ..., `a[r-2]`에 대해 분할 알고리즘을 수행
- 장점
  - 최악의 경우가 발생하는 확률을 낮추어 줌
  - 경계 키(sentinel key)를 사용할 필요가 없음
  - 전체 수행 시간을 약 5% 감소시킴

```cpp
void QuickSort(int a[], int l, int r)
{
    int i, j, m, v;
    if (r - l > 1) {
        m = (l + r) / 2;

        // 3개를 임의로 선택하고, 그 중에 중간값을 pivot으로 선택하는 코드
        if (a[l] > a[m]) swap(a, l, m);
        if (a[l] > a[r]) swap(a, l, r);
        if (a[m] > a[r]) swap(a, m, r);
        swap(a, m, r-1);

        // 여기서부터
        v = a[r-1]; i = l; j = r-1;
        for (;;) {
            while (a[++i] < v);
            while (a[--j] > v);
            if (i >= j) break;
            swap(a, i, j);
        }
        swap(a, i, r-1);
        // 여기까지는 동일
        QuickSort(a, l, i-1);
        QuickSort(a, i+1, r);
    }
    else if (a[l] > a[r]) swap(a, l, r);
}
```

### Merge Sort VS. Quick Sort

- 합병 정렬 : 분할-정복 (divide-and-conquer)
  - 처음에 화일을 두 부분으로 분할하고 나서, 각각의 부분을 개별적으로 정복함
  - Stable !
- 퀵 정렬 : 정복-분할(conquer-and-divide)
  - 순환 호출이 이루어지기 전에 대부분의 작업이 수행
  - Stable ?

## Shell Sort

![](https://github.com/heray1990/AlgorithmVisualization/blob/master/images/shell_sort_50samples_fps30_dpi50.gif?raw=true)

- 삽입 정렬을 간단하게 변형
  - k개의 서브리스트로 분할하여 삽입정렬
- 멀리 떨어진 원소끼리 교환이 가능하게 하여 정렬 속도를 향상시킴
- h-정렬 화일 : 모든 h번째 원소를 정렬한 화일
- 증가 순서의 예 (간격) : ..., 1093, 364, 121, 40, 13, 4, 1
  - 홀수, 짝수가 반복되는 것이 좋음
  - 예) 증가식: `h = 3*h + 1`, 감소식: `h = h/3`
- 특징
  - 순열 h가 1, 4, 13, 40, ...일때, 쉘 정렬의 비교 횟수는 <img src="https://latex.codecogs.com/svg.image?\inline&space;\bg{black}N^{3/2}" title="N^{3/2}" /> 을 넘지 않음
  - 안정적인 제자리 정렬

```cpp
ShellSort(a[], n)
    for (h ← 1; h < n; h ← 3*h+1) do { }; // 첫 번째 h 값 계산
    for ( ; h > 0; h ← h/3) do { // h 값을 감소시키며 진행
        for (i ← h + 1; i ≤ n; i ← i+1) do {
            v ← a[i];
            j ← i;
            while (j > h and a[j-h] > v) do {
                a[j] ← a[j-h];
                j ← j-h;
            } // while
            A[j] ← v;
        } // for
    } // for
end ShellSort()
```

### Analysis

- <img src="https://latex.codecogs.com/svg.image?O(n^2)" title="https://latex.codecogs.com/svg.image?O(n^2)" /> (worst known worst case gap sequence)
- <img src="https://latex.codecogs.com/svg.image?O(n\log n)" title="https://latex.codecogs.com/svg.image?O(n\logn)" /> (most gap sequences)
- <img src="https://latex.codecogs.com/svg.image?O(n\log^2n)" title="https://latex.codecogs.com/svg.image?O(n\log^2n)" /> (best known worst case gap sequence)

## Heap Sort

[Heap Sort | GeeksforGeeks Youtube](https://www.youtube.com/watch?v=MtQL_ll5KhQ)

- 히프(heap)를 이용해 정렬
  - 정렬할 원소를 모두 공백 히프에 하나씩 삽입
  - 한 원소씩 삭제 → 제일 큰 원소가 삭제됨
  - 이 원소를 리스트의 뒤에서부터 차례로 삽입
  - 오름차순으로 정렬된 리스트를 생성
- 제자리 정렬(in-place)이지만 불안정적(unstable)
- `N`개의 원소를 정렬하는데 `NlogN` 단계가 필요함
- 입력 배열의 순서에 민감하지 않음
- 내부 루프가 퀵 정렬보다 약간 길어서 평균적으로 퀵 정렬보다 2배 정도 느림

- 참고 : 히프 - 우선순위 큐의 일종

  - 히프 구조
    - <img width="588" alt="스크린샷 2022-04-16 오후 11 27 19" src="https://user-images.githubusercontent.com/73745836/163678888-00dd4c47-27fa-4c1d-b78e-ac807cdf2320.png">
  - 히프는 완전 이진 트리(complete binary tree) 이며 중복된 값을 허용함에 유의한다.
    - 이진 탐색 트리에서는 중복된 값을 허용하지 않았다.

- 참고 : 완전 이진 트리 : 노드를 삽입할 때 왼쪽부터 차례대로 삽입하는 트리
  - 완전 이진 트리<br>
    ![](https://t1.daumcdn.net/cfile/tistory/992097335A0E6CC721)
  - 완전 이진 트리 **X** <br>
    ![](https://t1.daumcdn.net/cfile/tistory/99CE39335A0E6CE422)

### Heap Sort Algorithm

```cpp
HeapSort(a[])
{
    n ← a.length-1; // n은 히프 크기 (원소의 수)
                    // a[0]은 사용하지 않고 a[1 : n]의 원소를 오름차순으로 정렬
    for (i ← n/2; i ≥ 1; i ← i-1) do    // 배열 a[]를 히프로 변환
        heapify(a, i, n);               // i는 내부 노드

    for (i ← n-1; i ≥ 1; i ← i-1) do {  // 배열 a[]를 히프로 변환
        temp ← a[1];    // a[1]은 제일 큰 원소
        a[1] ← a[i+1];  // a[1]과 a[i+1]을 교환
        a[i+1] ← temp;
        heapify(a, 1, i);
    }
}
end heapSort()
```

### Heapify Algorithm

```cpp
heapify(a[], h, m)
{
    // 루트 h를 제외한 h의 왼쪽 서브트리와 오른쪽 서브트리는 히프
    // 현재 시점으로 노드의 최대 레벨 순서 번호는 m
    v ← a[h];
    for (j ← 2*h; j ≤ m; j ← 2*j) do {
        if (j < m and a[j] < a[j+1]) then j ← j+1;
                                // j는 값이 큰 왼쪽 또는 오른쪽 자식 노드
        if (v ≥ a[j]) then exit;
        else a[j/2] ← a[j];     // a[j]를 부모 노드로 이동
    }
    a[j/2] ← v;
}
end heapify()
```

## Counting Sort

- 계수 정렬
- 장점
  - 시간 복잡도가 `O(n)`이다.
  - 비교 기반 정렬 알고리즘에 비해 빠르다.
- 단점
  - N에 비례하는 추가 기억장소가 필요하기 때문에 제자리 정렬은 아니다.
    - N의 범위가 크면 공간의 낭비가 심해진다.
  - 중복이 되어 있지 않다면, 사용하는데 의미가 없다.
- 적용 범위
  - 입력 키가 어떤 범위에 있을 때 적용 가능
  - 예를 들어 1부터 k 사이의 작은 정수 범위에 있다는 것을 미리 알고 있을 때에만 적용 가능

## Radix Sort

- 전체 키를 여러 자리로 나누어 각 자리마다 계수 정렬과 같은 안정적 정렬 알고리즘을 적용하여 정렬하는 방법
- `d` 자리수 숫자들에 대하여 계수 정렬로 정렬 (자릿수만큼 뺑뺑이를 돈다.) - 각 자리수마다 `O(N)` 시간이 걸리므로 전체로는 `O(dN)` 시간이 걸리는데, `d`
  를 상수로 취급할 수 있다면 `O(N)` 시간이 걸리게 됨
- 전체 정렬 데이터 개수만큼의 기억 장소와 진법 크기만큼의 기억 장소가 추가로 필요함
- 키가 `m`자리 숫자로 되어 있는 경우 `m`번의 패스를 반복 수행
- `N` 개의 원소에 대해 이 연산의 시간 복잡도는 `Ο(N)`
- 사용 예 : 학번 및 사번 같은 고유번호, 주민등록번호등

```cpp
RadixSort(a[], n)
{
    for (k ← 1; k ≤ m; k ← k+1) do {    // m은 digit 수, k=1은 가장 작은 자리 수
        for (i ← 0; i < n; i ← i+1) do {
            kd ← digit(a[i], k);    // k번째 숫자를 kd에 반환
            enqueue(Q[kd], a[i]);   // Q[kd]에 a[i]를 삽입
        }
        p ← 0;
        for (i ← 0; i ≤ 9; i ← i+1) do {
            while (Q[i] ≠ Ø) do {   // Q[i]의 모든 원소를 a[]로 이동
                p ← p+1;
                a[p] ← dequeue(Q[i]);
            }
        }
    }
}
end RadixSort()
```
