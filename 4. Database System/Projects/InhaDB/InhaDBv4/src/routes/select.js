import express from 'express';
import { selectSql } from '../database/sql';

const router = express.Router();

// 기존의 입력 값 불러오기
router.get('/', async (req, res) => {
    const student = await selectSql.setStudents();
    res.render('select', { // hbs 파일 이름 : select
        title: 'Student Info',
        student,
    });
});

module.exports = router;

