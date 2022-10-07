# Company Database

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

---

1. 'Newbenefits' 프로젝트에 참여하는 모든 사원의 급여를 10% 올린 경우의 급여를 제시하라. (`Fname`, `Lname`, `Increased_sal`)
   ```sql
   mysql> select Fname, Lname, Salary*1.1 as Increased_sal from project, works_on,
   employee where Pname='Newbenefits' and Pnumber=Pno and Essn=Ssn;
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
    mysql> select DISTINCT Essn from works_on where Pno=1 or Pno=2 or Pno=3;
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
    mysql> select DISTINCT Essn from works_on where Pno IN (1,2,3);
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
11. 각 부서에 대해서 부서이름, 부서에 소속된 사원의 수와 최고 급여와 평균 급여를 구하라.

    ```sql

    ```

12. 프로젝트에 대해서 프로젝트 번호, 프로젝트 이름, 그 프로젝트에서 근무 하는 사원들의 수를 검색하라.
13. 세 명 이상의 사원이 근무하는 프로젝트에 대해서 프로젝트 번호, 프로젝트 이름, 그 프로젝트에서 근무하는 사원들의 수를 검색하라.
14. 프로젝트에 대해서 프로젝트 번호, 프로젝트 이름, 5번 부서에 속하면서 프로젝트에서 근무하는 사원의 수를 검색하라.
15. 3명 이상의 사원이 근무하는 각 부서에 대해서 부서 번호와 40,000달러가 넘는 급여를 받는 사원의 `ssn` 및 `salary`를 검색하라.
