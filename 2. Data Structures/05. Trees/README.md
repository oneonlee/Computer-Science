# Trees
An abstract model of a hierarchical structure

## Terminology

<img width="265" alt="스크린샷 2021-12-10 오후 2 37 10" src="https://user-images.githubusercontent.com/73745836/145522856-33feaab6-4710-4bac-9d1f-5e9de31df1a1.png">

| Terminology           | Explain                                                              | Example                   |
|-----------------------|----------------------------------------------------------------------|---------------------------|
| Root                  | node without parent                                                  | A                         |
| Internal node         | node with at least one child                                         | A, B, C, F                |
| External node (=Leaf) | node without children                                                | E, I, J, K, G, H, D       |
| Ancestors of a node   | parent, grandparent, great-grandparent, etc.                         |                           |
| Siblings of a node    | Any node which shares a parent                                       |                           |
| Depth of a node       | number of ancestors                                                  | K의 경우, A, B, F이므로 3 |
| Height of a tree      | maximum depth of any node                                            | 3                         |
| Descendant of a node  | child, grandchild, great-grandchild, etc.                            |                           |
| Subtree               | tree consisting of a node and its descendants (부분집합 같은 개념)   |                           |
| Edge                  | a pair of node (u, v) such that u is a parent of v((C, H))           |                           |
| Path                  | A sequence of nodes such that any two consecutive nodes form an edge | A, B, F, J                |
| Ordered tree          | a tree with a linear ordering defined for the children of each node  |                           |
