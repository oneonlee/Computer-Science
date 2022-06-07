# Backtracking, Branch & Bound

## Backtracking

- DFS 또는 그와 유사한 스타일의 탐색을 총칭한다
- Go as deeply as possible, backtrack if impossible (이 길이 아닌가보다...)
  - 가능한 지점까지 탐색하다가 막히면 되돌아간다
- 예
  - Maze, 8-Queens problem, Map coloring, ...

## Branch-and-Bound

- 분기(branch)와 한정(bound)의 결합
  - 분기를 한정시켜 쓸데없는 시간 낭비를 줄이는 방법
- Backtracking과 공통점, 차이점
  - 공통점
    - 경우들을 차례로 나열하는 방법 필요
  - 차이점
    - Backtracking : 가보고 더 이상 진행이 되지 않으면 돌아온다. <br>("가봐야 안다.")
    - Branch & Bound : 최적해를 찾을 가능성이 없으면 분기는 하지 않는다. <br>("안 가봐도 안다.", "가봐도 소용없어서 안 간다.")
      - pruning (가지치기)

## 분석

- Branch & Bound로 문제를 풀 경우 방문하는 마디의 개수가 Backtracking으로 풀 경우 보다 더 적다.
- 그러나 아직도 알고리즘의 시간복잡도는 지수적이거나 그보다 못하다!
- 예를 들어, n=100이 되면 문제를 풀 수 없는 것과 다름없다고 할 수 있다.
- 다른 방법이 있을까?
  - 근사(approximation) 알고리즘: 최적의 해답을 준다는 보장은 없지만, 무리 없이 최적에 가까운 해답을 주는 알고리즘.

## A\* Algorithm

- 최단경로 Algorithm의 대명사!
- Best-First-Search
  - 각 정점이 매력함수값 `g(x)`를 갖고 있다
  - 방문하지 않은 정점들 중 `g(x)` 값이 가장 매력적인 것부터 방문한다
- A\* algorithm은 best-first search에 목적점에 이르는 잔여추정거리를 고려하는 알고리즘이다
  - Vertex `x`로부터 목적점에 이르는 잔여거리의 추정치 `h(x)`는 실제치보다 크면 안된다.
  - best-first search : `g(x) + h(x)`

### Shortest Path 문제

- Remind: Dijkstra algorithm (`1:n`)
  - 시작점은 하나
  - 시작점으로부터 다른 모든 vertex에 이르는 최단경로를 구한다. (목적점이 하나가 아니다.)

<img width="1007" alt="Dijkstra 1-4" src="https://user-images.githubusercontent.com/73745836/172295655-95ccab07-2b28-4b58-9e94-4c51b5b3e3c6.png">
<img width="1007" alt="Dijkstra 5-8" src="https://user-images.githubusercontent.com/73745836/172296270-3aed5512-ffde-4c85-a0a2-3fc332eeea82.png">
<img width="1007" alt="Dijkstra 9-10" src="https://user-images.githubusercontent.com/73745836/172296312-aa206b6a-7725-45e2-b050-7271141a3cb1.png">

- A\* algorithm에서는 목적점이 하나다. (`1:1`)
  <img width="1007" alt="A* Algorithm 1-3" src="https://user-images.githubusercontent.com/73745836/172297216-43e2f4ab-3f85-4a7f-bae1-80b052fe2b20.png">
  <img width="1007" alt="A* Algorithm 4-5" src="https://user-images.githubusercontent.com/73745836/172297382-6f3faf70-5de2-434f-bb22-eef9e67ea68e.png">

> 추정잔여거리를 사용함으로써 탐색의 단계가 현저히 줄었다.
