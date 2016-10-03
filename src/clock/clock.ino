// Define columns
#define C6 4
#define C5 5
#define C4 6
#define C3 7
#define C2 8
#define C1 9
// Define rows
#define R1 10
#define R2 11
#define R3 12
#define R4 13

// The time timeBits are stored as a boolean array.
bool timeBits[24];
bool numberBits[4];

// The current row to light up for displaying the time.
// The rows cycle top to bottom.
// _0_0_0 <-- Row 1
// _00000
// 000000
// 000000
//
// _0_0_0
// _00000 <-- Row 2
// 000000
// 000000
//
// _0_0_0
// _00000
// 000000 <-- Row 3
// 000000
//
// _0_0_0
// _00000
// 000000
// 000000 <-- Row 4
int displayRow = 1;

// Set all the pins that will be used.
void setup(){
    // Set columns
    pinMode(C1, OUTPUT);
    pinMode(C2, OUTPUT);
    pinMode(C3, OUTPUT);
    pinMode(C4, OUTPUT);
    pinMode(C5, OUTPUT);
    pinMode(C6, OUTPUT);
    // Set rows
    pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
    pinMode(R3, OUTPUT);
    pinMode(R4, OUTPUT);
    // Open Serial Port
    Serial.begin(9600);
}

// Clear all pins and the timeBits array.
void clearTime() {
    // Turn off columns
    digitalWrite(C1, LOW);
    digitalWrite(C2, LOW);
    digitalWrite(C3, LOW);
    digitalWrite(C4, LOW);
    digitalWrite(C5, LOW);
    digitalWrite(C6, LOW);
    // Turn off rows
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(R3, LOW);
    digitalWrite(R4, LOW);
    // Empty the timeBits array
    memset(timeBits, false, 24 * sizeof(bool));
}

// Clear all pins and the timeBits array.
void allOn() {
    // Turn off columns
    digitalWrite(C1, HIGH);
    digitalWrite(C2, HIGH);
    digitalWrite(C3, HIGH);
    digitalWrite(C4, HIGH);
    digitalWrite(C5, HIGH);
    digitalWrite(C6, HIGH);
}

// Map the timeBits that have been set to true to turning on the appropriate pins.
void displayTime() {
    // Turn on columns.
    if (timeBits[0] || timeBits[1] || timeBits[2] || timeBits[3]) {
        //Serial.println("Column 1");
        digitalWrite(C1, HIGH);
    }
    if (timeBits[4] || timeBits[5] || timeBits[6] || timeBits[7]) {
        //Serial.println("Column 2");
        digitalWrite(C2, HIGH);
    }
    if (timeBits[8] || timeBits[9] || timeBits[10] || timeBits[11]) {
        //Serial.println("Column 3");
        digitalWrite(C3, HIGH);
    }
    if (timeBits[12] || timeBits[13] || timeBits[14] || timeBits[15]) {
        //Serial.println("Column 4");
        digitalWrite(C4, HIGH);
    }
    if (timeBits[16] || timeBits[17] || timeBits[18] || timeBits[19]) {
        //Serial.println("Column 5");
        digitalWrite(C5, HIGH);
    }
    if (timeBits[20] || timeBits[21] || timeBits[22] || timeBits[23]) {
        //Serial.println("Column 6");
        digitalWrite(C6, HIGH);
    }
    // Turn on rows.
    if (displayRow == 1){
        //Serial.println("Row 1");
        digitalWrite(R1, HIGH);
    }
    if (displayRow == 2){
        //Serial.println("Row 2");
        digitalWrite(R2, HIGH);
    }
    if (displayRow == 3){
        //Serial.println("Row 3");
        digitalWrite(R3, HIGH);
    }
    if (displayRow == 4){
        //Serial.println("Row 4");
        digitalWrite(R4, HIGH);
    }
}

// Insert the given timeBits into the timeBits array at the given offset.
void insertIntoBits(int offset) {
    timeBits[0 + offset] = numberBits[0];
    timeBits[1 + offset] = numberBits[1];
    timeBits[2 + offset] = numberBits[2];
    timeBits[3 + offset] = numberBits[3];
}

// Convert the given int into into a four bit array.
void intToBits(int n) {
    memset(numberBits, false, 4 * sizeof(bool));
    switch (n) {
        case 1:
            numberBits[0] = false; // Remove 0s after debugging.
            numberBits[1] = false;
            numberBits[2] = false;
            numberBits[3] = true;
            break;
        case 2:
            numberBits[0] = false;
            numberBits[1] = false;
            numberBits[2] = true;
            numberBits[3] = false;
            break;
        case 3:
            numberBits[0] = false;
            numberBits[1] = false;
            numberBits[2] = true;
            numberBits[3] = true;
            break;
        case 4:
            numberBits[0] = false;
            numberBits[1] = true;
            numberBits[2] = false;
            numberBits[3] = false;
            break;
        case 5:
            numberBits[0] = false;
            numberBits[1] = true;
            numberBits[2] = false;
            numberBits[3] = true;
            break;
        case 6:
            numberBits[0] = false;
            numberBits[1] = true;
            numberBits[2] = true;
            numberBits[3] = false;
            break;
        case 7:
            numberBits[0] = false;
            numberBits[1] = true;
            numberBits[2] = true;
            numberBits[3] = true;
            break;
        case 8:
            numberBits[0] = true;
            numberBits[1] = false;
            numberBits[2] = false;
            numberBits[3] = false;
            break;
        case 9:
            numberBits[0] = true;
            numberBits[1] = false;
            numberBits[2] = false;
            numberBits[3] = true;
            break;
    }
}

// Update the timeBits array with the given int at the given offset.
void setBits(int n, int offset) {
    String value;
    char number[2];
    sprintf(number, "%02d", n);
    value = number[0];
    int first = value.toInt();
    value = number[1];
    int second = value.toInt();
    insertIntoBits(offset);
    insertIntoBits(offset + 4);
}

// Update the hour timeBits.
// _0____
// _0____
// 00____
// 00____
void updateHour(int n) {
    setBits(n, 0);
}

// Update the minute timeBits.
// ___0__
// __00__
// __00__
// __00__
void updateMinute(int n) {
    setBits(n, 9);
}

// Update the second timeBits.
// _____0
// ____00
// ____00
// ____00
void updateSecond(int n) {
    setBits(n, 17);
}

// Change the time that will be displayed next.
void updateTime(int h, int m, int s) {
    updateHour(h);
    updateMinute(m);
    updateSecond(s);
}

// Increment the display row.
void incrementRow() {
    displayRow++;
    if (displayRow > 4) {
        displayRow = 1;
    }
}

// The main loop.
void loop(){
    clearTime();
    updateTime(12, 34, 56);
//    allOn();
    displayTime();
    incrementRow();
    delay(20);
    // Add debug time to serial port.
}
