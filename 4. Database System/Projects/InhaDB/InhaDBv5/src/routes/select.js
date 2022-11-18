// Copyright 2021 kms
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

import express from "express";
import { selectSql, updateSql } from '../database/sql'; // sql import

const router = express.Router();

router.get('/', async function (req, res) {
    const classes = await selectSql.getClasses(); // "Class" 테이블의 정보 불러오기

    if (req.cookies.user_id) {
        res.render('select', { // hbs 파일 이름 : select
            title: "2022학년 2학기 수강신청",
            classes, // 불러온 class 정보 같이 넘겨주기
            user_id: req.cookies.user_id,
            user_name: req.cookies.user_name,
        });
    } else {
        res.render('/')
    }
});

// 수강 신청 버튼을 눌렀을 경우 update query를 실행하며 신청 결과를 DB에 업데이트함
router.post('/', async (req, res) => {
    console.log('update router:', req.body.signUpBtn);

    const data = {
        Student_Id: req.cookies.user_id, // Student 테이블의 Id
        Class_Id: req.body.signUpBtn,    // Class 테이블의 Id
    };

    await updateSql.updateClass(data);
    await updateSql.updateStudentTakesClass(data);

    console.log(`${req.cookies.user_name} 학생의 ${req.body.signUpBtn}번 과목의 수강 신청이 완료되었습니다!`);

    res.redirect('/sugang');
});

module.exports = router;