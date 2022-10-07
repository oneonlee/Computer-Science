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

# SQL Practice

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
