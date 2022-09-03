# Trees

An abstract model of a hierarchical structure

## Contents

1. Tree
2. Binary Tree
3. Traversal
4. Arithmetic Expression Tree

## 1. Tree

### Terminology

<img width="265" alt="스크린샷 2021-12-10 오후 2 37 10" src="https://user-images.githubusercontent.com/73745836/145522856-33feaab6-4710-4bac-9d1f-5e9de31df1a1.png">

| Terminology           | Explain                                                              | Example                   |
| --------------------- | -------------------------------------------------------------------- | ------------------------- |
| Root                  | node without parent                                                  | A                         |
| Child                 | if node u is the parent of node v, v is a child of u                 | except A                         |
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


### Tree ADT

We use positions to abstract nodes

- Generic functions:
  - `integer size()`
  - `boolean empty()`
- Accessor functions:
  - `position root()`
  - `list<position> positions()`
- Position-based functions:
  - `position p.parent()`
  - `list<position> p.children()`
- Query functions:
  - `boolean p.isRoot()`
  - `boolean p.isExternal()`
- Additional update functions may be defined by data structures implementing the Tree ADT

<img width="384" alt="스크린샷 2021-12-12 오후 3 19 26" src="https://user-images.githubusercontent.com/73745836/145702616-eda37a85-d71b-49b7-9602-59ec70fcd840.png">

### Linked Structure for Trees

- A node is represented by an object storing
  - Element
  - Parent node
  - Sequence of children nodes
- Node objects implement the Position ADT
- **The time complexities** of the functions of an n-node linked tree structure
  - `isRoot()`: `O(1)`
  - `isExternal()`: `O(1)`
  - `parent()`: `O(1)`
  - `p.children()`: `O(c_p) `
  - `size()`: `O(1)`
  - `empty()`: `O(1)`
  - `root()`: `O(1)`
  - `positions()`: `O(n)`
- **The space complexity**: `O(n)`

### Depth and Height

- Depth of a node: number of ancestors
  - Time complexity: `O(dp)` where dp ≤ n

```cpp
Algorithm depth(T, p)
  if p.isRoot()
    return 0
  else
    return 1+depth(T,p.parent())
```

- Height of a tree: maximum depth of any node
  - Time complexity: `O(n)`

```cpp
Algorithm height(T, p)
  if p.isExternal()
    return 0
  else
    h=0
    for each q ∈ p.children()
      h = max(h,height(T,q))
    return 1+h
```

## 2. Binary Trees

<img width="234" alt="스크린샷 2021-12-12 오후 4 55 28" src="https://user-images.githubusercontent.com/73745836/145704876-614ced76-cf16-4eb5-93d6-1b6447f7e179.png">

- A binary tree is a tree with the following properties:
  - Each internal node has at most two children (exactly two for proper binary trees)
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
  - `n_E`: number of external nodes
  - `n_I`: number of internal nodes
  - `h`: height
- Properties for a non empty binary tree `T`:
  - <img width="512" alt="스크린샷 2021-12-12 오후 5 08 51" src="https://user-images.githubusercontent.com/73745836/145705204-5ce41875-a2e1-44ef-bce8-b40d393e022e.png">

### Binary Tree ADT

- The Binary Tree ADT extends the Tree ADT
- Inherits all the methods of the Tree ADT
  - `isRoot() isExternal() p.parent() p.children() size() empty() root() positions()`
- Additional position methods:
  - `position p.left()`
  - `position p.right()`
- Update methods may also be defined by data structures implementing the Binary Tree ADT
- `Proper binary tree`: Each node has either 0 or 2 children (otherwise improper)

### Linked Structure for Binary Trees

<img width="178" alt="스크린샷 2021-12-12 오후 7 58 03" src="https://user-images.githubusercontent.com/73745836/145709622-510e5d63-da7a-4c25-b4fb-3d6e3ab76644.png">

- Assuming a proper binary tree
- A node is represented by an object storing
  - Element
  - Parent node
  - Left child node
  - Right child node
- Node objects implement the Position ADT

<img width="676" alt="스크린샷 2021-12-12 오후 7 57 40" src="https://user-images.githubusercontent.com/73745836/145709608-318b1279-e170-457d-bb41-2b07176234cf.png">

### Binary Tree Update Functions

- Provide the means to build and modify trees

  - `addRoot()`: Add a root to an empty tree
  - `expandExternal(p)`: Create two new external nodes and making them the left and right children of `p`
  - `removeAboveExternal(p)`: Remove the external node `p` together with its parent `q`, then replace `q` with the sibling of `p`

