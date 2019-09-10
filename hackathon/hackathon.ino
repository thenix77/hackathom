#include "DHT.h"

#define DHTPIN D5     
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

int pin[] = {0,0,0,0,0};
float temp;

void setup() {
  Serial.begin(9600);
  Serial.println("#3Hackathon de la selva");

  dht.begin();
  temp = 20;
  Serial.println(temp);

  pinMode(D0 , OUTPUT); //RED
  pinMode(D1 , OUTPUT); //RED
  pinMode(D2 , OUTPUT); //ORANGE
  pinMode(D3 , OUTPUT); //ORANGE
  pinMode(D4 , OUTPUT); //GREEN
}

void loop() {
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t) ) {
   return;
  }


  //RED
  if(t > 33) luces(1,1,1,1,1);  
  //red
  if(t <= 33  && t >= 30 ) luces(1,1,1,1,0);
  //Naranja
  if(t < 30 && t >28 ) luces(1,1,1,0,0);
  //Naranja
  if(t < 28 && t >26 ) luces(1,1,0,0,0);
  //verde
  if(t <= 26  ) luces(1,0,0,0,0);

  
  if (temp != t)
  {
     temp = t;
     Serial.println(t);
  // Serial.print("\r\n");
  }
  
  delay(2000);
  
} 


void luces(int p0,int p1,int p2, int p3, int p4){
  digitalWrite(D0, p0);
  digitalWrite(D1, p1);
  digitalWrite(D2, p2);
  digitalWrite(D3, p3);
  digitalWrite(D4, p4);
  
}
