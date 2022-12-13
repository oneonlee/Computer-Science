# Search Trees

- [1. Binary Search Trees](#1-binary-search-trees)
- [2. AVL Trees](#2-avl-trees)
- [3. Splay Trees](#3-splay-trees)
- [4. (2,4) Trees](#4-24-trees)

## 1. Binary Search Trees

<img width="257" alt="스크린샷 2021-12-14 오후 4 36 09" src="https://user-images.githubusercontent.com/73745836/145953360-732467e5-fe38-4f98-8fc9-8fc1d090e810.png">

- A binary search tree is a binary tree storing entries (key,value) at its internal nodes and satisfying the following property:
  - Let `u`, `v`, and `w` be three nodes such that `u` is in the left subtree of `v` and `w` is in the right subtree of `v`.
  - We have `key(u) <= key(v) <= key(w)`
- External nodes do not store items
- An inorder traversal of a binary search trees visits the keys in increasing order

### Binary Search

- Binary search can perform operations of the ordered map
  - Similar to the high-low game
  - At each step, the number of candidate items is halved
  - Terminates after `O(logn)` steps
  - <img width="209" alt="스크린샷 2021-12-14 오후 4 54 52" src="https://user-images.githubusercontent.com/73745836/145955977-b0c9a438-75e5-4c11-8798-48d83896ba7b.png">

#### Example: `find(7)`

<img width="483" alt="스크린샷 2021-12-14 오후 5 00 52" src="https://user-images.githubusercontent.com/73745836/145956919-5b361767-015b-45c4-b176-cf8af35398f0.png">

### Search

<img width="289" alt="스크린샷 2021-12-14 오후 5 04 25" src="https://user-images.githubusercontent.com/73745836/145957476-45de105b-d3a9-4db8-97b3-53558bc685d0.png">

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

#### Example: `find(4)`

- Call `TreeSearch(4, root)`
  <img width="254" alt="스크린샷 2021-12-14 오후 5 04 08" src="https://user-images.githubusercontent.com/73745836/145957437-03a1a3ae-736d-4af3-bc5e-cb47aeaea123.png">

### Insertion

참고 : [티스토리 DEV_NUNU - 이진 검색 트리 2](https://new93helloworld.tistory.com/115?category=691027)

Step 1) Find `k`<br>
Step 2) Insert `k`

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

  - <img width="269" alt="스크린샷 2021-12-14 오후 5 07 02" src="https://user-images.githubusercontent.com/73745836/145957928-a3321cd8-df6e-4889-aad0-9351a2d266d1.png">

- Inserting an entry with key 78
  - <img width="557" alt="스크린샷 2021-12-14 오후 5 08 48" src="https://user-images.githubusercontent.com/73745836/145958146-fa4e593a-5afd-463e-8a82-89e1725c298b.png">

### Removal

참고 : [티스토리 DEV_NUNU - 이진 검색 트리 3](https://new93helloworld.tistory.com/116?category=691027)

- To perform operation `erase(k)`, we search for key `k`
- Assume key `k` is in the tree, and let `v` be the node storing `k`
- If node `v` has a leaf child `w`, we remove `v` and `w` from the tree with operation `removeAboveExternal(w)`, which removes `w` and its parent
  - An example operation of `removeAboveExternal(w)`
  - <img width="288" alt="스크린샷 2021-12-14 오후 5 12 53" src="https://user-images.githubusercontent.com/73745836/145958839-26434a27-a832-4734-9805-879f9022a108.png">

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
  <img width="267" alt="스크린샷 2021-12-14 오후 5 57 47" src="https://user-images.githubusercontent.com/73745836/145966063-066272b4-8a50-4984-b1aa-1b9426f62aa1.png">

- Removing an entry with key `32`
  <img width="545" alt="스크린샷 2021-12-14 오후 5 58 38" src="https://user-images.githubusercontent.com/73745836/145966197-0fc34dd6-01d2-4e3f-8d8f-cfed8ef9a6ba.png">

### Removal (cont.)

- We consider the case where the key `k` to be removed is stored at a node `v` whose children are both internal
  - we find the internal node `w` that follows `v` in an inorder traversal
  - we copy `key(w)` into node `v`
  - we remove node `w` and its left child `z` (which must be a leaf) by means of operation `removeAboveExternal(z)`

#### Example: Removal

- `erase(3)`
  <img width="260" alt="스크린샷 2021-12-14 오후 6 15 50" src="https://user-images.githubusercontent.com/73745836/145968955-7af45d5d-270d-4856-87e9-b0b32ef9dbb3.png">

- Removing an entry with key `65`
  <img width="559" alt="스크린샷 2021-12-14 오후 6 17 30" src="https://user-images.githubusercontent.com/73745836/145969235-935381fb-7107-41e3-8a7c-274226739c29.png">

### Performance

- The height `h` is `O(n)` in the worst case
- Consider an ordered map with `n` items implemented by means of a binary search tree of height `h`
  - Functions `find`, `put` and `erase` take `O(h) = O(n)` time
- Functions `size`, `empty` take `O(1)`

<img width="251" alt="스크린샷 2021-12-14 오후 6 50 59" src="https://user-images.githubusercontent.com/73745836/145974801-10f98aa9-9319-406c-87d2-afd921b6cbd4.png">

## 2. AVL Trees

- An AVL tree is a binary search tree that satisfies the following **Height-Balance Property**:
  - For every internal node `v` of `T`, the heights of the children of `v` can differ by at most 1 (왼쪽, 오른쪽 서브 트리의 높이 차이가 최대 1 입니다.)
- The heigh to fan AVL tree storing `n` keys is `O(logn)`
- **A**del’son-**V**el’skii and **L**andis
- <img width="318" alt="스크린샷 2021-12-14 오후 6 55 58" src="https://user-images.githubusercontent.com/73745836/145975636-8f3f7fde-ef1b-4fc4-b165-89767ebed458.png">
  - An example of an AVL tree where the heights are shown next to the nodes

### Insertion

- Insertion is as in a binary search tree
- Always done by expanding an external node.
- Example:
  - <img width="455" alt="스크린샷 2021-12-14 오후 6 57 25" src="https://user-images.githubusercontent.com/73745836/145975867-000401c6-e5bc-4274-adb0-79e6f67d8615.png">

### Trinode Restructuring

- Let `(a,b,c)` be an inorder listing of `x`,`y`,`z`
- Perform the rotations needed to make `b` the topmost node of the three
- <img width="720" alt="스크린샷 2021-12-14 오후 6 59 06" src="https://user-images.githubusercontent.com/73745836/145976157-00324919-2c20-484e-b6de-bb5a7749581b.png">

## 3. Splay Trees

## 4. (2,4) Trees

- Visualization : [2-3-4 tree](https://people.ksp.sk/~kuko/gnarley-trees/234tree.html) (초기 로딩느림 주의)

- A (2,4) tree (also called 2-4 tree or 2-3-4 tree) is a multi-way search with the following properties
  - Node-Size Property
    - every internal node has at most four children
  - Depth Property
    - all the external nodes have the same depth
- Depending on the number of children, an internal node of a (2,4) tree is called a 2-node, 3-node or 4-node

<img width="554" alt="스크린샷 2022-04-18 - ᅩ전 1 37 22" src="https://user-images.githubusercontent.com/73745836/163723903-549ffd82-620a-4a76-920a-98bdc57313b1.png">
