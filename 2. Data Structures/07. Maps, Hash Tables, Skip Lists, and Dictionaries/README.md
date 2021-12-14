# Maps, Hash Tables, Skip Lists, and Dictionaries

## Contents

1. Maps
2. Hash Tables
3. Skip Lists
4. Dictionaries

## 1. Maps

- A map models a searchable collection of key-value entries
- The main operations of a map are for searching, inserting, and deleting items
- Multiple entries with the same key are not allowed
- Applications:
  - address book
  - student-record data base
- Often called _associative containers_

### 1) The Map ADT

- `find(k)`: If `M` contains an entry `e=(k,v)`, then **return an iterator** `p` referring to this entry; otherwise, **return** the special iterator **end**
  - key 값을 찾는 것이 아니라 position을 찾는다.
- `put(k,v)`: If `M` does not have an entry with key equal to `k`, then add `entry (k,v)` to `M`; otherwise, replace the value with `v` and **return an iterator** referring to the inserted/modified entry
- `erase(k)`: Remove from `M` the entry with key equal to `k`; an error condition occurs if `M` has no such entry
- `erase(p)`: Remove from `M` the entry referenced by iterator `p`; an error condition occurs if `p` points to the end sentinel
- `begin()`: **Return an iterator** to the first entry of `M`
- `end()`: **Return an iterator** to a position just beyond the end of `M`
- `size()`, `empty()`

#### Example

| Operation | Output     | Map               |
| --------- | ---------- | ----------------- |
| empty()   | true       | Ø                 |
| put(5,A)  | p1:[(5,A)] | (5,A)             |
| put(7,B)  | p2:[(7,B)] | (5,A),(7,B)       |
| put(2,C)  | p3:[(2,C)] | (5,A),(7,B),(2,C) |
| put(7,D)  | p2:[(7,E)] | (5,A),(7,D),(2,C) |
| find(7)   | p2:[(7,E)] | (5,A),(7,D),(2,C) |
| find(3)   | end        | (5,A),(7,D),(2,C) |
| find(2)   | p3:[(2,C)] | (5,A),(7,D),(2,C) |
| size()    | 3          | (5,A),(7,D),(2,C) |
| erase(5)  | -          | (7,D),(2,C)       |
| erase(p2) | -          | (7,D)             |
| find(7)   | p1:[(7,D)] | (7,D)             |
| empty()   | false      | (7,D)             |

#### A Simple List-Based Map

<img width="545" alt="스크린샷 2021-12-13 오후 4 10 10" src="https://user-images.githubusercontent.com/73745836/145767799-cb59d2e9-579f-470c-b8d1-a06a55c2e50b.png">

- We can efficiently implement a map using an unsorted list
- We store the items of the map in a list `L` (based on a doubly-linked list), in arbitrary order

#### Algorithms

##### The find Algorithm

```cpp
Algorithm find(k):
  for each p in [L.begin(), L.end()) do
    if p.key() == k then
      return p
  return L.end() // there is no entry with key equal to k
```

##### The put Algorithm

```cpp
Algorithm put(k,v):
  for each p in [L.begin(), L.end()) do
    if p.key() == k then
      *p ← (k, v)
      return p
  p = L.insertBack((k, v)) // there is no entry with key k
  n = n + 1 // increment number of entries
  return p
```

##### The erase Algorithm

```cpp
Algorithm erase(k):
  for each p in [L.begin(), L.end()) do
    if p.key() == k then
      L.erase(p)
      n = n - 1 // decrement number of entries
      return
```

#### Performance of a List-Based Map

- Performance:
  - `put` takes `O(n)` time since we need to determine whether it is already in the
    sequence
  - `find` and `erase` take `O(n)` time since in the worst case (the item is not found) we traverse the entire sequence to look for an item with the given key
- The unsorted list implementation is effective only for maps of small size

### 2) The Ordered Map ADT

<img width="403" alt="스크린샷 2021-12-13 오후 4 17 15" src="https://user-images.githubusercontent.com/73745836/145768679-d4f420ff-2023-4c59-9eb5-55e92b166631.png">

- Keys come from a total order
- New operations:
  - Each returns an iterator to an entry:
  - `firstEntry()`: smallest key in the map
  - `lastEntry()`: largest key in the map
  - `ceilingEntry(k)`: smallest `key >= k`
  - `floorEntry(k)`: largest `key <= k`
  - All return **end** if the map is empty

## 2. Hash Tables

### Intuitive Notion of a Map

