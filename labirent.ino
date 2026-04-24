#define MOTOR_L_IN1 9
#define MOTOR_L_IN2 10
#define MOTOR_R_IN3 11
#define MOTOR_R_IN4 6

int speed = 128;

void setup() {
  pinMode(MOTOR_L_IN1, OUTPUT);
  pinMode(MOTOR_L_IN2, OUTPUT);
  pinMode(MOTOR_R_IN3, OUTPUT);
  pinMode(MOTOR_R_IN4, OUTPUT);
}

void ileri() {

  // SOL MOTOR İLERİ
  analogWrite(MOTOR_L_IN1, speed);
  analogWrite(MOTOR_L_IN2, LOW);

  // SAĞ MOTOR İLERİ
  analogWrite(MOTOR_R_IN3, speed);
  analogWrite(MOTOR_R_IN4, LOW);
}

void geri() {
  // SOL MOTOR GERİ
  analogWrite(MOTOR_L_IN1, LOW);
  analogWrite(MOTOR_L_IN2, speed);

  // SAĞ MOTOR GERİ
  analogWrite(MOTOR_R_IN3, LOW);
  analogWrite(MOTOR_R_IN4, speed);
}

void sol() {
  // SOL MOTOR DUR
  analogWrite(MOTOR_L_IN1, speed);
  analogWrite(MOTOR_L_IN2, LOW);

  analogWrite(MOTOR_R_IN3, LOW);
  analogWrite(MOTOR_R_IN4, LOW);
}

void sag() {
  // SAG MOTOR DUR
  analogWrite(MOTOR_L_IN1, LOW);
  analogWrite(MOTOR_L_IN2, LOW);

  analogWrite(MOTOR_R_IN3, speed);
  analogWrite(MOTOR_R_IN4, LOW);
}

void loop() {
  sol();
  delay(430);
  analogWrite(MOTOR_L_IN1, LOW);
  analogWrite(MOTOR_L_IN2, LOW);
  analogWrite(MOTOR_R_IN3, LOW);
  analogWrite(MOTOR_R_IN4, LOW);
  delay(1000);
  sag();
  delay(430);
  while (true) {
    analogWrite(MOTOR_L_IN1, LOW);
    analogWrite(MOTOR_L_IN2, LOW);
    analogWrite(MOTOR_R_IN3, LOW);
    analogWrite(MOTOR_R_IN4, LOW);
  }
}
