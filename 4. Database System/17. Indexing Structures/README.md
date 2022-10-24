# Indexing Structures (`CREATE INDEX`)

- MySQL에서 Key의 종류
  - PRI
  - UNI (unique)
  - MUL (Multiple occurances column)
- Query의 2가지 종류
  - Exact Match Query
  - Range Query
- `CREATE INDEX`
  - (1) JOIN 애트리뷰트에 건다.
  - (2) Cardinality가 큰 테이블에 건다.
  - (3) 많이 건다? / 조금 건다?
    - 인덱스의 최대 단점 => Insert, Update가 느려짐
    - '많이 건다'의 의미 :
      - index의 개수
      - 다중 컬럼 x
  - (4) Read-Only에 건다!

---

## Source

1. **Fundamentals of Database Systems 7th Edition** by Ramez Elmasri, Shamkant B. Navathe.
