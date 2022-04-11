#include <DHT.h>
#include <DHT_U.h>

int SENSOR = 2;
float TEMPERATURA;
DHT dht (SENSOR, DHT11);

void setup(){
  Serial.begin(9600);
  dht.begin();
  }

void loop(){
  TEMPERATURA = dht.readTemperature();
  Serial.println(TEMPERATURA);
  
  
  delay(500);
  
  }  
