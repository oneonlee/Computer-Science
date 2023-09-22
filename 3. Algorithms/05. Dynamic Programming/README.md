# Dynamic Programming

## Contents

- [스트링 편집거리 (Levenshtein Distance)](#스트링-편집거리-levenshtein-distance)
- [연쇄 행렬 곱셈 (Matrix-chain Multiplication)](#연쇄-행렬-곱셈-matrix-chain-multiplication)
- [최적 이진 탐색트리 (Optimal BST)](#최적-이진-탐색트리-optimal-bst)
- [최단경로 찾기 (Shortest Path)](#최단경로-찾기-shortest-path)
  - [무작정 알고리즘 (brute-force algorithm)](#무작정-알고리즘-brute-force-algorithm)
  - [Floyd 알고리즘 I](#floyd-알고리즘-i)
  - [Floyd 알고리즘 II](#floyd-알고리즘-ii)
- [0-1 Knapsack Problem](#0-1-knapsack-problem)

## 스트링 편집거리 (Levenshtein Distance)

- 두 스트링의 유사도를 측정하기 위해 사용
- Levenshtein Distance ($LD$)라고도 함
- 원래의 스트링을 $S$(source), 편집하고자 하는 목표 스트링을 $T$(target), 각각의 문자열의 길이를 $m$, $n$
- $\delta_{I}$는 삽입 연산의 비용
- $\delta_{D}$는 삭제 연산의 비용
- $\delta_{S}$는 교환 연산의 비용
- 편집 거리 : $𝑆$를 $𝑇$로 변환하는데 필요한 **삽입, 삭제, 대치** 연산의 **최소 비용**
  - $𝑆$ = “test”, $𝑇$=“test” → $LD(𝑆, 𝑇) = 0$
  - $𝑆$ = “test”, $𝑇$=“te**n**t” → $LD(𝑆, 𝑇) = 1$
- 편집 거리가 커질수록, 두 스트링의 유사도는 낮아지게 됨
- $𝐷[𝑖][𝑗]$를 $𝑆 = 𝑠_1, 𝑠_2, ... 𝑠_𝑗$와 $𝑇 = 𝑡_1, 𝑡_2, ..., 𝑡_𝑖$ 사이의 편집 거리라고 할 때, $𝐷[𝑖][𝑗]$의 점화식 (Recursive Property)은 아래와 같다.

![](Levenshtein%20Distance/img/recursive_property.png)

## 연쇄 행렬 곱셈 (Matrix-chain Multiplication)

- $i × j$ 행렬과 $j × k$ 행렬을 곱하기 위해서는 일반적으로 $i × j × k$번 만큼의 기본적인 곱셈이 필요하다.
- 연쇄적으로 행렬을 곱할 때, 어떤 행렬곱셈을 먼저 수행하느냐에 따라서 필요한 기본적인 곱셈의 횟수가 달라지게 된다.
- 예를 들어서, 다음 연쇄행렬곱셈을 생각해 보자:
  - $A_1 × A_2 × A_3$
  - $A_1$의 크기는 $10 × 100$이고, $A_2$의 크기는 $100 × 5$이고, $A_3$의 크기는 $5 × 50$라고하자.
  - $A_1 × A_2$를 먼저 계산한다면, 기본적인 곱셈의 총 횟수는 7,500회
  - $A_2 × A_3$를 먼저 계산한다면, 기본적인 곱셈의 총 횟수는 75,000회
  - 따라서, 연쇄적으로 행렬을 곱할 때 기본적인 **곱셈의 횟수가 가장 적게 되는 최적의 순서를 결정하는 알고리즘**을 개발하는 것이 목표이다.<br><br>
- 알고리즘: 가능한 모든 순서를 모두 고려해 보고, 그 가운데에서 가장 최소를 택한다. (DP)
- 시간복잡도 분석: 최소한 **지수(exponential-time)** 시간
- 증명:
  - $n$개의 행렬($A_1$, $A_2$, ..., $A_n$)을 곱할 수 있는 모든 순서의 가지 수를 $t_n$이라고 하자.
  - 만약 $A_1$이 마지막으로 곱하는 행렬이라고 하면, 행렬 $A_2$, ..., $A_n$을 곱하는 데는 $t_{n-1}$개의 가지수가 있을 것이다.
  - $A_n$이 마지막으로 곱하는 행렬이라고 하면, 행렬 $A_1$, ..., $A_{n-1}$을 곱하는 데는 또한 $t_{n-1}$개의 가지수가 있을 것이다.
  - 그러면, $t_{n} \geq t_{n-1} + t_{n-1}=2 t_{n-1}$이고 $t_{2}=1$이라는 사실은 쉽게 알 수 있다.
  - 따라서 $t_{n}\geq 2 \cdot t_{n-1} \geq 2^2 \cdot t_{n-2}\geq \cdots \geq 2^{n-2} \cdot t_{2}= 2^{n-2} = \Theta(2^n)$
- $d_k$를 행렬 $A_k$의 열(column)의 수라고 하자. 그러면 자연히 $A_k$의 행(row)의 수는 $d_{k-1}$가 된다.
- $A_{1}$의 행의 수는 $d_{0}$라고 하자. 그러면, 다음과 같이 재귀 관계식을 구축할 수 있다.
  - $1\leq i\leq j\leq n$
  - $M \[ i \] \[ j \] = i < j$일 때,
  - $A_{i}$부터 $A_{j}$까지의 행렬을 곱하는데 필요한 기본적인 곱셈의 최소 횟수
  - $M[i][j] = \mathrm{minimum}\_{i \leq k \leq j-1} (M[i][k] + M[k+ 1][j] + d_{i-1} d_{k} d_{j})$
  - if $i \geq j$, $M[i][j]=0$

## 최적 이진 탐색트리 (Optimal BST)

- 이진 탐색 트리
  - 루트의 왼쪽 서브트리에 있는 원소의 키 값은 루트보다 작고, 루트의 오른쪽 서브트리에 있는 원소의 키 값은 루트보다 큰 이진 트리
- 최적 이진 탐색 트리
  - 트리 내의 키와 각 키가 탐색될 확률이 주어져 있을 때 그 트리의 평균 탐색 비용, 즉, 평균 비교 횟수를 계산하고 이를 최소화하는 탐색 트리를 구축하는 문제<br>
- 키 값 $a_{i} \leq a_{i+1} \leq \cdots \leq a_{j}$일 경우 $A[i][j]$는 이진 탐색 트리의 $i$부터 $j$까지의 노드에 대한 최소 평균 탐색 시간
<img src ="https://user-images.githubusercontent.com/73745836/171447644-d91df242-b233-4e71-b2a0-e547b010c667.jpeg" width = 40%/>

### 점화식

$A[i][j]=\mathrm{min}\_{i\leq k\leq j}\left ( A[i][k-1]+ A[k+ 1][j]+ \sum_{q=i}^{j}P\left ( a_q \right ) \right )$

$A[i][j]=P\left ( a_i \right )$

$A[i][i-1]=0, \ \textrm{for} \ 1\leq i\leq n-1 $

### 알고리즘

```c
OptimalBST(p[], r[], n) {
    for (i ← 1; i ≤ n; i ← i + 1) do {
        A[i,i] ← p[i];
        r[i,i] ← i;
    }
    for (h ← 1; h < n; h ← h + 1) do {
        for (i ← 1; i ≤ n-h; i ← i + 1) do {
            j ← i + h;
            A[i,j] ← mini≤k≤j(A[i,k-1] + A[k+1,j] + Σ P[m]);
            r[i,j] ← 최소 값을 갖는 k;
        }
    }
    return A[1,n];
} end OmtimalBST()
```

```c
node_pointer BuildTree( i, j ) {
    index k;
    node_pointer p;

    k = r[i][j];
    if(k==0) return;
    else{
        p = new node_pointer;
        p -> key = Key[k];
        p -> left = BuildTree( i, k-1 );
        p -> right = BuildTree( k+1, j );
        return p;
    }
} end BuildTree()
```

## 최단경로 찾기 (Shortest Path)

### 무작정 알고리즘 (brute-force algorithm)

- 한 정점에서 다른 정점으로의 모든 경로의 길이를 구한 뒤, 그들 중에서 최소 길이를 찾는다.

### Floyd 알고리즘 I

- 문제: 가중치 포함 그래프의 각 정점에서 다른 모든 정점까지의 최단거리 를 계산하라.
- 입력: 가중치 포함, 방향성 그래프 $W$ 와 그 그래프에서의 정점의 수 $n$
- 출력: 최단거리의 길이가 포함된 배열 $D$

#### 알고리즘

```c
void floyd(int n, const number W[][], number D[][]) {
    int i, j, k;
    D = W;
    for(k=1; k <= n; k++)
        for(i=1;  i <= n; i++)
            for(j=1; j <= n; j++)
            D[i][j] = minimum(D[i][j],D[i][k]+D[k][j]);
}
```

- 모든 경우를 고려한 분석:
  - 단위연산: for-`j` 루프안의 지정문
  - 입력크기: 그래프에서의 정점의 수 $n$
  - $T(n)=n \times n \times n = n^3 \in \Theta \left ( n^3 \right )$

### Floyd 알고리즘 II

- 문제: 가중치 포함 그래프의 **각 정점에서 다른 모든 정점까지**의 최단거리를 계 산하고, 각각의 최단경로를 구하라.
- 입력: **가중치 포함 방향성 그래프** $W$ 와 그 그래프에서의 정점의 수 $n$
- 출력: 최단경로의 길이가 포함된 배열 $D$ , 그리고 다음을 만족하는 배열 $P$.

![](Floyd's%20Algorithm/img/P.png)

#### 알고리즘

```c
void floyd2(int n, const number W[][], number D[][], index P[][]) {
    index i, j, k;
    for(i=1; i <= n; i++)
        for(j=1; j <= n; j++)
            P[i][j] = 0;
    D = W;
    for(k=1; k<= n; k++)
        for(i=1; i <= n; i++)
            for(j=1; j<=n; j++)
                if (D[i][k] + D[k][j] < D[i][j]) {
                    P[i][j] = k; // 최솟값 저장
                    D[i][j] = D[i][k] + D[k][j];
                }
}
```

### TSP (Traveling Salesperson Problem)

1. 해밀턴 경로(Hamiltonian Circuit), 일주여행경로 : 모든 정점을 한 번씩만 거쳐서 출발한 정점으로 다시 돌아오는 경로
2. TSP (Traveling Salesperson Problem), 외판원 문제
   - Mathematically formulated in the 1800s by the Irish mathematician William Rowan Hamilton
   - an **NP-hard** problem in **combinatorial optimization**
   - Is important in **theoretical computer scienc**e and **operations research**.
   - 최소한 하나의 일주여행 경로가 존재하는 경우, **가중치 포함 방향 그래프**에서 **최적 일주여행경로**를 찾는 문제

<p style="text-align:center;"><img width="415" alt="스크린샷 2022-06-02 후 1 25 40" src="https://user-images.githubusercontent.com/73745836/171552803-bb097ab1-29d1-4f01-beef-5c57732b8953.png"></p>

- TSP 문제에 쓰일 용어
  - $𝑉$ : 모든 정점의 집합
  - $𝐴$ : $𝑉$의 부분집합
  - $D \[v_{i} \] \[ A \] = A$에 속한 정점을 각각 한 번씩만 거쳐서 $v_{i}$에서 $v_{1}$ 로 가는 최단경로의 길이
    - $v_{i}$ : 정점, 𝐴 : 집합

<img width=50% alt="스크린샷 2022-06-02ᅩ후 1 52 17" src="https://user-images.githubusercontent.com/73745836/171555320-ac0080fc-b55f-409d-b59a-1f16f36c87a5.png">

## 0-1 Knapsack Problem

문제 : 
- $S = \{ item_{1}, item_{2}, \cdots , item_{n} \}$
- $w_i =  \mathrm{weights\ of}\ item_{i}$
- $p_i = \mathrm{price\ of}\ item_{i}$
- $W = \mathrm{capacity\ of\ knapsack\  \left (Total\ weight\ that\ can\ be\ carried\ in\ the\ backpack \right )}$ 라고 할 때,
- $\sum_{item_i\in A} w_i\leq W$를 만족하면서 $\sum_{item_i\in A} p_i$가 최대가 되도록 $A\subseteq S$가 되는 $A$를 결정하는 문제이다.

### 무작정 (탐욕적) 알고리즘
- $n$ 개의 물건에 대해서 모든 부분집합을 다 고려한다.
- 그러나 불행하게도 크기가 $n$ 인 집합의 부분집합의 수는 $2^{n}$개 이다.

### 동적계획적인 접근 방법

$i>0$이고 $w>0$일 때, 전체 무게가 $w$가 넘지 않도록 $i$번째 까지의 항목 중에서 얻어진 최고의 이익 (optional profit)을 $P[i][w]$라고 하면, 

![](Knapsack%20Problem/img/recursive_property.png) 

와 같다. 이때, $𝑃[𝑖 − 1][𝑤]$는 $𝑖$번째 항목을 포함시키지 않는 경우의 최고 이익이고,
$𝑝_{𝑖} +𝑃[𝑖−1][𝑤−𝑤_{𝑖}]$는 𝑖번째 항목을 포함시키는 경우의 최고 이익이다.
