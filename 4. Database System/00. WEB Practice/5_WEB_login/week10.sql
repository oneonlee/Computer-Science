CREATE SCHEMA IF NOT EXISTS `week10` DEFAULT CHARACTER SET utf8mb4;

use week10;

CREATE TABLE USER 
( Id VARCHAR(20) NOT NULL,
 Password VARCHAR(20) NOT NULL,
 Role VARCHAR(15) NOT NULL,
 PRIMARY KEY (id));

CREATE TABLE DEPARTMENT
( ID INT(10) NOT NULL AUTO_INCREMENT,
  Dname VARCHAR(15) NOT NULL,
  Dnumber INT NOT NULL,
PRIMARY KEY (ID, Dnumber),
UNIQUE      (Dname));

INSERT INTO user VALUES ("admin", "admin1234", "super");
INSERT INTO user VALUES ("12000000", "test1234", "student");

insert into department values (null, "정보통신공학과", 0);
insert into department values (null, "컴퓨터공학과", 1);
insert into department values (null, "전기공학과", 2);
insert into department values (null, "전자공학과", 3);