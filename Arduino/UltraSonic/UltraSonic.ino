const int trigPin = 4;
const int echoPin = 2;

void setup() {
    Serial.begin(9600); // Initialize serial communication at 9600 bits per second
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    int pulseWidth = pulseIn(echoPin, HIGH);
    Serial.print("Pulse Width: ");
    Serial.println(pulseWidth);
    long distance = pulseWidth/29/2;
    Serial.print("Distance: ");
    Serial.println(distance);
    
    delay(1000); // Wait 1 second before the next measurement
}
