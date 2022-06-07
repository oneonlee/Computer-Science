# Graph

## Contents

- [Graph](#graph-1)
- [그래프의 표현 방법](#그래프의-표현-방법)
  - [Adjacency Matrix](#adjacency-matrix)
  - [Adjacency List](#adjacency-list)
- [Graph Traversal](#graph-traversal)
  - [깊이 우선 탐색 (Depth-First Search; DFS)](#깊이-우선-탐색-depth-first-search-dfs)
  - [너비 우선 탐색 (Breadth-First Search; BFS)](#너비-우선-탐색-breadth-first-search-bfs)
- [Shortest Path Algorithms](#shortest-path-algorithms)

## Graph

- 현상이나 사물을 정점(vertex)과 간선(edge)으로 표현한 것
- `Graph G = (V, E)`
  - `V` : 정점 집합
  - `E` : 간선 집합
- 두 정점이 간선으로 연결되어 있으면 인접하다고 한다.
  - 인접 = adjacent
  - 간선은 두 정점의 관계를 나타낸다.

### 그래프 용어

- 정점(vertex, node), 이음선(edge, arc)
- **방향** 그래프(**directed** graph)
- **가중치(weight)**, 가중치 포함 그래프(weighted graph)
- 경로(path), 단순경로(simple path) - 같은 정점을 두번 지나지 않음
- 순환(cycle) - 한 정점에서 다시 그 정점으로 돌아오는 경로
- **순환** 그래프(**cyclic** graph) vs **비순환** 그래프(**acyclic** graph)
- 길이(length)

## 그래프의 표현 방법

1. [Adjacency Matrix](#adjacency-matrix)
2. [Adjacency List](#adjacency-list)

### Adjacency Matrix

- `NXN` 행렬로 표현
  - `N` : 정점의 총 수
  - 원소 `(i, j) = 1` : 정점 `i` 와 정점 `j` 사이에 간선이 있음
  - 원소 `(i, j) = 0` : 정점 `i` 와 정점 `j` 사이에 간선이 없음
- 유향 그래프의 경우
  - 원소 `(i, j)`는 정점 `i`로부터 정점 `j`로 연결되는 간선이 있는지를 나타냄
- 가중치 있는 그래프의 경우
  - 원소`(i, j)`는 1 대신에 가중치를 가짐

#### 무향 그래프의 예

<img width="1007" alt="스크린샷 2022-06-07 오후 2 12 41" src="https://user-images.githubusercontent.com/73745836/172301079-29118945-f143-485c-9e30-f8fe2da708ec.png">

#### 가중치가 있는 무향 그래프의 예

<img width="1007" alt="스크린샷 2022-06-07 오후 2 12 48" src="https://user-images.githubusercontent.com/73745836/172301087-ed84b6ef-e3f2-4eeb-a829-8740708a5c9e.png">

#### 유향 그래프의 예

<img width="1007" alt="스크린샷 2022-06-07 오후 2 12 53" src="https://user-images.githubusercontent.com/73745836/172301093-baaa73cf-2af2-43e8-88fc-7f0b88d2b067.png">

#### 가중치가 있는 유향 그래프의 예

<img width="1007" alt="스크린샷 2022-06-07 오후 2 13 02" src="https://user-images.githubusercontent.com/73745836/172301097-3ed4d8e5-84da-4c89-91cf-7a6d931d9983.png">

#### 유향 그래프의 다른 예

<img width="1007" alt="스크린샷 2022-06-07 오후 2 13 10" src="https://user-images.githubusercontent.com/73745836/172301102-6373c517-0451-478b-9da1-a8298278f669.png">

#### 가중치가 있는 그래프의 다른 예

<img width="1007" alt="스크린샷 2022-06-07 오후 2 13 36" src="https://user-images.githubusercontent.com/73745836/172301113-dc009369-7f49-411d-bee9-31117428a71e.png">

### Adjacency List

- `N`개의 연결 리스트로 표현
- `i`번째 리스트는 정점 `i`에 인접한 정점들을 리스트로 연결해 놓음
- 가중치 있는 그래프의 경우
  - 리스트는 가중치도 보관한다

#### 무향 그래프의 예

<img width="1029" alt="스크린샷 2022-06-07 오후 2 23 55" src="https://user-images.githubusercontent.com/73745836/172302268-91c4bf4d-4677-4bd1-a30d-a073e2fa5892.png">

#### 가중치가 있는 무향 그래프의 예

<img width="1029" src="https://user-images.githubusercontent.com/73745836/172302273-ad01f122-8a68-43b1-84c1-438dd74b7cf9.png">

## Graph Traversal

- 대표적 두 가지 방법

  - DFS (Depth-First Search)
  - BFS (Breadth-First Search)

- 동일한 Tree를 각각 DFS/BFS로 방문하기
  - DFS : 깊이 먼저, **스택** 활용
  - BFS : 너비 먼저, **큐** 활용

<img width="715" alt="DFS vs BFS" src="https://user-images.githubusercontent.com/73745836/172302719-15d527b5-48cd-4683-b5d2-e70d4150f86e.png">

### 깊이 우선 탐색 (Depth-First Search; DFS)

- (1) 정점 i를 방문한다.
- (2) 정점 i에 인접한 정점 중에서 아직 **방문하지 않은 정점**이 있으면, 이 정점들을 모두 **스택**에 저장한다.
- (3) **스택**에서 정점을 삭제하여 새로운 i를 설정하고, 단계 (1)을 수행한다.
- (4) **스택**이 공백이 되면 연산을 종료한다.

```c
DFS(s) {
    // s 는 시작 정점
    for (i←0; i<n; i ← i +1) do {
        visited[i] ← false; // 모든 정점을 방문하지 않은 것으로 마크
    }
    stack ← createStack(); // 방문할 정점을 저장하는 스택
    push(stack, s); // 시작 정점 s를 스택에 저장
    while (not isEmpty(stack)) do { // 스택이 공백이 될 때까지 반복 처리
        j ← pop(stack);
        if (visited[j] = false) then { // 정점 j를 아직 방문하지 않았다면
            visit j;                   // 직접 j를 방문하고
            visited[j] ← true;         // 방문 한 것으로 마크
            for (each k ∈ adjacency(j)) do {  // 정점 j에 인접한 정점 중에서
                if (visited[k] = false) then  // 아직 방문하지 않은 정점들을
                    push(stack, k);           // 스택에 저장
            } // end for
        } // end if
    } // end while
} end DFS()
```

### 너비 우선 탐색 (Breadth-First Search; BFS)

- (1) 정점 i를 방문한다.
- (2) 정점 i에 인접한 정점 중에서 아직 **방문하지 않은 정점**이 있으면, 이 정점들을 모두 **큐**에 저장한다.
- (3) **큐**에서 정점을 삭제하여 새로운 i를 설정하고, 단계 (1)을 수행한다.
- (4) **큐**가 공백이 되면 연산을 종료한다.

```c
BFS(s) {
    // s 는 시작 정점
    for (i←0; i<n; i ← i +1) do {
        visited[i] ← false; // 모든 정점을 방문하지 않은 것으로 마크
    }
    visited[s] ← true;
    queue ← creatQ(); // 방문할 정점을 저장하는 큐
    enqueue(queue, s); // 시작 정점 s를 큐에 저장
    while (not isEmpty(queue)) do { // 큐가 공백이 될 때까지 반복 처리
        j ← dequeue(queue);
        visit j; // 직접 j를 방문
        for (each k ∈ adjacency(j)) do {   // 정점 j에 인접한 정점 중에서
            if (visited[k] = false) then { // 아직 방문하지 않은 정점들을
                enqueue(queue, k);         // 큐에 저장
                visited[k] ← true;         // 방문 한 것으로 마크
            } // end if
        } // end for
    } // end while
} end BFS()
```

## Shortest Path Algorithms

| Algorithm       | Complexity                   | Handle Negative weight?            | Properties                                                         |
| --------------- | ---------------------------- | ---------------------------------- | ------------------------------------------------------------------ |
| Dijkstra        | `O((n+m) log n)`<br>`O(n^2)` | No                                 | - Good for dense graph <br> - Adjacency matrix is better           |
| Bellman-Ford    | `O(nm)`                      | Yes                                | - Detect negative weight cycle<br> - Adjacency edge list is better |
| DAG-based       | `O(n+m)`                     | Yes                                | - Graph must be acyclic <br> - Adjacency edge list is better       |
| Floyd- Warshall | `O(n^3)`                     | Yes<br> (No negative-weight cycle) | - Good for dense graph<br> - Adjacency matrix is better            |
