#include <WiFiS3.h>
#include <MQTTClient.h>

const char* ssid = "iPhone 12 Pro Max";      // Your SSID
const char* password = "Natthapong_34";  // Your Password

const char MQTT_BROKER_ADRRESS[] = "phycom.it.kmitl.ac.th";  // CHANGE TO MQTT BROKER'S ADDRESS
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "66070101";  // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "66070101";                        // CHANGE IT IF REQUIRED, empty if not required
const char MQTT_PASSWORD[] = "";                        // CHANGE IT IF REQUIRED, empty if not required

// The MQTT topics that Arduino should publish/subscribe
// const char PUBLISH_TOPIC[] = "66070101/temp";    // CHANGE IT AS YOU DESIRE
// const char PUBLISH_TOPIC[] = "66070101/light";    // CHANGE IT AS YOU DESIRE
const char PUBLISH_TOPIC[] = "66070101/food";    // CHANGE IT AS YOU DESIRE
const char SUBSCRIBE_TOPIC[] = "66070101/venus";  // CHANGE IT AS YOU DESIRE

const int PUBLISH_INTERVAL = 5000;

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;

void setup() {
  Serial.begin(9600); //

  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    Serial.print("Arduino UNO R4 - Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, password);

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

  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    sendToMQTT();
    lastPublishTime = millis();
  }
  delay(1000);
}

void sendToMQTT() {

  // int val = millis();
  // Clear the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Set the trigPin HIGH for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Read the echoPin, return the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    
    // Calculate the distance in cm and inches
    distanceCm = duration * 0.034 / 2;
    distanceInch = duration * 0.0133 / 2;
    Serial.print(distanceCm);
    Serial.println();
  if (distanceCm > 20) {
      String val_str = "off";
      char messageBuffer[10];
      val_str.toCharArray(messageBuffer, 10);

      // Publish the message to the MQTT topic
      mqtt.publish(PUBLISH_TOPIC, messageBuffer);

      // Print debug information to the Serial Monitor in one line
      Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_TOPIC) + " | payload: " + String(messageBuffer));
  } else {
      String val_str = "on";
      char messageBuffer[10];
      val_str.toCharArray(messageBuffer, 10);

      // Publish the message to the MQTT topic
      mqtt.publish(PUBLISH_TOPIC, messageBuffer);

      // Print debug information to the Serial Monitor in one line
      Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_TOPIC) + " | payload: " + String(messageBuffer));
  }

  // // Convert the string to a char array for MQTT publishing
  // char messageBuffer[10];
  // val_str.toCharArray(messageBuffer, 10);

  // // Publish the message to the MQTT topic
  // mqtt.publish(PUBLISH_TOPIC, messageBuffer);

  // // Print debug information to the Serial Monitor in one line
  // Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_TOPIC) + " | payload: " + String(messageBuffer));
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

void messageHandler(String &topic, String &payload) {
  Serial.println("Arduino UNO R4 - received from MQTT: topic: " + topic + " | payload: " + payload);
  int val = payload.toInt();
  analogWrite(9, val);
  // You can process the incoming data , then control something
  /*
  process something
  */
}

float betaCalculation(float R_thermistor) {
    float T0 = 298.15; // Reference temperature (25°C in Kelvin)
    float R0 = 10000;  // Resistance at 25°C (10kΩ)
    float beta = 105103; // Beta coefficient for TTC05103

    // Calculate temperature in Kelvin
    float tempK = 1.0 / ((1.0 / T0) + (1.0 / beta) * log(R_thermistor / R0));

    // Convert Kelvin to Celsius
    float tempC = tempK - 273.15;
    return tempC;
}