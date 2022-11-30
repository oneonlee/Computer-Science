# Query Optimization

> 가장 cost-effective 한 내용으로 plan을 짜서 execution 한다.

## Incremental View Maintenance

- Update view incrementally by accounting for changes that occurred since last update
  - Join
  - Selection
  - Projection
  - Intersection - Aggregation

## Use of Selectives in Cost-Based Optimization

- Cost components for query execution
  - Access cost to secondary storage
  - **Disk storage** cost
  - **Computation** cost
  - **Memory usage** cost
  - **Communication** cost

## Additional Issues Related to Query Optimization

### Displaying the system’s query execution plan

- Oracle syntax

```sql
EXPLAIN PLAN FOR <SQL query>
```

- IBM DB2 syntax

```sql
EXPLAIN PLAN SELECTION [additional options] FOR <SQL-query>
```

- SQL server syntax

```sql
SET SHOWPLAN_TEXT ON or SET SHOWPLAN_XML ON or SET SHOW PLAN_ALL ON
```

## Mysql EXPLAIN

참고 : [[MySQL] 실행계획 (explain) 보는법](https://gradle.tistory.com/4)

- Mysql join type
  - The type column of `EXPLAIN` output describes how tables are joined.
- 아래로 갈수록 안좋은 type임
  - system : The table has only one row (= system table). This is a special case of the const join type.
  - const : 테이블에 조건을 만족하는 레코드가 하나일 때, 상수 취급
  - eq_ref : primary key나 unique not null column으로 생성된 인덱스를 사용해 조인을 하는 경우이다. const 방식 다음으로 빠른 방법이다.
    - ```sql
        SELECT * FROM ref_table,other_table WHERE ref_table.key_column=other_table.column;
      ```
  - ref : 인덱스로 지정된 컬럼끼리의 '=' , '<=>' 와 같은 연산자를 통한 비교로 수행되는 조인이다
    - ```sql
        SELECT * FROM ref_table WHERE key_column=expr;
      ```
  - fulltext : The join is performed using a FULLTEXT index.
  - ref_or_null : ref와 동일하나 NULL까지 찾을때.
    - ```sql
        SELECT * FROM ref_table WHERE key_column=expr OR key_column IS NULL;
      ```
  - index_merge : 인덱스 병합 최적화가 적용되는 조인타입. 이 경우, key컬럼은 사용된 인덱스의 리스트를 나타내며 key_len 컬럼은 사용된 인덱스중 가장 긴 key명을 나타낸다.
  - unique_subquery : 오직 하나의 결과만을 반환하는 'IN'이 포함된 서브쿼리의 경우이다.
  - index_subquery : unique_subquery와 비슷하지만 여러개의 결과를 반환한다
  - range : 특정한 범위의 rows들을 매칭시키는데 인덱스가 사용된 경우이다. BETWEEN이나 IN, '>', '>=' 등이 사용될 때이다.
  - all : 조인시에 모든 테이블의 모든 row를 스캔하는 경우. 물론 성능이 가장 느리다.

---

## References

1. **Fundamentals of Database Systems 7th Edition** by Ramez Elmasri, Shamkant B. Navathe.
2. [[MySQL] 실행계획 (explain) 보는법](https://gradle.tistory.com/4)
