const int ledPin1 = 5;  // เลือก PWM Pin สำหรับ LED1
const int ledPin2 = 6; // เลือก PWM Pin สำหรับ LED2

int brightness1 = 0; // ความสว่างของ LED1
int brightness2 = 0; // ความสว่างของ LED2

void setup() {
  // กำหนด Pin เป็น Output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // Fading LED1 จาก Off ไปยัง Full-Bright
  analogWrite(ledPin1, brightness1);
  brightness1++;

  // Fading LED2 จาก Off ไปยัง Full-Bright เร็วเป็นสองเท่า
  analogWrite(ledPin2, brightness2);
  brightness2 += 2;

  // ตรวจสอบความสว่าง 
  if (brightness1 > 255) {
    brightness1 = 0;
  }
  if (brightness2 > 255) {
    brightness2 = 0;
  }

  delay(10); // หน่วงเวลาเล็กน้อยสำหรับการปรับความสว่าง
}