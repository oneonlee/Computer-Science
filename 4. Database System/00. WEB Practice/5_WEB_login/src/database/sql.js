import mysql from 'mysql2';

// 데이터베이스 연결
const pool = mysql.createPool(
    process.env.JAWSDB_URL ?? {
        host: 'localhost',
        // port: 3306,
        user: 'root',
        password: 'Mgeon3812!',
        database: 'week10',
        waitForConnections: true,
        connectionLimit: 10,
        queueLimit: 0,
    }
);

// async / awiat 사용
const promisePool = pool.promise();

// select query
export const selectSql = {
    setUsers: async () => {
        const sql = `select * from user`;
        const [rows] = await promisePool.query(sql);

        return rows;
    },
    getDepartment: async () => {
        const sql = `select * from department`;
        const [rows] = await promisePool.query(sql);

        return rows;
    },
};

// delete query
export const deleteSql = {
    deleteDepartment: async (data) => {
        console.log("deleteSql.deleteDepartment:", data.Dnumber);
        const sql = `delete from department where Dnumber=${data.Dnumber}`;
        await promisePool.query(sql);
    },
};