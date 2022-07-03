#include <Stepper.h>

#define X_STEP A0
#define X_DIR A1
#define Y_STEP A2
#define Y_DIR A3
#define JOY_X A4
#define JOY_Y A5

boolean IT_value = false;
int joy_x, joy_y; //조이스틱 방향

void setup() {
  // put your setup code here, to run once:
  pinMode(X_STEP, OUTPUT);//스텝모터 x축
  pinMode(X_DIR, OUTPUT);//스텝모터 x축 방향
  pinMode(Y_STEP, OUTPUT);//스텝모터 y축
  pinMode(Y_DIR, OUTPUT);//스텝모터 y축 방향
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("X : ");//조이스틱 x축
  Serial.print(analogRead(A4)); //조이스틱 x축 값
  Serial.print(" Y : ");//조이스틱 y축
  Serial.println(analogRead(A5));//조이스틱 y축 값
  Serial.println(" ");
  joy_x = analogRead(A4);
  joy_y = analogRead(A5);
  delay(3); //딜레이 값에 따라 스텝모터의 회전속도가 달라짐 딜레이가 높으면 느려짐

//조이스틱 중간값 약 512
  if(joy_x > 600) {//조이스틱 x축을 오른쪽으로 이동하면 x축 서보모터 오른쪽 이동
    digitalWrite(X_DIR, HIGH);
    digitalWrite(X_STEP, HIGH);
    delayMicroseconds(10);
    digitalWrite(X_STEP, LOW);
    delayMicroseconds(10);
  }
  if(joy_x < 400) {//조이스틱 x축을 왼쪽으로 이동하면 x축 서보모터 왼쪽 이동
    digitalWrite(X_DIR, LOW);
    digitalWrite(X_STEP, HIGH);
    delayMicroseconds(10);
    digitalWrite(X_STEP, LOW);
    delayMicroseconds(10);
  }
  if(joy_y > 600) {//조이스틱 y축을 위쪽으로 이동하면 y축 서보모터 위쪽 이동
    digitalWrite(Y_DIR, HIGH);
    digitalWrite(Y_STEP, HIGH);
    delayMicroseconds(10);
    digitalWrite(Y_STEP, LOW);
    delayMicroseconds(10);
  }
  if(joy_y < 400) {//조이스틱 x축을 아래쪽으로 이동하면 y축 서보모터 아래쪽 이동
    digitalWrite(Y_DIR, LOW);
    digitalWrite(Y_STEP, HIGH);
    delayMicroseconds(10);
    digitalWrite(Y_STEP, LOW);
    delayMicroseconds(10);
  }
}