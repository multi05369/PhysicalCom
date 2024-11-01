const int BTN_RED = 4;
const int BTN_GREEN = 5;
const int BTN_BLUE = 6;

const int PIN_RED = 8;
const int PIN_GREEN = 9;
const int PIN_BLUE = 10;

bool is_red_on = false;
bool is_green_on = false;
bool is_blue_on = false;

void setup() {
  pinMode(BTN_RED, INPUT);
  pinMode(BTN_GREEN, INPUT);
  pinMode(BTN_BLUE, INPUT);
  
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void loop() {
  change_stat(BTN_RED, PIN_RED, &is_red_on);
  change_stat(BTN_GREEN, PIN_GREEN, &is_green_on);
  change_stat(BTN_BLUE, PIN_BLUE, &is_blue_on);
  delay(5);
}

void change_stat(int btn_pin, int led_pin, bool* status) {
  if (digitalRead(btn_pin) == LOW) {
    *status = !(*status);
    if (*status) {
      digitalWrite(led_pin, HIGH);
    } else {
      digitalWrite(led_pin, LOW);
    }
    delay(100);
  }
}