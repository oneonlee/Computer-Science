import express from 'express';
import { manageSql } from '../database/sql';

const router = express.Router();

router.get('/', async (req, res) => {
    const data = {
        username: req.cookies.username,
        name: req.cookies.name,
    };
    const vehicles = await manageSql.get10Vehicles(data);
    res.render('manage', { // hbs 파일 이름 : manage
        title: `Vehicle Reservation | ${req.cookies.name}`,
        display_type: '10 Vehicles',
        vehicles,
    });
});
router.get('/all', async (req, res) => {
    const data = {
        username: req.cookies.username,
        name: req.cookies.name,
    };
    const vehicles = await manageSql.getAllVehicles(data);
    res.render('manage', { // hbs 파일 이름 : manage
        title: `Vehicle Reservation | ${req.cookies.name}`,
        display_type: 'All Vehicles',
        vehicles,
    });
});
router.get('/ONSALE', async (req, res) => {
    const data = {
        username: req.cookies.username,
        name: req.cookies.name,
    };
    const vehicles = await manageSql.getOnSaleVehicles(data);
    res.render('manage', { // hbs 파일 이름 : manage
        title: `Vehicle Reservation | ${req.cookies.name}`,
        display_type: 'On Sale Vehicles',
        vehicles,
    });
});
router.get('/RESERVED', async (req, res) => {
    const data = {
        username: req.cookies.username,
        name: req.cookies.name,
    };
    const vehicles = await manageSql.getReservedVehicles(data);
    res.render('manage', { // hbs 파일 이름 : manage
        title: `Vehicle Reservation | ${req.cookies.name}`,
        display_type: 'Reserved Vehicles',
        vehicles,
    });
});
router.get('/SOLDOUT', async (req, res) => {
    const data = {
        username: req.cookies.username,
        name: req.cookies.name,
    };
    const vehicles = await manageSql.getSoldVehicles(data);
    res.render('manage', { // hbs 파일 이름 : manage
        title: `Vehicle Reservation | ${req.cookies.name}`,
        display_type: 'Sold Out Vehicles',
        vehicles,
    });
});

// Create 버튼을 눌렀을 경우 createVehicle 트랜잭션을 실행
router.post('/Create', async (req, res) => {
    const vars = req.body;
    const data = {
        Vin: vars.vin,
        Model: vars.model,
        Price: vars.price,
        Status: vars.status,
        username: req.cookies.username,
        name: req.cookies.name,
    }
    await manageSql.createVehicle(data);

    res.redirect('/manage');
})

// Update 버튼을 눌렀을 경우 updateVehicle 트랜잭션을 실행
router.post('/Update', async (req, res) => {
    const vars = req.body;
    const data = {
        Vid: vars.vid,
        Vin: vars.vin,
        Model: vars.model,
        Price: vars.price,
        Status: vars.status,
    }
    await manageSql.updateVehicle(data);

    res.redirect('/manage');
})

// Delete 버튼을 눌렀을 경우 deleteVehicle 트랜잭션을 실행
router.post('/Delete', async (req, res) => {
    const data = {
        Vid: req.body.delBtn,
        Dealer_id: req.body.dealer_id,
    };

    await manageSql.deleteVehicle(data);
    res.redirect('/manage');
});


module.exports = router;