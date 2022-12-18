-- MySQL Workbench Forward Engineering
SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema Car_Dealer
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `Car_Dealer` DEFAULT CHARACTER SET utf8 ;
USE `Car_Dealer` ;

-- -----------------------------------------------------
-- Table `Car_Dealer`.`VEHICLE`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Car_Dealer`.`VEHICLE` (
  `Vid` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Vin` VARCHAR(45) NOT NULL,
  `Model` VARCHAR(45) NOT NULL,
  `Price` INT UNSIGNED NOT NULL,
  `Status` VARCHAR(20) NOT NULL,
  PRIMARY KEY (`Vid`),
  UNIQUE INDEX `Vid_UNIQUE` (`Vid` ASC) VISIBLE,
  UNIQUE INDEX `Vin_UNIQUE` (`Vin` ASC) VISIBLE)
ENGINE = InnoDB;

-- -----------------------------------------------------
-- Table `Car_Dealer`.`SALESPERSON`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Car_Dealer`.`SALESPERSON` (
  `Sid` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Susername` VARCHAR(32) NOT NULL,
  `Spassword` VARCHAR(20) NOT NULL,
  `Sname` VARCHAR(4) NOT NULL,
  PRIMARY KEY (`Sid`),
  UNIQUE INDEX `Sid_UNIQUE` (`Sid` ASC) VISIBLE,
  UNIQUE INDEX `Susername_UNIQUE` (`Susername` ASC) VISIBLE);

-- -----------------------------------------------------
-- Table `Car_Dealer`.`SALESPERSON_manages_VEHICLE`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Car_Dealer`.`SALESPERSON_manages_VEHICLE` (
  `Salesperson_id` INT UNSIGNED NOT NULL,
  `Vehicle_id` INT UNSIGNED NOT NULL,
  INDEX `fk_S_manages_V_VEHICLE1_idx` (`Vehicle_id` ASC) VISIBLE,
  INDEX `fk_S_manages_V_SALESPERSON1_idx` (`Salesperson_id` ASC) VISIBLE,
  PRIMARY KEY (`Salesperson_id`, `Vehicle_id`),
  CONSTRAINT `fk_SALESPERSON_has_VEHICLE_SALESPERSON`
    FOREIGN KEY (`Salesperson_id`)
    REFERENCES `Car_Dealer`.`SALESPERSON` (`Sid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_SALESPERSON_has_VEHICLE_VEHICLE1`
    FOREIGN KEY (`Vehicle_id`)
    REFERENCES `Car_Dealer`.`VEHICLE` (`Vid`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);

-- -----------------------------------------------------
-- Table `Car_Dealer`.`CUSTOMER`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Car_Dealer`.`CUSTOMER` (
  `Cid` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Cusername` VARCHAR(45) NOT NULL,
  `Cpassword` VARCHAR(20) NOT NULL,
  `Cname` VARCHAR(4) NOT NULL,
  `Dealer_id` INT UNSIGNED NULL,
  `Reserved_vehicle_id` INT UNSIGNED NULL,
  PRIMARY KEY (`Cid`),
  UNIQUE INDEX `Cid_UNIQUE` (`Cid` ASC) VISIBLE,
  UNIQUE INDEX `Cusername_UNIQUE` (`Cusername` ASC) VISIBLE,
  INDEX `fk_CUSTOMER_S_manages_V1_idx` (`Dealer_id` ASC, `Reserved_vehicle_id` ASC) VISIBLE,
  UNIQUE INDEX `Reserved_vehicle_id_UNIQUE` (`Reserved_vehicle_id` ASC) VISIBLE,
  CONSTRAINT `fk_CUSTOMER_SALESPERSON_manages_VEHICLE1`
    FOREIGN KEY (`Dealer_id` , `Reserved_vehicle_id`)
    REFERENCES `Car_Dealer`.`SALESPERSON_manages_VEHICLE` (`Salesperson_id` , `Vehicle_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;