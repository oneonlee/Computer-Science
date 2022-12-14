import express from 'express';
import { reserveSql } from '../database/sql';

const router = express.Router();

router.get('/', async (req, res) => {
    const data = {
        username: req.cookies.username,
        name: req.cookies.name,
    };

    const user_reservation = await reserveSql.getUserReservation(data);
    const available_vehicles = await reserveSql.get10AvailableVehicles();

    var isEmpty = false;
    if (Array.isArray(user_reservation) && user_reservation.length == 0)
        isEmpty = true;

    res.render('reserve', {
        title: `Vehicle Reservation | ${req.cookies.name}`,
        user_reservation,
        available_vehicles,
        isEmpty,
    }
    );
});


router.get('/all', async (req, res) => {
    const data = {
        username: req.cookies.username,
        name: req.cookies.name,
    };

    const user_reservation = await reserveSql.getUserReservation(data);
    const available_vehicles = await reserveSql.getAvailableVehicles();

    var isEmpty = false;
    if (Array.isArray(user_reservation) && user_reservation.length == 0)
        isEmpty = true;

    res.render('reserve', {
        title: `Vehicle Reservation | ${req.cookies.name}`,
        user_reservation,
        available_vehicles,
        isEmpty,
    }
    );
});

// Apply 버튼을 눌렀을 경우 setUserReservation query를 실행
router.post('/Apply', async (req, res) => {
    let username = req.cookies.username;
    let name = req.cookies.name;
    const vars = req.body;
    const data = {
        Vid: vars.vid,
        Salesperson_id: vars.salesperson_id,
        username: username,
        name: name,
    }
    await reserveSql.setUserReservation(data);

    res.redirect('/reserve');
});

// Delete 버튼을 눌렀을 경우 removeUserReservation query를 실행
router.post('/Delete', async (req, res) => {
    const data = {
        Dealer_id: req.body.dealer_id,
        Vid: req.body.delBtn,
    };

    await reserveSql.removeUserReservation(data);
    res.redirect('/reserve');
});

module.exports = router;