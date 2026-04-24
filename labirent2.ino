#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensorF;
VL53L0X sensorL;
VL53L0X sensorR;

int F, L, R;

int RFmotorPin = 9;
int RBmotorPin = 10;
int LFmotorPin = 11;
int LBmotorPin = 6;

int RbaseSpeed = 45;
int LbaseSpeed = 45;
int turnSpeed = 80;
int reg = 10;

int wallThreshold = 200;  // mm

int Lref = 56, Rref = 56;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);

  digitalWrite(1, LOW);
  digitalWrite(0, LOW);

  pinMode(RFmotorPin, OUTPUT);
  pinMode(RBmotorPin, OUTPUT);
  pinMode(LFmotorPin, OUTPUT);
  pinMode(LBmotorPin, OUTPUT);

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);

  delay(500);

  Wire.begin();
  //Serial.begin(9600);

  // FRONT
  digitalWrite(2, HIGH);
  delay(150);
  sensorF.init(true);
  sensorF.setAddress(0x30);

  // LEFT
  digitalWrite(3, HIGH);
  delay(150);
  sensorL.init(true);
  sensorL.setAddress(0x31);

  // RIGHT
  digitalWrite(4, HIGH);
  delay(150);
  sensorR.init(true);
  sensorR.setAddress(0x32);

  sensorF.startContinuous();
  sensorL.startContinuous();
  sensorR.startContinuous();
  digitalWrite(1, LOW);
  digitalWrite(0, LOW);
}

void loop() {
  // F = sensorF.readRangeContinuousMillimeters();
  // //Serial.print("F: "), Serial.println(F);
  // L = sensorL.readRangeContinuousMillimeters();
  // // Serial.print("L: "), Serial.println(L);
  // R = sensorR.readRangeContinuousMillimeters();
  // // Serial.print("R: "), Serial.println(R);
  digitalWrite(1,0);
  digitalWrite(0,0);


  // if (L > R) {
  //   analogWrite(LFmotorPin, (LbaseSpeed));
  //   analogWrite(RFmotorPin, (RbaseSpeed + reg));
  //   analogWrite(LBmotorPin, 0);
  //   analogWrite(RBmotorPin, 0);
  //   //digitalWrite(0, HIGH);
  //   digitalWrite(1, LOW);
  // }
  // delay(100);
  // if (R > L) {
  //   analogWrite(LFmotorPin, (LbaseSpeed + reg));
  //   analogWrite(RFmotorPin, (RbaseSpeed));
  //   analogWrite(LBmotorPin, 0);
  //   analogWrite(RBmotorPin, 0);
  //   digitalWrite(0, LOW);
  //   // digitalWrite(1, HIGH);
  // }
  // delay(100);
}

// if (sensorF.timeoutOccurred() || sensorL.timeoutOccurred() || sensorR.timeoutOccurred()) {
//   stopMotors();
// }

// -------- SAĞ DUVAR TAKİP --------


/*
  while (F > 200) {
    F = sensorF.readRangeContinuousMillimeters();
    ileriGit();
  }
  stopMotors();
  delay(100);
  // // Sağ boşsa sağa dön
  // if (R > wallThreshold) {
  //   sagaDon();
  // }
  // // Ön açık ve sağ duvar varsa düz git
  // else if (F > wallThreshold) {
  //   ileriGit();
  // }
  // // Ön kapalıysa sola dön
  // else {
  //   solaDon();
  // }
}

//////////////// MOTOR FONKSİYONLARI //////////////////

void ileriGit() {
  analogWrite(LFmotorPin, baseSpeed);
  analogWrite(RFmotorPin, baseSpeed);
  analogWrite(LBmotorPin, 0);
  analogWrite(RBmotorPin, 0);
  delay(200);
}

void sagaDon() {
  analogWrite(LFmotorPin, 100);
  analogWrite(RFmotorPin, 0);
  analogWrite(LBmotorPin, 0);
  analogWrite(RBmotorPin, turnSpeed);
  delay(200);
  analogWrite(LFmotorPin, 0);
  analogWrite(RFmotorPin, 0);
  analogWrite(LBmotorPin, 0);
  analogWrite(RBmotorPin, 0);
  delay(200);
}

void solaDon() {
  analogWrite(LFmotorPin, 0);
  analogWrite(RFmotorPin, turnSpeed);
  analogWrite(LBmotorPin, turnSpeed);
  analogWrite(RBmotorPin, 0);
  delay(200);
  analogWrite(LFmotorPin, 0);
  analogWrite(RFmotorPin, 0);
  analogWrite(LBmotorPin, 0);
  analogWrite(RBmotorPin, 0);
  delay(200);
}

void stopMotors() {
  analogWrite(LFmotorPin, 0);
  analogWrite(RFmotorPin, 0);
  analogWrite(LBmotorPin, 0);
  analogWrite(RBmotorPin, 0);
  delay(200);
}


*/