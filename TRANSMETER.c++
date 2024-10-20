#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

int enA = 3;
int enB = 9;
int motor_A = 4;
int motor_B = 5;
int motor_C = 6;
int motor_D = 7;

RF24 rx_data(8, 10);

const byte address[6] = "00001";

struct data {
  int Xaxis;
  int Yaxis;

};
data receive;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
receive.begin();
receive.openReadingPipe(0,address);
receive.setPALevel(RF24_PA_MIN);
receive.setDataRate(RF24_250KBPS);
receive.startListening();
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(motor_A, OUTPUT);
pinMode(motor_B, OUTPUT);
pinMode(motor_C, OUTPUT);
pinMode(motor_D, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly
 while(receive.available()) {
    receive.read(&receive_data, sizeof(data));
 if(receive_data.Yaxis > 400) {
  digitalWrite(motor_A, LOW);
  digitalWrite(motor_B, HIGH);
  digitalWrite(motor_C, HIGH);
  digitalWrite(motor_D, LOW);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  
}else if(receive_data.Yaxis < 320) {
  digitalWrite(motor_A, HIGH);
  digitalWrite(motor_B, LOW);
  digitalWrite(motor_C, LOW);
  digitalWrite(motor_D, HIGH);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
} else if(receive_data.Xaxis < 320){
  digitalWrite(motor_A, HIGH);
  digitalWrite(motor_B, LOW);
  digitalWrite(motor_C, HIGH);
  digitalWrite(motor_D, LOW);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
}else if(receive_data.Xaxis > 400){
  digitalWrite(motor_A, LOW);
  digitalWrite(motor_B, HIGH);
  digitalWrite(motor_C, LOW);
  digitalWrite(motor_D, HIGH);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
}else {
  digitalWrite(motor_A, LOW);
  digitalWrite(motor_B, LOW);
  digitalWrite(motor_C, LOW);
  digitalWrite(motor_D, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  }
 }
}