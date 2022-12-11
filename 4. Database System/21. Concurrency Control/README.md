# Concurrency Control (병행 제어)

> 여러 트랜잭션들이 동시에 실행되면서도 데이터베이스의 일관성을 유지할 수 있게 하는 기법

- Concurrency Control의 주요 목표
  - 일관성 (consistency) 유지
  - 공용성 (sharability) 최대화
    - 여러 사용자가 데이터베이스를 이용 가능
    - 단일 사용자 DBMS vs 복수 사용자 DBMS (병행데이터베이스)
  * 사용자에 대한 응답 시간(response time)의 단축
  * 시스템 활용도 (system utilization) 최대화

|        | 트랜잭션 1 | 트랜잭션 2 | 발생하는 문제들                                            | 동시 접근                       |
| ------ | ---------- | ---------- | ---------------------------------------------------------- | ------------------------------- |
| case 1 | read       | read       | 문제 없음                                                  | 허용                            |
| case 2 | read       | write      | - Dirty read<br> - Non-repeatable read<br> - Phantom read  | 허용 또는 불가 선택             |
| case 3 | write      | write      | - Lost Update<br> - Inconsistency<br> - Cascading rollback | lock을 이용하여 제한적으로 허용 |

## 병행제어 실패 현상

- Dirty Write
  - 같은 데이터에 동시에 두 개 이상의 트랜잭션이 값을 바꾸고자 함
  - 갱신 분실 (Lost Update) 유발
- Dirty Read
  - 아직 commit되지 않은 트랜잭션의 내용을 읽으려고 함
- Non-repeatable Read (Unrepeatable Read)
  - 동일 트랜잭션에서 동일한 대상을 여러번 읽을 때 그 사이에 수정 또는 삭제가 반영되어 값이 변경됨
  - 모순성 (Inconsistency) 유발
- Phantom Read
  - 동일 트랜잭션에서 동일한 대상을 여러번 읽을 때 그 사이에 새로운 값(Phantom Tuple)이 삽입되어 값이 변경됨

### 무제어 동시 공용의 문제점

- 갱신 분실 (Lost Update)
- 모순성 (Inconsistency)
- 연쇄 복귀 (Cascade Rollback)
  - 두개 이상의 Transaction이 수행되던 중 한개의 Transaction이 취소될 때 나머지 다른 Transaction도 연쇄적으로 취소되는 현상
  - 회복 불가(Unrecoverable): 연쇄복귀 되어야 하는 트랜잭션들 중 하나가 종료되어 회복이 불가능해 지는 현상
  - 문제의 원인
    - 충돌(conflict) :
      - 상이한 트랜잭션에 속하고 있으면서 동일한 데이터 아이템을 처리 대상으로 하는 두 연산
      - 최소한 하나의 기록(write) 연산
    - 공용하는 충돌된 데이터를 통해 트랜잭션 사이에 간섭이 일어나기 때문
    - 충돌이 일어나는 경우 : 같은 것을 읽을 때
      - read_i(x)와 write_j(x), write_i(x)와 read_j(x), write_i(x)와 write_j(x)
    - 충돌이 일어나지 않는 경우 : 다른 것을 읽을 때
      - read(x)와 write(y), write(x)와 read(y), write(x)와 write(y)

## 직렬 가능성

- 스케줄
  - 실행 순서
  - 트랜잭션 연산들의 순서
- 직렬 스케줄(serial schedule)
  - 트랜잭션 {T1, ..., Tn}의 순차적 실행
  - 인터리브드되지 않은 스케줄
  - 스케줄의 각 트랜잭션 Ti의 모든 연산 <Ti1,...,Tin>가 연속적으로 실행
  - `n!`가지의 방법
  - 트랜잭션들이 서로 독립적이라면, 어떠한 직렬 스케줄도 모두 정확함
- 비직렬 스케줄(nonserial schedule)
  - 인터리브된 스케줄
  - 트랜잭션 {T1, ..., Tn}의 병렬 실행

### 직렬 가능성 이론 이용

- 직렬 가능성 검사하지 않고 직렬 가능성 보장
- 병행제어 기법
  - 로킹 (locking) → 2PL
  - 타임스탬프 (timestamp) → MVCC (Multi Version Concurrency Control)
  - 낙관적 검증 (Optimistic Validation)과 Snapshot Isolation

## 병행제어 기법

- 로킹(Locking)
  - 상호 배제, 독점 제어의 과정. 다시 말해 잠금이 된 데이터 집합을 생성 (무간섭을 보장)
  - 트랜잭션이 어떤 데이터에 접근하고자 할 때 로킹 수행
  - 로킹이 되어 있는 데이터에는 다른 트랜잭션이 접근할 수 없음
  - 트랜잭션은 로킹이 된 데이터에 대해서만 연산 수행
  - 로킹 단위: 필드, 레코드, 파일, 데이터베이스 모두 로킹 단위가 될 수 있음
  - 로킹 단위가 크면
    - 관리하기 용이(로킹 오버헤드 감소)하지만 병행성 수준(동시성 수준) 낮아짐
  - 로킹 단위가 작으면
    - 병행성(동시성 수준)이 높아지지만 관리가 까다로움(로킹 오버헤드 증가)
