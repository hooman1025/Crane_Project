#include <Stepper.h>

#define X_STEP A0
#define X_DIR A1

#define Y_STEP A2
#define Y_DIR A3
void setup() {
// put your setup code here, to run once:
pinMode(X_STEP, OUTPUT);//���ܸ��� x��
pinMode(X_DIR, OUTPUT);//���ܸ��� x�� ����
pinMode(Y_STEP, OUTPUT);//���ܸ��� y��
pinMode(Y_DIR, OUTPUT);//���ܸ��� y�� ����
}

//���ܸ��� ���⺰�� 2�����ݾ� ������
void loop() {
// put your main code here, to run repeatedly:
digitalWrite(X_DIR, HIGH); //ȸ�� ���� ����
digitalWrite(Y_DIR, LOW);

for(int x = 0; x < 500; x++) //100���� �ѹ����� ȸ��
{
digitalWrite(X_STEP, HIGH);
digitalWrite(Y_STEP, HIGH);
delay(2);
digitalWrite(X_STEP, LOW);
digitalWrite(Y_STEP, LOW);
delay(2);
}
delay(1000);

digitalWrite(X_DIR, LOW);
digitalWrite(Y_DIR, HIGH);

for(int x = 0; x < 500; x++)
{
digitalWrite(X_STEP, HIGH);
digitalWrite(Y_STEP, HIGH);
delay(2);
digitalWrite(X_STEP, LOW);
digitalWrite(Y_STEP, LOW);
delay(2);
}
delay(1000);
}