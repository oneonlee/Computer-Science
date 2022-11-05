import express from 'express';
import { selectSql, updateSql } from '../database/sql';

const router = express.Router();

router.get('/employee', async (_req, res) => {
    const emp_res = await selectSql.getEmployee();
    res.render('updateEmployee', { // hbs 파일 이름 : updateEmployee
        title: '직원 테이블 갱신',
        emp_res,
    });
});
router.post('/employee', async (_req, res) => {
    await updateSql.updateEmployee();

    res.redirect('/update/employee');
});

router.get('/department', async (_req, res) => {
    const dept_res = await selectSql.getDepartment();
    res.render('updateDepartment', {
        title: '부서 테이블 갱신',
        dept_res,
    });
});
router.post('/department', async (req, res) => {
    const vars = req.body;
    const data = {
        Dname: vars.dname,
    }
    await updateSql.updateDepartment(data);

    res.redirect('/update/department');
})

module.exports = router;