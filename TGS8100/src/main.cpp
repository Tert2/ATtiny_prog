#include <Arduino.h>

#define F_CPU 20000000UL  // CPUクロック周波数

#define DATA_BIT   4  // PA4
#define OE_BIT  5  // PA5
#define LATCH_BIT  6  // PA6
#define CLOCK_BIT 7  // PA7
#define PRESSED(pin) (!(VPORTA.IN & (1 << (pin))))
#define PULSE_PIN 10  // PB0
#define AOUT_PIN  3   // PA3
#define LEFT 1
#define RIGHT 0

const uint8_t segnum[4]= {
  0b11111110, // 1(LEFT)
  0b11111101, // 2
  0b11111011, // 3
  0b11110111, // 4(RIGHT)
};
const uint8_t minnum[10] = {0x3F, 0x06, 0b01011011, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
const uint8_t secnum[10] = {0x3F, 0x30, 0x5B, 0x79, 0x74, 0x6D, 0b01101111, 0b00111100, 0x7F, 0b01111101};
const uint8_t wait[8] = {0x01, 0x02, 0x04, 0x08, 0x08, 0x10, 0x20, 0x01};


  // const uint8_t MODE[3] = {0x40, 0x50, 0x60}; // mode data
volatile uint8_t received_data = 0x00;
volatile bool received_check = false;



void ShiftInit() {
  _PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 0);  // disable the clock prescaler
  VPORTA.DIR = 0xF0; // initialize VPORTA
  PORTA.PIN1CTRL = PORT_PULLUPEN_bm;
  PORTA.PIN2CTRL = PORT_PULLUPEN_bm;
  VPORTA.OUT &= ~(1 << OE_BIT); // set OE_BIT to LOW
}

void pulseClock() {
  VPORTA.OUT |= (1 << CLOCK_BIT); // set CLOCK_BIT to HIGH
  delay(1); // wait for 1 us
  VPORTA.OUT &= ~(1 << CLOCK_BIT); // set CLOCK_BIT to LOW
}

uint8_t upper8(uint16_t val) {
  return (uint8_t)((val >> 8) & 0xFF); // return the upper 8 bits
}

uint8_t lower8(uint16_t val) {
  return (uint8_t)(val & 0xFF); // return the lower 8 bits
}

uint16_t bitplus(uint8_t upper, uint8_t lower) {
  return ((uint16_t)upper << 8) | (uint16_t)lower;
}

void myShiftOut_fast(uint8_t val, uint8_t num) {
  uint16_t shiftbit;
  shiftbit = bitplus(segnum[(int)num], val); // combine upper and lower bytes
  VPORTA.OUT &= ~(1 << LATCH_BIT); // set LATCH_BIT to LOW
  for (int8_t i = 15; i >= 0; i--) {
    if (shiftbit & (1 << i)) {
      VPORTA.OUT |= (1 << DATA_BIT); // set DATA_BIT to HIGH
    } else {
      VPORTA.OUT &= ~(1 << DATA_BIT); // set DATA_BIT to LOW
    }
    pulseClock(); // pulse the clock
  }
  VPORTA.OUT |= (1 << LATCH_BIT); // set LATCH_BIT to HIGH
}

void ShiftOut(uint16_t val, uint8_t LR) {
  uint8_t upper = upper8(val); // get the upper byte
  uint8_t lower = lower8(val); // get the lower byte
  if(LR == LEFT) {
    myShiftOut_fast(upper, 0); // shift out the upper byte for LEFT
    delay(1);
    myShiftOut_fast(lower, 1); // shift out the lower byte for LEFT
    delay(1);
  } else {
    myShiftOut_fast(upper, 3); // shift out the upper byte for RIGHT
    delay(1);
    myShiftOut_fast(lower, 2); // shift out the lower byte for RIGHT
    delay(1);
  }
}

uint16_t shiftculc(uint16_t val, uint8_t LR) {
  uint8_t lower, upper, templower, tempupper;
  uint16_t result;
  lower = val % 10;
  upper = (val-lower) / 10;
  if (LR == LEFT){
    templower = minnum[lower];
    tempupper = minnum[upper];
  } else {
    templower = secnum[lower];
    tempupper = secnum[upper];
  }
  result = bitplus(tempupper, templower); // combine upper and lower bytes
  return result; // return the combined value
}



int adval = 0; //ADC データ用変数
float sensor_r; // センサ抵抗値用変数

void setup() {
  ShiftInit(); // initialize the shift register
  pinMode(PULSE_PIN, OUTPUT); //PULSE ピンを出力に設定
}

void loop() {
  digitalWrite(PULSE_PIN, HIGH); //PULSE ピン HIGH
  delay(1); //OUT が安定するまでの待ち
  adval = analogRead(AOUT_PIN); //ADC 取り込み
  delay(1); // 時間調整
  digitalWrite(PULSE_PIN, LOW); //PULSE ピンを LOW
  if (adval != 0) {
    sensor_r = 6144.0 / adval - 10;
    int disp = (int)sensor_r; // 小数点以下切り捨て
    if (disp < 0) disp = 0;
    if (disp > 99) disp = 99;
    ShiftOut(shiftculc(disp, LEFT), LEFT);
    ShiftOut(shiftculc(disp, RIGHT), RIGHT);
  } else {
    ShiftOut(shiftculc(0, LEFT), LEFT);
    ShiftOut(shiftculc(0, RIGHT), RIGHT);
  }
  delay(998); // 時間調整
}
