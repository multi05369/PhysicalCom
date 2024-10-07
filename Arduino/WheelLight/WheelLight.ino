const int ledPin = 3;  // Pin for LED (PWM pin)
const int potPin = A0; // Pin for Potentiometer (Analog input pin)

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as OUTPUT
}

void loop() {
  int potValue = analogRead(potPin); // Read the value from the Potentiometer

  // Scale the potValue directly
  int brightness = potValue / 4; // Scale down from 0-1023 to 0-255
  
  analogWrite(ledPin, brightness); // Write the brightness value to the LED
}
