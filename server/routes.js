const mqtt = require('./mqttClient');

const router = function (app) {
    // endpoint to control ws2812b light strips at home
    // rest params
    //  :room = room of the house (livingroom | bedroom | kitchen)
    //  :location = the location of the strip (ceiling)
    //  :type = the type of action for the light strip (fill | pallette)
    //  :value = if type is color then a color name or comma separated RGB
    //           if type is pallette then name of pallette to use
    // query string params
    //  - brightness = integer value between 0 and 255
    app.get("/home/:room/:location/:type/:value", (req, res) => {
        const room = req.params.room;
        const location = req.params.location;
        const type = req.params.type;
        const value = req.params.value;
        const brightness = req.query.brightness || 255;

        console.log(room, location, type, value, brightness);

        let message = {
            type: type,
            value: value,
            brightness: brightness
        };

        mqtt.publish('/home/livingroom/ceiling', JSON.stringify(message))
            .then(() => {
                console.log('successfully published to device');
            });

        res.sendStatus(200);
    });
}

module.exports = router;