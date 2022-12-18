import mysql from 'mysql2';

// 데이터베이스 연결
const pool = mysql.createPool(
    process.env.JAWSDB_URL ?? {
        host: 'localhost',
        port: 3306,
        user: 'root',
        password: 'Mgeon3812!',
        database: 'Car_Dealer',
        waitForConnections: true,
        connectionLimit: 10,
        queueLimit: 0,
    }
);

// async & awiat 사용
const promisePool = pool.promise();

// Transactions for Login
export const loginSql = {
    getSalesperson: async () => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        const sql = `SELECT * FROM SALESPERSON`;
        const [rows] = await promisePool.query(sql);

        await promisePool.query(`COMMIT`); // END of transaction
        return rows;
    },
    getCustomer: async () => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        const sql = `SELECT * FROM CUSTOMER`;
        const [rows] = await promisePool.query(sql);

        await promisePool.query(`COMMIT`); // END of transaction
        return rows;
    },
};

// Transactions for reservation
export const reserveSql = {
    getAvailableVehicles: async () => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        const sql = `SELECT * from Reservation_table`;
        const [rows] = await promisePool.query(sql);

        await promisePool.query(`COMMIT`); // END of transaction
        return rows;
    },
    get10AvailableVehicles: async () => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        const sql = `SELECT * from Reservation_table LIMIT 10`;
        const [rows] = await promisePool.query(sql);

        await promisePool.query(`COMMIT`); // END of transaction
        return rows;
    },

    setUserReservation: async (data) => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        // 담당 딜러의 id와 차량 등의 예약 정보를 update
        const customer_sql = `UPDATE CUSTOMER 
                            SET Dealer_id = ${data.Salesperson_id}, Reserved_vehicle_id = ${data.Vid}
                            WHERE Cusername = "${data.username}" and Cname = "${data.name}"`;
        await promisePool.query(customer_sql);

        const vehicle_sql = `UPDATE VEHICLE
                            SET Status = "RESERVED"
                            WHERE Vid = ${data.Vid}`;
        await promisePool.query(vehicle_sql);

        await promisePool.query(`COMMIT`); // END of transaction
    },
    getUserReservation: async (data) => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        let username = data.username;
        let name = data.name;
        const sql = `SELECT Vin, Model, Price, Status, Dealer_id, Reserved_vehicle_id 
                    FROM CUSTOMER, VEHICLE 
                    WHERE Reserved_vehicle_id=Vid AND Cusername="${username}" AND Cname="${name}";`;
        const [rows] = await promisePool.query(sql);

        await promisePool.query(`COMMIT`); // END of transaction
        return rows;
    },
    removeUserReservation: async (data) => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        const customer_sql = `UPDATE CUSTOMER 
                            SET Dealer_id = NULL, Reserved_vehicle_id = NULL
                            WHERE Dealer_id = ${data.Dealer_id} AND Reserved_vehicle_id = ${data.Vid}`;
        await promisePool.query(customer_sql);

        const vehicle_sql = `UPDATE VEHICLE
                            SET Status = "ONSALE"
                            WHERE Vid = ${data.Vid}`;
        await promisePool.query(vehicle_sql);

        await promisePool.query(`COMMIT`); // END of transaction
    },
};

