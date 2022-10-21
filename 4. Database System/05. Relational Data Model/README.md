# Relational Data Model

- [관계형 데이터 모델의 개념](#관계형-데이터-모델의-개념)
  - [용어 정의 (릴레이션, 투플, 애트리뷰트 등)](#관계모델-용어)
- [관계형 데이터 모델의 제약조건과 관계형 데이터베이스 스키마](#관계형-데이터-모델의-제약조건-constraint)
  - [(1) 도메인 제약 조건(domain constraints)](#1-도메인-제약-조건domain-constraints)
  - [(2) 키 제약조건(key constraints)](#2-키-제약조건key-constraints)
  - [(3) NULL에 대한 제약조건(constraints on NULLs)](#3-null에-대한-제약조건constraints-on-nulls)
  - [(4) 엔티티 무결성 제약조건(entity integrity constraints)](#4-엔티티-무결성-제약조건entity-integrity-constraints)
  - [(5) 참조 무결성 제약조건(referential integrity constraints)](#5-참조-무결성-제약조건referential-integrity-constraints)
- 갱신 연산과 제약 조건의 위반 처리
  - 릴레이션에 투플을 삽입하거나 삭제 변경할 때 제약조건을 만족하는지 검사

## 관계형 데이터 모델의 개념

### 관계모델 용어

- 행 → 튜플
- 열 → 애트리뷰트
- 테이블 → 릴레이션
- 테이블은 수학 객체 "관계"의 구체적인 인스턴스
- 도메인(domain)
  - 애트리뷰트가 가질 수 있는 값(value)들의 집합
    - 단순도메인(simpledomain) → 단순 애트리뷰트 : 원자값
    - 복합 도메인 (composite domain) → 복합 애트리뷰트 : 복합값
      - 연, 월, 일 ⇒ 날짜:<연,월,일>

### 관계모델의 구성

- 관계모델에서 데이터베이스는 릴레이션(테이블)들의 모임으로 표현됨
- 릴레이션은 튜플(행, 레코드)들의 집합으로 표현됨
- 튜플은 애트리뷰트(컬럼, 필드, 혹은 속성)들로 구성됨
- 일반적으로 ER 모델링 이후에 관계 모델로 변환
  - 테이블: 엔티티 타입 (혹은 다치 애트리뷰트 또는 관계 타입)
  - 행: 엔티티 혹은 관계에 해당하는 사실(인스턴스)을 표현함
  - 열: 애트리뷰트들을 표시함

### Relation의 특성들

- 튜플의 무순서성
  - 릴레이션은 튜플들의 집합으로 정의됨
  - 집합에서 원소의 순서가 무의미한 것과 마찬가지로 튜플의 순서 역시 의미가 없음
- 애트리뷰트의 원자성(atomic)
  - 튜플 내의 각 값은 더 이상 나눌 수 없는 원자값(atomic value)들임
  - 값을 알 수 없거나 해당되는 값이 없을 때에는 NULL 이라는 특수 값을 사용함. NULL도 atomic으로 취급
    - 널(NULL)
      - ‘적용할 수 없음(inapplicable)’이라는 의미
      - ‘알려지지 않음(unknown)’의 의미

## 관계형 데이터 모델의 제약조건 (constraint)

- 제약조건은 모든 릴레이션 인스턴스들이 만족해야 하는 조건임
- 스키마 기반 제약조건: 데이터 모델 스키마에서 DDL을 통해 직접 표현 가능한 조건
  - (1) 도메인 제약 조건(domain constraints)
  - (2) 키 제약조건(key constraints)
  - (3) 널에 대한 제약조건(constraints on NULLs)
  - (4) 엔티티 무결성 제약조건(entity integrity constraints)
  - (5) 참조 무결성 제약조건(referential integrity constraints)

### (1) 도메인 제약 조건(domain constraints)

- 각 애트리뷰트 A의 값은 반드시 A의 도메인 dom(A)에 속하는 원자값이어야 함
  - `VARCHAR` 형으로 선언된 Name 변수에는 정수형 `Integer` 값이 올 수 없는 경우를 의미

### (2) 키 제약조건(key constraints)

- 키 : 튜플을 유일하게 식별할 수 있는 애트리뷰트 집합
- 릴레이션은 튜플의 집합으로 정의되므로, 모든 원소는 중복되어서는 안 됨
- 어떤 두 튜플도 릴레이션의 모든 애트리뷰트에 대해 같은 값들의 조합을 가질 수 없음<br><br>
- 슈퍼 키 (super key)
  - 유일성(uniqueness)은 만족하지만 최소성(minimality)이 만족되는 않는 애트리뷰트의 집합
  - 키(key)를 포함하는 모든 속성의 집합
- 기본 키 (primary key)
  - 후보 키(candidate key) 중에서 데이타베이스 설계자가 지정한 하나의 키
  - 각 튜플에 대한 기본키 값은 항상 유효(no NULL value)
- 대체 키 (alternate key)
  - 후보키 중에 기본키를 제외한 나머지 후보키
- 슈퍼키(superkey), 후보키(candidate key), 기본키(PK, primary key)
  - 튜플을 식별할 수 있으면 모두 슈퍼키가 될 수 있음

### (3) NULL에 대한 제약조건(constraints on NULLs)

- 애트리뷰트 값으로 널을 허용하지 않는 경우, 애트리뷰트는 널을 가질 수 없음

### (4) 엔티티 무결성 제약조건(entity integrity constraints)

- 삽입: 기본키 값이 같으면 삽입이 금지됨
- 수정: 기본키 값이 같거나 NULL로도 수정이 금지됨
- 삭제: 특별한 확인이 필요하지 않으며 즉시 수행함

### (5) 참조 무결성 제약조건(referential integrity constraints)

- 한 릴레이션에 있는 튜플이 다른 릴레이션에 있는 튜플을 참조하려면 반드시 참조되는 튜플이 그 릴레이션 내에 존재해야 함
- 하나의 릴레이션 R에서 속성 F의 값으로 다른 릴레이션 S의 기본키 P값을 참조하는 경우에 R과 S는 참조 무결성 제약 조건을 가진다고 함 (**F는 NULL을 가질 수 있음**)
- t1[F] = t2[P]이면 R의 튜플 t1이 S의 튜플 t2를 참조(reference)한다고 하며, F를 외래키(foreign key)라고 부름
  - R을 참조한(referencing) 릴레이션, S를 참조된(referenced) 릴레이션이라고 부름
- 다른 제약조건과 달리 참조 무결성은 두 릴레이션에 대한 제약조건임<br><br>
- 부모릴레이션에 삽입
  - 정상적으로 진행됨
- 자식릴레이션에 삽입
  - 참조받는 테이블에 외래키 값이 없으므로 삽입 금지
- 부모릴레이션의 삭제
  - 참조하는 테이블을 같이 삭제할 수 있어서 금지하거나 추가작업이 필요
- 자식릴레이션의 삭제
  - 바로 삭제 가능함
- 수정
  - 삭제와 삽입의 연속 수행으로 각 삭제와 삽입의 제약을 고려하여 진행됨

---

## Source

1. **Fundamentals of Database Systems 6th Edition** by Ramez Elmasri, Shamkant B. Navathe.
2. **데이터베이스 시스템 (Database System Concepts) 6th Edition** by Abranham Silberschatz, Henry F.Korth, S.Sudarchan, 김형주 역.
