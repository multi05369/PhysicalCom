/*
 *
 * This Arduino UNO R4 code is made available for public use without any restriction
 *
 */
#include <WiFiS3.h>
#include <MQTTClient.h>

const byte numRows = 4; // Number of rows on the keypad
const byte numCols = 4; // Number of columns on the keypad


const char WIFI_SSID[] = "iPhone 12 Pro Max";          // CHANGE TO YOUR WIFI SSID
const char WIFI_PASSWORD[] = "Natthapong_34";  // CHANGE TO YOUR WIFI PASSWORD

const char MQTT_BROKER_ADRRESS[] = "phycom.it.kmitl.ac.th";  // CHANGE TO MQTT BROKER'S ADDRESS
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "66070101_broad";  // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "broad_101";                                            // CHANGE IT IF REQUIRED, empty if not required
const char MQTT_PASSWORD[] = "";                                            // CHANGE IT IF REQUIRED, empty if not required

// The MQTT topics that Arduino should publish/subscribe
const char PUBLISH_TOPIC[] = "66070101/food";    // CHANGE IT AS YOU DESIRE
const char SUBSCRIBE_TOPIC[] = "66070101/food";  // CHANGE IT AS YOU DESIRE

const int PUBLISH_INTERVAL = 60 * 1000;  // 60 seconds

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

char keymap[numRows][numCols] = 
{
  {'1', '2', '3', 'A'}, 
  {'4', '5', '6', 'B'}, 
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {9, 8, 7, 6}; 
byte colPins[numCols] = {5, 4, 3, 2};

// Define a value for NO_KEY
#define NO_KEY '\0'

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

  // Set row pins as OUTPUT and column pins as INPUT_PULLUP
  for (int i = 0; i < numRows; i++) {
      pinMode(rowPins[i], OUTPUT);
      digitalWrite(rowPins[i], HIGH); // Initially, set all rows HIGH
  }
  for (int i = 0; i < numCols; i++) {
      pinMode(colPins[i], INPUT_PULLUP); // Enable pull-up resistors on column pins
  }

  connectToMQTT();
}

void loop() {
  mqtt.loop();
  //ultrasonic();

  char keypressed = getKey();
  sendToMQTT(String(keypressed));

  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    sendToMQTT();
    lastPublishTime = millis();
  }

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

void sendToMQTT() {

  char keypressed = getKey();
  String val_str = String(keypressed);

  // Convert the string to a char array for MQTT publishing
  char messageBuffer[10];
  val_str.toCharArray(messageBuffer, 10);

  // Publish the message to the MQTT topic
  mqtt.publish(PUBLISH_TOPIC, messageBuffer);

  // Print debug information to the Serial Monitor in one line
  Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_TOPIC) + " | payload: " + String(messageBuffer));
}

void sendToMQTT(String data) {

   // Publish the message to the MQTT topic
  mqtt.publish(PUBLISH_TOPIC, data);

  // Print debug information to the Serial Monitor in one line
  Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_TOPIC) + " | payload: " + String(data));
}

void messageHandler(String &topic, String &payload) {
  //Serial.println("Arduino UNO R4 - received from MQTT: topic: " + topic + " | payload: " + payload);

}

// void ultrasonic(){
//   digitalWrite(4,1);
//   delayMicroseconds(10);
//   digitalWrite(4,0);

//   int pulseWidth = pulseIn(2,1);

//   long distanct = pulseWidth/29/2;

//   Serial.println(distanct);

//   if (distanct > 20){
//     sendToMQTT("off");
//   }else{
//     sendToMQTT("on");
//   }
// }

char getKey() {
    // Scan the rows and detect pressed keys
    for (int row = 0; row < numRows; row++) {
        // Set the current row LOW and the rest HIGH
        digitalWrite(rowPins[row], LOW);
        for (int col = 0; col < numCols; col++) {
            if (digitalRead(colPins[col]) == LOW) {
                // A key is pressed, return the corresponding key from the keymap
                while (digitalRead(colPins[col]) == LOW); // Wait for the key to be released
                digitalWrite(rowPins[row], HIGH); // Reset the row to HIGH
                return keymap[row][col];
            }
        }
        digitalWrite(rowPins[row], HIGH); // Set the row back to HIGH
    }
    return NO_KEY;
}
