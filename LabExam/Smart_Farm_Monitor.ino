/*
 *
 * This Arduino UNO R4 code is made available for public use without any restriction
 *
 */
#include "arduino_secrets.h"
#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = SECRET_SSID;          // CHANGE TO YOUR WIFI SSID
const char WIFI_PASSWORD[] = SECRET_PASS;  // CHANGE TO YOUR WIFI PASSWORD

const char MQTT_BROKER_ADRRESS[] = "test.mosquitto.org";  // CHANGE TO MQTT BROKER'S ADDRESS
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "MyMyMy_Board";  // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "";                                            // CHANGE IT IF REQUIRED, empty if not required
const char MQTT_PASSWORD[] = "";                                            // CHANGE IT IF REQUIRED, empty if not required

// The MQTT topics that Arduino should publish/subscribe
const char PUBLISH_TOPIC[] = "it66070082/test";    // CHANGE IT AS YOU DESIRE
const char SUBSCRIBE_TOPIC[] = "it66070082/test";  // CHANGE IT AS YOU DESIRE

const int PUBLISH_INTERVAL = 60 * 1000;  // 60 seconds

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

void setup() {
  Serial.begin(9600);

  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    Serial.print("Arduino UNO R4 - Attempting to connect to SSID: ");
    Serial.println(WIFI_SSID);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    // wait 10 seconds for connection:
    delay(10000);
  }
  // print your board's IP address:
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  connectToMQTT();
}

void loop() {
  mqtt.loop();
  delay(5000);
  onMoistureChange();
  delay(5000);
  onThermistorChange();
  delay(5000);
  onLightSensorChange();
  delay(5000);
  onMQ135Change();
  delay(5000);
  onMQ8Change();
}

void connectToMQTT() {
  // Connect to the MQTT broker
  mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);

  // Create a handler for incoming messages
  mqtt.onMessage(messageHandler);

  Serial.print("Arduino UNO R4 - Connecting to MQTT broker");

  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();

  if (!mqtt.connected()) {
    Serial.println("Arduino UNO R4 - MQTT broker Timeout!");
    return;
  }

  // Subscribe to a topic, the incoming messages are processed by messageHandler() function
  if (mqtt.subscribe(SUBSCRIBE_TOPIC))
    Serial.print("Arduino UNO R4 - Subscribed to the topic: ");
  else
    Serial.print("Arduino UNO R4 - Failed to subscribe to the topic: ");

  Serial.println(SUBSCRIBE_TOPIC);
  Serial.println("Arduino UNO R4 - MQTT broker Connected!");
}

void sendToMQTT(String data) {

  // Publish the message to the MQTT topic
  mqtt.publish(PUBLISH_TOPIC, data);

  // Print debug information to the Serial Monitor in one line
  Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_TOPIC) + " | payload: " + String(data));
}

void messageHandler(String &topic, String &payload) {
  Serial.println("Arduino UNO R4 - received from MQTT: topic: " + topic + " | payload: " + payload);

}

void onMoistureChange()  {
  float Read = analogRead(A5);
  float moistureLevel = map(Read, 1023, 0, 0, 100);
  String output = "Moisture: " + String(moistureLevel);
  sendToMQTT(output);
}

void onThermistorChange()  {
  float RT, VR, ln, Temp, T0, Read;
  int RT0 = 10000;
  int B = 3977;
  float a=A0;

  int VCC = 5;
  int R = 10000;

  T0 = 25 + 273.15;
  Read = analogRead(A4);
  Read = (5.00 / 1023.00) * Read;
  VR = VCC - Read;
  RT = Read / (VR / R);

  ln = log(RT / RT0);
  Temp = (1 / ((ln / B) + (1 / T0)));

  Temp = Temp - 273.15;

  String output = "Temp: " + String(Temp);
  sendToMQTT(output);

}

void onLightSensorChange()  {
  int Read = analogRead(A3);
  int lightLevel = map(Read, 1023, 0, 0, 100);
  // Update Cloud
  String output = "lightLevel: " + String(lightLevel);
  sendToMQTT(output);
}

void onMQ135Change()  {
  float Read = analogRead(A2);
  int MQ135Level = map(Read, 1023, 0, 0, 100);
  String output = "MQ135Level: " + String(MQ135Level);
  sendToMQTT(output);
}

void onMQ8Change()  {
  float Read = analogRead(A1);
  int MQ8Level = map(Read, 0, 1023, 0, 100);
  String output = "MQ8Level: " + String(MQ8Level);
  sendToMQTT(output);
}