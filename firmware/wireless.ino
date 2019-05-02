// #include <Arduino.h>
// #include <ESP8266WiFi.h>
// #include <PubSubClient.h>

// WiFiClient espClient;
// PubSubClient client(espClient);

// long lastMsg = 0;
// char msg[50];
// int value = 0;

// void callback(char *topic, byte *payload, unsigned int length)
// {
//     Serial.print("Message arrived [");
//     Serial.print(topic);
//     Serial.print("] ");

//     for (int i = 0; i < length; i++)
//     {
//         Serial.print((char)payload[i]);
//     }

//     Serial.println();
// }

// void reconnect()
// {
//     while (!client.connected())
//     {
//         Serial.print("Attempting MQTT connection...");
//         String clientId = "ESP8266Client-";
//         clientId += String(random(0xffff), HEX);

//         if (client.connect(clientId.c_str()))
//         {
//             Serial.println("connected");
//             client.publish("test/topic", "hello world!");
//             client.subscribe("inTopic");
//         }
//         else
//         {
//             Serial.print("failed, rc=");
//             Serial.print(client.state());
//             Serial.println(" try again in 5 seconds");
//             delay(5000);
//         }
//     }
// }

// void setup()
// {
//     Serial.begin(115200);
//     delay(1000);
//     Serial.print("initializing wifi...");

//     WiFi.mode(WIFI_STA);
//     WiFi.begin("ARM Insight", "4Rm1N51GH7");

//     Serial.println("initialized");

//     while (WiFi.status() != WL_CONNECTED)
//     {
//         delay(750);
//         Serial.print(".");
//     }

//     Serial.println("...connected");

//     Serial.print("IP Address: ");
//     Serial.println(WiFi.localIP());

//     client.setServer("tdc.app", 1883);
//     client.setCallback(callback);
// }

// void loop()
// {
//     if (!client.connected())
//     {
//         reconnect();
//     }

//     client.loop();

//     long now = millis();
//     if (now - lastMsg > 2000)
//     {
//         lastMsg = now;
//         ++value;
//         snprintf(msg, 50, "hello world #%ld", value);
//         Serial.print("Publish message: ");
//         Serial.println(msg);
//         client.publish("test/topic", "hello from esp!");
//     }
// }
