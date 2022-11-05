import mysql from 'mysql2';

// 데이터베이스 연결
const pool = mysql.createPool({
    host: 'localhost',
    port: 3306,
    user: 'root',
    password: 'Mgeon3812!',
    database: 'week9',
});

// async / awiat 사용
const promisePool = pool.promise();

// select query
export const selectSql = {
    getEmployee: async () => {
        const sql = `select * from employee`;
        const [result] = await promisePool.query(sql);

        return result;
    },
    getDepartment: async () => {
        const sql = `select * from department`;
        const [result] = await promisePool.query(sql);

        return result
    }
}

// insert query
export const insertSql = {
    // data라는 객체 타입의 파라미터에 입력할 정보를 받아서 query문 생성
    setEmployee: async (data) => {
        const sql = `insert into employee values (
            "${data.fname}", "${data.Minit}", "${data.Lname}", "${data.Ssn}", "${data.Bdate}",
            "${data.Address}", "${data.Sex}", "${data.Salary}", "${data.Super_ssn}", "${data.Dno}"
        )`
        console.log(data)
        await promisePool.query(sql);
    },
    setDepartment: async (data) => {
        const sql = `insert into department values (
            "${data.Dname}", "${data.Dnumber}", "${data.Mgr_ssn}", "${data.Mgr_start_date}"
        )`
        await promisePool.query(sql);
    }
};

export const updateSql = {
    updateEmployee: async () => {
        const sql = `update employee set salary = 500 where Minit = "F"`;
        await promisePool.query(sql);
    },

    updateDepartment: async (data) => {
        console.log(data);
        const sql = `update department set dname = "${data.Dname}" where Dnumber=5`;
        console.log(sql);
        await promisePool.query(sql);
    }
}
