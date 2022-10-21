1. [Basic SQL](#basic-sql)
2. [Practice](#basic-sql-practice)

---

# Basic SQL

- [SQL의 제약 조건 지정](#sql의-제약-조건-지정)
- [SQL에서의 기본 검색 질의](#sql에서의-기본-검색-질의)
- [Join 연산의 종류](#join의-종류)
- [SQL에서의 INSERT, DELETE, UPDATE 구문]
- Additional Features of SQL
- [SQL에서의 집합 연산](#sql에서의-집합-연산)
- [문자열에 대한 비교](#문자열에-대한-비교)
- [질의 결과의 정렬](#질의-결과의-정렬)
- [SQL에서의 `INSERT`, `DELETE`, `UPDATE` 구문](#sql에서의-insert-delete-update-구문)
  - [`INSERT INTO VALUE`](#insert-into-value)
  - [`SELECT와` 결합된 `INSERT` 명령](#select와-결합된-insert-명령)
  - [`DELETE` 문](#delete-문)
  - [`UPDATE` 문](#update-문)

## SQL의 제약 조건 지정

### NOT NULL, DEFAULT

속성에서의 `NOT NULL` 제약 조건은 그 속성에 대해 NULL 값이 허락되지 않음을 명시한다. 달리 말하면, 제약조건은 그 속성의 도메인에서 NULL 값을 제외시킨다.

- 기본적으로 PK를 제외한 모든 애트리뷰트는 NULL을 허용함
  - FK도 NULL 값을 가질 수 있음
  - PK 속성들은 NULL 값을 갖지 않고 유일함
- `NOT NULL` 제약조건을 지정하여 애트리뷰트에 NULL 값을 허용하지 않을 수도 있음
  - ```sql
     CREATE TABLE DEPARTMENT (DNUMBER INT NOT NULL, ... );
    ```
- `DEFAULT` 문을 이용하여 애트리뷰트의 디폴트 값을 명시
  - ```sql
     CREATE TABLE EMPLOYEE (DNO INT DEFAULT 1, ... );
    ```

## SQL에서의 기본 검색 질의

SQL 표현의 기본 구조는 `SELECT, FROM, WHERE`의 세 개의 절로 이루어진다. 질의는 `FROM` 절에 나열된 릴레이션들을 입력으로 받고, `WHERE`과 `SELECT` 절에 명시된 동작을 수행해 결과로 릴레이션을 만들어 낸다.

- SQL은 SQL 표현의 결과에서 뿐만 아니라 릴레이션에도 중복을 허용한다.
  - 중복이 제거되도록 하고 싶은 경우에는 `SELECT` 뒤에 `DISTINCT`라는 키워드를 삽입한다.
  - `DISTINCT`는 질의 결과에서 유일한 튜플들만 남기라는 의미의 키워드임
    - 만약 `SELECT DISTINCT DEPT_NAME, SALARY` 구문이면, SALARY는 `DISTINCT` 효과를 받지 않고, DEPT_NAME에서 겹치는 것들중 먼저 나온 튜플만 출력된다.

## JOIN의 종류

JOIN (조인)이란?

> 두 개 이상의 테이블이나 데이터베이스를 연결하여 하나로 만들고, 데이터를 검색하는 방법

![](https://pbs.twimg.com/media/DY1QkzxW4AAsTYg?format=jpg&name=medium)

1. [Inner Join](#inner-join)
   - [Equi Join](#equi-join)
   - [Natural Join](#natural-join)
2. [Outer Join](#outer-join)
   - [Left Outer Join](#left-outer-join)
   - [Right Outer Join](#right-outer-join)
   - [Full Outer Join](#full-outer-join)
3. [Cross Join](#cross-join)
4. [Self Join](#self-join)
5. [Anti Join](#anti-join)
6. [Semi Join](#semi-join)

### Inner Join

- 교집합으로, 기준 테이블과 조인할 테이블의 중복된 값을 보여준다.

![](https://www.codeproject.com/KB/database/Visual_SQL_Joins/INNER_JOIN.png)

```sql
SELECT <select_list>
FROM Table_A A
INNER JOIN Table_B B
ON A.Key = B.Key
```

- 문법 1 : 명시적 조인 표현 (Explicit Notation)
  - 테이블에 조인을 하라는 것을 지정하기 위해 'JOIN' 키워드를 사용하고 ON의 키워드를 조인에 대한 구문을 지정하는데 사용한다.
  - ```sql
     SELECT * FROM EMPLOYEE
     INNER JOIN DEPARTMENT
     ON EMPLOYEE.DepartmentID = DEPARTMENT.DepartmentID;
    ```
- 문법 2 : 암시적 조인 표현 (Implicit Notation)
  - SELECT 구문의 FROM절에서 콤마(`,`)를 사용하여 단순히 조인을 위한 여러 테이블을 나열한다.
  - ```sql
    SELECT * FROM EMPLOYEE, DEPARTMENT
    WHERE EMPLOYEE.DepartmentID = DEPARTMENT.DepartmentID;
    ```

#### Equi Join

- EQUAL 연산자(=)를 사용해서 Equi Join이라고 한다. WHERE 절에 기술되는 JOIN 조건을 검사해서 양쪽 테이블에 같은 조건의 값이 존재할 경우 해당 데이터를 가져오는 조인 방법이다.

#### Natural Join

- Natural Join은 Equi Join의 결과에서 중복되는 속성(동일한 이름과 타입)을 제거한 릴레이션이다.
  - 동일한 이름을 갖는 칼럼이 있지만, 데이터 타입이 다르면 에러가 발생한다.
- 조인 조건이 필요 없다.

### Outer Join

Outer Join이란 조인 조건에서 동일한 값이 없는 행도 반환할 때 사용한다.

#### Left Outer Join

![](https://www.codeproject.com/KB/database/Visual_SQL_Joins/LEFT_JOIN.png)

- 기준테이블값과 조인테이블과 중복된 값을 보여준다.
- 왼쪽테이블 기준으로 JOIN을 한다고 생각하면 편하다.
- 매칭되는 데이터가 없는 경우 NULL을 표시한다.

```sql
SELECT <select_list>
FROM Table_A A
LEFT JOIN Table_B B
ON A.Key = B.Key
```

#### Right Outer Join

![](https://www.codeproject.com/KB/database/Visual_SQL_Joins/RIGHT_JOIN.png)

- LEFT OUTER JOIN과는 반대로 오른쪽 테이블 기준으로 JOIN하는 것이다. LEFT의 반대 버전.
- 매칭되는 데이터가 없는 경우 NULL을 표시한다.

```sql
SELECT <select_list>
FROM Table_A A
RIGHT JOIN Table_B B
ON A.Key = B.Key
```

#### Full Outer Join

![](https://www.codeproject.com/KB/database/Visual_SQL_Joins/FULL_OUTER_JOIN.png)

- 합집합을 말한다. A와 B 테이블의 모든 데이터가 검색된다. 매칭되는 데이터가 없는 경우 NULL을 표시한다.
- MySQL에서는 Full Join을 지원하지 않지만, UNION 구문으로 구현할 수 있다.

```sql
SELECT <select_list>
FROM Table_A A
FULL OUTER JOIN Table_B B
ON A.Key = B.Key
```

### Cross Join

![](https://camo.githubusercontent.com/c8170fd119eac82de056d7b1659824b1d398627fa09cccb70553becd4906d146/68747470733a2f2f696d67312e6461756d63646e2e6e65742f7468756d622f523132383078302f3f73636f64653d6d746973746f72793226666e616d653d687474702533412532462532466366696c6531302e75662e746973746f72792e636f6d253246696d61676525324639393346344534343541384132443238314143363642)

- Cross Join은 모든 경우의 수를 전부 표현해주는 방식이다.
- Cartesian Product(카디션 곱)이라고도 하며 조인되는 두 테이블에서 곱집합을 반환한다.
  - 예를 들어 m열을 가진 테이블과 n열을 가진 테이블이 교차 조인되면 m\*n 개의 열을 생성한다.

```sql
SELECT
A.NAME, B.AGE
FROM TABLE_A A, TABLE_A B
```

### Self Join

![](https://camo.githubusercontent.com/3600303a038c6cc6f6189738e96de0f791673b542f84c1895afa9b32a4fb6208/68747470733a2f2f696d67312e6461756d63646e2e6e65742f7468756d622f523132383078302f3f73636f64653d6d746973746f72793226666e616d653d687474702533412532462532466366696c6532352e75662e746973746f72792e636f6d253246696d61676525324639393334314433333541384133363344303631344538)

- Self Join은 자기 자신과 자기 자신을 조인하는 것으로, 하나의 테이블을 여러번 복사해서 조인한다고 생각하면 편하다. 같은 테이블을 사용하기 때문에 테이블에 반드시 별명을 붙여야한다.
  - 명령어가 따로 있는게 아니라 outer join이던 inner join이던 자기 자신의 테이블과 조인할 경우 SELF JOIN이라고 생각하면 된다.
- 자신이 가지고 있는 칼럼을 다양하게 변형시켜 활용할 경우에 자주 사용된다.

### Anti Join

- Anti Join은 서브 쿼리 결과에는 없는 메인 쿼리 결과 데이터만 추출하는 조인이다. (Semi Join과 반대)
  - 한쪽 테이블에만 있는 데이터를 추출한다.
  - `NOT IN`이나 `NOT EXISTS` 연산자를 사용한다.

```sql
SELECT *
FROM employee a, department b WHERE a.dno = b.dnumber AND a.dno
NOT IN
      ( SELECT dnumber
      FROM department
      WHERE mgr_ssn IS NULL) ;
```

### Semi Join

- Semi Join은 서브 쿼리 결과에서 존재하는 메인 쿼리 결과 데이터만 추출하는 조인이다. (Anti Join과 반대)
  - `IN`이나 `EXISTS` 연산자를 사용한다.

```sql
SELECT *
FROM employee a, department b WHERE a.dno = b.dnumber AND a.dno
IN
 ( SELECT dnumber
   FROM department
   WHERE mgr_ssn IS NOT NULL ) ;
```

## SQL에서의 집합 연산

- 합집합(`UNION`), 차집합(`EXCEPT`), 교집합(`INTERSECT`)
  - 릴레이션에 대한 집합 연산의 결과는 튜플들의 다중집합임
  - 참고 : `UNION` 연산자는 기본적으로 고유한(distinct) 값만 선택한다.
    중복된 값을 허용하려면 `UNION ALL`을 사용해야한다.
- 다중집합 연산: `UNION ALL`, `EXCEPT ALL`, `INTERSECT ALL`
  - 연산 결과는 중복을 제거하지 않은 다중집합임

## 문자열에 대한 비교

- SQL은 `LIKE` 비교 연산자를 사용하여 문자열(혹은 부분 문자열)에 대해 비교조건을 적용할 수 있다.
- 부분 문자열을 표현할 때 `%`는 임의의 개수의 문자를 의미하고, `_`는 임의의 한 문자를 의미한다.

## 질의 결과의 정렬

- `ORDER BY` 절
  - 하나 이상의 애트리뷰트 값 순서로 질의 결과 튜플을 정렬
    - e.g., `ORDER BY DNAME DESC, LNAME ASC, FNAME ASC`
  - 키워드 `DESC`: 내림차순으로 정렬 – Descending
  - 키워드 `ASC`: 오름차순 정렬 – Ascending
  - Default 정렬은 오름차순(ASC)임

## SQL에서의 `INSERT`, `DELETE`, `UPDATE` 구문

### `INSERT INTO VALUE`

- INSERT문으로 릴레이션에 튜플 하나를 추가
  - 삽입하는 튜플 값은 CREATE TABLE 명령에서 지정한 애트리뷰트 순서와 동일하게 지정해야 함
    - ```sql
       INSERT INTO EMPLOYEE
       VALUES (‘Richard’,‘K’,‘Marini’,‘653298653’,’30-DEC-52’,
          ’98 Oak Forest, Katy, TX’,‘M’,37000,‘987654321’,4) ;
      ```
  - 값들의 순서를 애트리뷰트 순서와 다르게 지정하려면 INSERT 문장에서 애트리뷰트 이름을 명시해야 함
    - ```sql
       INSERT INTO EMPLOYEE (FNAME, LNAME, DNO, SSN)
       VALUES (FNAME=‘Richard’, LNAME=‘Marini’,DNO= 4, SSN=‘653298653’) ;
      ```
    - 이름을 명시하지 않은 애트리뷰트들은 NULL이나 DEFAULT 값을 가짐
  - 무결성 조건
    - DDL에서 지정한 무결성 제약조건을 만족해야 함
  - 그러나 DBMS에 따라서 효율성 때문에 일부 제약조건들을 지원하지 않을 수 있음

### `SELECT와` 결합된 `INSERT` 명령

- 질의의 결과로 생성된 다중 튜플을 또 다른 릴레이션에 삽입하는 경우에 SELECT와 INSERT가 결합된 문장을 사용함

```sql
CREATE TABLE WORKS_ON_INFO
(  EMP_NAME       VARCHAR(15),
   PROJ_NAME      VARCHAR(15),
   HOURS_PER_WEEK DECIMAL(3,1) );
```

```sql
INSERT INTO WORKS_ON_INFO (EMP_NAME, PROJ_NAME, HOURS_PER_WEEK)
SELECT E.LNAME, P.PNAME, W.HOURS
FROM PROJECT P, WORKS_ON W, EMPLOYEE E
WHERE P.PNUMBER=W.PNO AND W.ESSN=E.SSN;
```

### `DELETE` 문

- DELETE 명령은 릴레이션에서 튜플(들)을 제거하는 명령이다.
  - 삭제할 튜플에 대한 조건은 WHERE 절에서 명시한다.
  - WHERE 절을 생략한 경우에는 테이블 내의 모든 튜플을 삭제하며, 테이블은 데이터베이스 내에서 빈 테이블로 남게 된다.
    - ```sql
       DELETE FROM EMPLOYEE;
      ```
  - 한번의 DELETE 명령으로 WHERE 절의 조건을 만족하는 튜플을 모두 삭제함
    - ```sql
       DELETE FROM EMPLOYEE WHERE LNAME=‘Brown’ ;
      ```
    - ```sql
       DELETE FROM EMPLOYEE WHERE SSN=‘123456789’ ;
      ```
    - ```sql
       DELETE FROM EMPLOYEE WHERE DNO=5;
      ```

### `UPDATE` 문

- UPDATE 명령은 튜플의 애트리뷰트 값을 수정하기 위해 사용한다.
  - WHERE 절은 한 릴레이션에서 수정할 튜플을 선택하는데 사용된다.
  - SET절은 변경할 애트리뷰트와 그들의 새로운 값을 명시한다.

---

## Basic SQL Practice

### Company Database

[Go to Problems](#problems)

```sql
mysql> use company;
Database changed
mysql> show tables;
+-------------------+
| Tables_in_company |
+-------------------+
| DEPARTMENT        |
| DEPENDENT         |
| DEPT_LOCATIONS    |
| EMPLOYEE          |
| PROJECT           |
| WORKS_ON          |
+-------------------+
6 rows in set (0.00 sec)

mysql> desc department;
+----------------+-------------+------+-----+---------+-------+
| Field          | Type        | Null | Key | Default | Extra |
+----------------+-------------+------+-----+---------+-------+
| Dname          | varchar(15) | NO   | UNI | NULL    |       |
| Dnumber        | int         | NO   | PRI | NULL    |       |
| Mgr_ssn        | char(9)     | NO   | MUL | NULL    |       |
| Mgr_start_date | date        | YES  |     | NULL    |       |
+----------------+-------------+------+-----+---------+-------+
4 rows in set (0.00 sec)

mysql> desc dependent;
+----------------+-------------+------+-----+---------+-------+
| Field          | Type        | Null | Key | Default | Extra |
+----------------+-------------+------+-----+---------+-------+
| Essn           | char(9)     | NO   | PRI | NULL    |       |
| Dependent_name | varchar(15) | NO   | PRI | NULL    |       |
| Sex            | char(1)     | YES  |     | NULL    |       |
| Bdate          | date        | YES  |     | NULL    |       |
| Relationship   | varchar(8)  | YES  |     | NULL    |       |
+----------------+-------------+------+-----+---------+-------+
5 rows in set (0.00 sec)

mysql> desc dept_locations;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| Dnumber   | int         | NO   | PRI | NULL    |       |
| Dlocation | varchar(15) | NO   | PRI | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)

mysql> desc employee;
+-----------+--------------+------+-----+---------+-------+
| Field     | Type         | Null | Key | Default | Extra |
+-----------+--------------+------+-----+---------+-------+
| Fname     | varchar(10)  | NO   |     | NULL    |       |
| Minit     | char(1)      | YES  |     | NULL    |       |
| Lname     | varchar(20)  | NO   |     | NULL    |       |
| Ssn       | char(9)      | NO   | PRI | NULL    |       |
| Bdate     | date         | YES  |     | NULL    |       |
| Address   | varchar(30)  | YES  |     | NULL    |       |
| Sex       | char(1)      | YES  |     | NULL    |       |
| Salary    | decimal(5,0) | YES  |     | NULL    |       |
| Super_ssn | char(9)      | YES  | MUL | NULL    |       |
| Dno       | int          | NO   | MUL | NULL    |       |
+-----------+--------------+------+-----+---------+-------+
10 rows in set (0.00 sec)

mysql> desc project;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| Pname     | varchar(15) | NO   | UNI | NULL    |       |
| Pnumber   | int         | NO   | PRI | NULL    |       |
| Plocation | varchar(15) | YES  |     | NULL    |       |
| Dnum      | int         | NO   | MUL | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
4 rows in set (0.00 sec)

mysql> desc works_on;
+-------+--------------+------+-----+---------+-------+
| Field | Type         | Null | Key | Default | Extra |
+-------+--------------+------+-----+---------+-------+
| Essn  | char(9)      | NO   | PRI | NULL    |       |
| Pno   | int          | NO   | PRI | NULL    |       |
| Hours | decimal(3,1) | NO   |     | NULL    |       |
+-------+--------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> select * from department;
+----------------+---------+-----------+----------------+
| Dname          | Dnumber | Mgr_ssn   | Mgr_start_date |
+----------------+---------+-----------+----------------+
| Headquarters   |       1 | 888665555 | 1981-06-19     |
| Administration |       4 | 987654321 | 1995-01-01     |
| Research       |       5 | 333445555 | 1988-05-22     |
+----------------+---------+-----------+----------------+
3 rows in set (0.01 sec)

mysql> select * from dependent;
+-----------+----------------+------+------------+--------------+
| Essn      | Dependent_name | Sex  | Bdate      | Relationship |
+-----------+----------------+------+------------+--------------+
| 123456789 | Alice          | F    | 1988-12-30 | Daughter     |
| 123456789 | Elizabeth      | F    | 1967-05-05 | Spouse       |
| 123456789 | Michael        | M    | 1988-01-04 | Son          |
| 333445555 | Alice          | F    | 1986-04-04 | Daughter     |
| 333445555 | Joy            | F    | 1958-05-03 | Spouse       |
| 333445555 | Theodore       | M    | 1983-10-25 | Son          |
| 987654321 | Abner          | M    | 1942-02-28 | Spouse       |
+-----------+----------------+------+------------+--------------+
7 rows in set (0.00 sec)

mysql> select * from dept_locations;
+---------+-----------+
| Dnumber | Dlocation |
+---------+-----------+
|       1 | Houston   |
|       4 | Stafford  |
|       5 | Bellaire  |
|       5 | Houston   |
|       5 | Sugarland |
+---------+-----------+
5 rows in set (0.00 sec)

mysql> select * from employee;
+----------+-------+---------+-----------+------------+-------------------------+------+--------+-----------+-----+
| Fname    | Minit | Lname   | Ssn       | Bdate      | Address                 | Sex  | Salary | Super_ssn | Dno |
+----------+-------+---------+-----------+------------+-------------------------+------+--------+-----------+-----+
| John     | B     | Smith   | 123456789 | 1965-01-09 | 731 Fondren, Houston TX | M    |  30000 | 333445555 |   5 |
| Franklin | T     | Wong    | 333445555 | 1965-12-08 | 638 Voss, Houston TX    | M    |  40000 | 888665555 |   5 |
| Joyce    | A     | English | 453453453 | 1972-07-31 | 5631 Rice, Houston TX   | F    |  25000 | 333445555 |   5 |
| Ramesh   | K     | Narayan | 666884444 | 1962-09-15 | 975 Fire Oak, Humble TX | M    |  38000 | 333445555 |   5 |
| James    | E     | Borg    | 888665555 | 1937-11-10 | 450 Stone, Houston TX   | M    |  55000 | NULL      |   1 |
| Jennifer | S     | Wallace | 987654321 | 1941-06-20 | 291 Berry, Bellaire TX  | F    |  43000 | 888665555 |   4 |
| Ahmad    | V     | Jabbar  | 987987987 | 1969-03-29 | 980 Dallas, Houston TX  | M    |  25000 | 987654321 |   4 |
| Alicia   | J     | Zelaya  | 999887777 | 1968-01-19 | 3321 Castle, Spring TX  | F    |  25000 | 987654321 |   4 |
+----------+-------+---------+-----------+------------+-------------------------+------+--------+-----------+-----+
8 rows in set (0.01 sec)

mysql> select * from project;
+-----------------+---------+-----------+------+
| Pname           | Pnumber | Plocation | Dnum |
+-----------------+---------+-----------+------+
| ProductX        |       1 | Bellaire  |    5 |
| ProductY        |       2 | Sugarland |    5 |
| ProductZ        |       3 | Houston   |    5 |
| Computerization |      10 | Stafford  |    4 |
| Reorganization  |      20 | Houston   |    1 |
| Newbenefits     |      30 | Stafford  |    4 |
+-----------------+---------+-----------+------+
6 rows in set (0.00 sec)

mysql> select * from works_on;
+-----------+-----+-------+
| Essn      | Pno | Hours |
+-----------+-----+-------+
| 123456789 |   1 |  32.5 |
| 123456789 |   2 |   7.5 |
| 333445555 |   2 |  10.0 |
| 333445555 |   3 |  10.0 |
| 333445555 |  10 |  10.0 |
| 333445555 |  20 |  10.0 |
| 453453453 |   1 |  20.0 |
| 453453453 |   2 |  20.0 |
| 666884444 |   3 |  40.0 |
| 888665555 |  20 |  16.0 |
| 987654321 |  20 |  15.0 |
| 987654321 |  30 |  20.0 |
| 987987987 |  10 |  35.0 |
| 987987987 |  30 |   5.0 |
| 999887777 |  10 |  10.0 |
| 999887777 |  30 |  30.0 |
+-----------+-----+-------+
16 rows in set (0.00 sec)
```

### Problems

1. 성이 'Borg'인 사원(들)의 전체 이름(`Fname`, `Minit`, `Lname`)과 생년월일(`Bdate`)과 주소(`Address`)를 검색하라.
   ```sql
   mysql> select Fname, Minit, Lname, Bdate, Address from employee WHERE Lname='Borg';
   +-------+-------+-------+------------+-----------------------+
   | Fname | Minit | Lname | Bdate      | Address               |
   +-------+-------+-------+------------+-----------------------+
   | James | E     | Borg  | 1937-11-10 | 450 Stone, Houston TX |
   +-------+-------+-------+------------+-----------------------+
   1 row in set (0.00 sec)
   ```
1. 릴레이션 `EMPLOYEE`와 `DEPARTMENT`의 카티션 곱을 검색하라.
   ```sql
   mysql> select * from Employee, Department;
   +----------+-------+---------+-----------+------------+-------------------------+------+--------+-----------+-----+----------------+---------+-----------+----------------+
   | Fname    | Minit | Lname   | Ssn       | Bdate      | Address                 | Sex  | Salary | Super_ssn | Dno | Dname          | Dnumber | Mgr_ssn   | Mgr_start_date |
   +----------+-------+---------+-----------+------------+-------------------------+------+--------+-----------+-----+----------------+---------+-----------+----------------+
   | John     | B     | Smith   | 123456789 | 1965-01-09 | 731 Fondren, Houston TX | M    |  30000 | 333445555 |   5 | Research       |       5 | 333445555 | 1988-05-22     |
   | John     | B     | Smith   | 123456789 | 1965-01-09 | 731 Fondren, Houston TX | M    |  30000 | 333445555 |   5 | Administration |       4 | 987654321 | 1995-01-01     |
   | John     | B     | Smith   | 123456789 | 1965-01-09 | 731 Fondren, Houston TX | M    |  30000 | 333445555 |   5 | Headquarters   |       1 | 888665555 | 1981-06-19     |
   | Franklin | T     | Wong    | 333445555 | 1965-12-08 | 638 Voss, Houston TX    | M    |  40000 | 888665555 |   5 | Research       |       5 | 333445555 | 1988-05-22     |
   | Franklin | T     | Wong    | 333445555 | 1965-12-08 | 638 Voss, Houston TX    | M    |  40000 | 888665555 |   5 | Administration |       4 | 987654321 | 1995-01-01     |
   | Franklin | T     | Wong    | 333445555 | 1965-12-08 | 638 Voss, Houston TX    | M    |  40000 | 888665555 |   5 | Headquarters   |       1 | 888665555 | 1981-06-19     |
   | Joyce    | A     | English | 453453453 | 1972-07-31 | 5631 Rice, Houston TX   | F    |  25000 | 333445555 |   5 | Research       |       5 | 333445555 | 1988-05-22     |
   | Joyce    | A     | English | 453453453 | 1972-07-31 | 5631 Rice, Houston TX   | F    |  25000 | 333445555 |   5 | Administration |       4 | 987654321 | 1995-01-01     |
   | Joyce    | A     | English | 453453453 | 1972-07-31 | 5631 Rice, Houston TX   | F    |  25000 | 333445555 |   5 | Headquarters   |       1 | 888665555 | 1981-06-19     |
   | Ramesh   | K     | Narayan | 666884444 | 1962-09-15 | 975 Fire Oak, Humble TX | M    |  38000 | 333445555 |   5 | Research       |       5 | 333445555 | 1988-05-22     |
   | Ramesh   | K     | Narayan | 666884444 | 1962-09-15 | 975 Fire Oak, Humble TX | M    |  38000 | 333445555 |   5 | Administration |       4 | 987654321 | 1995-01-01     |
   | Ramesh   | K     | Narayan | 666884444 | 1962-09-15 | 975 Fire Oak, Humble TX | M    |  38000 | 333445555 |   5 | Headquarters   |       1 | 888665555 | 1981-06-19     |
   | James    | E     | Borg    | 888665555 | 1937-11-10 | 450 Stone, Houston TX   | M    |  55000 | NULL      |   1 | Research       |       5 | 333445555 | 1988-05-22     |
   | James    | E     | Borg    | 888665555 | 1937-11-10 | 450 Stone, Houston TX   | M    |  55000 | NULL      |   1 | Administration |       4 | 987654321 | 1995-01-01     |
   | James    | E     | Borg    | 888665555 | 1937-11-10 | 450 Stone, Houston TX   | M    |  55000 | NULL      |   1 | Headquarters   |       1 | 888665555 | 1981-06-19     |
   | Jennifer | S     | Wallace | 987654321 | 1941-06-20 | 291 Berry, Bellaire TX  | F    |  43000 | 888665555 |   4 | Research       |       5 | 333445555 | 1988-05-22     |
   | Jennifer | S     | Wallace | 987654321 | 1941-06-20 | 291 Berry, Bellaire TX  | F    |  43000 | 888665555 |   4 | Administration |       4 | 987654321 | 1995-01-01     |
   | Jennifer | S     | Wallace | 987654321 | 1941-06-20 | 291 Berry, Bellaire TX  | F    |  43000 | 888665555 |   4 | Headquarters   |       1 | 888665555 | 1981-06-19     |
   | Ahmad    | V     | Jabbar  | 987987987 | 1969-03-29 | 980 Dallas, Houston TX  | M    |  25000 | 987654321 |   4 | Research       |       5 | 333445555 | 1988-05-22     |
   | Ahmad    | V     | Jabbar  | 987987987 | 1969-03-29 | 980 Dallas, Houston TX  | M    |  25000 | 987654321 |   4 | Administration |       4 | 987654321 | 1995-01-01     |
   | Ahmad    | V     | Jabbar  | 987987987 | 1969-03-29 | 980 Dallas, Houston TX  | M    |  25000 | 987654321 |   4 | Headquarters   |       1 | 888665555 | 1981-06-19     |
   | Alicia   | J     | Zelaya  | 999887777 | 1968-01-19 | 3321 Castle, Spring TX  | F    |  25000 | 987654321 |   4 | Research       |       5 | 333445555 | 1988-05-22     |
   | Alicia   | J     | Zelaya  | 999887777 | 1968-01-19 | 3321 Castle, Spring TX  | F    |  25000 | 987654321 |   4 | Administration |       4 | 987654321 | 1995-01-01     |
   | Alicia   | J     | Zelaya  | 999887777 | 1968-01-19 | 3321 Castle, Spring TX  | F    |  25000 | 987654321 |   4 | Headquarters   |       1 | 888665555 | 1981-06-19     |
   +----------+-------+---------+-----------+------------+-------------------------+------+--------+-----------+-----+----------------+---------+-----------+----------------+
   24 rows in set (0.00 sec)
   ```
1. 모든 사원들의 사번(`SSN`)과 그들이 속한 소속 부서(`DNAME`)들을 모두 검색하라.
   ```sql
   mysql> select Ssn, Dname from employee, department WHERE Dno=Dnumber;
   +-----------+----------------+
   | Ssn       | Dname          |
   +-----------+----------------+
   | 987654321 | Administration |
   | 987987987 | Administration |
   | 999887777 | Administration |
   | 888665555 | Headquarters   |
   | 123456789 | Research       |
   | 333445555 | Research       |
   | 453453453 | Research       |
   | 666884444 | Research       |
   +-----------+----------------+
   8 rows in set (0.00 sec)
   ```
1. `Headquarters` 부서에서 근무하는 모든 사원의 이름(`Fname`, `Lname`)과 주소(`Address`)를 검색하라.
   ```sql
   mysql> select Fname, Lname, Address from employee, department WHERE Dno=Dnumber AND Dname='Headquarters';
   +-------+-------+-----------------------+
   | Fname | Lname | Address               |
   +-------+-------+-----------------------+
   | James | Borg  | 450 Stone, Houston TX |
   +-------+-------+-----------------------+
   1 row in set (0.00 sec)
   ```
1. `Administration` 부서에서 일하는 사원들의 성(`Lname`)과 이름(`Fname`), 그리고 관리자를 시작한 날(`mgr_start_date`)을 검색하라.
   ```sql
   mysql> select Lname, Fname, Mgr_start_date from employee, department WHERE Dno=Dnumber AND Dname='Administration';
   +---------+----------+----------------+
   | Lname   | Fname    | Mgr_start_date |
   +---------+----------+----------------+
   | Wallace | Jennifer | 1995-01-01     |
   | Jabbar  | Ahmad    | 1995-01-01     |
   | Zelaya  | Alicia   | 1995-01-01     |
   +---------+----------+----------------+
   3 rows in set (0.00 sec)
   ```
1. 각 사원에 대해 사원의 이름(`Fname`)과 성(`Lname`), 직속 상사의 이름 (`Fname`)과 성(`Lname`)을 검색하라.

   ```sql
   mysql> select E.Fname, E.Lname, S.Fname, S.Lname from Employee AS E, Employee AS S WHERE E.Super_ssn = S.Ssn;
   +----------+---------+----------+---------+
   | Fname    | Lname   | Fname    | Lname   |
   +----------+---------+----------+---------+
   | John     | Smith   | Franklin | Wong    |
   | Franklin | Wong    | James    | Borg    |
   | Joyce    | English | Franklin | Wong    |
   | Ramesh   | Narayan | Franklin | Wong    |
   | Jennifer | Wallace | James    | Borg    |
   | Ahmad    | Jabbar  | Jennifer | Wallace |
   | Alicia   | Zelaya  | Jennifer | Wallace |
   +----------+---------+----------+---------+
   7 rows in set (0.01 sec)

   mysql> select E.Fname AS Employee_Fname, E.Lname AS Employee_Lname, S.Fname AS Super_Fname, S.Lname AS Super_Lname from Employee AS E, Employee AS S WHERE E.Super_ssn = S.Ssn;
   +----------------+----------------+-------------+-------------+
   | Employee_Fname | Employee_Lname | Super_Fname | Super_Lname |
   +----------------+----------------+-------------+-------------+
   | John           | Smith          | Franklin    | Wong        |
   | Franklin       | Wong           | James       | Borg        |
   | Joyce          | English        | Franklin    | Wong        |
   | Ramesh         | Narayan        | Franklin    | Wong        |
   | Jennifer       | Wallace        | James       | Borg        |
   | Ahmad          | Jabbar         | Jennifer    | Wallace     |
   | Alicia         | Zelaya         | Jennifer    | Wallace     |
   +----------------+----------------+-------------+-------------+
   7 rows in set (0.00 sec)
   ```

1. 'Houston'에 위치한 모든 프로젝트에 대해서 프로젝트 번호(`Pnumber`), 담당 부서 번호(`Dnum`), 부서 관리자의 성(`Lname`), 주소(`Address`), 생년월일 (`Bdate`)을 검색하라.
   ```sql
   mysql> select P.Pnumber, P.Dnum, E.Lname, E.Address, E.Bdate from project as P, employee as E, department as D WHERE P.Plocation='Houston' AND P.Dnum=D.Dnumber AND D.Mgr_ssn = E.Ssn;
   +---------+------+-------+-----------------------+------------+
   | Pnumber | Dnum | Lname | Address               | Bdate      |
   +---------+------+-------+-----------------------+------------+
   |       3 |    5 | Wong  | 638 Voss, Houston TX  | 1965-12-08 |
   |      20 |    1 | Borg  | 450 Stone, Houston TX | 1937-11-10 |
   +---------+------+-------+-----------------------+------------+
   2 rows in set (0.00 sec)
   ```
1. 일반 사원이든 관리자이든 간에 성(`Lname`)이 'Smith'인 사원이 수행하는 프로젝트 번호(`Pnumber`)의 리스트를 검색하라. (hint : `UNION`)
   ```sql
   mysql> (select Pnumber from project, works_on, employee where Pnumber=Pno and Essn=Ssn and Lname='Smith')
      -> UNION
      -> (select Pnumber from project, department, employee where Dnum=Dnumber and Mgr_ssn=Ssn and Lname='Smith');
   +---------+
   | Pnumber |
   +---------+
   |       1 |
   |       2 |
   +---------+
   2 rows in set (0.00 sec)
   ```
1. 주소에 'Houston TX'가 포함되는 모든 사원(`Fname`, `Lname`)을 검색하라.

   ```sql
   mysql> select Fname, Lname from Employee where Address LIKE '%Houston TX%';
   +----------+---------+
   | Fname    | Lname   |
   +----------+---------+
   | John     | Smith   |
   | Franklin | Wong    |
   | Joyce    | English |
   | James    | Borg    |
   | Ahmad    | Jabbar  |
   +----------+---------+
   5 rows in set (0.00 sec)

   mysql> -- 확인 및 검증하기 --
   mysql> select Fname, Lname, Address from Employee where Address LIKE '%Houston TX%';
   +----------+---------+-------------------------+
   | Fname    | Lname   | Address                 |
   +----------+---------+-------------------------+
   | John     | Smith   | 731 Fondren, Houston TX |
   | Franklin | Wong    | 638 Voss, Houston TX    |
   | Joyce    | English | 5631 Rice, Houston TX   |
   | James    | Borg    | 450 Stone, Houston TX   |
   | Ahmad    | Jabbar  | 980 Dallas, Houston TX  |
   +----------+---------+-------------------------+
   5 rows in set (0.00 sec)
   ```

1. 1960년대 태어난 모든 사원의 전체 이름(`Fname`, `Lname`)을 검색하라.

   ```sql
   mysql> select Fname, Lname from employee where Bdate LIKE '196%';
   +----------+---------+
   | Fname    | Lname   |
   +----------+---------+
   | John     | Smith   |
   | Franklin | Wong    |
   | Ramesh   | Narayan |
   | Ahmad    | Jabbar  |
   | Alicia   | Zelaya  |
   +----------+---------+
   5 rows in set (0.00 sec)

   mysql> -- 확인 및 검증하기 --
   mysql> select Fname, Lname, Bdate from employee where Bdate LIKE '196%';
   +----------+---------+------------+
   | Fname    | Lname   | Bdate      |
   +----------+---------+------------+
   | John     | Smith   | 1965-01-09 |
   | Franklin | Wong    | 1965-12-08 |
   | Ramesh   | Narayan | 1962-09-15 |
   | Ahmad    | Jabbar  | 1969-03-29 |
   | Alicia   | Zelaya  | 1968-01-19 |
   +----------+---------+------------+
   5 rows in set (0.01 sec)
   ```

---

## Source

1. **Fundamentals of Database Systems 7th Edition** by Ramez Elmasri, Shamkant B. Navathe.
2. **데이터베이스 시스템 (Database System Concepts) 6th Edition** by Abranham Silberschatz, Henry F.Korth, S.Sudarchan, 김형주 역.
3. [gyoogle GitHub | tech-interview-for-developer/Computer Science/Database/[Database SQL] JOIN.md](https://github.com/gyoogle/tech-interview-for-developer/blob/master/Computer%20Science/Database/%5BDatabase%20SQL%5D%20JOIN.md)
4. [carrot.log | [Database] JOIN의 종류 : INNER, OUTER, CROSS, SELF](https://velog.io/@yanghl98/Database-JOIN)
5. [FRANK'S BLOG | 관계형 데이터베이스에서 조인(join)이란?](https://blog.advenoh.pe.kr/database/%EA%B4%80%EA%B3%84%ED%98%95-%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%B2%A0%EC%9D%B4%EC%8A%A4%EC%97%90%EC%84%9C-%EC%A1%B0%EC%9D%B8-join%EC%9D%B4%EB%9E%80/)
6. [C.L. Moffatt | Visual Representation of SQL Joins](https://www.codeproject.com/Articles/33052/Visual-Representation-of-SQL-Joins)
7. https://swingswing.tistory.com/12
8. [거꾸로 바라본 세상 | [SQL] Join(조인)](https://clairdelunes.tistory.com/22)
