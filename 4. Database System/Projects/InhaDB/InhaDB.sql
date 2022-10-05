-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema InhaDB
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema InhaDB
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `InhaDB` DEFAULT CHARACTER SET utf8 ;
USE `InhaDB` ;

-- -----------------------------------------------------
-- Table `InhaDB`.`Building`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `InhaDB`.`Building` (
  `Id` INT NOT NULL AUTO_INCREMENT,
  `Name` VARCHAR(12) NOT NULL,
  PRIMARY KEY (`Id`),
  UNIQUE INDEX `Id_UNIQUE` (`Id` ASC) VISIBLE,
  UNIQUE INDEX `Name_UNIQUE` (`Name` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `InhaDB`.`Room`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `InhaDB`.`Room` (
  `Id` INT NOT NULL AUTO_INCREMENT,
  `Name` VARCHAR(10) NOT NULL,
  `Capacity` INT NULL,
  `Building_Id` INT NOT NULL,
  PRIMARY KEY (`Id`, `Building_Id`),
  UNIQUE INDEX `Id_UNIQUE` (`Id` ASC) VISIBLE,
  UNIQUE INDEX `Name_UNIQUE` (`Name` ASC) VISIBLE,
  INDEX `fk_Room_Building_idx` (`Building_Id` ASC) VISIBLE,
  CONSTRAINT `fk_Room_Building1`
    FOREIGN KEY (`Building_Id`)
    REFERENCES `InhaDB`.`Building` (`Id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `InhaDB`.`Department`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `InhaDB`.`Department` (
  `Id` INT NOT NULL AUTO_INCREMENT,
  `Name` VARCHAR(60) NOT NULL,
  `Email` VARCHAR(45) NULL,
  `Phone number` VARCHAR(12) NULL,
  `Room_Id` INT NOT NULL,
  `Room_Building_Id` INT NOT NULL,
  PRIMARY KEY (`Id`),
  UNIQUE INDEX `Id_UNIQUE` (`Id` ASC) VISIBLE,
  UNIQUE INDEX `Name_UNIQUE` (`Name` ASC) VISIBLE,
  INDEX `fk_Department_Room_idx` (`Room_Id` ASC, `Room_Building_Id` ASC) VISIBLE,
  CONSTRAINT `fk_Department_Room1`
    FOREIGN KEY (`Room_Id` , `Room_Building_Id`)
    REFERENCES `InhaDB`.`Room` (`Id` , `Building_Id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `InhaDB`.`Class`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `InhaDB`.`Class` (
  `Id` INT NOT NULL AUTO_INCREMENT,
  `Name` VARCHAR(30) NOT NULL,
  `Professor` VARCHAR(30) NOT NULL,
  `Number of participants` INT NULL,
  `Department_Id` INT NOT NULL,
  `Room_Id` INT NOT NULL,
  PRIMARY KEY (`Id`, `Department_Id`),
  UNIQUE INDEX `Id_UNIQUE` (`Id` ASC) VISIBLE,
  INDEX `fk_Class_Department_idx` (`Department_Id` ASC) VISIBLE,
  INDEX `fk_Class_Room_idx` (`Room_Id` ASC) VISIBLE,
  CONSTRAINT `fk_Class_Department1`
    FOREIGN KEY (`Department_Id`)
    REFERENCES `InhaDB`.`Department` (`Id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Class_Room1`
    FOREIGN KEY (`Room_Id`)
    REFERENCES `InhaDB`.`Room` (`Id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `InhaDB`.`Student`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `InhaDB`.`Student` (
  `Id` INT NOT NULL AUTO_INCREMENT,
  `Name` VARCHAR(30) NOT NULL,
  `Email` VARCHAR(45) NULL,
  `Phone number` VARCHAR(12) NULL,
  `Major` VARCHAR(60) NOT NULL,
  `Student Id` INT NOT NULL,
  PRIMARY KEY (`Id`),
  UNIQUE INDEX `Id_UNIQUE` (`Id` ASC) VISIBLE,
  UNIQUE INDEX `Email_UNIQUE` (`Email` ASC) VISIBLE,
  UNIQUE INDEX `Phone number_UNIQUE` (`Phone number` ASC) VISIBLE,
  UNIQUE INDEX `Student Id_UNIQUE` (`Student Id` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `InhaDB`.`Student_takes_Class`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `InhaDB`.`Student_takes_Class` (
  `Student_Id` INT NOT NULL,
  `Class_Id` INT NOT NULL,
  PRIMARY KEY (`Student_Id`, `Class_Id`),
  INDEX `fk_Student_takes_Class_Class_idx` (`Class_Id` ASC) VISIBLE,
  INDEX `fk_Student_takes_Class_Student_idx` (`Student_Id` ASC) VISIBLE,
  CONSTRAINT `fk_Student_has_Class_Student1`
    FOREIGN KEY (`Student_Id`)
    REFERENCES `InhaDB`.`Student` (`Id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Student_has_Class_Class1`
    FOREIGN KEY (`Class_Id`)
    REFERENCES `InhaDB`.`Class` (`Id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `InhaDB`.`Department_manages_Student`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `InhaDB`.`Department_manages_Student` (
  `Department_Id` INT NOT NULL,
  `Student_Id` INT NOT NULL,
  PRIMARY KEY (`Department_Id`, `Student_Id`),
  INDEX `fk_Department_manages_Student_Student_idx` (`Student_Id` ASC) VISIBLE,
  INDEX `fk_Department_manages_Student_Department_idx` (`Department_Id` ASC) VISIBLE,
  CONSTRAINT `fk_Department_has_Student_Department1`
    FOREIGN KEY (`Department_Id`)
    REFERENCES `InhaDB`.`Department` (`Id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Department_has_Student_Student1`
    FOREIGN KEY (`Student_Id`)
    REFERENCES `InhaDB`.`Student` (`Id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;


-- -----------------------------------------------------
-- Insert values into tables
-- -----------------------------------------------------
INSERT INTO Building
VALUES      (null, '2호관'),
            (null, '5호관'),
            (null, '9호관'),
            (null, '본관'),
            (null, '하이테크센터');

INSERT INTO Room
VALUES      (null, '2북-291', 10, 1),
            (null, '5동-105B', 50, 2),
            (null, '5북-211', 10, 2),
            (null, '9-409', 10, 3),
            (null, '하-230', 70, 5),
            (null, '하-232', 80, 5),
            (null, '하-416', 10, 5),
            (null, '하-424', 50, 5),
            (null, '하-801', 10, 5);

INSERT INTO Department
VALUES      (null, '기계공학과', '220478@inha.ac.kr', '032-860-7300', 1, 1),
            (null, '전자공학과', null, '032-860-7410', 9, 5),
            (null, '정보통신공학과', '221103@inha.ac.kr', '032-860-7430', 7, 5),
            (null, '수학과', null, '032-860-7620', 3, 2),
            (null, '경제학과', null, '032-860-7770', 4, 3);

INSERT INTO Class
VALUES      (null, '공업수학 2', '최경표', 46, 2, 2),
            (null, '오퍼레이팅시스템', '김기창', 50, 3, 8),
            (null, '신호및시스템', '김춘우', 51, 3, 8),
            (null, '컴퓨터네트워크', '유상조', 65, 3, 8),
            (null, '데이터베이스설계', '최원익', 76, 3, 8);

INSERT INTO Student
VALUES      (null, '이동건', 'time@inha.edu', '01000000000', '정보통신공학과', '12181879'),
            (null, '공신오', 'eng-sig-op@inha.edu', '01011111111', '정보통신공학과', '12201111'),
            (null, '오컴데', 'op-com-da@inha.edu', '01022222222', '수학과', '12192222'),
            (null, '공신컴', 'eng-sig-com@inha.edu', '01033333333', '정보통신공학과', '12213333'),
            (null, '신컴데', 'sig-com-da@inha.edu', '01044444444', '전자공학과', '12194444');
            
INSERT INTO Student_takes_Class
VALUES      (1, 1), (1, 2), (1, 3), (1, 4), (1, 5),
            (2, 1), (2, 2), (2, 3),
            (3, 2), (3, 4), (3, 5),
            (4, 1), (4, 3), (4, 4),
            (5, 3), (5, 4), (5, 5);

INSERT INTO Department_manages_Student
VALUES      (2, 3),
            (3, 1), (3, 2), (3, 3), (3, 4), (3, 5),
            (4, 3);