- Intuitively, a map `M` supports the abstraction of using keys as indices with a syntax such as `M[k]`.
- As a mental warm-up, consider a restricted setting in which a map with `n` items uses keys that are known to be integers in a range from `0` to `N-1`, for some `N>=n`.

<img width="469" alt="스크린샷 2021-12-13 오후 4 24 51" src="https://user-images.githubusercontent.com/73745836/145769541-515ed5d7-80f8-4d35-835a-d799fccd3e0f.png">

### More General Kinds of Keys

- But what should we do if our keys are not integers in the range from `0` to `N-1`?
  - Use a hash function to map general keys to corresponding indices in a table.
  - For instance,the last four digits of a Social Security number.

<img width="175" alt="스크린샷 2021-12-13 오후 4 27 55" src="https://user-images.githubusercontent.com/73745836/145769927-f5641bd7-30b2-4ad1-9cdd-e58fee4a0527.png">

### Hash Functions and Hash Tables

- A hash function `h` maps keys of a given type to integers in a fixed interval `[0,N-1]`
- Example:
  - `h(x) = x mod N` is a hash function for integer keys
- The integer `h(x)` is called the hash value of key `x`
- A hash table `H` for a given key type consists of
  - Hash function `h`
  - Array (called table) of size `N`
- When implementing a map with a hash table, the goal is to store item `(k,o)` at index `i = h(k)`

#### Example

- We design a hash table for a map storing entries as (SSN, Name), where SSN(social security number) is a nine-digit positive integer
- Our hash table uses an array of size `N=10,000` and the hash function `h(x) = last four digits of x`

<img width="281" alt="스크린샷 2021-12-13 오후 4 33 11" src="https://user-images.githubusercontent.com/73745836/145770544-4dd524b7-4cd4-476f-bd7d-0885b9c6854e.png">

### Hash Collisions

- Some keys will map to the same index of `H`
  - Chaining: put values that hash to same locationin a linked list (or a “bucket”)
  - Open addressing: if a collision occurs, have a method to select another location in the table

### Hash Functions

- A hash function is usually specified as the composition of two functions:
  - Hash code `h_1: keys → integers`
  - Compression function `h_2: integers → [0, N - 1]`
- The hash code is applied first, and the compression function is applied next on the result, i.e., <img width="119" alt="스크린샷 2021-12-13 오후 5 09 31" src="https://user-images.githubusercontent.com/73745836/145775071-ce93a62f-6002-4fd5-924e-ba1030a06d9b.png">
- The goal of the hash function is to “disperse” the keys in an apparently random way

### Hash Codes

- Integer cast
  - We reinterpret the bits of the key as an integer
  - Suitable for keys of length less than or equal to the number of bits of the integer type (e.g., byte, short, int and float in C++)
- Component sum
  - We partition the bits of the key into components of fixed length (e.g., 16 or 32 bits) and we sum the components
  - Suitable for numeric keys of fixed length greater than or equal to the number of bits of the integer type (e.g., long and double in C++)
- Polynomial accumulation
  - We partition the bits of the key into a sequence of components of fixed length (e.g., 8, 16 or 32 bits)
    - <img width="90" alt="스크린샷 2021-12-13 오후 4 41 32" src="https://user-images.githubusercontent.com/73745836/145771544-07d61214-79cb-4844-96a5-788cd1ad6259.png">
  - We evaluate the polynomial
    - <img width="285" alt="스크린샷 2021-12-13 오후 4 42 11" src="https://user-images.githubusercontent.com/73745836/145771611-bb9975ab-6a73-41e7-b4ad-8c2756627829.png">
    - at a fixed value z
  - Example
    - Hello: partition into five 8-bit (=1-byte) components
      - `H,e,l,l,o`
    - ASCII value of `H,e,l,l,o`: `72,101,108,108,111`
    - Evaluate the polynomial
      - <img width="345" alt="스크린샷 2021-12-13 오후 4 43 48" src="https://user-images.githubusercontent.com/73745836/145771823-438d9db7-806b-4e6e-a9c6-eed884d48312.png">
      - Depending on the value of `z`, the polynomial will be determined.

### Compression Functions

- Division
  - <img width="126" alt="스크린샷 2021-12-13 오후 4 46 03" src="https://user-images.githubusercontent.com/73745836/145772098-a3123df5-9298-4c80-80b1-b5728f46bdf3.png">
  - The size `N` of the hash table is usually chosen to be a prime
  - The reason has to do with number theory and is beyond the scope of this course
