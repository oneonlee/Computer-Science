import express from 'express';
import { selectSql, deleteSql } from '../database/sql';

const router = express.Router();

// 기존의 입력 값 불러오기
router.get('/', async (req, res) => {
    const student_takes_class = await selectSql.setStudent_takes_Class();
    res.render('delete', { // hbs 파일 이름 : delete
        title: 'Drop the Class',
        student_takes_class,
    });
});

// 삭제 버튼을 눌렀을 경우 delete query를 실행하며 조회 페이지로 이동
router.post('/', async (req, res) => {
    console.log('delete router:', req.body.delBtn);
    const deleteDataInfo = req.body.delBtn.split(',');
    const data = {
        Student_Id: deleteDataInfo[0],
        Class_Id: deleteDataInfo[1],
    };

    await deleteSql.deleteStudent_takes_Class(data);

    res.redirect('/delete');
});

module.exports = router;