- An example operation of `removeAboveExternal(w)`
  - <img width="532" alt="스크린샷 2021-12-12 오후 8 00 28" src="https://user-images.githubusercontent.com/73745836/145709695-dd2ee025-8e1d-4c67-a804-c895bf2c5b13.png">

<img width="741" alt="스크린샷 2021-12-12 오후 8 02 00" src="https://user-images.githubusercontent.com/73745836/145709730-2b12a007-2705-4019-a672-82cba798bf40.png">

### Vector-Based Structure of Binary Trees

<img width="196" alt="스크린샷 2021-12-12 오후 8 18 19" src="https://user-images.githubusercontent.com/73745836/145710167-d3882581-1e74-48ae-af8a-fab2a352e627.png">

- Level numbering of nodes in a binary tree `T`
  - If `v` is the root of `T`, then `f(v)=1`
  - If `v` is the left child of node `u`, then `f(v)=2f(u)`
  - If `v` is the right child of node `u`, then `f(v)=2f(u)+1`
  - This numbering may skip some numbers
    - ex> 8, 9는 없다. 나중에 들어올 값을 위해, 자리를 비워두는 의도도 있다.

<img width="677" alt="스크린샷 2021-12-12 오후 8 37 36" src="https://user-images.githubusercontent.com/73745836/145710652-0ba355f2-d651-4083-aa64-6bfc6087d38e.png">

- A vector-based representation of a binary tree `T`
  - Node `v` is associated with the element of a vector `S` at `f(v)`
  - The vector `S` has size <img width="174" alt="스크린샷 2021-12-12 오후 8 26 57" src="https://user-images.githubusercontent.com/73745836/145710377-60af03c3-b6d8-4ccb-bfbc-9004f680c1bc.png"> (`N=f_M+1<=2^n-1`)
    - `f_M`: the maximum value of `f(v)`
    - `+1`의 이유: 0번 index도 포함되기 때문
    - `n`은 노드의 개수
  - Implement using an extendable array
  - `h`와 `n`의 관계: height가 node가 됨

### Performance of Binary Tree Implementations

- Linked structure vs. vector
  - Both have the same time complexity
  - Space complexity
    - Linked structure: `O(n)`
    - Vector: `O(2^n)`

<img width="371" alt="스크린샷 2021-12-12 오후 8 42 41" src="https://user-images.githubusercontent.com/73745836/145710745-6c88c015-70e7-42b4-a186-f842a1b0cafd.png">

## 3. Traversal

- A traversal visits the nodes of a tree in a systematic manner
- search 랑은 다르다. (모든 node들을 찾아가는 규칙)

### 1) Preorder Traversal

<img width="677" alt="스크린샷 2021-12-12 오후 8 55 54" src="https://user-images.githubusercontent.com/73745836/145711152-30764330-cec9-4e33-9c85-a3e8cfcecf66.png">

- In a preorder traversal, a node is visited before its descendants
- Application: print a structured document

```cpp
Algorithm preOrder(T,p)
  visit(p)
  for each child q of p
    preOrder(T,q)
```

<img width="498" alt="스크린샷 2021-12-12 오후 8 54 36" src="https://user-images.githubusercontent.com/73745836/145711110-e09a2d92-2d5d-4896-9112-86262ef9c441.png">

#### Exercise

<img width="262" alt="스크린샷 2021-12-12 오후 4 05 54" src="https://user-images.githubusercontent.com/73745836/145703654-8edb7787-0380-4faa-b38b-53dcea9ec827.png">
<details>
<summary>Result :</summary>
<div markdown="1">
A B E F I J K C G H D
</div>
</details>

### 2) Postorder Traversal

<img width="754" alt="스크린샷 2021-12-12 오후 8 57 09" src="https://user-images.githubusercontent.com/73745836/145711193-0dc68ac2-e28d-4ec2-bd81-1633df5aea22.png">

- In a post order traversal, a node is visited after its descendants
- Application: compute space used by files in a directory and its subdirectories

```cpp
Algorithm postOrder(T,p)
  for each child q of p
    postOrder(T,q)
  visit(p)
```

<img width="378" alt="스크린샷 2021-12-12 오후 9 01 54" src="https://user-images.githubusercontent.com/73745836/145711355-ef3a0889-5549-490a-b7d7-ff8040483927.png">

#### Exercise: Postorder Traversal

<img width="262" alt="스크린샷 2021-12-12 오후 8 59 05" src="https://user-images.githubusercontent.com/73745836/145711263-976594bc-0379-4197-a4f4-d5f6ac6770f7.png">

- In a post order traversal, a node is visited after its descendants
- List the nodes of this tree inpost order traversal order.

<details>
<summary>Result :</summary>
<div markdown="1">
E, I, J, K, F, B, G, H, C, D, A
</div>
</details>