- Multiply, Add and Divide(MAD)
  - <img width="173" alt="스크린샷 2021-12-13 오후 4 47 30" src="https://user-images.githubusercontent.com/73745836/145772307-0ea43f7e-1a58-4d38-b357-160df0194ec5.png">
  - `a` and `b` are nonnegative integers such that <img width="101" alt="스크린샷 2021-12-13 오후 4 48 24" src="https://user-images.githubusercontent.com/73745836/145772428-2e1456c7-6959-43bd-bdf4-8e74cb75cba3.png">
  - Otherwise, every integer would map to the same value `b`

### Collision Handling: Separate Chaining

- Collisions occur when different elements are mapped to the same cell
- Separate Chaining: let each cell in the table point to a linked list of entries that map there
  - Separate chaining is simple, but requires additional memory outside the table

<img width="297" alt="스크린샷 2021-12-13 오후 4 57 05" src="https://user-images.githubusercontent.com/73745836/145773545-c8632b2a-f580-4aa4-9259-1eb573b5d9c8.png">

#### Exercise: Separate Chaining

- Assume you have a hash table `H` with `N = 9` slots (`A[0 − 8]`) and let the hash function be `h(k) = k mod N`
- Demonstrate (by picture) the insertion of the following entries into a hash table with collisions resolved by chaining
  - (Jacob,TX)→5→
  - (Kevin,PA)→28→
  - (Angie,PA)→19→
  - (Mary,NY)→15→
  - (John,MA)→20→
  - (Mike,WA)→33→
  - (James,CA)→12→
  - (Jane,WY)→17→
  - (Julie,FL)→10→

<details>
<summary>Result :</summary>
<div markdown="1">
- (Jacob,TX)→5→5
- (Kevin,PA)→28→1 
- (Angie,PA)→19→1
- (Mary,NY)→15→6
- (John,MA)→20→2
- (Mike,WA)→33→6
- (James,CA)→12→3 
- (Jane,WY)→17→8 
- (Julie,FL)→10→1
  
| 0 | 1           | 2          | 3           | 4 | 5           | 6          | 7 | 8          |
|---|-------------|------------|-------------|---|-------------|------------|---|------------|
|   | (Kevin, PA) | (John, MA) | (James, CA) |   | (Jacob, TX) | (Mary, NY) |   | (Jane, WY) |
|   | (Angie, PA) |            |             |   |             | (Mike, WA) |   |            |
|   | (Julie, FL) |            |             |   |             |            |   |            |
</div>
</details>

### Collision Handling: Linear Probing

- Open addressing: the colliding item is placed in a different cell of the table
- Linear probing: handles collisions by placing the colliding item in the next (circularly) available table cell
- Each table cell inspected is referred to as a “probe”
- Colliding items lump together, causing future collisions to cause a longer sequence of probes
- Example:
  - <img width="283" alt="스크린샷 2021-12-13 오후 5 39 51" src="https://user-images.githubusercontent.com/73745836/145779201-9a104629-0224-4486-85e9-484b0c710037.png">
  - `h(x) = x mod 13`
  - Insert keys `18,41,22,44,59,32,31,73,` in this order

#### Exercise: Linear Probing

- Assume you have a hash table `H` with `N = 11` slots(`A[0−10]`) and let the hash function be `h(k) = k mod N`
- Demonstrate (by picture) the insertion of the following entries into a hash table with collisions resolved by linear probing.
  - (Jacob,TX)→10→
  - (Kevin,PA)→22→
  - (Angie,PA)→31→
  - (Mary,NY)→4→
  - (John,MA)→15→
  - (Mike,WA)→28→
  - (James,CA)→17→
  - (Jane,WY)→88→
  - (Julie,FL)→59→

<details>
<summary>Result :</summary>
<div markdown="1">
- (Jacob,TX)→10→ 10
- (Kevin,PA)→22→ 0
- (Angie,PA)→31→ 9
- (Mary,NY)→4→ 4
- (John,MA)→15→ 4
- (Mike,WA)→28→ 6
- (James,CA)→17→ 6
- (Jane,WY)→88→ 0
- (Julie,FL)→59→ 4

| 0           | 1          | 2   | 3   | 4          | 5          | 6          | 7           | 8           | 9           | 10          |
| ----------- | ---------- | --- | --- | ---------- | ---------- | ---------- | ----------- | ----------- | ----------- | ----------- |
| (Kevin, PA) | (Jane, WY) |     |     | (Mary, NY) | (John, MA) | (Mike, WA) | (James, CA) | (Julie, FL) | (Angie, PA) | (Jacob, TX) |

