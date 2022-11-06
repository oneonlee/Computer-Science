import express from 'express';
import { selectSql, updateSql } from '../database/sql';

const router = express.Router();

router.get('/student', async (_req, res) => {
    const student_res = await selectSql.getStudent();
    res.render('updateStudent', { // hbs 파일 이름 : updateStudent
        main_title: "UPDATE \'Student\' table",
        student_res,
    });
});
router.post('/student', async (req, res) => {
    const vars = req.body;
    const data = {
        Id: vars.id,
        Name: vars.name,
        Email: vars.email,
        Phone_number: vars.phonenumber,
        Major: vars.major,
        Student_Id: vars.studentid,
    }
    await updateSql.updateStudent(data);

    res.redirect('/update/student');
})

module.exports = router;