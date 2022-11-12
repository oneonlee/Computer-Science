import express from "express";
import { selectSql } from "../database/sql";

const router = express.Router();

router.get('/', (req, res) => {
    res.render('login');
});

router.post('/', async (req, res) => {
    const vars = req.body;
    const user = await selectSql.setUsers();
    let whoAmI = '';
    let checkLogin = false;

    user.map((user) => {
        console.log(user.Id);
        if (vars.id === user.Id && vars.password === user.Password) {
            console.log('login success!');
            checkLogin = true;
            if (vars.id === 'admin') {
                whoAmI = 'admin';
            } else {
                whoAmI = 'user';
            }
        }
    })

    if (checkLogin && whoAmI === 'admin') {
        res.redirect('/delete');
    } else if (checkLogin && whoAmI === 'user') {
        res.redirect('/select');
    } else {
        console.log('login failed!');
        res.send("<script>alert('로그인에 실패했습니다.'); location.href='/';</script>");
    }
})

module.exports = router;