### 3) Inorder Traversal

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

 <img width="803" alt="스크린샷 2021-12-12 오후 8 51 32" src="https://user-images.githubusercontent.com/73745836/145711020-5a426b2c-f099-4c24-896e-b0f40f0cc56d.png">

#### Exercise: Inorder Traversal

- In an inorder traversal a node is visited after its left subtree and before its right subtree
- List the nodes of this tree in inorder traversal order.

<img width="246" alt="스크린샷 2021-12-13 오전 10 52 50" src="https://user-images.githubusercontent.com/73745836/145740515-47f168e9-9b48-4673-b81a-1f71dfcd726a.png">
<details>
<summary>Result :</summary>
<div markdown="1">
D, B, H, E, I, A, F, C, G
</div>
</details>

### 4) Euler Tour Traversal

- Generic traversal of a binary tree
- Includes as special cases the preorder, postorder and inorder traversals
- Walk around the tree and visit each node three times:
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

<img width="364" alt="스크린샷 2021-12-13 오전 11 32 22" src="https://user-images.githubusercontent.com/73745836/145743421-4f36b9ac-d92b-470f-abd1-c58e144b3728.png">

#### Exercise

<details>
<summary>Result :</summary>
<div markdown="1">
`+ X 2 2 2 X - 5 5 5 - 1 1 1 - X + X 3 3 3 X 2 2 2 X +`
</div>
</details>

## 4. Arithmetic Expression Tree

<img width="371" alt="스크린샷 2021-12-12 오후 4 55 55" src="https://user-images.githubusercontent.com/73745836/145704891-ceb50858-61a9-4666-ad08-6043d5b82c69.png">

- Binary tree associated with an arithmetic expression
- Internal nodes: operators
- Leaves: operands

##### Exercise

<img width="242" alt="스크린샷 2021-12-12 오후 4 56 22" src="https://user-images.githubusercontent.com/73745836/145704901-352e7663-63cc-45fc-a348-d7fa899d0fa1.png">

<details>
<summary>Result :</summary>
<div markdown="1">
(2X(a-1))+(3Xb)
</div>
</details>

### Print Arithmetic Expressions

#### 1) Inorder traversal

- Specialization of an **inorder traversal** (수식작성에 효과적)
  - print operand or operator when visiting node
  - print `(` before traversing left subtree
  - print `)` after traversing right subtree

```cpp
Algorithm printExpression(T,p)
  if ¬p.isExternal()
    print(“(”)
    inOrder(T,p.left())
  print(p.element())
  if ¬p.isExternal()
    inOrder(p.right())
    print (“)”)
```

##### Exercise

<img width="246" alt="스크린샷 2021-12-13 오전 11 06 11" src="https://user-images.githubusercontent.com/73745836/145741472-6966ead5-c216-4360-8b62-4b0a1193bdd6.png">

<details>
<summary>Result :</summary>
<div markdown="1">
`((2X(a-1))+(3Xb))`
</div>
</details>

#### 2) Euler Tour traversal

- Specialization of an Euler Tour traversal (inorder와 기능적으로 크게 차이는 없음)
  - Left-visit: if node is internal, print `(`
  - Bottom-visit: print value or operator stored at node
  - Right-visit: if node is internal, print `)`

```cpp
Algorithm printExpEuler(T,p)
  if ¬p.isExternal()
    print(p.element())
  else
    print(“(”)
    printExpEuler(T,p.left())
    print(p.element())
    printExpEuler(T,p.right())
    print (“)”)
```

### Evaluate Arithmetic Expressions

- Specialization of a **postorder traversal** (계산 수행에 효과적)
  - recursive method returning the value of a subtree
  - when visiting an internal node, combine the values of the subtrees

```cpp
Algorithm evalExpr(T,p)
  if p.isExternal()
    return p.element()
  else
    x ← evalExpr(T,p.left())
    y ← evalExpr(T,p.right()) à ¬ operator stored at p return x à y
```

#### Exercise

- Draw an expression tree that has
  - Four leaves, storing the values 1,5,6, and 7
  - 3 internal nodes, storing operations `+,-,*,/`
    - operators can be used more than once, but each internal node stores only one
  - The value of the root is 21

<details>
<summary>Result :</summary>
<div markdown="1">
<img width="239" alt="스크린샷 2021-12-13 오전 11 24 14" src="https://user-images.githubusercontent.com/73745836/145742803-9e9a285a-894d-4fb8-a350-f2fbc5f39972.png">
<img width="218" alt="스크린샷 2021-12-13 오전 11 24 49" src="https://user-images.githubusercontent.com/73745836/145742831-c8ed922f-2be0-4b34-bfc7-3a639b35d4df.png">
</div>
</details>
