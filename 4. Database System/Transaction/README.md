# Transaction

- 트랜잭션 : DB 작업을 수행하는 단위 프로세스 (e.g., 계좌이체, 좌석예약)
  - 여러 사용자가 (동시에) 동일한 데이터베이스를 공유 가능하도록 지원
  - 동시에 사용하더라도 일관성을 보장하기 위한 동시성 제어

## 트랜잭션의 주요 성질 : **ACID**

- 원자성(Atomicity) : 트랜잭션과 관련된 작업들이 부분적으로 실행되다가 **중단되지 않는 것을 보장**하는 능력
- 일관성(Consistency) : 트랜잭션이 실행을 성공적으로 완료하면 **언제나 일관성 있는 데이터베이스 상태로 유지**하는 것을 의미
- 격리성(Isolation) : 트랜잭션을 수행 시 **다른 트랜잭션의 연산 작업이 끼어들지 못하도록 보장**하는 것을 의미
- 영속성(Durability) : 성공적으로 수행된 트랜잭션은 **영원히 반영**되어야 한다.

## MySQL의 autocommit, commit, rollback

```sql
mysql> show variables like '%commit%';
+-----------------------------------------+-------------------+
| Variable_name                           | Value             |
+-----------------------------------------+-------------------+
| autocommit                              | ON                |
| binlog_group_commit_sync_delay          | 0                 |
| binlog_group_commit_sync_no_delay_count | 0                 |
| binlog_order_commits                    | ON                |
| innodb_api_bk_commit_interval           | 5                 |
| innodb_commit_concurrency               | 0                 |
| innodb_flush_log_at_trx_commit          | 1                 |
| original_commit_timestamp               | 36028797018963968 |
| replica_preserve_commit_order           | ON                |
| replication_sender_observe_commit_only  | OFF               |
| slave_preserve_commit_order             | ON                |
+-----------------------------------------+-------------------+
11 rows in set (0.00 sec)
```

```sql
mysql> start transaction;
Query OK, 0 rows affected (0.01 sec)

mysql> insert into m1 values (7, 'seven');
Query OK, 1 rows affected (0.01 sec)

mysql> select * from m1;
-- m1 테이블이 출력됨
-- 테이블에 7이 포함되어 출력됐지만, 실제로는 반영된 것이 아님

mysql> rollback;
Query OK, 0 rows affected (0.00 sec)

mysql> select * from m1;
-- m1 테이블이 출력됨
-- 7이 반영되지 않은 상태에서 rollback 했으므로 7이 출력되지 않음
```

```sql
mysql> set autocommit = 0; -- autocommit 변수의 값을 OFF로 끄는 동작
```

---

- 기말고사: **Transaction & Concuurncy Control**