- 2단계 로킹 규약 (2PL; Two-Phase Locking Protocol)
  - Lock과 Unlock이 동시에 이루어지면 일관성이 보장되지 않으므로 Lock만 가능한 단계와 Unlock만 가능한 단계를 구분
  - (1) 확장 단계(growing phase)
    - 트랜잭션은 lock만 수행하고 unlock은 수행할 수 없는 단계
  - (2) 축소 단계(shrinking phase)
    - 트랜잭션은 unlock만 수행하고 lock은 수행할 수 없는 단계
  - 직렬가능성 보장 : 스케줄 내의 모든 트랜잭션들이 2단계 로킹 규약을 준수한다면 그 스케줄은 직렬 가능
    - 하지만 unlock까지 기다려야하기 때문에 너무 느림
  - 교착 상태(Deadlock)이 발생할 수도 있음
    - 교착 상태(Deadlock) : 모든 트랜잭션들이 실행을 전혀 진전시키지 못하고 무한정 기다리고 있는 상태
      - T1은 T2가 데이터 아이템 x를 unlock하기 기다림
      - T2는 T1이 데이터 아이템 y를 unlock하기 기다림
    - 교착상태가 발생하는 필요충분조건
      - 상호 배제(mutual exclusion)
      - 대기(wait for)
      - 선취 금지(no preempt)
      - 순환 대기(circular wait)
  - 해결책
    - 탐지(detection) : 교착 상태가 일단 일어난 뒤에 교착 상태 발생 조건의 하나를 제거
    - 회피(avoidance) : 자원을 할당할 때마다 교착 상태가 일어나지 않도록 실시간 알고리즘을 사용하여 검사
    - 예방(prevention) : 트랜잭션을 실행시키기 전에 교착 상태 발생이 불가능 하게 만드는 방법
  - 교착상태의 회피(Avoidance) : 타임스탬프 이용
    - 트랜잭션의 시작 순서에 기초하는 식별자(identifier)
    - 트랜잭션이 기다려야 할지 복귀해야 할지 결정하는 데 사용
    - 트랜잭션 재시도 : T2에 의해 로크된 x를 T1이 요구할 때
    - (1) wait-die 기법
      - 비선점기법에 기반. 트랜잭션 T1가 이미 T2가 로크한 데이터 아이템을 요청할 때 만일 T1의 타임스탬프가 T2의 것보다 작은 경우(즉 TS(T1) < TS(T2)가 되어 T1가 고참인 경우)에는 T1는 기다린다. 그렇지 않으면 T1는 복귀(즉 die)하고 다시 시작한다
      - 오래된 트랜잭션은 새로운 트랜잭션이 자원을 방출하기를 기다림
    - (2) wound-wait 기법
      - 선점기법에 기반. 트랜잭션 T1가 이미 T2가 로크한 데이터 아이템을 요청할 때 T1의 타임스탬프가 T2의 것보 다 클 경우 (즉 TS(T1) > TS(T2)가 되어 T2가 고참인 경우)에는 기다린다. 그렇지 않으면 T2는 복귀해서 (즉 T1는 T2를 상처 입힌 다(선점)) 다시 시작한다
      - 오래된 트랜잭션은 절대 새로운 트랜잭션을 기다리지 않음
- 타임스탬프 (Time Stamp)
  - 데이터에 접근하는 시간을 미리 정하여서 정해진 시간(Time Stamp)의 순서대로 데이터에 접근 하여 수행
  - 직렬가능성을 보장한다.
  - 교착상태가 발생하지 않는다.
  - 연쇄복귀 (Cascading Rollback)를 초래할 수 있음
- 낙관적 병행제어 (Optimistic Concurrency Control)
  - 트랜잭션 수행 동안은 어떠한 검사도 하지 않고, 트랜잭션 종료 시에 일괄적으로 검사
  - 트랜잭션 수행 동안 그 트랜잭션을 위해 유지되는 데이터 항목들의 지역 사본에 대해서만 갱신
  - 트랜잭션 종료 시에 동시성을 위한 트랜잭션 직렬화가 검증되면 일시에 DB로 반영
- 다중 버전 병행제어 (MVCC; Multi-version, Concurrency Control)
  - 여러 버전의 타임스탬프를 비교하여 스케줄상 직렬가능성이 보장되는 타임스탬프를 선택
  - 충돌이 발생할 경우 복귀 수행. 연쇄 복귀 발생 가능성

## Type of Violation

| Isolation Level  | Dirty Read | Nonrepeatable Read | Phantom |
| ---------------- | ---------- | ------------------ | ------- |
| READ UNCOMMITTED | Yes        | Yes                | Yes     |
| READ COMMITTED   | No         | Yes                | Yes     |
| REPEATABLE READ  | No         | No                 | Yes     |
| SERIALIZABLE     | No         | No                 | No      |

---

# References

1. **Fundamentals of Database Systems 7th Edition** by Ramez Elmasri, Shamkant B. Navathe.
2. https://itwiki.kr/w/%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%B2%A0%EC%9D%B4%EC%8A%A4_%EB%B3%91%ED%96%89%EC%A0%9C%EC%96%B4
