#include <WiFiS3.h>

const char* ssid = "";      // Your SSID
const char* password = "";  // Your Password

void setup() {
  Serial.begin(9600);

  // Connect to the Wi-Fi network
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Since there’s no password, pass only the SSID
  WiFi.begin(ssid, password);

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi network");

  // Print the IP address
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Your code here (e.g., handling communication)
}