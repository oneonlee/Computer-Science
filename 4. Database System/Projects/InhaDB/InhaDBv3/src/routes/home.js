import express from 'express';
import { insertSql } from '../database/sql';

const router = express.Router();

// get과 post 방식으로 구분
router.get('/', (_req, res) => {
    res.render('home');
})

router.post('/', (req, res) => {
    const vars = req.body;

    const data = {
        Id: vars.id,
        Name: vars.name,
        Position: vars.position,
        Department_Id: vars.departmentid,
    };
    insertSql.setEmployee(data);

    res.redirect('/');
})

module.exports = router;