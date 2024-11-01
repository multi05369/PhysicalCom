void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(A0);
  float Vout = (analogValue / 1023.0) * 5;
  float R1 = 10000;  // 10kΩ
  float R_thermistor = (R1 * (5.0 - Vout)) / Vout;Í

  // Calculate temperature using Beta parameter equation
  float temperature = betaCalculation(R_thermistor);

  Serial.print("Temperature: ");
  Serial.println(temperature);

  delay(1000);  // Read every 1 second
}

float betaCalculation(float R_thermistor) {
    float T0 = 298.15; // Reference temperature (25°C in Kelvin)
    float R0 = 10000;  // Resistance at 25°C (10kΩ)
    float beta = 4050; // Beta coefficient for TTC05103

    // Calculate temperature in Kelvin
    float tempK = 1.0 / ((1.0 / T0) + (1.0 / beta) * log(R_thermistor / R0));

    // Convert Kelvin to Celsius
    float tempC = tempK - 273.15;
    return tempC;
}