// Transactions for managing vehicles
export const manageSql = {
    get10Vehicles: async (data) => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        const sql = `SELECT Vid, Vin, Model, Price, Status, Sid as Dealer_id
                    FROM VEHICLE, SALESPERSON, SALESPERSON_manages_VEHICLE 
                    WHERE Vid = Vehicle_id AND Sid = Salesperson_id AND Sname = "${data.name}" AND Susername = "${data.username}"
                    LIMIT 10`;
        const [rows] = await promisePool.query(sql);

        await promisePool.query(`COMMIT`); // END of transaction
        return rows;
    },
    getAllVehicles: async (data) => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        const sql = `SELECT Vid, Vin, Model, Price, Status, Sid as Dealer_id
                    FROM VEHICLE, SALESPERSON, SALESPERSON_manages_VEHICLE 
                    WHERE Vid = Vehicle_id AND Sid = Salesperson_id AND Sname = "${data.name}" AND Susername = "${data.username}"`;
        const [rows] = await promisePool.query(sql);

        await promisePool.query(`COMMIT`); // END of transaction
        return rows;
    },
    getOnSaleVehicles: async (data) => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        const sql = `SELECT Vid, Vin, Model, Price, Status, Sid as Dealer_id
                    FROM VEHICLE, SALESPERSON, SALESPERSON_manages_VEHICLE 
                    WHERE STATUS='ONSALE'
                    AND Vid = Vehicle_id AND Sid = Salesperson_id AND Sname = "${data.name}" AND Susername = "${data.username}"`;
        const [rows] = await promisePool.query(sql);

        await promisePool.query(`COMMIT`); // END of transaction
        return rows;
    },
    getReservedVehicles: async (data) => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        const sql = `SELECT Vid, Vin, Model, Price, Status, Sid as Dealer_id
                    FROM VEHICLE, SALESPERSON, SALESPERSON_manages_VEHICLE 
                    WHERE STATUS='RESERVED'
                    AND Vid = Vehicle_id AND Sid = Salesperson_id AND Sname = "${data.name}" AND Susername = "${data.username}"`;
        const [rows] = await promisePool.query(sql);

        await promisePool.query(`COMMIT`); // END of transaction
        return rows;
    },
    getSoldVehicles: async (data) => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        const sql = `SELECT Vid, Vin, Model, Price, Status, Sid as Dealer_id
                    FROM VEHICLE, SALESPERSON, SALESPERSON_manages_VEHICLE 
                    WHERE STATUS='SOLDOUT'
                    AND Vid = Vehicle_id AND Sid = Salesperson_id AND Sname = "${data.name}" AND Susername = "${data.username}"`;
        const [rows] = await promisePool.query(sql);

        await promisePool.query(`COMMIT`); // END of transaction
        return rows;
    },

    createVehicle: async (data) => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        const get_max_vid_sql = `SELECT Vid as Maximum_vid FROM VEHICLE ORDER BY Vid DESC LIMIT 1;`;
        const [rows1] = await promisePool.query(get_max_vid_sql);
        const Maximum_vid = rows1[0].Maximum_vid;

        const get_sid_sql = `SELECT Sid AS Salesperson_id FROM SALESPERSON WHERE Sname="${data.name}" AND Susername="${data.username}";`
        const [rows2] = await promisePool.query(get_sid_sql);
        const Salesperson_id = rows2[0].Salesperson_id;

        // INSERT문의 실행 순서를 고려하여 배치하였음

        // Vid, Vin, Model, Price, Status 순서
        const vehicle_insert_sql = `INSERT INTO VEHICLE 
                                    VALUE (${Maximum_vid + 1}, "${data.Vin}", "${data.Model}", ${data.Price}, "${data.Status}")`;
        await promisePool.query(vehicle_insert_sql);

        // Salesperson_id, Vehicle_id 순서
        const manages_insert_sql = `INSERT INTO SALESPERSON_manages_VEHICLE 
                                    VALUE (${Salesperson_id}, ${Maximum_vid + 1})`;
        await promisePool.query(manages_insert_sql);

        await promisePool.query(`COMMIT`); // END of transaction
    },

    updateVehicle: async (data) => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        const sql = `UPDATE VEHICLE 
                     SET Vin = "${data.Vin}", Model = "${data.Model}", 
                     Price = ${data.Price}, Status = "${data.Status}"
                     WHERE Vid = ${data.Vid}`;
        await promisePool.query(sql);

        await promisePool.query(`COMMIT`); // END of transaction
    },

    deleteVehicle: async (data) => {
        await promisePool.query(`START TRANSACTION`); // BEGIN of transaction

        // Update 및 Delete문의 실행 순서를 고려하여 배치하였음
        const customer_delete_sql = `UPDATE CUSTOMER 
                                     SET Dealer_id = NULL, Reserved_vehicle_id = NULL
                                     WHERE Dealer_id = ${data.Dealer_id} AND Reserved_vehicle_id = ${data.Vid}`;
        await promisePool.query(customer_delete_sql);

        const manages_delete_sql = `DELETE FROM SALESPERSON_manages_VEHICLE WHERE Salesperson_id = ${data.Dealer_id} AND Vehicle_id = ${data.Vid}`;
        await promisePool.query(manages_delete_sql);

        const vehicle_delete_sql = `DELETE FROM VEHICLE WHERE Vid = ${data.Vid}`;
        await promisePool.query(vehicle_delete_sql);

        await promisePool.query(`COMMIT`); // END of transaction
    },
};