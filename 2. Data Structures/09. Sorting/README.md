# Sorting

## Contents

1. Merge-Sort
2. Quick-Sort
3. Lower Bound for Sorting

## Sorting so far...

### PQ-sort

- Insert the elements one by one with a series of `insert(e)` operations
- Remove the elements in sorted order with a series of `removeMin()` operations

### Selection-sort

- Inserting elements into a PQ (implemented with an **unsorted list**) without taking care of the order;
  - Removing an element from the PQ needs a search

### Insertion-sort

- Inserting elements into a PQ (implemented with a **sorted list**) while taking care of the order;
  - Removing an element at the front

### Heap-sort

- Inserting elements into a PQ (implemented with a **heap**) while keeping the heap-order;
  - Removing an element at the root of the heap (a downheap maybe necessary)

### Summary of Sorting Algorithms

<img width="590" alt="스크린샷 2021-12-14 오후 10 22 03" src="https://user-images.githubusercontent.com/73745836/146006336-81a051e7-386a-42c1-bfad-b317c77b4b05.png">

## 1. Merge-Sort

### Divide-and-Conquer

- Divide-and-conquer is a general algorithm design paradigm:
  - Divide: divide the input data `S` in two disjoint subsets `S_1` and `S_2`
  - Recur: solve the subproblems associated with `S_1` and `S_2`
  - Conquer: combine the solutions for `S_1` and `S_2` into a solution for `S`
- The base case for the recursion are subproblems of size `0` or `1`

### Merge-Sort

- Merge-sort is a sorting algorithm based on the divide-and-conquer paradigm
- Like heap-sort
  - It uses a comparator
  - It has `O(n log n)` running time
- Unlike heap-sort
- It does not use an auxiliary priority queue
- It accesses data in a sequential manner (suitable to sort data on a disk)

- Merge-sort on an input sequence `S` with `n` elements consists of three steps:
  - Divide: partition `S` into two sequences `S_1` and `S_2` of about `n/2` elements each
  - Recur: recursively sort `S_1` and `S_2`
  - Conquer: merge `S_1` and `S_2` into a unique sorted sequence

```cpp
Algorithm mergeSort(S, C)
  Input sequence S with n
    elements, comparator C
  Output sequence S sorted
    according to C
  if S.size() > 1
    (S1, S2) ← partition(S, n/2)
    mergeSort(S1, C)
    mergeSort(S2, C)
  else:
    S ← merge(S1, S2)
```

### Merging Two Sorted Sequences

- The conquer step of merge-sort consists of merging two sorted sequences `A` and `B` into a sorted sequence `S` containing the union of the elements of `A` and `B`
- Merging two sorted sequences, each with `n/2` elements and implemented by means of a doubly linked list, takes `O(n)` time

```cpp
Algorithm merge(A, B)
  Input sequences A and B with n/2 elements each
  Output sorted sequence of A È B

  S ← empty sequence
  while ¬A.empty() ∩ ¬B.empty()
    if A.front() < B.front()
      S.addBack(A.front());
      A.eraseFront();
    else
      S.addBack(B.front());
      B.eraseFront();

  while ¬A.empty()
    S.addBack(A.front());
    A.eraseFront();

  while ¬B.empty()
    S.addBack(B.front());
    B.eraseFront();

  return S
```

### Merge-Sort Tree

- An execution of merge-sort is depicted by a binary tree
- Each node represents are cursive call of merge-sort and stores
  - Unsorted sequence before the execution and its partition
  - Sorted sequence at the end of the execution
- The root is the initial call
- The leaves are calls on subsequences of size `0` or `1`

<img width="349" alt="스크린샷 2021-12-15 오전 1 55 38" src="https://user-images.githubusercontent.com/73745836/146043434-9b50bf32-e45a-4c59-b7ae-42d6a24b485c.png">

#### Execution Example

