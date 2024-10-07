const byte numRows = 4; // Number of rows on the keypad
const byte numCols = 4; // Number of columns on the keypad

const int LED_RED_CUSTOM = 10;
const int LED_GREEN_CUSTOM = 11;
const int LED_BLUE_CUSTOM = 12;

bool is_red_on = false;
bool is_green_on = false;
bool is_blue_on = false;

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
    pinMode(LED_RED_CUSTOM, OUTPUT);
    pinMode(LED_GREEN_CUSTOM, OUTPUT);
    pinMode(LED_BLUE_CUSTOM, OUTPUT);

    // Set row pins as OUTPUT and column pins as INPUT_PULLUP
    for (int i = 0; i < numRows; i++) {
        pinMode(rowPins[i], OUTPUT);
        digitalWrite(rowPins[i], HIGH); // Initially, set all rows HIGH
    }
    for (int i = 0; i < numCols; i++) {
        pinMode(colPins[i], INPUT_PULLUP); // Enable pull-up resistors on column pins
    }
}

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

void loop() {
    char keypressed = getKey();
    if (keypressed != NO_KEY) {
        Serial.println(keypressed);
        switch (keypressed) {
            case '1':
            case '4':
            case '7':
            case '*':
                is_red_on = !is_red_on;
                digitalWrite(LED_RED_CUSTOM, is_red_on ? HIGH : LOW);
                break;
            case '2':
            case '5':
            case '8':
            case '0':
                is_green_on = !is_green_on;
                digitalWrite(LED_GREEN_CUSTOM, is_green_on ? HIGH : LOW);
                break;
            case '3':
            case '6':
            case '9':
            case '#':
                is_blue_on = !is_blue_on;
                digitalWrite(LED_BLUE_CUSTOM, is_blue_on ? HIGH : LOW);
                break;
            default:
                break;
        }
    }
}
