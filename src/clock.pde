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

// The time bits are stored as a boolean array.
bool bits[24];

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
    // Empty the bits array
    memset(bits, false, 24 * sizeof(bool));
}

void displayTime() {
    if (C1){
        digitalWrite(C1, HIGH);
    }
    if (C2){
        digitalWrite(C2, HIGH);
    }
    if (C3){
        digitalWrite(C3, HIGH);
    }
    if (C4){
        digitalWrite(C4, HIGH);
    }
    if (C5){
        digitalWrite(C5, HIGH);
    }
    if (C6){
        digitalWrite(C6, HIGH);
    }
    if (R1 && displayRow == 1){
        digitalWrite(R1, HIGH);
    }
    if (R2 && displayRow == 2){
        digitalWrite(R2, HIGH);
    }
    if (R3 && displayRow == 3){
        digitalWrite(R3, HIGH);
    }
    if (R4 && displayRow == 4){
        digitalWrite(R4, HIGH);
    }
}

void insertIntoBits(bool * b, int offset) {
   bits[0 + offset] = b[0];
   bits[1 + offset] = b[1];
   bits[2 + offset] = b[2];
   bits[3 + offset] = b[3];
}

bool * intToBits(int n) {
    bool bits[4];
    switch (n) {
        case 1:
            bits[0] = false; // Remove 0s after debugging.
            bits[1] = false;
            bits[2] = false;
            bits[3] = true;
            break;
        case 2:
            bits[0] = false;
            bits[1] = false;
            bits[2] = true;
            bits[3] = false;
            break;
        case 3:
            bits[0] = false;
            bits[1] = false;
            bits[2] = true;
            bits[3] = true;
            break;
        case 4:
            bits[0] = false;
            bits[1] = true;
            bits[2] = false;
            bits[3] = false;
            break;
        case 5:
            bits[0] = false;
            bits[1] = true;
            bits[2] = false;
            bits[3] = true;
            break;
        case 6:
            bits[0] = false;
            bits[1] = true;
            bits[2] = true;
            bits[3] = false;
            break;
        case 7:
            bits[0] = false;
            bits[1] = true;
            bits[2] = true;
            bits[3] = true;
            break;
        case 8:
            bits[0] = true;
            bits[1] = false;
            bits[2] = false;
            bits[3] = false;
            break;
        case 9:
            bits[0] = true;
            bits[1] = false;
            bits[2] = false;
            bits[3] = true;
            break;
    }
    return bits;
}

// Update the hour bits.
// _0____
// _0____
// 00____
// 00____
void updateBits(int n, int offset) {
    char number[2];
    sprintf(number, "%02d", n);
    int first = atoi(number[0]);
    int second = atoi(number[1]);
    insertIntoBits(intToBits(first), offset);
    insertIntoBits(intToBits(first), offset + 4);
}

// Update the hour bits.
// _0____
// _0____
// 00____
// 00____
void updateHour(int n) {
    updateBits(n, 0);
}

// Update the minute bits.
// ___0__
// __00__
// __00__
// __00__
void updateMinute(int n) {
    updateBits(n, 9);
}

// Update the second bits.
// _____0
// ____00
// ____00
// ____00
void updateSecond(int n) {
    updateBits(n, 17);
}

void updateTime(int h, int m, int s) {
    updateHour(h);
    updateMinute(m);
    updateSecond(s);
}

void loop(){
    clearTime();
    updateTime(12, 34, 56);
    displayTime();
    delay(5);
    displayRow++;
    if (displayRow > 4) {
        displayRow = 1;
    }
}
