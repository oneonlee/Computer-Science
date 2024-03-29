1. [Complex SQL](#complex-sql)
2. [Practice](#complex-sql-practice)

---

# Complex SQL

- [NULL 값을 포함한 비교](#null-값을-포함한-비교)
- [중첩 질의(nested query)와 집합 비교](#중첩-질의nested-query와-집합-비교)
- [상관 중첩 질의 (Correlated Nested Query)](#상관-중첩-질의-correlated-nested-query)
- [SQL의 EXISTS 함수와 UNIQUE 함수](#sql의-exists-함수와-unique-함수)
- [SQL에서 명시적 집합과 애트리뷰트의 재명명](#sql에서-명시적-집합과-애트리뷰트의-재명명)
- [집계 함수(Aggregate functions)](#집계-함수aggregate-functions)
- [Grouping: Group by와 Having 절](#grouping-group-by와-having-절)
- [SELECT문 요약](#select문-요약)

---

## NULL 값을 포함한 비교

- 애트리뷰트의 값이 NULL인지 검사하는 연산자
  - `IS NULL`
  - `IS NOT NULL`

## 중첩 질의(nested query)와 집합 비교

### 중첩 질의

- 다른 질의의 WHERE 절 내에 완전한 SELECT 질의가 나타나는 형태
- 외부 질의와 내부 질의로 구분됨

### 비교 연산자 `IN`

- 외부 질의의 한 튜플에 대하여, 이 튜플이 임의의 튜플 집합의 원소가 되는지 비교하는 연산이다.
- 집합에 있어서 원소 여부를 확인하는 '∈'와 동일한 기능을 한다.

### `= ALL` 연산자

- 하나의 값 v가 집합 V내의 모든 값들과 같으면 참이 된다.
- 집합에서 '∀'에 해당한다.
- `ALL` 앞에 `=` 대신 `>`, `>=`, `<`, `<=`를 사용할 수도 있다.
  - e.g., `= ALL`, `>= ALL`, `< ALL` ...

### `= ANY`(`= SOME`) 연산자

- 하나의 값 v가 집합 V내의 어떤 하나의 값과 같으면 참이 된다.
- 집합에서 '∃'에 해당한다.
- `ANY`(`SOME`) 앞에 `=` 대신 `>`, `>=`, `<`, `<=`를 사용할 수도 있다.

## 상관 중첩 질의 (Correlated Nested Query)

- 내부 질의의 WHERE 절에 있는 조건에서, 외부 질의에 선언된 릴레이션의 일부 애트리뷰트를 참조하는 경우에 두 질의를 상관된 질의(Correlated Query)라고 한다.
- 이러한 상관 중첩질의는 비중첩 질의로 변환할 수 있다.
  - 한 질의는 항상 단일 블록 질의로 변환할 수 있음

## SQL의 EXISTS 함수와 UNIQUE 함수

### EXISTS 함수

- 상관된 중첩질의에서 내부 질의의 결과가 공집합인가를 검사함
- `EXISTS(Q)`: 질의 `Q`의 결과에 최소한 한 개의 투플이 있다면 참을 반환

## SQL에서 명시적 집합과 애트리뷰트의 재명명

- `WHERE` 절에 값들의 명시적 집합 사용 가능
  - e.g., `SELECT DISTINCT ESSN FROM WORKS_ON WHERE PNO IN (1, 2, 3);`
- 질의 결과 애트리뷰트의 재명명
  - 결과에 나타나는 애트리뷰트의 이름은 키워드 `AS`를 사용하여 원하는 새 이름으로 재명명할 수
    있음
  - `AS`를 사용하여 애트리뷰트와 릴레이션에 별명을 붙일 수 있음

## 집계 함수(Aggregate functions)

- SQL에서는 COUNT, SUM, MAX, MIN, AVG 등의 집계 (or 내장) 함수를 제공함
- COUNT 함수는 질의에서 투플이나 값의 개수를 반환함
- SUM, MAX, MIN, AVG 함수는 수치 값들의 다중집합에 적용되며, 각각 합, 최대값, 최소
  값, 평균값을 반환함
- 집계 함수가 NULL을 대하는 태도는 "투명인간"이다.
  - DISTINCT 키워드를 사용해도 NULL은 투명인간 취급.

## Grouping: Group by와 Having 절

- 그룹화 (grouping)

  - 특정 애트리뷰트(들)의 값이 같은 투플들을 모아서 그룹을 생성하고, 이들 그룹에 대하여 집단함수를 적용함
  - 이 때, 특정 애트리뷰트들을 **그룹화 애트리뷰트**라 하며, SQL의 **GROUP BY절**에 지정함
  - 대부분의 경우, SELECT절에 그룹화 애트리뷰트(들)를 지정하여, 그 값과 그 값에 해당하는 투플 그룹에 **집단함수**를 적용한 결과를 동시에 반환함

- Having: GROUP BY 절에 대한 조건을 제시할 수 있음

---

## Complex SQL Practice

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

1. 'Newbenefits' 프로젝트에 참여하는 모든 사원의 급여를 10% 올린 경우의 급여를 제시하라. (`Fname`, `Lname`, `Increased_sal`)
   ```sql
   mysql> select Fname, Lname, Salary*1.1 as Increased_sal from project, works_on, employee where Pname='Newbenefits' and Pnumber=Pno and Essn=Ssn;
   +----------+---------+---------------+
   | Fname    | Lname   | Increased_sal |
   +----------+---------+---------------+
   | Jennifer | Wallace |       47300.0 |
   | Ahmad    | Jabbar  |       27500.0 |
   | Alicia   | Zelaya  |       27500.0 |
   +----------+---------+---------------+
   3 rows in set (0.00 sec)
   ```
2. 급여가 30,000달러에서 40,000달러 사이에 있는 5번 부서의 모든 사원을 검색하라.
   ```sql
   mysql> select * from employee WHERE (Salary BETWEEN 30000 AND 40000) AND Dno=5;
   +----------+-------+---------+-----------+------------+-------------------------+------+--------+-----------+-----+
   | Fname    | Minit | Lname   | Ssn       | Bdate      | Address                 | Sex  | Salary | Super_ssn | Dno |
   +----------+-------+---------+-----------+------------+-------------------------+------+--------+-----------+-----+
   | John     | B     | Smith   | 123456789 | 1965-01-09 | 731 Fondren, Houston TX | M    |  30000 | 333445555 |   5 |
   | Franklin | T     | Wong    | 333445555 | 1965-12-08 | 638 Voss, Houston TX    | M    |  40000 | 888665555 |   5 |
   | Ramesh   | K     | Narayan | 666884444 | 1962-09-15 | 975 Fire Oak, Humble TX | M    |  38000 | 333445555 |   5 |
   +----------+-------+---------+-----------+------------+-------------------------+------+--------+-----------+-----+
   3 rows in set (0.00 sec)
   ```
   ```sql
   mysql> select * from employee WHERE Salary>=30000 AND Salary<=40000 AND Dno=5;
   +----------+-------+---------+-----------+------------+-------------------------+------+--------+-----------+-----+
   | Fname    | Minit | Lname   | Ssn       | Bdate      | Address                 | Sex  | Salary | Super_ssn | Dno |
   +----------+-------+---------+-----------+------------+-------------------------+------+--------+-----------+-----+
   | John     | B     | Smith   | 123456789 | 1965-01-09 | 731 Fondren, Houston TX | M    |  30000 | 333445555 |   5 |
   | Franklin | T     | Wong    | 333445555 | 1965-12-08 | 638 Voss, Houston TX    | M    |  40000 | 888665555 |   5 |
   | Ramesh   | K     | Narayan | 666884444 | 1962-09-15 | 975 Fire Oak, Humble TX | M    |  38000 | 333445555 |   5 |
   +----------+-------+---------+-----------+------------+-------------------------+------+--------+-----------+-----+
   3 rows in set (0.00 sec)
   ```
3. 모든 사원의 (1) 급여(높은 순서) (2) 생년월일(나이가 많은 순서)을 제시하라.
   ```sql
   mysql> select Salary, Bdate from employee ORDER BY Salary DESC, Bdate ASC;
   +--------+------------+
   | Salary | Bdate      |
   +--------+------------+
   |  55000 | 1937-11-10 |
   |  43000 | 1941-06-20 |
   |  40000 | 1965-12-08 |
   |  38000 | 1962-09-15 |
   |  30000 | 1965-01-09 |
   |  25000 | 1968-01-19 |
   |  25000 | 1969-03-29 |
   |  25000 | 1972-07-31 |
   +--------+------------+
   8 rows in set (0.00 sec)
   ```
4. 상사가 없는 모든 사원의 이름(`Fname`, `Lname`)을 검색하라.
   ```sql
   mysql> select Fname, Lname from employee where Super_ssn IS NULL;
   +-------+-------+
   | Fname | Lname |
   +-------+-------+
   | James | Borg  |
   +-------+-------+
   1 row in set (0.00 sec)
   ```
5. 부양가족의 성별(`Sex`)과 사원의 성별이 같은 사원의 이름(`Fname`, `Lname`)을 검색하라.
   ```sql
   mysql> select D.Sex, E.Fname, E.Lname from dependent as D, employee as E where D.Essn=E.Ssn and D.Sex=E.Sex;
   +------+----------+-------+
   | Sex  | Fname    | Lname |
   +------+----------+-------+
   | M    | John     | Smith |
   | M    | Franklin | Wong  |
   +------+----------+-------+
   2 rows in set (0.00 sec)
   ```
   ```sql
   mysql> select D.Sex, E.Fname, E.Lname from dependent AS D, employee as E where E.Ssn IN (select Essn where D.Sex=E.Sex);
   +------+----------+-------+
   | Sex  | Fname    | Lname |
   +------+----------+-------+
   | M    | John     | Smith |
   | M    | Franklin | Wong  |
   +------+----------+-------+
   2 rows in set (0.00 sec)
   ```
   ```sql
   mysql> select D.Sex, E.Fname, E.Lname from dependent AS D, employee as E where EXISTS (select * where D.Essn=E.Ssn and D.Sex=E.Sex);
   +------+----------+-------+
   | Sex  | Fname    | Lname |
   +------+----------+-------+
   | M    | John     | Smith |
   | M    | Franklin | Wong  |
   +------+----------+-------+
   2 rows in set (0.00 sec)
   ```
6. 부양가족이 없는 종업원들의 이름(`Fname`, `Lname`)을 검색하라.
   ```sql
   mysql> select Fname, Lname from employee where NOT EXISTS (select * from dependent where Ssn=Essn);
   +--------+---------+
   | Fname  | Lname   |
   +--------+---------+
   | Joyce  | English |
   | Ramesh | Narayan |
   | James  | Borg    |
   | Ahmad  | Jabbar  |
   | Alicia | Zelaya  |
   +--------+---------+
   5 rows in set (0.00 sec)
   ```
7. 프로젝트 번호 1,2,3에서 일하는 사원의 주민등록번호(`Essn`)를 검색하라.
   ```sql
   mysql> select Distinct(Essn) from works_on WHERE Pno<=3;
   +-----------+
   | Essn      |
   +-----------+
   | 123456789 |
   | 453453453 |
   | 333445555 |
   | 666884444 |
   +-----------+
   4 rows in set (0.01 sec)
   ```
   ```sql
   mysql> select Distinct(Essn) from works_on WHERE Pno IN (1,2,3);
   +-----------+
   | Essn      |
   +-----------+
   | 123456789 |
   | 453453453 |
   | 333445555 |
   | 666884444 |
   +-----------+
   4 rows in set (0.00 sec)
   ```
8. 사원의 급여의 합, 최고 급여, 최저 급여, 평균 급여를 구하라.
   ```sql
   mysql> select SUM(Salary), MAX(Salary), MIN(Salary), AVG(Salary) from employee;
   +-------------+-------------+-------------+-------------+
   | SUM(Salary) | MAX(Salary) | MIN(Salary) | AVG(Salary) |
   +-------------+-------------+-------------+-------------+
   |      281000 |       55000 |       25000 |  35125.0000 |
   +-------------+-------------+-------------+-------------+
   1 row in set (0.00 sec)
   ```
9. 회사의 총 사원수를 제시하라.
   ```sql
   mysql> select COUNT(*) from employee;
   +----------+
   | COUNT(*) |
   +----------+
   |        8 |
   +----------+
   1 row in set (0.02 sec)
   ```
10. 각 부서에서 근무하는 사원의 수를 검색하라. (부서이름과 소속 사원수를 제시)
    ```sql
    mysql> select Dname, COUNT(*) from department, employee WHERE Dno=Dnumber GROUP BY Dname;
    +----------------+----------+
    | Dname          | COUNT(*) |
    +----------------+----------+
    | Administration |        3 |
    | Headquarters   |        1 |
    | Research       |        4 |
    +----------------+----------+
    3 rows in set (0.00 sec)
    ```
11. 각 부서에 대해서 부서이름, 부서에 소속된 사원의 수와 최고 급여와 평균 급여를 구하라.
    ```sql
    mysql> select Dname, COUNT(*), MAX(Salary), AVG(Salary) from department, employee WHERE Dno=Dnumber GROUP BY Dname;
    +----------------+----------+-------------+-------------+
    | Dname          | COUNT(*) | MAX(Salary) | AVG(Salary) |
    +----------------+----------+-------------+-------------+
    | Administration |        3 |       43000 |  31000.0000 |
    | Headquarters   |        1 |       55000 |  55000.0000 |
    | Research       |        4 |       40000 |  33250.0000 |
    +----------------+----------+-------------+-------------+
    3 rows in set (0.01 sec)
    ```
12. 프로젝트에 대해서 프로젝트 번호, 프로젝트 이름, 그 프로젝트에서 근무 하는 사원들의 수를 검색하라.
    ```sql
    mysql> select Pnumber, Pname, COUNT(*) from project, employee WHERE Dnum=Dno GROUP BY Pnumber, Pname;
    +---------+-----------------+----------+
    | Pnumber | Pname           | COUNT(*) |
    +---------+-----------------+----------+
    |       1 | ProductX        |        4 |
    |       2 | ProductY        |        4 |
    |       3 | ProductZ        |        4 |
    |      10 | Computerization |        3 |
    |      20 | Reorganization  |        1 |
    |      30 | Newbenefits     |        3 |
    +---------+-----------------+----------+
    6 rows in set (0.01 sec)
    ```
13. 세 명 이상의 사원이 근무하는 프로젝트에 대해서 프로젝트 번호, 프로젝트 이름, 그 프로젝트에서 근무하는 사원들의 수를 검색하라.
    ```sql
    mysql> select Pnumber, Pname, COUNT(*) from project, employee WHERE Dnum=Dno AND Dno IN
       -> (select Dno from employee GROUP BY Dno HAVING COUNT(*)>=3)
       -> GROUP BY Pnumber, Pname;
    +---------+-----------------+----------+
    | Pnumber | Pname           | COUNT(*) |
    +---------+-----------------+----------+
    |       1 | ProductX        |        4 |
    |       2 | ProductY        |        4 |
    |       3 | ProductZ        |        4 |
    |      10 | Computerization |        3 |
    |      30 | Newbenefits     |        3 |
    +---------+-----------------+----------+
    5 rows in set (0.03 sec)
    ```
14. 프로젝트에 대해서 프로젝트 번호, 프로젝트 이름, 5번 부서에 속하면서 프로젝트에서 근무하는 사원의 수를 검색하라.
    ```sql
    mysql> select Pnumber, Pname, COUNT(*) from project, employee, works_on WHERE Pnumber=Pno and Ssn=Essn and Dno=5 GROUP BY Pnumber, Pname;
    +---------+-----------------+----------+
    | Pnumber | Pname           | COUNT(*) |
    +---------+-----------------+----------+
    |       1 | ProductX        |        2 |
    |       2 | ProductY        |        3 |
    |       3 | ProductZ        |        2 |
    |      10 | Computerization |        1 |
    |      20 | Reorganization  |        1 |
    +---------+-----------------+----------+
    5 rows in set (0.01 sec)
    ```
15. 3명 이상의 사원이 근무하는 각 부서에 대해서 부서 번호와 40,000달러가 넘는 급여를 받는 사원의 `ssn` 및 `salary`를 검색하라.
    ```sql
    mysql> select Dno, Ssn, Salary from employee WHERE Salary>40000 AND Dno IN
      -> (select Dno from employee GROUP BY Dno HAVING COUNT(*)>=3)
      -> GROUP BY Dno, Ssn, Salary;
    +-----+-----------+--------+
    | Dno | Ssn       | Salary |
    +-----+-----------+--------+
    |   4 | 987654321 |  43000 |
    +-----+-----------+--------+
    1 row in set (0.00 sec)
    ```

## SELECT문 요약

- 6개의 절로 구성
  - 질의의 평가 순서
    - FROM → WHERE절 → GROUP BY → HAVING → SELECT → ORDER BY
  - (1) SELECT <애트리뷰트 목록>
    - SELECT 절은 질의 결과에 포함될 애트리뷰트들이나 함수를 나열함
  - (2) FROM <테이블 목록>
    - FROM 절은 질의의 대상을 명시하는 곳으로 조인된 릴레이션이나 릴레이션(들)을 지정함
  - (3) [WHERE <조건>]
    - WHERE 절은 투플들에 대한 조건을 명시함
  - (4) [GROUP BY <집단화 애트리뷰트>]
    - GROUP BY절은 그룹화 애트리뷰트들을 지정함
  - (5) [HAVING <집단 조건>]
    - HAVING 절은 그룹들에 대한 조건을 지정함
  - (6) [ORDER BY <애트리뷰트 목록>]
    - ORDER BY 절은 정렬 기준이 되는 애트리뷰트(들)을 지정함

---

## Source

1. **Fundamentals of Database Systems 7th Edition** by Ramez Elmasri, Shamkant B. Navathe.
2. **데이터베이스 시스템 (Database System Concepts) 6th Edition** by Abranham Silberschatz, Henry F.Korth, S.Sudarchan, 김형주 역.
