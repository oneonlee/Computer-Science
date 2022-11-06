import mysql from 'mysql2';

require("dotenv").config(); // 모듈 불러오기

// 데이터베이스 연결
const pool = mysql.createPool({
    host: 'localhost',
    port: 3306,
    user: 'root',
    password: process.env.MYSQL_PASSWORD,
    database: 'InhaDB',
});

// async / await 사용
const promisePool = pool.promise();

// select query
export const selectSql = {
    getBuilding: async () => {
        const sql = `select * from Building`;
        const [result] = await promisePool.query(sql);
        return result;
    },
    getClass: async () => {
        const sql = `select * from Class`;
        const [result] = await promisePool.query(sql);
        return result;
    },
    getClub: async () => {
        const sql = `select * from Club`;
        const [result] = await promisePool.query(sql);
        return result;
    },
    getClub_has_Student: async () => {
        const sql = `select * from Club_has_Student`;
        const [result] = await promisePool.query(sql);
        return result;
    },
    getDepartment: async () => {
        const sql = `select * from Department`;
        const [result] = await promisePool.query(sql);
        return result;
    },
    getDepartment_manages_Student: async () => {
        const sql = `select * from Department_manages_Student`;
        const [result] = await promisePool.query(sql);
        return result;
    },
    getEmployee: async () => {
        const sql = `select * from Employee`;
        const [result] = await promisePool.query(sql);
        return result;
    },
    getRoom: async () => {
        const sql = `select * from Room`;
        const [result] = await promisePool.query(sql);
        return result;
    },
    getStudent: async () => {
        const sql = `select * from Student`;
        const [result] = await promisePool.query(sql);
        return result;
    },
    getStudent_takes_Class: async () => {
        const sql = `select * from Student_takes_Class`;
        const [result] = await promisePool.query(sql);
        return result;
    },
}

// insert query
export const insertSql = {
    // data라는 객체 타입의 파라미터에 입력할 정보를 받아서 query문 생성
    setEmployee: async (data) => {
        const sql = `insert into employee values (
            "${data.Id}", "${data.Name}", "${data.Position}", "${data.Department_Id}"
        )`
        console.log(data)
        await promisePool.query(sql);
    },
};

// update query
export const updateSql = {
    updateStudent: async (data) => {
        console.log(data);
        const sql = `UPDATE Student 
                     SET Name = "${data.Name}", Email = "${data.Email}", 
                     Phone_number = "${data.Phone_number}", Major = "${data.Major}",
                     Student_Id = ${data.Student_Id}
                     WHERE Id=${data.Id}`;
        console.log(sql);
        await promisePool.query(sql);
    },
};