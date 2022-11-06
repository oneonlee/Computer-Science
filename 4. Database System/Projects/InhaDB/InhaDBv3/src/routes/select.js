import express from 'express';
import { selectSql } from '../database/sql';

const router = express.Router();

router.get('/', async (_req, res) => {
    const Building = await selectSql.getBuilding();
    const Class = await selectSql.getClass();
    const Club = await selectSql.getClub();
    const Club_has_Student = await selectSql.getClub_has_Student();
    const Department = await selectSql.getDepartment();
    const Department_manages_Student = await selectSql.getDepartment_manages_Student();
    const Employee = await selectSql.getEmployee();
    const Room = await selectSql.getRoom();
    const Student = await selectSql.getStudent();
    const Student_takes_Class = await selectSql.getStudent_takes_Class();


    res.render('select', {
        main_title: "Tables_in_InhaDB",
        title1: "Building",
        title2: "Class",
        title3: "Club",
        title4: "Club_has_Student",
        title5: "Department",
        title6: "Department_manages_Student",
        title7: "Employee",
        title8: "Room",
        title9: "Student",
        title10: "Student_takes_Class",
        Building,
        Class,
        Club,
        Club_has_Student,
        Department,
        Department_manages_Student,
        Employee,
        Room,
        Student,
        Student_takes_Class,
    })
})

module.exports = router;