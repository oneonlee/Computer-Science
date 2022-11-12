import express from 'express';
import { selectSql } from '../database/sql';

const router = express.Router();

router.get('/', async (req, res) => {
    const department = await selectSql.getDepartment();

    res.render('select', {
        title: 'IT 공대',
        department,
    });
});

module.exports = router;