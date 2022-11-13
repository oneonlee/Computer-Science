import mysql from 'mysql2';
import { loginInfo } from "../routes/login.js";

// 데이터베이스 연결
const pool = mysql.createPool(
    process.env.JAWSDB_URL ?? {
        host: 'localhost',
        // port: 3306,
        user: 'root',
        password: 'Mgeon3812!',
        database: 'InhaDB',
        waitForConnections: true,
        connectionLimit: 10,
        queueLimit: 0,
    }
);

// async / awiat 사용
const promisePool = pool.promise();

// select query
export const selectSql = {
    setStudents: async () => {
        const loginId = await loginInfo.id();
        let sql = `SELECT * FROM Student `;
        if (loginId === undefined) {
            console.log("undefined", sql)
        }
        else {
            sql = `SELECT * FROM Student WHERE Student_Id=${loginId}`;
        }
        const [rows] = await promisePool.query(sql);
        return rows;
    },

    setStudent_takes_Class: async () => {
        const loginId = await loginInfo.id();
        let sql = `SELECT S.Id as Student_Id, S.Student_Id as Student_Number, SC.Class_Id as Class_Id, C.Name as Class_Name FROM Student as S, Student_takes_Class as SC, Class as C WHERE S.Id=SC.Student_Id AND C.Id=SC.Class_Id`;
        if (loginId === undefined) {
            console.log("undefined", sql)
        }
        else {
            sql = `SELECT S.Id as Student_Id, S.Student_Id as Student_Number, SC.Class_Id as Class_Id, C.Name as Class_Name FROM Student as S, Student_takes_Class as SC, Class as C WHERE S.Id=SC.Student_Id AND C.Id=SC.Class_Id AND S.Student_Id=${loginId}`;
        }
        const [rows] = await promisePool.query(sql);
        return rows;
    },
};

// delete query
export const deleteSql = {
    deleteStudent_takes_Class: async (data) => {
        // console.log("deleteSql.deleteStudent_takes_Class:", data.Class_Id);
        const sql = `DELETE FROM Student_takes_Class WHERE Student_Id=${data.Student_Id} AND Class_Id=${data.Class_Id}`;
        await promisePool.query(sql);
    },
};