![ezgif com-gif-maker](https://user-images.githubusercontent.com/73745836/146045844-e9a5097e-402c-41ca-92e1-5457b0ebf118.gif)

### Analysis of Merge-Sort

- The height `h` of the merge-sort tree is `O(logn)`
  - At each recursive call we divide in half the sequence,
- The overall amount or work done at the nodes of depth `i` is `O(n)`
  - We partition and merge `2^i` sequences of size `n/2^i`
  - We make `2^(i+1)` recursive calls
- Thus, the total running time of merge-sort is `O(nlogn)`

<img width="449" alt="스크린샷 2021-12-15 오전 2 14 47" src="https://user-images.githubusercontent.com/73745836/146047016-1c49a4dd-8ee1-4894-a0a7-7e0a5307fc37.png">

### Summary of Sorting Algorithms

<img width="655" alt="스크린샷 2021-12-15 오전 2 15 17" src="https://user-images.githubusercontent.com/73745836/146047080-efa1544e-059f-4ca6-bc96-0f1fef17c655.png">

## 2. Quick-Sort

<img width="270" alt="스크린샷 2021-12-15 오전 2 20 39" src="https://user-images.githubusercontent.com/73745836/146047906-6d36eda2-65cd-4687-914f-e863dba29a11.png">

- Quick-sort is a randomized sorting algorithm based on the divide-and-conquer paradigm:
  - Divide: pick a random element `x` (called _pivot_) and partition `S` into
    - `L` elements less than `x`
    - `E` elements equal `x`
    - `G` elements greater than `x`
  - Recur: sort `L` and `G`
  - Conquer: join `L`, `E` and `G`

### Partition

- We partition an input sequenceas follows:
  - We remove, in turn, each element `y` from `S` and
  - We insert `y` into `L`, `E` or `G`, depending on the result of the comparison with the pivot `x`
- Each insertion and removal is at the beginning or at the end of a sequence, and hence takes `O(1)` time
- Thus, the partition step of quick-sort takes `O(n)` time

```cpp
Algorithm partition(S, p)
  Input sequence S, position p of pivot
  Output subsequences L, E, G of the elements of S less than, equal to, or greater than the pivot, respectively

  L, E, G ← empty sequences
  x ← S.erase(p)

  while ¬S.empty()
    y ¬ S.eraseFront()
    if y < x
      L.insertBack(y)
    else if y = x
      E.insertBack(y)
    else // y > x
      G.insertBack(y)
  return L, E, G
```

### Quick-Sort Tree

<img width="533" alt="스크린샷 2021-12-15 오전 2 26 23" src="https://user-images.githubusercontent.com/73745836/146048835-b68846a9-5054-4b5b-a5c5-9afb852c23a5.png">

- An execution of quick-sort is depicted by a binary tree
  - Each node represents are cursive call of quick-sort and stores
    - Unsorted sequence before the execution and its pivot
    - Sorted sequence at the end of the execution
  - The root is the initial call
  - The leaves are call son subsequences of size `0` or `1`

#### Execution Example

![ezgif com-gif-maker (1)](https://user-images.githubusercontent.com/73745836/146048962-20155ca9-b650-45a8-8ed0-0c4fd0a0a64a.gif)

### Worst-case Running Time

- The worst case for quick-sort occurs when the pivot is the unique minimum or maximum element
- One of `L` and `G` has size `n-1` and the other has size `0`
- The running time is proportional to the sum
  `n + (n - 1) + ... + 2 + 1`
- Thus, the worst-case running time of quick-sort is `O(n^2)`

<img width="404" alt="스크린샷 2021-12-15 오전 2 30 13" src="https://user-images.githubusercontent.com/73745836/146049487-8b326158-9064-4380-8b58-f66e1f182047.png">

### Expected Running Time

- Consider a recursive call of quick-sort on a sequence of sizes
  - Good call: the sizes of `L` and `G` are each less than `3s/4`
  - Bad call: one of `L` and `G` has size greater than `3s/4`

<img width="511" alt="스크린샷 2021-12-15 오전 2 31 52" src="https://user-images.githubusercontent.com/73745836/146049697-d454af8f-a9b2-4a39-950a-86b91aa4e539.png">

- A call is good with probability `1/2`

  - `1/2` of the possible pivots cause good calls:
    <img width="326" alt="스크린샷 2021-12-15 오전 2 33 01" src="https://user-images.githubusercontent.com/73745836/146049855-3a7003dc-843e-4da1-9715-f21c77fa2ba1.png">

- The expected height of the quick-sort tree is `O(logn)`
- The amount or work done at the nodes of the same depth is `O(n)`
- Thus, the expected running time of quick-sort is`O(nlogn)`

<img width="403" alt="스크린샷 2021-12-15 오전 2 34 24" src="https://user-images.githubusercontent.com/73745836/146050064-751b1710-a364-46ef-b27e-267015ba7643.png">

### In-Place Quick-Sort

- Quick-sort can be implemented to run in-place
- In the partition step, we use replace operations to rearrange the elements of the input sequence such that
  - The elements less than the pivot have rank less than `h`
  - The elements equal to the pivo thave rank between h and `k`
  - The elements greater than the pivot have rank greater than `k`
- The recursive calls consider
  - Elements with rank less than `h`
  - Elements with rank greater than `k`

```cpp
Algorithm inPlaceQuickSort(S, l, r)
  Input sequence S, ranks l and r
  Output sequence S with the elements of rank between l and r rearranged in increasing order

  if l >= r
    return
  i ← a random integer between l and r
  x ← S.elemAtRank(i)
  (h, k) ← inPlacePartition(x)
  inPlaceQuickSort(S, l, h - 1)
  inPlaceQuickSort(S, k + 1, r)
```

### In-Place Partitioning

- Send pivot to the end of the sequence

  - <img width="330" alt="스크린샷 2021-12-15 오전 2 38 51" src="https://user-images.githubusercontent.com/73745836/146050764-dc7b9921-7d68-4967-ae0c-722082ad2c00.png">

- Repeat until `l` and `r` cross:
  - Scan `l` to the right until finding an element>=`x`
  - Scan `r` to the left until finding an element<`x`
  - Swap elements at indices `l` and `r`
- Then swap the element at `l` and at the end (at `x`)

#### Example

![ezgif com-gif-maker (2)](https://user-images.githubusercontent.com/73745836/146051888-ea8796d9-f48d-4e07-a54c-e1cd1a2368a3.gif)

### Summary of Sorting Algorithms

<img width="656" alt="스크린샷 2021-12-15 오전 2 44 55" src="https://user-images.githubusercontent.com/73745836/146051815-29231caa-4867-42c0-94b4-edca5af1977d.png">

## 3. Lower Bound for Sorting
