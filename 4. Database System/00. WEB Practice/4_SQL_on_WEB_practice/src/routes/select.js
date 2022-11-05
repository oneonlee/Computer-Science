import express from 'express';
import {selectSql} from '../database/sql';

const router = express.Router();

router.get('/', async (_req, res) => {
    const employee = await selectSql.getEmployee();
    const department = await selectSql.getDepartment();
    
    res.render('select', {
        title: '직원 테이블',
        title2: '부서 테이블',
        employee,
        department,
    })
})

module.exports = router;