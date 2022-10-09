import express from "express";
import bodyParser from "body-parser";
import path from 'path';
import sql from './sql';

const PORT_NUMBER = 3000;
const app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

app.get("/Insert/", async (req, res) => {
    const truncate_Tables = await sql.delTables();
    const insert_Values = await sql.setValues();
    res.send(`
    <h1>INSERT COMPLETED!<h1/>
    <h2>Click <a href="/">HERE</a> to go to main page!</h2>
    `);
})
app.get("/Building/", async (req, res) => {
    const building_table = await sql.getBuilding();
    res.json({ "Building": building_table })
});

app.get("/Class/", async (req, res) => {
    const class_table = await sql.getClass();
    res.json({ "Class": class_table })
});

app.get("/Club/", async (req, res) => {
    const club_table = await sql.getClub();
    res.json({ "Club": club_table })
});

app.get("/Club_has_Student/", async (req, res) => {
    const club_has_student_table = await sql.getClubHasStudent();
    res.json({ "Club_has_Student": club_has_student_table })
});

app.get("/Department/", async (req, res) => {
    const department_table = await sql.getDepartment();
    res.json({ "Department": department_table })
});

app.get("/Department_manages_Student/", async (req, res) => {
    const department_manages_student_table = await sql.getDepartmentManagesStudent();
    res.json({ "Department_manages_Student": department_manages_student_table })
});

app.get("/Employee/", async (req, res) => {
    const employee_table = await sql.getEmployee();
    res.json({ "Employee": employee_table })
});

app.get("/Room/", async (req, res) => {
    const room_table = await sql.getRoom();
    res.json({ "Room": room_table })
});

app.get("/Student/", async (req, res) => {
    const student_table = await sql.getStudent();
    res.json({ "Student": student_table })
});

app.get("/Student_takes_Class/", async (req, res) => {
    const student_takes_class_table = await sql.getStudentTakesClass();
    res.json({ "Student_takes_Class": student_takes_class_table })
});

app.get("/", (req, res) => {
    res.sendFile(path.join(__dirname + '/index.html'));
});

app.listen(PORT_NUMBER, () => {
    console.log(`Server is running on port ${PORT_NUMBER}.`);
});