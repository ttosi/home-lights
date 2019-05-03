const express = require('express');
const routes = require('./routes');
const mqtt = require('./mqttClient');

const app = express();

routes(app);

const server = app.listen(process.env.PORT || 3000, () => {
    console.log(`server listening on port ${ process.env.PORT || 3000 }`);
    mqtt.connect('mqtt://tdc.app')
        .then(() => {
            console.log('connected to mqtt broker');
        });
});



// const mqttClient = mqtt.connect('mqtt://tdc.app');
// mqttClient.on('connect', () => {
//     mqttClient.subscribe('test', err => {
//         if(err) throw err;
//         mqttClient.publish('test', 'hell yeah!!');
//     })
// });