</div>
</details>

### Collision Handling: Quadratic Probing

- Linear probing has an issue with clustering
- Another strategy called quadratic probing uses a hash function
  - <img width="216" alt="스크린샷 2021-12-13 오후 5 47 08" src="https://user-images.githubusercontent.com/73745836/145780276-c8e2c723-301b-48b4-90c7-9c0d36b1591b.png">
  - for `i = 0, 1, ..., N -1`
- Example
  - (Mary,NY)→4→4+1^2 → 5(vs.4)
  - (John,MA)→15→15+2^2 → 8(vs.4)
  - (Mike,WA)→28→28+3^2 → 4(vs.4)
  - (James,CA)→17→17+4^2 → 0
  - (Jane,WY)→88→88+5^2 → 3
  - (Julie,FL)→59→59+6^2 → 7(vs.4)
- This can still cause secondary clustering

### Collision Handling: Double Hashing

- Double hashing uses a secondary hash function `h'(k)` and handles collisions by placing an item in the first available cell of the series
  - <img width="298" alt="스크린샷 2021-12-13 오후 5 55 31" src="https://user-images.githubusercontent.com/73745836/145781558-3017ad5f-8ad9-436c-98ab-f2510be5eb2d.png">
  - The secondary hash function `h'(k)` cannot have zero values
  - The table size `N` must be a prime to allow probing of all the cells
- Common choice of compression function for the secondary hash function:
  - <img width="155" alt="스크린샷 2021-12-13 오후 5 56 58" src="https://user-images.githubusercontent.com/73745836/145781796-fb935ad7-45b1-423c-be2b-dce119a7aeaf.png"> where
    - `q<N`
    - `q` is a prime
  - The possible values for `h'(k)` are `1, 2, ... , q`

#### Exercise: Double Hashing

- Consider a hash table storing integer keys that handles collision with double hashing
  - `N=13`
  - `h(k) = k mod 13`
  - `h'(k) = 7 – (k mod 7)`
- Insert keys `18,41,22,44,59,32,31,73,` in this order

<details>
<summary>Result :</summary>
<div markdown="1">
<img width="160" alt="스크린샷 2021-12-13 오후 5 59 32" src="https://user-images.githubusercontent.com/73745836/145782186-e583162b-215f-476a-8c1b-dd3a06780f88.png">
</div>
</details>

### Performance of Hashing

- In the worst case, searches, insertions and removals on a hash table take `O(n)` time
- The worst case occurs when all the keys inserted into the map collide

## 3. Skip Lists

### What is a Skip List

- A skip list for a set `S` of distinct (key, element) items is a series of lists <img width="104" alt="스크린샷 2021-12-13 오후 10 01 15" src="https://user-images.githubusercontent.com/73745836/145817125-72ff76af-1857-4e5f-bd94-50ee7852f8aa.png"> such that
- Each list `S_i` contains the special keys `+∞` and `-∞`
- List `S_0` contains the keys of `S` in nondecreasing order
- Each list is a subsequence of the previous one, i.e., <img width="133" alt="스크린샷 2021-12-13 오후 10 03 06" src="https://user-images.githubusercontent.com/73745836/145817366-b160e66d-588e-4cce-974c-4a923a283d75.png">
- List `S_h` contains only the two special keys

<img width="542" alt="스크린샷 2021-12-13 오후 10 03 59" src="https://user-images.githubusercontent.com/73745836/145817487-e98fafdf-c654-4e90-a064-25dc33ef7792.png">

### Insertion

- To insert an entry `(x,o)` into a skip list, we use a randomized algorithm:
- We repeatedly toss a coin until we get tails, and we denote with `i` the number of times the coin came up heads
- If `i >= h`, we add new lists <img width="98" alt="스크린샷 2021-12-13 오후 10 06 53" src="https://user-images.githubusercontent.com/73745836/145817918-50a94528-cfda-4539-9bd1-64561221aff3.png">, each containing only the two special keys
- We search for `x` in the skip list and find the positions `p_0, p_1 , ..., p_i` of the items with largest key less than x in each list `S_0, S_1, ... , S_i`
- For `j ← 0, ..., i`, we insert item `(x, o)` into list `S_j` after position `p_j`
- Example: insert key `15`, with `i = 2`

<img width="572" alt="스크린샷 2021-12-13 오후 10 09 45" src="https://user-images.githubusercontent.com/73745836/145818410-6f0591a8-6bec-43d1-aacd-c67e54a67273.png">

## 4. Dictionaries
