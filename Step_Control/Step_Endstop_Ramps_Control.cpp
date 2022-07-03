#define X_STEP 54
#define X_DIR 55
#define X_ENABLE 38
#define X_MIN 3
#define X_MAX 2

#define Y_STEP 60
#define Y_DIR 61
#define Y_ENABLE 56
#define Y_MIN 14
#define Y_MAX 15

#define Z_STEP 46
#define Z_DIR 48
#define Z_ENABLE 62
#define Z_MIN 18
#define Z_MAX 19

#define JOY_X A3
#define JOY_Y A4

int joy_x, joy_y;

void HOME();
int flag = 0;

void setup() {
  Serial.begin(9600);
  pinMode(X_STEP, OUTPUT);
  pinMode(X_DIR, OUTPUT);
  pinMode(X_ENABLE, OUTPUT);
  pinMode(X_MIN, INPUT);

  pinMode(Y_STEP, OUTPUT);
  pinMode(Y_DIR, OUTPUT);
  pinMode(Y_ENABLE, OUTPUT);
  pinMode(Y_MIN, INPUT);

  pinMode(Z_STEP, OUTPUT);
  pinMode(Z_DIR, OUTPUT);
  pinMode(Z_ENABLE, OUTPUT);
  pinMode(Z_MIN, INPUT);

  digitalWrite(X_ENABLE, LOW);
  digitalWrite(Y_ENABLE, LOW);

  digitalWrite(X_DIR, LOW);
  digitalWrite(Y_DIR, LOW);
  HOME();
}

void loop() {
  joy_x = analogRead(JOY_X);
  joy_y = analogRead(JOY_Y);
  // delayMicroseconds(1);



  if (flag == 1) {
    if (joy_x > 600) {
      digitalWrite(X_DIR, HIGH);
      digitalWrite(X_STEP, HIGH);
      delayMicroseconds(1);
      digitalWrite(X_STEP, LOW);
      delayMicroseconds(1);
    }
    if (joy_x < 400) {
      digitalWrite(X_DIR, LOW);
      digitalWrite(X_STEP, HIGH);
      delayMicroseconds(1);
      digitalWrite(X_STEP, LOW);
      delayMicroseconds(1);
    }
    if (joy_y < 400) {
      digitalWrite(Y_DIR, HIGH);
      digitalWrite(Y_STEP, HIGH);
      delayMicroseconds(1);
      digitalWrite(Y_STEP, LOW);
      delayMicroseconds(1);
    }
    if (joy_y > 600) {
      digitalWrite(Y_DIR, LOW);
      digitalWrite(Y_STEP, HIGH);
      delayMicroseconds(1);
      digitalWrite(Y_STEP, LOW);
      delayMicroseconds(1);
    }
  }
}

void HOME() {
  while (digitalRead(X_MIN)) {
    digitalWrite(X_STEP, HIGH);
    delayMicroseconds(150);
    digitalWrite(X_STEP, LOW);
    delayMicroseconds(150);
  }
  delay(1000);
  while (digitalRead(X_MIN)) {
    digitalWrite(Y_STEP, HIGH);
    delayMicroseconds(150);
    digitalWrite(Y_STEP, LOW);
    delayMicroseconds(150);
  }
  flag = 1;
}