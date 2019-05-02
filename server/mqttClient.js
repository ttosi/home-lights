const mqtt = require('mqtt');
let client;

module.exports = {
    connect: (server) => {
        return new Promise((resolve, reject) => {
            client = mqtt.connect(server);
            client.on('connect', (err) => {
                // if(err) reject(err);
                resolve(true);
            })
        });
    },
    subscribe: (topic) => {
        return new Promise((resolve, reject) => {
            if(!client) reject('not connected to mqtt server');
            // client.sub
        });
    },
    publish: (topic, message) => {
        return new Promise((resolve, reject) => {
            if(!client) reject('not connected to mqtt server');
            client.publish(topic, message, err => {
                if(err) reject(err);
                resolve(true)
            });
        });
    }
};