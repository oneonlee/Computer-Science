# Priority Queues and Heaps

- [1. Priority Queues](#1-priority-queues)
  - Selection Sort
  - Insertion Sort
  - Priority Queue Sort
- [2. Heaps](#2-heaps)
- [3. Priority Queues and Heaps](#3-priority-queues-and-heaps)
  - Heap Sort

## 1. Priority Queues

### Priority Queue ADT

- A priority queue stores a collection of entries
  - Each element is associated with a “key” value representing rank or weigh
- Functions
  - `insert(e)`: inserts an element e
  - `object min()`: returns (but does not remove) an element with smallest key; error if empty - **return O**
  - `removeMin()`: removes the element referenced by `min();` error if empty - **return X**
  - `integer size()`
  - `boolean empty()`
- Applications: Standby flyers, auctions, stock market

#### Example

| Operation     | Output    | Priority Queue |
| ------------- | --------- | -------------- |
| `insert(5)`   | -         | {5}            |
| `insert(9)`   | -         | {5, 9}         |
| `insert(2)`   | -         | {2, 5, 9}      |
| `insert(7)`   | -         | {2, 5, 7, 9}   |
| `min()`       | [2]       | {2, 5, 7, 9}   |
| `removeMin()` | -         | {5, 7, 9}      |
| `size()`      | 3         | {5, 7, 9}      |
| `min()`       | [5]       | {5, 7, 9}      |
| `removeMin()` | -         | {7, 9}         |
| `removeMin()` | -         | {9}            |
| `removeMin()` | -         | {}             |
| `empty()`     | `true`    | {}             |
| `removeMin()` | `"error"` | {}             |

- Each call to `min()` returns a reference to an entry in the queue, not the actual value
  - 값을 주지 않고, position(reference)를 준다.
- Although the “Priority Queue” column shows the items in sorted order, they are not necessarily stored in this order
  - key 값만 알면 `min()`과 `removeMin()`을 사용할 수 있기 때문에 Priority Queue는 정렬이 되어있을 필요는 없다.
    - 정렬 O: `insert()`에서 탐색
    - 정렬 X: `min()`에서 탐색

### List-based Priority Queue

| Implementation with an unsorted list                                                                                          | Implementation with a sorted list                                                                                             |
| ----------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| <img width="209" src="https://user-images.githubusercontent.com/73745836/145746655-4954c489-b59a-4325-9d4f-146d046598d5.png"> | <img width="211" src="https://user-images.githubusercontent.com/73745836/145746670-f71358d7-27ba-4da2-aa96-6cf37b8bb642.png"> |
| Performance                                                                                                                   | Performance                                                                                                                   |
| `insert` takes `O(1)` time since we can insert the item at the beginning or end of the sequence                               | `insert` takes `O(n)` time since we have to find the place where to insert the item                                           |
| `removeMin` and `min` take `O(n)` time since we have to traverse the entire sequence to find the smallest key                 | `removeMin` and `min` take `O(1)` time, since the smallest key is at the beginning                                            |

<img width="340" alt="스크린샷 2021-12-13 오후 12 16 37" src="https://user-images.githubusercontent.com/73745836/145746950-f00cd940-68b9-4eee-81ca-fb46c6d20b12.png">

### Priority Queue Sort

- We can use a priority queue to sort a set of comparable elements
- Insert the elements one by one with a series of `insert(e)` operations
- Remove the elements in sorted order with a series of `removeMin()` operations

```cpp
Algorithm PQ-Sort(L, P)
  Input List L, priority queue P
  Output Sorted list L
  while not L.empty()
    e ← L.front()
    L.eraseFront()
    P.insert(e)
  while not P.empty()
    e ← P.min()
    P.removeMin()
    L.insertBack(e)
```

### Selection-Sort

- Selection-sort is the variation of PQ-sort where the priority queue is implemented with an unsorted list
- Running time of Selection-sort:

  - 1. Inserting the elements into the priority queue with n insert operations takes `O(n)` time
  - 2. Removing the elements in sorted order from the priority queue with n `removeMin` operations takes time proportional to
    - <img width="346" alt="스크린샷 2021-12-13 오후 12 21 47" src="https://user-images.githubusercontent.com/73745836/145747368-320d5abd-0798-4da0-a457-8393b50c0f47.png">

- Selection-sort runs in `O(n^2)` time
  - <img width="283" alt="스크린샷 2021-12-13 오후 12 23 42" src="https://user-images.githubusercontent.com/73745836/145747508-13209574-602b-4e9f-9e37-55453c2dd684.png">

#### Selection-Sort Example

|         | List L                | Priority Queue P (unsorted list) |
| ------- | --------------------- | -------------------------------- |
| Input:  | (7, 4, 8, 2, 5, 3, 9) | ()                               |
|         |                       |                                  |
| Phase 1 |                       |                                  |
| (a)     | (4, 8, 2, 5, 3, 9)    | (7)                              |
| (b)     | (8, 2, 5, 3, 9)       | (7, 4)                           |
| ...     | ...                   | ..                               |
| (g)     | ()                    | (7, 4, 8, 2, 5, 3, 9)            |
|         |                       |                                  |
| Phase 2 |                       |                                  |
| (a)     | (2)                   | (7, 4, 8, 5, 3, 9)               |
| (b)     | (2, 3)                | (7, 4, 8, 5, 9)                  |
| (c)     | (2, 3, 4)             | (7, 8, 5, 9)                     |
| (d)     | (2, 3, 4, 5)          | (7, 8, 9)                        |
| (e)     | (2, 3, 4, 5, 7)       | (8, 9)                           |
| (f)     | (2, 3, 4, 5, 7, 8)    | (9)                              |
| (g)     | (2, 3, 4, 5, 7, 8, 9) | ()                               |

##### Exercise

- Run the selection-sort on the following input sequence:
  - (22, 15, 36, 44, 10, 3, 9)

<details>
<summary>Result :</summary>
<div markdown="1">

|         | List L                     | Priority Queue P (unsorted list) |
| ------- | -------------------------- | -------------------------------- |
| Input:  | (22, 15, 36, 44, 10, 3, 9) | ()                               |
|         |                            |                                  |
| Phase 1 |                            |                                  |
| (a)     | (15, 36, 44, 10, 3, 9)     | (22)                             |
| (b)     | (36, 44, 10, 3, 9)         | (22, 15)                         |
| ...     | ...                        | ..                               |
| (g)     | ()                         | (22, 15, 36, 44, 10, 3, 9)       |
|         |                            |                                  |
| Phase 2 |                            |                                  |
| (a)     | (3)                        | (22, 15, 36, 44, 10, 9)          |
| (b)     | (3, 9)                     | (22, 15, 36, 44, 10)             |
| (c)     | (3, 9, 10)                 | (22, 15, 36, 44)                 |
| (d)     | (3, 9, 10, 15)             | (22, 36, 44)                     |
| (e)     | (3, 9, 10, 15, 22)         | (36, 44)                         |
| (f)     | (3, 9, 10, 15, 22, 36)     | (44)                             |
| (g)     | (3, 9, 10, 15, 22, 36, 44) | ()                               |

</div>
</details>

### Insertion-sort

- Insertion-sort is the variation of PQ-sort where the priority queue is implemented with a sorted list
- Running time of Insertion-sort:

  - 1. Inserting the elements into the priority queue with `n` `insert` operations takes time proportional to
    - <img width="245" alt="스크린샷 2021-12-13 오후 12 36 58" src="https://user-images.githubusercontent.com/73745836/145748553-b3950746-05ef-488e-9759-89f2a46161cd.png">
  - 2. Removing the elements in sorted order from the priority queue with a series of `n` `removeMin` operations takes `O(n)` time

- Insertion-sort runs in `O(n^2)` time
  - <img width="283" alt="스크린샷 2021-12-13 오후 12 36 37" src="https://user-images.githubusercontent.com/73745836/145748524-cc720acd-7dea-46fe-9e88-f47b232ada6b.png">

#### Insertion-sort Example

|         | List L                | Priority Queue P (sorted list) |
| ------- | --------------------- | ------------------------------ |
| Input:  | (7, 4, 8, 2, 5, 3, 9) | ()                             |
|         |                       |                                |
| Phase 1 |                       |                                |
| (a)     | (4, 8, 2, 5, 3, 9)    | (7)                            |
| (b)     | (8, 2, 5, 3, 9)       | (4, 7)                         |
| ...     | ...                   | ..                             |
| (g)     | ()                    | (2, 3, 4, 5, 7, 8, 9)          |
|         |                       |                                |
| Phase 2 |                       |                                |
| (a)     | (2)                   | (7, 4, 8, 5, 3, 9)             |
| (b)     | (2, 3)                | (7, 4, 8, 5, 9)                |
| (c)     | (2, 3, 4)             | (7, 8, 5, 9)                   |
| (d)     | (2, 3, 4, 5)          | (7, 8, 9)                      |
| (e)     | (2, 3, 4, 5, 7)       | (8, 9)                         |
| (f)     | (2, 3, 4, 5, 7, 8)    | (9)                            |
| (g)     | (2, 3, 4, 5, 7, 8, 9) | ()                             |

##### Exercise

- Run the insertion-sort on the following input sequence:
  - (22, 15, 36, 44, 10, 3, 9)

<details>
<summary>Result :</summary>
<div markdown="1">

|         | List L                     | Priority Queue P (unsorted list) |
| ------- | -------------------------- | -------------------------------- |
| Input:  | (22, 15, 36, 44, 10, 3, 9) | ()                               |
|         |                            |                                  |
| Phase 1 |                            |                                  |
| (a)     | (15, 36, 44, 10, 3, 9)     | (22)                             |
| (b)     | (36, 44, 10, 3, 9)         | (15, 22)                         |
| ...     | ...                        | ..                               |
| (g)     | ()                         | (3, 9, 10, 15, 22, 36, 44)       |
|         |                            |                                  |
| Phase 2 |                            |                                  |
| (a)     | (3)                        | (22, 15, 36, 44, 10, 9)          |
| (b)     | (3, 9)                     | (22, 15, 36, 44, 10)             |
| (c)     | (3, 9, 10)                 | (22, 15, 36, 44)                 |
| (d)     | (3, 9, 10, 15)             | (22, 36, 44)                     |
| (e)     | (3, 9, 10, 15, 22)         | (36, 44)                         |
| (f)     | (3, 9, 10, 15, 22, 36)     | (44)                             |
| (g)     | (3, 9, 10, 15, 22, 36, 44) | ()                               |

</div>
</details>

## 2. Heaps

- A heap `T` is a binary tree storing keys at its nodes and satisfying the following properties:
  - Heap-Order: for every internal node `v` other than the root, **`key(v)>=key(parent(v))`**
    - A minimum key is always stored at the root of `T`
    - 부모가 우선순위가 더 높다. (형제는 상관없다.)
  - Complete Binary Tree: let `h` be the height of the heap
    - The height is the smallest if `T` is complete
    - For `i` = `0, ..., h-1`,there are `2^i` nodes at depth `i`
  - The last node of a heap is the right most node at the maximum depth
    - <img width="311" alt="스크린샷 2021-12-13 오후 2 05 27" src="https://user-images.githubusercontent.com/73745836/145755459-8b99144e-7f39-41d0-9b1c-fc41c3af3ab9.png">

### Height of a Heap

- Theorem: A heap storing `n` keys has height `O(logn)`
  - Proof: (we apply the complete binary tree property)
    - Let `h` be the height of a heap storing `n` keys
    - Since there are `2^i` keys at depth `i = 0, ..., h-1` and at least one key at depth `h`,we have <img width="393" alt="스크린샷 2021-12-13 오후 2 10 05" src="https://user-images.githubusercontent.com/73745836/145755831-42f8193f-daab-44bb-ba9c-b1f2a42b402f.png">
    - Level `h` has at most `2^h` nodes: <img width="107" alt="스크린샷 2021-12-13 오후 2 11 31" src="https://user-images.githubusercontent.com/73745836/145755945-cfca413e-64e3-485a-af56-818b15363734.png">
    - Thus, <img width="217" alt="스크린샷 2021-12-13 오후 2 11 50" src="https://user-images.githubusercontent.com/73745836/145755975-238a6dfa-e338-412f-ad83-8a8acabc5db3.png">

<img width="500" alt="스크린샷 2021-12-13 오후 2 12 16" src="https://user-images.githubusercontent.com/73745836/145755998-c20dd68a-ba78-40b0-9de3-6cf38077ff0c.png">

### Vector-based Heap Implementation

- We can represent a heap with `n` keys by means of a vector of length `n + 1`
- For the node at rank `i`
  - the left child is at rank `2i`
  - the right child is at rank `2i+1`
- Links between nodes are not explicitly stored
- The cell of at rank `0` is not used
- Operation insert corresponds to inserting at rank `n+1`
- Operation `removeMin` corresponds to removing at rank `n`

<img width="241" alt="스크린샷 2021-12-13 오후 2 15 02" src="https://user-images.githubusercontent.com/73745836/145756256-4d62bf07-03f3-40fc-84c8-b17035e43587.png">

## 3. Priority Queues and Heaps

<img width="495" alt="스크린샷 2021-12-13 오후 2 16 31" src="https://user-images.githubusercontent.com/73745836/145756384-35718552-2af0-4a76-9ac0-f4b99bfb39bd.png">

- We can use a heap to implement a priority queue
- We store a (key,element) item at each internal node
- We keep track of the position of the last node

### 1) Insertion into a Heap

<img width="537" alt="스크린샷 2021-12-13 오후 2 17 20" src="https://user-images.githubusercontent.com/73745836/145756462-a290ad40-9897-43a6-8158-c8dc01dfc62f.png">

- Function `insert` of the priority queue ADT corresponds to the insertion of a key `k` to the heap

- The insertion algorithm consists of three steps
  - Find the insertion node `z` (the new last node)
  - Store `k` at `z`
  - Restore the heap-order property (discussed next)

### 2) Upheap

<img width="537" alt="스크린샷 2021-12-13 오후 2 26 51" src="https://user-images.githubusercontent.com/73745836/145757232-0ea7a8d8-c5ab-4080-ae84-ea8ec2d3adfd.png">

- After the insertion of a new key `k`, the heap-order property may be violated
- Algorithm upheap restores the heap-order property by swapping `k` along an upward path from the insertion node
- Upheap terminates when the key `k` reaches the root or a node whose parent has a key smaller than or equal to `k`
- Since a heap has height `O(logn)`, upheap runs in `O(logn)` time

<img width="569" alt="스크린샷 2021-12-13 오후 3 32 52" src="https://user-images.githubusercontent.com/73745836/145763623-d813fc1f-5740-4829-8d46-8ce1c08119d3.png">
<img width="569" alt="스크린샷 2021-12-13 오후 3 33 17" src="https://user-images.githubusercontent.com/73745836/145763655-e554b9c3-57aa-4450-9fff-af318c3d0ea0.png">

### 3) Removal from a Heap

- Function `removeMin` of the priority queue ADT corresponds to the removal of the root key from the heap
- The removal algorithm consists of three steps
  - Replace the root key with the key of the last node `w`
  - Remove `w`
  - Restore the heap-order property (discussed next)

<img width="560" alt="스크린샷 2021-12-13 오후 2 29 50" src="https://user-images.githubusercontent.com/73745836/145757494-22911403-b8cf-445d-b3be-9866e2fc412c.png">

### 4) Downheap

<img width="560" alt="스크린샷 2021-12-13 오후 2 32 13" src="https://user-images.githubusercontent.com/73745836/145757705-c222f659-8531-4431-9479-e7cafcaa30a7.png">

- After replacing the root key with the key `k` of the last node, the heap-order property may be violated
- Algorithm downheap restores the heap-order property by swapping key `k` along a downward path from the root
- Upheap terminates when key `k` reaches a leaf or a node whose children have keys greater than or equal to `k`
- Since a heap has height `O(logn)`, down heap runs in `O(logn)` time

<img width="561" alt="스크린샷 2021-12-13 오후 2 32 45" src="https://user-images.githubusercontent.com/73745836/145757738-8dd00ec7-5b86-4a70-94ab-c8e05baa08cc.png"><img width="561" alt="스크린샷 2021-12-13 오후 2 32 55" src="https://user-images.githubusercontent.com/73745836/145757753-24f95048-f9a9-439a-a41a-4cf584f8dced.png">

### 5) Merging Two Heaps

<img width="262" alt="스크린샷 2021-12-13 오후 3 19 14" src="https://user-images.githubusercontent.com/73745836/145762165-c2960149-ab51-4e63-a812-20d11d2860a5.png">

- We are given two heaps and a key `k`
- We create a new heap with the root node storing `k` and with the two heaps as subtrees
- We perform down heap to restore the heap-order property

### Heap-Sort

- Consider a priority queue with `n` items implemented by means of a heap
  - The space used is `O(n)`
  - Functions `insert` and `removeMin` take `O(logn)` time
  - Functions `size`, `empty`, and `min` take time `O(1)` time
- Using a heap-based priority queue, we can sort a sequence of `n` elements in `O(nlogn)` time
  - The resulting algorithm is called **heap-sort**
  - Heap-sort is much **faster** than quadratic sorting algorithms, such as insertion-sort and selection-sort

<img width="465" alt="스크린샷 2021-12-13 오후 2 35 58" src="https://user-images.githubusercontent.com/73745836/145758000-2d386382-58a6-47e5-a796-64f02f60dc50.png">

### Priority Queue Summary

<img width="549" alt="스크린샷 2021-12-13 오후 2 37 16" src="https://user-images.githubusercontent.com/73745836/145758123-87fb8f41-a895-49f0-a336-ae274365298a.png">

### Bottom-up Heap Construction

<img width="772" alt="스크린샷 2021-12-13 오후 3 41 38" src="https://user-images.githubusercontent.com/73745836/145764512-bbf26405-5a69-4adc-8730-70c8d6065070.png">

- We can construct a heap storing `n` given keys in using a bottom-up construction with `log n` phases
- In phase `i`, pairs of heaps with `2^i-1` keys are merged into heaps with `2^(i+1)-1` keys

#### Example

<img width="720" alt="스크린샷 2021-12-13 오후 3 42 20" src="https://user-images.githubusercontent.com/73745836/145764619-4ac9e278-cb63-4eaf-8f3d-90816339ae16.png">
<img width="720" alt="스크린샷 2021-12-13 오후 3 42 30" src="https://user-images.githubusercontent.com/73745836/145764640-8fe656db-adcb-4095-bf74-f1a25faaff41.png">

### Analysis

- We visualize the worst-case time of a downheap with a proxy path that goes first right and then repeatedly goes left until the bottom of the heap (this path may differ from the actual downheap path)
- Since each node is traversed by at most two proxy paths, the total number of nodes of the proxy paths is `O(n)`
- Thus, bottom-up heap construction runs in `O(n)` time
- Bottom-up heap construction is faster than `n` successive insertions and speeds up the first phase of heap-sort

<img width="620" src="https://user-images.githubusercontent.com/73745836/145764897-e569990c-272d-48ab-8fd4-fd336fd1ac32.png">
