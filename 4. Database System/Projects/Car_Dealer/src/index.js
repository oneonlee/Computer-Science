import express from 'express';
import logger from 'morgan';
import path from 'path';

import loginRouter from './routes/login';
import manageRouter from './routes/manage';
import reserveRouter from './routes/reserve';

const PORT = 3000;

const app = express(); // 'express'라는 클래스에 대한 'app' 객체 생성

// app.use(express.static(path.join(__dirname, '/src')));
app.use(express.urlencoded({ extended: false })) // encoding 여부 : false
app.use(express.json()); // json 형태로 가져온다.

app.set('views', path.join(__dirname, './views')); // 'views'라는 엔진 사용
app.set('view engine', 'hbs');

app.use(logger('dev'));

app.use('/', loginRouter);
app.use('/manage', manageRouter);
app.use('/reserve', reserveRouter);

app.listen(PORT, () => {
    console.log(`Server is running at http://localhost:${PORT}`)
});