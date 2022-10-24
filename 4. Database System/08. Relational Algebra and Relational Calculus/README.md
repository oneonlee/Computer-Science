- [관계 대수 (Relational Algebra)](#관계-대수-relational-algebra)
- [관계 해석 (Relational Calculus)](#관계-해석-relational-calculus)
- [문제 미리보기](#문제-미리보기)

---

# Relational Algebra and Relational Calculus

- 연산과 데이타 언어
  - 연산 : 시스템 입장
  - 데이타 언어 : 사용자 입장
- 관계 데이타 언어
  - 관계 대수(relational algebra)
    - 절차 언어 : how + what
  - 관계해석(relational calculus)
    - 비 절차 언어 : what
    - 투플 관계해석
    - 도메인 관계해석
- 데이터베이스에서 관계 해석과 관계 대수는 표현이나 기능 면에서 동등
  - relationally complete
  - complete set : {σ, Π, ∪, -, ×}

| 구분 | 관계대수                       | 관계해석                                                          |
| ---- | ------------------------------ | ----------------------------------------------------------------- |
| 특징 | 절차적 언어(순서/과정 명시)    | Predicate Calculus 기반<br> 비절차적 언어(계산수식의 유연적 사용) |
| 목적 | How                            | What                                                              |
| 구분 | 순수관계연산자, 일반집합연산자 | 튜플 관계해석, 도메인 관계해석                                    |

- 관계 대수
  - 관계형 데이터베이스에서 원하는 정보와 그 정보를 검색하기 위해서 어떻게 유도하는가를 기술하는 절차적인 언어
  - 릴레이션을 처리하기 위해 연산자와 연산규칙을 제공하는 언어로 피연산자가 릴레이션이고 결과도 릴레이션임
  - 연산자로는 순수 관계 연산자와 일반 집합 연산자가 있음
  - 질의에 대한 해를 구하기 위해 수행해야 할 연산의 순서를 명시함
- 관계 해석
  - 수학의 Predicate Calculus에 기반을 두고 relational database를 위해 제안
  - 관계해석은 관계 데이터의 연산을 표현하는 방법으로, 원하는 정보를 정의할 때는 계산 수식을 사용
  - 관계해석은 원하는 정보가 무엇(What)이라는 것만 정의하는 비절차적 특성을 지님
  - 튜플 관계해석과 도메인 관계해석이 있음
- 기본적으로 관계해석과 관계대수는 관계 데이터베이스를 처리하는 기능과 능력면에서 동등하며 관계 대수로 표현한 식은 관계해석으로 표현할 수 있다.

## 관계 대수 (Relational Algebra)

- 릴레이션을 처리하기 위한 연산의 집합
  - 릴레이션 : 투플의 집합
- 기본 연산
  - 순수 관계 연산자 (relational operators)
    - 셀렉트(SELECT,  )
    - 프로젝트(PROJECT, Π )
    - 조인(JOIN, ⋈ )
    - 디비전(DIVISION, ÷)
  - 일반 집합 연산자 (set operators)
    - 합집합(UNION, ∪)
    - 교집합(INTERSECT, ∩)
    - 차집합(DIFFERENCE, -)
    - 카티션 프로덕트(CARTESIAN PRODUCT, ×)
- 폐쇄 성질 (closure property)
  - 피연산자와 연산 결과가 모두 릴레이션
  - 중첩(nested)된 수식의 표현이 가능

## 관계 해석 (Relational Calculus)

- “어떻게 검색할 것인가” 보다 “**무엇**을 검색할 것인가” 만을 기술하는 선언적 표현법을 사용하는 비절차적 질의어
- SQL을 포함한 많은 상업용 관계 언어들이 관계 해석에 기반을 두고 있음
- 투플 관계 해석(tuple relational calculus)과 도메인 관계 해석 (domain relational calculus)으로
  구분됨
- 관계 대수와의 차이점
  - 관계 해석은 하나의 선언적(declarative) 해석식으로 검색 질의를 명시하며, 비절차적인 언어임
  - 관계 대수에서는 연산들을 순차적으로 사용하므로 절차적인 성질을 가짐
  - 두 언어의 표현력(expressive power)은 동등함
- 관계적 완전성(relationally completeness)
  - 어떤 관계 질의어 L이 있을 때, L이 관계 해석(또는 관계 대수)으로 표현 가능한 어떤 질의도 표현할 수 있으면 L은 “관계적으로 완전(relationally complete)하다”라고 한다.
  - 대부분의 관계 질의어들은 관계적으로 완전(해야)하며, 집단 함수(aggregate functions), 그룹화(grouping), 순서화(ordering) 등의 연산들을 제공하므로 관계 해석보다 표현력이 강해진다.

## 문제 미리보기

### (2017년 제1회 정보처리기사 필기 기출문제 1번)

- 다음 관계대수 중 순수 관계연산자가 아닌 것은? ①
  - ① 차집합 (difference)
  - ② 프로젝트 (project)
  - ③ 조인 (join)
  - ④ 디비전 (division)
- [설명] 순수 관계연산자는 관계 데이터베이스에 적용할 수 있도록 특별히 개발한 관계연산자로 Select, Project, Join, Division이 있다.

### (2017 제2회 정보처리기사 필기 기출문제 2번)

- 조건을 만족하는 릴레이션의 수평적 부분집합으로 구성하며, 연산자의 기호는 그리스 문자 시그마(σ)를 사용하는 관계대수 연산은? ①
  - ① Select
  - ② Project
  - ③ Join
  - ④ Division
- [설명] 각 관계대수 연산자는 아래와 같다.
- ① Select : σ ② Project : π ③ Join : ⋈ ④ Division : ÷

### (2017 제2회 정보처리기사 필기 기출문제 5번)

- 관계 해석에 대한 설명으로 틀린 것은? ②
  - ① 튜플 관계 해석과 도메인 관계 해석이 있다.
  - ② 질의에 대한 해를 구하기 위해 수행해야 할 연산의 순서를 명시해야 하는 절차적인 언어이다.
  - ③ 릴레이션을 정의하는 방법을 제공한다.
  - ④ 수학의 predicate calculus에 기반을 두고 있다.
- [설명] 관계 해석은 비절차적인 언어로 ②의 절차적인 언어와 거리가 멀다.

---

## Source

1. **Fundamentals of Database Systems 7th Edition** by Ramez Elmasri, Shamkant B. Navathe.
