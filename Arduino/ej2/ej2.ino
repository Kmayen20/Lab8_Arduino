#include <DHT.h>
#include <DHT_U.h>

int led1= 10;
int led2= 11;
int led3= 12;
int SENSOR = 2;
int incomingByte;
int TEMPERATURA;
int HUMEDAD;
String cmd;
DHT dht (SENSOR, DHT11);

void setup(){
    pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  dht.begin();
  }

void loop(){
  TEMPERATURA = dht.readTemperature();
  HUMEDAD = dht.readHumidity();

  Serial.println(TEMPERATURA);


  delay(50);
  if (Serial.available()>0){
    incomingByte = Serial.read();
    if (incomingByte < 25){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      } if (incomingByte > 25){
          digitalWrite(led3, HIGH);
          digitalWrite(led2, LOW);
          digitalWrite(led1, LOW);
        }  if(incomingByte == 25) {
            digitalWrite(led2, HIGH);
            digitalWrite(led1, LOW);
            digitalWrite(led3, LOW);
          } 
    }

  }
    
