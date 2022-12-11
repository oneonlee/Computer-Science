# NoSQL

> **N**ot **o**nly **SQL**

- 데이터베이스의 일관성보다는 가용성과 확장성에 중점을 두고 있음.
- 비정형 데이터를 저장하기 위해 유연한 데이터 모델을 지원하고, 관계 데이터베이스와 동일한 데이터 처리가 가능하면서도 더저렴한 비용으로 분산 처리와 병렬 처리를 할 수 있음

## NoSQL의 장/단점

- 장점
  - 유연한 스키마
  - 쉽고 빠른 설치/관리
  - Massive Scalability
  - 완화된 일관성 (eventual consistency) → High Performance & Availability
    - VS. strong consistency
- 단점
  - SQL과 같은 표준 질의 언어 부족 → 프로그래밍 모델 도입
  - 완화된 일관성 → ACID가 보장 안됨

## The CAP Theorem

또는 브루어의 정리 (Brewer Theorem)

> '**분산 컴퓨터 시스템**은 다음과 같은 세 가지 조건을 모두 **만족할 수 없음**'을 증명한 정리

(참고 : 이 중 2가지만 만족할 수 있다.)

- 일관성 (Consistency)
  - 모든 노드는 같은 시간에 모든 고객에게 같은 데이터를 보여줘야 한다.
  - (같은 시간에 조회하는 데이터는 항상 동일한 데이터이어야 한다.)
- 가용성 (Availability)
  - 모든 노드는 항상 읽거나 쓸 수 있어야 한다.
    - 특정 노드에 장애가 발생하여도 서비스는 가능해야 한다는 의미이다.
- 분할 내성 (Partition tolerance)
  - 메시지 전달이 실패하거나, 시스템의 일부가 망가져도 시스템이 계속 동작해야 한다.
  - 네트워크 노드로 분산되어 있어도 시스템을 동작할 수 있어야 한다.
    - 노드 간 통신에 문제가 발생하여도 정상적으로 동작해야 한다.

### RDBMS와의 차이

- RDBMS는 일반적으로 CA를 만족한다.
  - C : 트랜잭션을 통한 ACID, 외래키
  - A : Replication - DB 서버가 장애가 발생하더라도 다른 서버에 있는 데이터를 가져와 계속 서비스 할 수 있다.
- RDBMS는 *분할 내성 (Partition tolerance)*을 용인하지 않기 때문에 일관성과 가용성에 포커스를 두고 지킬 수 있다.

## Eventual Consistency

> 당장은 맞지 않지만, (실시간 동기화는 불가능하지만) 결국 언젠가는 eventually 데이터가 동기화되어 일관성이 맞춰지는것을 말한다.

## Sharding in MongoDB

> 샤딩이란 하나의 거대한 데이터베이스나 네트워크 시스템을 여러 개의 작은 조각으로 나누어 분산 저장하여 관리하는 것을 말한다. (수평적 확장)

---

# References

1. **Fundamentals of Database Systems 7th Edition** by Ramez Elmasri, Shamkant B. Navathe.
