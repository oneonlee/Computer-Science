# Searching

## Contents

- [Trees](#trees)
- [이진 트리 (Binary Tree)](#이진-트리-binary-tree)
- [이진 탐색 트리 (Binary Serarch Tree)](#이진-탐색-트리-binary-serarch-tree)
- [균형 트리 (Balanced Tree)](#균형-트리-balanced-tree)
  - [2-4 Tree](#2-4-tree)
  - [Red-Black Tree](#red-black-tree)
- [Hashing](#hashing)
  - [연쇄법 (chaining)](#연쇄법-chaining)
  - [선형 탐사법 (linear probing)](#선형-탐사법-linear-probing)
  - [이중 해싱 (double hashing)](#이중-해싱-double-hashing)
- [기수 탐색 (Radix searching)](#기수-탐색-radix-searching)
  - [디지털 탐색 트리 (Digital Search Tree)](#디지털-탐색-트리-digital-search-tree)
  - [기수 탐색 트라이 (Radix Search Trie)](#기수-탐색-트라이-radix-search-trie)
  - [패트리샤 트리 (Patricia)](#패트리샤-트리-patricia)
- [외부 탐색 (external seraching)](#외부-탐색-external-seraching)
  - [B-tree](#b-tree)

---

## Trees

- Tree Terminology


  <img width="265" alt="스크린샷 2021-12-10 - ᅩ후 2 37 10" src="https://user-images.githubusercontent.com/73745836/145522856-33feaab6-4710-4bac-9d1f-5e9de31df1a1.png">

| Terminology           | Explain                                                              | Example                   |
| --------------------- | -------------------------------------------------------------------- | ------------------------- |
| Root                  | node without parent                                                  | A                         |
| Child                 | if node u is the parent of node v, v is a child of u                 | A                         |
| Internal node         | node with at least one child                                         | A, B, C, F                |
| External node (=Leaf) | node without children                                                | E, I, J, K, G, H, D       |
| Ancestors of a node   | parent, grandparent, great-grandparent, etc.                         |                           |
| Siblings of a node    | Any node which shares a parent                                       |                           |
| **Depth of a node**   | number of ancestors (노드의 속성)                                    | K의 경우, A, B, F이므로 3 |
| **Height of a tree**  | maximum depth of any node (트리의 속성)                              | 3                         |
| Descendant of a node  | child, grandchild, great-grandchild, etc.                            |                           |
| Subtree               | tree consisting of a node and its descendants (부분집합 같은 개념)   |                           |
| **Degree**            | number of children of a node (트리의 속성)                           | F의 경우, I, J, K이므로 3 |
| Edge                  | a pair of node (u, v) such that u is a parent of v((C, H))           |                           |
| Path                  | A sequence of nodes such that any two consecutive nodes form an edge | A, B, F, J                |
| Ordered tree          | a tree with a linear ordering defined for the children of each node  |                           |


### 1) Preorder Traversal (P-L-R)

- A traversal visits the nodes of a tree in a systematic manner
- search 랑은 다르다. (모든 node들을 찾아가는 규칙)

<img width="677" alt="스크린샷 2021-12-12 - ᅩ후 8 55 54" src="https://user-images.githubusercontent.com/73745836/145711152-30764330-cec9-4e33-9c85-a3e8cfcecf66.png">

- In a preorder traversal, a node is visited before its descendants
- Application: print a structured document

```cpp
Algorithm preOrder(T,p)
  visit(p)
  for each child q of p
    preOrder(T,q)
```

### 2) Postorder Traversal (L-P-R)

<img width="754" alt="스크린샷 2021-12-12 - ᅩ후 8 57 09" src="https://user-images.githubusercontent.com/73745836/145711193-0dc68ac2-e28d-4ec2-bd81-1633df5aea22.png">

- In a post order traversal, a node is visited after its descendants
- Application: compute space used by files in a directory and its subdirectories

```cpp
Algorithm postOrder(T,p)
  for each child q of p
    postOrder(T,q)
  visit(p)
```

### 3) In-order Traversal

- In an inorder traversal, a node is visited after its left subtree and before its right subtree
- Application: draw a binary tree
  - `x(v)` = inorder rank of `v`
  - `y(v)` = depth of `v`

```cpp
Algorithm inOrder(T,p)
  if ¬p.isExternal()
    inOrder(T,p.left())
  visit(p)

  if ¬p.isExternal()
    inOrder(T,p.right())
```

<img width="803" alt="스크린샷 2021-12-12 - ᅩ후 8 51 32" src="https://user-images.githubusercontent.com/73745836/145711020-5a426b2c-f099-4c24-896e-b0f40f0cc56d.png">

### 4) Euler Tour Traversal

- Generic traversal of a binary tree
- Includes as special cases the preorder, postorder and inorder traversals
- Walk around the tree and visit each node three times: (한 노드를 3번 반복)
  - on the left (`preorder`)
  - from below (`inorder`)
  - on the right (`postorder`)
- 한붓그리기 느낌

```cpp
Algorithm eulerTour(T,p)
  visit(p) on the left // preOrder
  if ¬p.isExternal()
    eulerTour(T,p.left())
  visit(p) from below // inOrder
  if ¬p.isExternal()
    eulerTour(T,p.right())
  visit(p) on the right // postOrder
```

<img width="364" alt="스크린샷 2021-12-13 - ᅩ전 11 32 22" src="https://user-images.githubusercontent.com/73745836/145743421-4f36b9ac-d92b-470f-abd1-c58e144b3728.png">

## 이진 트리 (Binary Tree)

<img width="234" alt="스크린샷 2021-12-12 - ᅩ후 4 55 28" src="https://user-images.githubusercontent.com/73745836/145704876-614ced76-cf16-4eb5-93d6-1b6447f7e179.png">

- A binary tree is a tree with the following properties:
  - Each internal node has at most two children <br>
    (exactly two for proper binary trees)
    - degree = 2
  - The children of a node are an ordered pair
- We call the children of an internal node left child and right child
- Are cursive definition
  - A binary tree is either empty or consists of:
    - A node `r`,called the root of `T` and storing an element
    - A binary tree, called the left subtree of `T`
    - A binary tree, called the right subtree of `T`
- Applications:
  - arithmetic expressions
  - decision processes
  - searching

### Properties of Binary Trees

- Notation

  - `n`: number of nodes
  - `e`: number of external nodes
  - `i`: number of internal nodes
  - `h`: height

- Properties
  - `e` = `i` + 1 (외부노드 수 = 내부노드 수 + 1)
  - `n` = 2`e` - 1
  - `h` <= `i`
  - `h` <= (`n` - 1)/2
  - `e` <= 2^`h`
  - `h` >= log_2(`e`)
  - `h` >= log_2(`n` + 1) - 1

### Arithmetic Expression Tree

<img width="371" alt="스크린샷 2021-12-12 - ᅩ후 4 55 55" src="https://user-images.githubusercontent.com/73745836/145704891-ceb50858-61a9-4666-ad08-6043d5b82c69.png">

- Binary tree associated with an arithmetic expression
  - Internal nodes: operators
  - External nodes(leaves): operands

## 이진 탐색 트리 (Binary Serarch Tree)

- A binary search tree is a binary tree storing keys (or key-value entries) at its internal nodes and satisfying the following property:
  - Let `u`, `v`, and `w` be three nodes such that `u` is in the left subtree of `v` and `w` is in the right subtree of `v`. We have
  - **key(`u`) <= key(`v`) <= key(`w`)**
- External nodes do not store items
- An inorder traversal of a binary search trees visits the keys in increasing order

### Search

<img width="289" alt="스크린샷 2021-12-14 - ᅩ후 5 04 25" src="https://user-images.githubusercontent.com/73745836/145957476-45de105b-d3a9-4db8-97b3-53558bc685d0.png">

- To search for a key `k`, we trace a downward path starting at the root
- The next node visited depends on the comparison of `k` with the key of the current node
- If we reach a leaf, the key is not found and we return a null position

```cpp
Algorithm TreeSearch(k, u)
  if u.isExternal()
    return u

  if k < u.key()
    return TreeSearch(k, u.left())
  else if k = u.key()
    return u
  else // k > u.key()
    return TreeSearch(k, u.right())
```

### Insertion

참고 : https://new93helloworld.tistory.com/115?category=691027

- Step 1) Find `k`
- Step 2) Insert `k`
- Example:
  - <img width="455" alt="스크린샷 2021-12-14 - ᅩ후 6 57 25" src="https://user-images.githubusercontent.com/73745836/145975867-000401c6-e5bc-4274-adb0-79e6f67d8615.png">

<!-- - To perform operation `put(k,v)`, we search for key `k` (using `TreeSearch`) -->

- Assume `k` is not already in the tree, and let `w` be the leaf reached by the search
- We insert `k` at node `w` and expand `w` into an internal node

```cpp
public:
    void insertItem(const Key& k, const Element& e) // insert (key, element)
        { inserter(k, e); }
protected:
    BTPosition inserter(const Key& k, const Element& e) { // insert utillity
        BTPosition p = finder(k, T.root()); // find insertion spot
        // 내부노드인 경우
        while (T.isInternal(p)) // key already exists?
            // look further
            p = finder(k, T.rightChild(p)); // leftChild로 해도 아무 상관 없음
        // 외부노드인 경우
        T.expandExternal(p); // add new node here
        setItem(p, BSTItem(k, e)); // store (key, element)
        return p;
    }

```

#### Example: Insertion

- `put(5,"A")`

  - <img width="269" alt="스크린샷 2021-12-14 - ᅩ후 5 07 02" src="https://user-images.githubusercontent.com/73745836/145957928-a3321cd8-df6e-4889-aad0-9351a2d266d1.png">

- Inserting an entry with key 78
  - <img width="557" alt="스크린샷 2021-12-14 - ᅩ후 5 08 48" src="https://user-images.githubusercontent.com/73745836/145958146-fa4e593a-5afd-463e-8a82-89e1725c298b.png">

### Removal

참고 : https://new93helloworld.tistory.com/116?category=691027

- To perform operation `erase(k)`, we search for key `k`
- Assume key `k` is in the tree, and let `v` be the node storing `k`
- If node `v` has a leaf child `w`, we remove `v` and `w` from the tree with operation `removeAboveExternal(w)`, which removes `w` and its parent
  - An example operation of `removeAboveExternal(w)`
  - <img width="288" alt="스크린샷 2021-12-14 - ᅩ후 5 12 53" src="https://user-images.githubusercontent.com/73745836/145958839-26434a27-a832-4734-9805-879f9022a108.png">

```cpp
public:
    // remove using key
    void removeElement(const Key& k) throw(NonexistentElementException) {
        BTPosition p = finder(k, T.root()); // find the node
        if (p.isNull()) // not found?
            throw NonexistentElementException("Remove nonexistent element");
        remover(p); // remove it
    }
protected:
    BTPosition remover(const BTPosition& r) { // remove utility
        BTPosition p;
        if (T.isExternal(T.leftChild(r))) // left is external?
            p = T.leftChild(r); // remove from left
        else if (T.isExternal(T.rightChild(r))) // right is external?
            p = T.rightChild(r); // remove from right
        else {
            p = T.rightChild(r); // p = replacement
            do
                p = T.leftChild(p); // ... right subtree
            while (T.isInternal(p));
            setItem(r, T.parent(p).element()); // copy parent(p) to r
        }
        return T.removeAboveExternal(p); // remove p and parent
    }

```

#### Example: Removal

- `erase(4)`
  <img width="267" alt="스크린샷 2021-12-14 - ᅩ후 5 57 47" src="https://user-images.githubusercontent.com/73745836/145966063-066272b4-8a50-4984-b1aa-1b9426f62aa1.png">

- Removing an entry with key `32`
  <img width="545" alt="스크린샷 2021-12-14 - ᅩ후 5 58 38" src="https://user-images.githubusercontent.com/73745836/145966197-0fc34dd6-01d2-4e3f-8d8f-cfed8ef9a6ba.png">

### Removal (cont.)

- We consider the case where the key `k` to be removed is stored at a node `v` whose children are both internal
  - we find the internal node `w` that follows `v` in an inorder traversal
  - we copy `key(w)` into node `v`
  - we remove node `w` and its left child `z` (which must be a leaf) by means of operation `removeAboveExternal(z)`

#### Example: Removal
##### `erase(3)`
<img width="260" alt="스크린샷 2021-12-14 - ᅩ후 6 15 50" src="https://user-images.githubusercontent.com/73745836/145968955-7af45d5d-270d-4856-87e9-b0b32ef9dbb3.png">

##### Removing an entry with key `65`
<img width="559" alt="스크린샷 2021-12-14 - ᅩ후 6 17 30" src="https://user-images.githubusercontent.com/73745836/145969235-935381fb-7107-41e3-8a7c-274226739c29.png">

### Performance

- The height `h` is `O(n)` in the worst case
- Consider an ordered map with `n` items implemented by means of a binary search tree of height `h`
  - Functions `find`, `put` and `erase` take `O(h) = O(n)` time
- Functions `size`, `empty` take `O(1)`

<img width="251" alt="스크린샷 2021-12-14 - ᅩ후 6 50 59" src="https://user-images.githubusercontent.com/73745836/145974801-10f98aa9-9319-406c-87d2-afd921b6cbd4.png">

## 균형 트리 (Balanced Tree)

- Balanced의 정의 : **모든 leaf node들이 같은 level에 있는 상태**
- Balanced Tree의 정의 : **임의의 노드에서 파생되는 좌우의 부분트리의 노드 수가 최대 1 밖에 틀리지 않는 트리**

<br>

- 이진 트리 알고리즘
  - 최악의 경우 성능이 나쁨
    - 정렬된 파일 또는 역순으로 정렬된 파일, 큰 키와 작은 키가 교대로 나오는 파일
- 성능 개선
  - 퀵 정렬의 경우 성능 개선 방법은 확률에 의해 임의의 분할 원소를 선택하는 수 밖에 없음
  - 이진 트리 탐색의 경우에는 트리를 균형 있게 유지하면 최악의 상황을 피할 수 있음
  - 일반적인 개념은 쉽게 기술할 수 있지만, 실제 구현에서는 특수한 상황을 고려해야 함

### 2-4 Tree

- Visualization : [2-3-4 tree](https://people.ksp.sk/~kuko/gnarley-trees/234tree.html) (초기 로딩느림 주의)

- A (2,4) tree (also called 2-4 tree or 2-3-4 tree) is a multi-way search with the following properties
  - Node-Size Property
    - every internal node has at most four children
  - Depth Property
    - all the external nodes have the same depth
- Depending on the number of children, an internal node of a (2,4) tree is called a 2-node, 3-node or 4-node

<img width="554" alt="스크린샷 2022-04-18 - ᅩ전 1 37 22" src="https://user-images.githubusercontent.com/73745836/163723903-549ffd82-620a-4a76-920a-98bdc57313b1.png">

### Red-Black Tree

A red-black tree is a representation of a (2,4) tree by means of a binary tree whose nodes are colored red or black

## Hashing

- 모든 키의 레코드를 산술 연산에 의해 한 번에 바로 접근할 수 있는 기법
- 해싱의 단계
  - 해시 함수(hash function)를 통해 탐색 키를 해시 테이블 주소로 변환
  - 같은 테이블 주소로 사상되었을 경우에는 충돌을 해결(collision-resolution)해야 함

### 특징

- 시간과 공간의 균형
  - 메모리의 제한이 없을 경우 : 키를 메모리 주소로 사용하면 어떤 탐색이든지 한 번의 메모리 접근으로 수행 가능
  - 시간에 제한이 없을 경우 : 최소한의 메모리를 사용하여 데이터를 저장하고 순차 탐색
- 해싱은 이러한 두 극단 사이에서 합리적인 균형을 이룰 수 있는 방법을 제공
- 해싱을 사용하는 목적은 가용한 메모리를 효과적으로 사용하면서 빠르게 메모리에 접근하기 위함

### 해싱과 이진 트리

- 이진 트리보다 해싱을 많이 사용하는 이유
  - 간단함
  - 아주 빠른 탐색 시간
- 이진 트리의 장점
  - 동적
    - 삽입 횟수를 미리 알고 있지 않아도 됨
  - 최악의 경우 성능을 보장
    - 해싱의 경우 아무리 좋은 해시함수라도 모든 값을 같은 장소로 해싱하는 경우가 발생
  - 사용할 수 있는 연산의 종류가 많음 (예: 정렬연산)

### 연쇄법 (chaining)

- 동일 주소로 해시되는 모든 원소가 연결 리스트 형태로 연결됨
- 장점
  - 원소의 삭제가 용이
- 단점
  - 포인터 저장을 위한 기억공간이 필요
  - 기억장소 할당이 동적으로 이루어져야 함

### 선형 탐사법 (linear probing)

- 해시 함수 <img height="20" src="https://latex.codecogs.com/png.image?\inline&space;\huge&space;\dpi{300}\bg{white}h(k)&space;=&space;k&space;\mod&space;m" title="https://latex.codecogs.com/png.image?\inline \huge \dpi{300}\bg{white}h(k) = k \mod m" />
  - 개방 주소법(open addressing) 사용 : m 값이 입력 원소의 수보다 커야 함
- 클러스터링이 발생
  - 점유된 위치가 연속적으로 나타나는 뭉치가 있으면 이것이 점점 더 커지는 현상 - 이러한 뭉치는 평균 탐색 시간을 증가시킴
- 성능 특성
  - 해시 테이블이 2/3 정도 차 있을 경우, 선형 탐사법은 평균적으로 5번보다 적은 탐 사를 수행
  - 성공적인 탐색은 테이블이 90% 정도 찰 때까지 5번 이하의 탐사로 가능
  - 성공적이지 않은 탐색은 항상 성공적인 탐색에 비해 비용이 많이 듬

### 이중 해싱 (double hashing)

- 클러스터링 문제를 해결

  - 선형탐사법은 두번째 이후에 탐사되는 위치는 초기 탐사 위치에 따라 결정
  - 두번째 이후 탐사되는 위치가 첫번째 탐사 위치와 무관하다면 클러스터링을 없앨 수 있음

- 성능 특성
  - 이중 해싱은 평균적으로 선형 탐사보다 적은 탐사 회수를 가짐
  - 이중 해싱은 선형 탐사에 비해 작은 테이블 크기를 가지고도 동일한 탐색 성능을 나타냄
  - 테이블이 80% 이하로 채워져 있을 경우 성공적이지 않은 탐색의 평균 탐사 회수는 5번 이하이며, 99% 채워져 있을 경우 성공적인 탐색을 5번 이하로 할 수 있음

## 기수 탐색 (Radix searching)

- 탐색 키의 디지털 성질(0과 1)을 이용해 탐색을 위한 이진 트리를 만들어 탐색을 진행
- 탐색 키의 해당 비트가 0이면 왼쪽 자식을 방문하고, 1이면 오른쪽 자식을 방문
- 탐색 키가 클 때는 노드를 방문할 때마다 탐색 키를 비교하는 것이 성능에 많은 영향을 줌
- 기수 탐색 알고리즘은 탐색 키의 비교 횟수를 줄이면서 기억 장소의 낭비를 줄이고 구현을 쉽 게 하는 방향으로 개발되어 옴

### 디지털 탐색 트리 (Digital Search Tree)

- 탐색 키의 해당 비트가 0이면 왼쪽, 1이면 오른쪽으로 진행하여 단말 노드까지 이르면 그 곳에 새로운 노드를 삽입
- 노드를 방문할 때마다 탐색 키를 비교해야 하므로 탐색 키가 큰 경우 키 비교에 많은 시간이 걸림
- 균형은 맞지 않지만, 속도가 빠르다.
- 장점
  - 이해하기 쉽고 구현이 간단함
- 단점
  - 탐색 키의 비트에 따라 노드를 방문할 때 마다 디지털 탐색 트리의 키와 탐색 키를 매번 비교해야하므로, 탐색 키가 큰 경우에는 키 비교에 많은 시간이 소요

### 기수 탐색 트라이 (Radix Search Trie)

- 트라이(trie) : reTRIEval 에 유용하다고 하여 Fredkin이 명명함 (트리는 진짜 나무, 트라이는 덩쿨 같은 느낌)
- 노드를 내부 노드와 외부 노드로 나누어 내부 노드는 탐색시 왼쪽과 오른쪽 이동만을 나타내고 키는 외부 노드에만 저장
- 탐색 당 한 번의 키 비교만을 수행하므로 비교 시간을 절약
- 내부 노드는 키를 저장하지 않으므로 기억 장소의 낭비가 심하고, 내부 노드와 외부 노드를 나누어 관리해야 하므로 프로그래밍하기가 어려움

### 패트리샤 트리 (Patricia)

- “Practical Algorithm To **Retrieve** Information Coded In Alphanumeric”의 약자
- 노드에 몇 번째 비트를 비교할 것인지를 나타내는 숫자를 통해 내부 노드와 외부 노드의 구 분을 없애서 기억 장소를 절약
- 위쪽 링크(upward link)를 만나면 위쪽 링크가 가리키는 노드와 탐색 키를 비교하게 되므로 탐색당 1번만 비교 수행
- 노드마다 키를 비교해야 하는 디지털 탐색 트리의 단점과 내부 노드와 외부 노드를 두어 기억 장소를 낭비하는 기수 탐색 트라이의 단점을 동시에 극복한 방법

- 내부 노드에 키를 저장하여 기억 장소를 절약
- 상향 링크를 만날 때만 키 비교를 수행하게 하여 탐색 당 한 번의 비교만을 수행
- 디지털 탐색 트리와 기수 탐색 트라이의 단점을 동시에 극복

## 외부 탐색 (external seraching)

- 매우 큰 화일에 있는 데이터에 빠르게 접근하는 것은 많은 응용에서 매우 중요함
- 외부 탐색은 큰 디스크 화일을 주로 다룸
  - 테이프 같은 순차 접근 장치는 순차 탐색 외에 별다른 탐색 방법이 없음
- 외부 탐색 기법은 이미 배운 내부 탐색 기법의 논리적 확장임
- 10억개 이상의 데이타를 탐색하는데 불과 2∼3회의 디스크 접근으로 가능함
- 디스크는 페이지로 구분되어 있으며, 페이지는 많은 레코드를 가지고 있음

### B-tree

- Visualization : [B-tree](https://people.ksp.sk/~kuko/gnarley-trees/Btree.html) (초기 로딩느림 주의)

#### B+-트리의 성능 (B-트리와의 비교)

- 특정 키 값의 검색
  - 단점
    - 검색이 항상 리프 노드까지 내려가야만 종료 (항상 `O(log n))`
      - 검색하고자 하는 값이 인덱스 세트에서 발견되더라도 리프 노드까지 내려가야만 실제 레코드의 포인터를 알 수 있음
  - 장점
    - 인덱스 노드는 포인터를 저장하지 않으므로 노드 내 공간이 절약됨 → 트리레벨이 낮아질 수 있음
    - 범위 검색
      - 연결리스트를 순회 → 효율적
    - B+-트리는 **키 검색**과 **범위 검색**을 모두 필요로 하는 응용에서 효율적
      - DBMS
      - File systems
