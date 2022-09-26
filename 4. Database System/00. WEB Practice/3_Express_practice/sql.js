import mysql from 'mysql2';

const MYSQL_PASSWORD = 'Mgeon3812!';

const pool = mysql.createPool({
    host: 'localhost',
    port: 3306,
    user: 'root',
    password: MYSQL_PASSWORD,
    database: 'Company',
});

const promisePool = pool.promise();

const sql = {
    getEmployee: async () => {
        const results = await promisePool.query(`
            SELECT * FROM Employee
        `)

        return results;
    },
};

export default sql;