import mysql from 'mysql2';

require("dotenv").config(); // 모듈 불러오기

const pool = mysql.createPool({
    host: 'localhost',
    port: 3306,
    user: 'root',
    password: process.env.MYSQL_PASSWORD,
    database: 'InhaDB',
});

const promisePool = pool.promise();

const sql = {
    delTables: async () => {
        let results = await promisePool.query(`SET FOREIGN_KEY_CHECKS=0;`);
        results = await promisePool.query(`TRUNCATE Building;`);
        results = await promisePool.query(`TRUNCATE Room;`);
        results = await promisePool.query(`TRUNCATE Department;`);
        results = await promisePool.query(`TRUNCATE Employee;`);
        results = await promisePool.query(`TRUNCATE Class;`);
        results = await promisePool.query(`TRUNCATE Student;`);
        results = await promisePool.query(`TRUNCATE Student_takes_Class;`);
        results = await promisePool.query(`TRUNCATE Department_manages_Student;`);
        results = await promisePool.query(`TRUNCATE Club;`);
        results = await promisePool.query(`TRUNCATE Club_has_Student;`);
        results = await promisePool.query(`SET FOREIGN_KEY_CHECKS=1`);
        return results;
    },

    setValues: async () => {
        let results = await promisePool.query(`
        INSERT INTO Building 
        VALUES      (null, '2호관'),
                    (null, '5호관'),
                    (null, '9호관'),
                    (null, '본관'),
                    (null, '하이테크센터'),
                    (null, '학생회관');
        `);
        results = await promisePool.query(`
        INSERT INTO Room
        VALUES      (null, '2북-291', 10, 1),
                    (null, '5동-105B', 50, 2),
                    (null, '5북-211', 10, 2),
                    (null, '9-409', 10, 3),
                    (null, '하-230', 70, 5),
                    (null, '하-232', 80, 5),
                    (null, '하-416', 10, 5),
                    (null, '하-424', 50, 5),
                    (null, '하-801', 10, 5),
                    (null, '하-1234', 123, 5),
                    (null, '학생회관-123', 30, 6)
        `);
        results = await promisePool.query(`
        INSERT INTO Department
        VALUES      (null, '기계공학과', '220478@inha.ac.kr', '032-860-7300', 1, 1),
                    (null, '전자공학과', null, '032-860-7410', 9, 5),
                    (null, '정보통신공학과', '221103@inha.ac.kr', '032-860-7430', 7, 5),
                    (null, '수학과', null, '032-860-7620', 3, 2),
                    (null, '경제학과', null, '032-860-7770', 4, 3)
        `);
        results = await promisePool.query(`
        INSERT INTO Employee
        VALUES      (null, '박기계', '팀원', 1),
                    (null, '전전자', '교수', 2),
                    (null, '정정통', '조교수', 3),
                    (null, '김수학', '팀원', 4),
                    (null, '이경제', '팀원', 5)
        `);
        results = await promisePool.query(`
        INSERT INTO Class
        VALUES(null, '공업수학 2', '최경표', 46, 2, 2),
            (null, '오퍼레이팅시스템', '김기창', 50, 3, 8),
            (null, '신호및시스템', '김춘우', 51, 3, 8),
            (null, '컴퓨터네트워크', '유상조', 65, 3, 8),
            (null, '데이터베이스설계', '최원익', 76, 3, 8)
        `);
        results = await promisePool.query(`
        INSERT INTO Student
        VALUES(null, '이동건', 'time@inha.edu', '01000000000', '정보통신공학과', '12181879'),
            (null, '공신오', 'eng-sig-op@inha.edu', '01011111111', '정보통신공학과', '12201111'),
            (null, '오컴데', 'op-com-da@inha.edu', '01022222222', '수학과', '12192222'),
            (null, '공신컴', 'eng-sig-com@inha.edu', '01033333333', '정보통신공학과', '12213333'),
            (null, '신컴데', 'sig-com-da@inha.edu', '01044444444', '전자공학과', '12194444')
        `);
        results = await promisePool.query(`
        INSERT INTO Student_takes_Class
        VALUES(1, 1), (1, 2), (1, 3), (1, 4), (1, 5),
            (2, 1), (2, 2), (2, 3),
            (3, 2), (3, 4), (3, 5),
            (4, 1), (4, 3), (4, 4),
            (5, 3), (5, 4), (5, 5)
        `);
        results = await promisePool.query(`
        INSERT INTO Department_manages_Student
        VALUES(2, 3),
            (3, 1), (3, 2), (3, 3), (3, 4), (3, 5),
            (4, 3)
        `);
        results = await promisePool.query(`
        INSERT INTO Club
        VALUES(null, '축구 동아리', null, null),
            (null, '농구 동아리', null, null),
            (null, '야구 동아리', null, null),
            (null, '코딩 동아리', 10, 5),
            (null, '주식 동아리', 11, 6)
        `);
        results = await promisePool.query(`
        INSERT INTO Club_has_Student
        VALUES(1, 2), (1, 4),
            (2, 2), (2, 4),
            (3, 2), (3, 4),
            (4, 1), (4, 2), (4, 4),
            (5, 3)
        `)
        return results;
    },

    getBuilding: async () => {
        const results = await promisePool.query(`
        SELECT * FROM Building;
        `)
        return results;
    },
    getClass: async () => {
        const results = await promisePool.query(`
        SELECT * FROM Class;
        `)
        return results;
    },
    getClub: async () => {
        const results = await promisePool.query(`
        SELECT * FROM Club;
        `)
        return results;
    },
    getClubHasStudent: async () => {
        const results = await promisePool.query(`
        SELECT * FROM Club_has_Student;
        `)
        return results;
    },
    getDepartment: async () => {
        const results = await promisePool.query(`
        SELECT * FROM Department;
        `)
        return results;
    },
    getDepartmentManagesStudent: async () => {
        const results = await promisePool.query(`
        SELECT * FROM Department_manages_Student;
        `)
        return results;
    },
    getEmployee: async () => {
        const results = await promisePool.query(`
        SELECT * FROM Employee;
        `)
        return results;
    },
    getRoom: async () => {
        const results = await promisePool.query(`
        SELECT * FROM Room;
        `)
        return results;
    },
    getStudent: async () => {
        const results = await promisePool.query(`
        SELECT * FROM Student;
        `)
        return results;
    },
    getStudentTakesClass: async () => {
        const results = await promisePool.query(`
        SELECT * FROM Student_takes_Class;
        `)
        return results;
    }
};

export default sql;