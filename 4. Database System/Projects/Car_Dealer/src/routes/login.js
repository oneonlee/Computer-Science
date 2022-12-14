import cookieParser from "cookie-parser";
import express from "express";
import expressSession from 'express-session';
import { loginSql } from "../database/sql";

const router = express.Router();

// 쿠키 및 세션 설정
router.use(cookieParser());
router.use(expressSession({
    secret: 'dilab',
    resave: true,
    saveUninitialized: true,
}))

router.get('/', (req, res) => {
    if (req.cookies.username) { // 로그인을 한 유저라면
        if (req.cookies.whoAmI === 'admin') {
            res.redirect('/manage');
        } else if (req.cookies.whoAmI === 'user') {
            res.redirect('/reserve');
        }
    } else { // 로그인을 하지 않은 유저라면
        res.render('login'); // render login.hbs
    }
});

router.get('/logout', (req, res) => {
    if (req.cookies.whoAmI) {
        res.clearCookie('username')
        res.clearCookie('name')
        res.clearCookie('whoAmI')
        console.log('Logout Success!')
        res.redirect('/');
    } else {
        res.redirect('/');
    }
})

router.post('/', async (req, res) => {
    const vars = req.body;

    const admin = await loginSql.getSalesperson();
    const user = await loginSql.getCustomer();

    let username = '';
    let name = '';
    let whoAmI = '';
    let checkLogin = false;

    admin.map((admin) => {
        if (vars.id === admin.Susername && vars.password === admin.Spassword) {
            checkLogin = true;
            username = admin.Susername;
            name = admin.Sname;
            whoAmI = 'admin';
        }
    })

    user.map((user) => {
        if (vars.id === user.Cusername && vars.password === user.Cpassword) {
            checkLogin = true;
            username = user.Cusername;
            name = user.Cname;
            whoAmI = 'user';
        }
    })

    if (checkLogin) {
        console.log('Login Success!')
        res.cookie('username', username, {
            expires: new Date(Date.now() + 3600000), // ms 단위 (3600000: 1시간 유효)
            httpOnly: true
        })
        res.cookie('name', name, {
            expires: new Date(Date.now() + 3600000), // ms 단위 (3600000: 1시간 유효)
            httpOnly: true
        })
        res.cookie('whoAmI', whoAmI, {
            expires: new Date(Date.now() + 3600000), // ms 단위 (3600000: 1시간 유효)
            httpOnly: true
        })
        // res.redirect('/');
        if (whoAmI === 'admin') {
            console.log('Salesperson login success!');
            res.redirect('/manage');
        } else if (whoAmI === 'user') {
            console.log('Customer login success!');
            res.redirect('/reserve');
        }
    } else {
        console.log('login failed!');
        res.send("<script>alert('Incorrect ID or Password!'); location.href='/';</script>");
    }
})

module.exports = router;