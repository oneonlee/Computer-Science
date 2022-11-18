import cookieParser from "cookie-parser";
import express from "express";
import expressSession from 'express-session';


const router = express.Router();

// 쿠키 및 세션 설정
router.use(cookieParser());
router.use(expressSession({
    secret: 'dilab',
    resave: true,
    saveUninitialized: true,
}))

router.get('/logout', (req, res) => {
    if (req.cookies.user_id) { // 로그인을 한 유저라면
        res.clearCookie('user_id') // 'user_id'라는 쿠키 초기화
        res.clearCookie('user_name') // 'user_name'이라는 쿠키 초기화
        // 쿠키를 초기화하며 로그인이 풀리게 된다.
        res.redirect("/logout");
    } else { // 로그인을 하지 않았는데, /logout 페이지로 들어왔다면, 로그아웃 거부
        res.redirect("/");
    }
})

module.exports = router;