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
