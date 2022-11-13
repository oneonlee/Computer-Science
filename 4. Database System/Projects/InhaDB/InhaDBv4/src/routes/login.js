import express from "express";
import { selectSql } from "../database/sql";

const router = express.Router();

let loginId;
let loginPassword;

router.get('/', (req, res) => {
    res.render('login');
});

router.post('/', async (req, res) => {
    const vars = req.body;
    const student = await selectSql.setStudents();
    let whoAmI = '';
    let checkLogin = false;
    student.map((student) => {
        // ID가 Student_Id(학번)이고, PASSWORD는 Phone_number(전화번호)이라고 가정
        if (vars.id === String(student.Student_Id) /* Student 테이블의 Student_Id 속성은 INT 타입이므로
                                                    사용자가 입력한 STRING 타입의 vars.id와 비교하기 위해
                                                    student.Student_Id를 STRING 타입으로 형변환 시켜줌 */
            && vars.password === student.Phone_number) {
            console.log('login success!');
            checkLogin = true;
            if (vars.id === 'admin') {
                whoAmI = 'admin';
            } else {
                whoAmI = 'student';
            }
        }
    })
    loginId = vars.id;
    loginPassword = vars.password;
    if (checkLogin && whoAmI === 'admin') {
        res.redirect('/delete');
    } else if (checkLogin && whoAmI === 'student') {
        res.redirect('/select');
    } else {
        console.log('login failed!');
        res.send("<script>alert('로그인에 실패했습니다.'); location.href='/';</script>");
    }
})

export const loginInfo = {
    id: (req, res) => {
        return loginId;
    },
    password: (req, res) => {
        return loginPassword;
    },
};

module.exports = router;