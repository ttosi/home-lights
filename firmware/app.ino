#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <FastLED.h>
#include <PubSubClient.h>

#define NUM_LEDS 286
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

WiFiClient espClient;
PubSubClient mqttClient(espClient);

String clientId = "ESP8266Client-";

long lastMsg = 0;
char msg[50];
int value = 0;

void setup()
{
    Serial.begin(115200);
    delay(500);
    Serial.println("serial started!");

    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(255);

    fillSolid('o');

    Serial.print("starting wifi");
    WiFi.mode(WIFI_STA);
    WiFi.begin("Frontier6448", "1235281875");

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(250);
    }

    Serial.print("...connected (");
    Serial.print(WiFi.localIP());
    Serial.println(")");

    mqttClient.setServer("tdc.app", 1883);
    mqttClient.setCallback(mqttCallback);
}

void loop()
{
    if (!mqttClient.connected())
    {
        mqttConnect();
        delay(250);
    }

    mqttClient.subscribe("test/topic");
    mqttClient.loop();

    // fillSolid('r');
    // delay(2000);

    // fillSolid('g');
    // delay(2000);

    // fillSolid('b');
    // delay(1500);

    theaterChaseRainbow(50);

    delay(500);
}

void mqttConnect()
{
    Serial.print("connecting to mqtt broker..");
    while (!mqttClient.connected())
    {
        clientId += String(random(0xffff), HEX);
        mqttClient.connect(clientId.c_str());
        Serial.print(".");
        delay(250);
    }
    Serial.println(".connected!");
}

void mqttCallback(char *topic, byte *payload, unsigned int length)
{
    for (int i = 0; i < length; i++)
    {
        Serial.print((char)payload[i]);
    }

    Serial.println();
}

void fillSolid(char color)
{
    CRGB fillColor;
    switch (color)
    {
    case 'r': // red
        fillColor = CRGB::Red;
        break;
    case 'g': // green
        fillColor = CRGB::Green;
        break;
    case 'b': // blue
        fillColor = CRGB::Blue;
        break;
    case 'y': // yellow
        fillColor = CRGB::Yellow;
        break;
    case 'w': // white
        fillColor = CRGB::White;
        break;
    case 'o': // off (black)
        fillColor = CRGB::Black;
        break;
    default:
        break;
    }

    fill_solid(leds, NUM_LEDS, fillColor);
    FastLED.show();
}

void theaterChaseRainbow(int SpeedDelay)
{
    byte *c;

    for (int j = 0; j < 256; j++)
    {
        for (int q = 0; q < 3; q++)
        {
            for (int i = 0; i < NUM_LEDS; i = i + 3)
            {
                c = Wheel((i + j) % 255);
                setPixel(i + q, *c, *(c + 1), *(c + 2));
            }
            FastLED.show();

            delay(SpeedDelay);

            for (int i = 0; i < NUM_LEDS; i = i + 3)
            {
                setPixel(i + q, 0, 0, 0);
            }
        }
    }
}

void setPixel(int Pixel, byte red, byte green, byte blue)
{
    leds[Pixel].r = red;
    leds[Pixel].g = green;
    leds[Pixel].b = blue;
}

byte *Wheel(byte WheelPos)
{
    static byte c[3];

    if (WheelPos < 85)
    {
        c[0] = WheelPos * 3;
        c[1] = 255 - WheelPos * 3;
        c[2] = 0;
    }
    else if (WheelPos < 170)
    {
        WheelPos -= 85;
        c[0] = 255 - WheelPos * 3;
        c[1] = 0;
        c[2] = WheelPos * 3;
    }
    else
    {
        WheelPos -= 170;
        c[0] = 0;
        c[1] = WheelPos * 3;
        c[2] = 255 - WheelPos * 3;
    }

    return c;
}