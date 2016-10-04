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

// The current column to light up for displaying the time.
// _0_0_0
// _00000
// 000000
// 000000
//
// _0_0_0
// _00000
// 000000
// 000000
//
// _0_0_0
// _00000
// 000000
// 000000
//
// _0_0_0
// _00000
// 000000
// 000000
int displayColumn = 1;

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
    if (displayColumn == 1) {
        digitalWrite(C1, HIGH);
        if (timeBits[0]) {
            digitalWrite(R4, HIGH);
        }
        if (timeBits[1]) {
            digitalWrite(R3, HIGH);
        }
        if (timeBits[2]) {
            digitalWrite(R2, HIGH);
        }
        if (timeBits[3]) {
            digitalWrite(R1, HIGH);
        }
    }
    if (displayColumn == 2) {
        digitalWrite(C2, HIGH);
        if (timeBits[4]) {
            digitalWrite(R4, HIGH);
        }
        if (timeBits[5]) {
            digitalWrite(R3, HIGH);
        }
        if (timeBits[6]) {
            digitalWrite(R2, HIGH);
        }
        if (timeBits[7]) {
            digitalWrite(R1, HIGH);
        }
    }
    if (displayColumn == 3) {
        digitalWrite(C3, HIGH);
        if (timeBits[8]) {
            digitalWrite(R4, HIGH);
        }
        if (timeBits[9]) {
            digitalWrite(R3, HIGH);
        }
        if (timeBits[10]) {
            digitalWrite(R2, HIGH);
        }
        if (timeBits[11]) {
            digitalWrite(R1, HIGH);
        }
    }
    if (displayColumn == 4) {
        digitalWrite(C4, HIGH);
        if (timeBits[12]) {
            digitalWrite(R4, HIGH);
        }
        if (timeBits[13]) {
            digitalWrite(R3, HIGH);
        }
        if (timeBits[14]) {
            digitalWrite(R2, HIGH);
        }
        if (timeBits[15]) {
            digitalWrite(R1, HIGH);
        }
    }
    if (displayColumn == 5) {
        digitalWrite(C5, HIGH);
        if (timeBits[16]) {
            digitalWrite(R4, HIGH);
        }
        if (timeBits[17]) {
            digitalWrite(R3, HIGH);
        }
        if (timeBits[18]) {
            digitalWrite(R2, HIGH);
        }
        if (timeBits[19]) {
            digitalWrite(R1, HIGH);
        }
    }
    if (displayColumn == 6) {
        digitalWrite(C6, HIGH);
        if (timeBits[20]) {
            digitalWrite(R4, HIGH);
        }
        if (timeBits[21]) {
            digitalWrite(R3, HIGH);
        }
        if (timeBits[22]) {
            digitalWrite(R2, HIGH);
        }
        if (timeBits[23]) {
            digitalWrite(R1, HIGH);
        }
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
    intToBits(value.toInt());
    insertIntoBits(offset);
    value = number[1];
    intToBits(value.toInt());
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
    setBits(n, 8);
}

// Update the second timeBits.
// _____0
// ____00
// ____00
// ____00
void updateSecond(int n) {
    setBits(n, 16);
}

// Change the time that will be displayed next.
void updateTime(int h, int m, int s) {
    updateHour(h);
    updateMinute(m);
    updateSecond(s);
}

// Increment the display row.
void incrementColumn() {
    displayColumn++;
    if (displayColumn > 6) {
        displayColumn = 1;
    }
}

void debug() {
    delay(500);
}

// The main loop.
void loop(){
    clearTime();
    updateTime(12, 34, 56);
    //allOn();
    displayTime();
    incrementColumn();
    //debug();
    delay(2);
}
