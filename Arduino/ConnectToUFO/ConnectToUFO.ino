#include <WiFiS3.h>
const char* ssid = "ITFORGE_UFO";
const char* password = ""; 

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid);
}

void loop() {
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi network");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); // 10.110.198.104
}