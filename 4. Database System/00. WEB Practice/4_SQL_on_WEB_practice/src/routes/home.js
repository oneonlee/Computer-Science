import express from 'express';
import { insertSql } from '../database/sql';

const router = express.Router();

// get과 post 방식으로 구분
router.get('/', (_req, res) => {
    res.render('home');
})

router.post('/', (req, res) => {
    const vars = req.body;
    const var_length = Object.keys(req.body).length; // employee에 대한 요청인지, department에 대한 요청인지 구분하기 위해 길이라는 기준을 사용하여 구분

    if (var_length > 4) {
        const data = {
            Fname: vars.fname,
            Minit: vars.minit,
            Lname: vars.lname,
            Ssn: vars.ssn,
            Bdate: vars.bdate,
            Address: vars.address,
            Sex: vars.sex,
            Salary: vars.salary,
            Super_ssn: vars.superssn,
            Dno: vars.dno,
        };
        insertSql.setEmployee(data);
    } else {
        const data = {
            Dname: vars.dname,
            Dnumber: vars.dnumber,
            Mgr_ssn: vars.mgrssn,
            Mgr_start_date: vars.mgrstartdaate,
        };
        insertSql.setDepartment(data);
    }
    res.redirect('/');
})

module.exports = router;