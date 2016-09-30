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

// Update the hour bits.
// _0____
// _0____
// 00____
// 00____
void updateHour(int n) {
    char number[2];
    sprintf(number, "%d", n);
    int first = strtonum(number[0], NULL, 10);
    // int second = strtoumax(number[1], NULL, 10);
}

// Update the minute bits.
// ___0__
// __00__
// __00__
// __00__
void updateMinute(int n) {

}

// Update the second bits.
// _____0
// ____00
// ____00
// ____00
void updateSecond(int n) {

}

// The rows need to cycle top to bottom.
// _0_0_0 <--
// _00000
// 000000
// 000000
//
// _0_0_0
// _00000 <--
// 000000
// 000000
//
// _0_0_0
// _00000
// 000000 <--
// 000000
//
// _0_0_0
// _00000
// 000000
// 000000 <--
void updateTime(int h, int m, int s) {
    updateHour(h);
    updateMinute(m);
    updateSecond(s);
}

void loop(){
    clearTime();
    updateTime(12, 34, 56);
    delay(5);

    // if (co1 == 1){
    //   digitalWrite(C1, HIGH);
    // }
    // if (co2 == 1){
    //   digitalWrite(C2, HIGH);
    // }
    // if (co3 == 1){
    //   digitalWrite(C3, HIGH);
    // }
    // if (co4 == 1){
    //   digitalWrite(C4, HIGH);
    // }
    // if (co5 == 1){
    //   digitalWrite(C5, HIGH);
    // }
    // if (co6 == 1){
    //   digitalWrite(C6, HIGH);
    // }

    // if (ro == 1){
    //   digitalWrite(R1, HIGH);
    // }
    // if (ro == 2){
    //   digitalWrite(R2, HIGH);
    // }
    // if (ro == 3){
    //   digitalWrite(R3, HIGH);
    // }
    // if (ro == 4){
    //   digitalWrite(R4, HIGH);
    // }
}
