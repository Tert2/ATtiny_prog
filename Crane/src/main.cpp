#include <Arduino.h>

#define CW false
#define CCW true
#define X_DIR 0
#define Y_DIR 1
#define Z_DIR 2
#define ARM 3
#define X_S A0
#define Y_S A1
#define X_E A2
#define Y_E A3
#define X_BUT A4
#define Y_BUT A5
#define Z_adj A7
#define Z_U A8
#define Z_D A9

volatile uint8_t status=0;
// static uint8_t time;


uint8_t mpin[4][2] = {{13, 12}, {10, 9}, {7, 6}, {4, 3}};
// put function declarations here:
void motorControl(bool direction, int axis) {
  if(direction == CW) {
    digitalWrite((mpin[axis][1]), HIGH);
    digitalWrite((mpin[axis][0]), LOW);
  } else {
    digitalWrite((mpin[axis][0]), HIGH);
    digitalWrite((mpin[axis][1]), LOW);
  }
}

void motorStop(int axis) {
  digitalWrite((mpin[axis][0]), LOW);
  digitalWrite((mpin[axis][1]), LOW);
}

void check() {
  for(int i=0; i<8; i++) {
    motorControl(i%2, (i-i%2)/2);
    delay(1000);
    motorStop((i-i%2)/2);
  }
}


void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  pinMode(A7, INPUT_PULLUP);
  pinMode(A8, INPUT_PULLUP);
  pinMode(A9, INPUT_PULLUP);

  // check();
  for(int i=0; i<4; i++) {
    motorStop(i);
  }
}

void loop() {
  Serial.println(status);

  delay(50);
  switch(status) {
    case 0:{//待機
      if(digitalRead(X_BUT) == LOW)++status;
      if(digitalRead(Z_adj) == LOW)status=8;
      break;
    }
    case 1:{//X軸移動
      motorControl(CW, X_DIR);
      if(digitalRead(X_BUT) == HIGH || digitalRead(X_E) == LOW)++status;
      break;
    }
    case 2:{//X軸移動終了待機
      motorStop(X_DIR);
      if(digitalRead(Y_BUT) == LOW)++status;
      break;
    }
    case 3:
      motorControl(CW, Y_DIR);
      if(digitalRead(Y_BUT) == HIGH || digitalRead(Y_E) == LOW)++status;
      break;
    case 4:{
      motorStop(Y_DIR);
      status++;
      break;
    }
    case 5:{
      motorControl(CW, Z_DIR);
      delay(11000);
      motorStop(Z_DIR);
      motorControl(CW, ARM);
      delay(2000);
      motorStop(ARM);
      motorControl(CCW, Z_DIR);
      delay(12000);
      motorStop(Z_DIR);
      ++status;
      break;
    }
    case 6:{
      if(digitalRead(X_S)==HIGH)motorControl(CCW, X_DIR);else motorStop(X_DIR);
      if(digitalRead(Y_S)==HIGH)motorControl(CCW, Y_DIR);else motorStop(Y_DIR);
      if(digitalRead(X_S)==LOW&&digitalRead(Y_S)==LOW)++status;
      break;
    }
    case 7:{
      motorStop(X_DIR);
      motorStop(Y_DIR);
      motorControl(CCW, ARM);
      delay(2000);
      motorStop(ARM);
      status=0;
      break;
    }
    case 8:{
      if(digitalRead(Z_adj)==HIGH)status++;
      break;
    }
    case 9:{
      if(digitalRead(Z_U)==LOW){
        motorControl(CCW, Z_DIR);
      }else if(digitalRead(Z_D)==LOW){
        motorControl(CW, Z_DIR);
      }else{
        motorStop(Z_DIR);
      }
      if(digitalRead(Z_adj)==LOW)status=0;
      break;
    }
    default:
      status = 0;
      break;
  }
}
