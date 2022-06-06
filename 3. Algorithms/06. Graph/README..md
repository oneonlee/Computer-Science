# Graph

## Contents

- [Graph](#graph-1)

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
- 경로(path), 단순경로(simple path) – 같은 정점을 두번 지나지 않음
- 순환(cycle) – 한 정점에서 다시 그 정점으로 돌아오는 경로
- **순환** 그래프(**cyclic** graph) vs **비순환** 그래프(**acyclic** graph)
- 길이(length)
