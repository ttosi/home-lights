'use strict';

const mqtt = require('mqtt');
let client = undefined;

module.exports = {
    connect: (server) => {
        return new Promise((resolve, reject) => {
            if(!client) {
                client = mqtt.connect(server);
            }

            client.on('connect', (conn, err) => {
                if(err) { 
                    reject(err);
                    throw err;
                }
                resolve(true);
            });
        });
    },
    publish: (topic, message) => {
        return new Promise((resolve, reject) => {
            if(!client) {
                reject('not connected to mqtt server');
            }

            client.publish(topic, message, null, cb => {
                console.log('successfully published to device');                
            });
        });
    },
    subscribe: (topic) => {
        return new Promise((resolve, reject) => {
            if(!client) { 
                reject('not connected to mqtt server');
            }
            // TODO finish subscribe if needed
        });
    }
};