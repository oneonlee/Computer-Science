import mysql from "mysql2";

// 데이터베이스 연결
const pool = mysql.createPool(
  process.env.JAWSDB_URL ?? {
    host: 'localhost',
    user: 'root',
    database: 'inhadb',
    password: 'Mgeon3812!',
    waitForConnections: true,
    connectionLimit: 10,
    queueLimit: 0
  }
);

// async / await 사용
const promisePool = pool.promise();

// select query
export const selectSql = {
  getUsers: async () => {
    const [rows] = await promisePool.query(`SELECT * FROM STUDENT`);

    return rows
  },
  getClasses: async () => {
    const [rows] = await promisePool.query(`SELECT * FROM CLASS`);

    return rows
  },
}


// update query
export const updateSql = {
  updateClass: async (data) => { // Class 테이블의 Id가 ${data.Class_Id}인 행의 Current_Students_Num 열 값에 1을 증가시킴
    // const sql = `UPDATE Class SET Current_Students_Num=Current_Students_Num+1 WHERE Id=${data.Class_Id}`;

    /* 아래 쿼리는 위 쿼리와 다르게, 중복 신청 시 발생하는 오류를 방지하기 위하여 
    Student_takes_Class 테이블에 (Student_Id, Class_Id) 정보가 없을 때만 
    Current_Students_Num 열 값에 1을 증가시키도록 설계한 쿼리임 */
    const sql = `UPDATE Class SET Current_Students_Num=Current_Students_Num+1 WHERE Id=${data.Class_Id} AND NOT EXISTS (SELECT * FROM Student_takes_Class WHERE Student_Id=${data.Student_Id} AND Class_Id=${data.Class_Id})`;
    await promisePool.query(sql);
  },

  updateStudentTakesClass: async (data) => { // Student_takes_Class 테이블에 수강신청한 학생과 수업의 정보를 Insert 한다.
    // const sql = `INSERT INTO Student_takes_Class VALUES (${data.Student_Id}, ${data.Class_Id})`;

    /* 아래 쿼리는 위 쿼리와 다르게, 중복 신청 시 발생하는 오류를 방지하기 위하여 
    Student_takes_Class 테이블에 (Student_Id, Class_Id) 정보가 없을 때만 
    (Student_Id, Class_Id) 튜플을 삽입하도록 설계한 쿼리임 */
    // 참고 : https://moon15.tistory.com/entry/MySQL-%EB%8D%B0%EC%9D%B4%ED%84%B0-%ED%99%95%EC%9D%B8-%ED%9B%84-INSERT
    const sql = `INSERT INTO Student_takes_Class (Student_Id, Class_Id) SELECT ${data.Student_Id}, ${data.Class_Id} FROM DUAL WHERE NOT EXISTS(SELECT * FROM Student_takes_Class WHERE Student_Id = ${data.Student_Id} AND Class_Id = ${data.Class_Id})`;

    await promisePool.query(sql);
  },
};