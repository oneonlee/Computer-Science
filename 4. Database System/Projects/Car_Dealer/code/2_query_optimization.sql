-- -----------------------------------------------------
-- Make an additional index of VEHICLE table
-- -----------------------------------------------------
CREATE INDEX Vehicle_Status ON VEHICLE (Status) USING BTREE;

-- -----------------------------------------------------
-- Make views
-- -----------------------------------------------------
CREATE VIEW Reservation_table 
AS 
    SELECT Vid, Vin, Model, Price, Status, Salesperson_id 
        FROM VEHICLE, SALESPERSON_manages_VEHICLE 
        WHERE Vid=Vehicle_id AND STATUS='ONSALE';

