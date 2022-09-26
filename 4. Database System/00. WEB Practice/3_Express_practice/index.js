import express from "express";
import bodyParser from "body-parser";
import path from 'path';
import sql from './sql';

const PORT_NUMBER = 3000;
const app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

app.get("/", async (req, res) => {
    const employee = await sql.getEmployee();
    // console.log(employee);
    // res.sendFile(path.join(__dirname + 'index.html'));
    res.json({ "Employee": employee })
});

app.get("/", (req, res) => {
    res.sendFile(path.join(__dirname + '/index.html'));
});

app.listen(PORT_NUMBER, () => {
    console.log(`Server is running on port ${PORT_NUMBER}.`);
});