#include <ArduinoJson.h>
int x = 0;
StaticJsonDocument<256> doc;
void setup() {
  Serial.begin(9600);
  Serial.println("Hola Gato...!");
  pinMode(LED_BUILTIN,OUTPUT );
  
  }

void loop() {
  Serial.print(++x, DEC);
  led();
  
 /* char json[] =
      "{\"sensor\":\"gps\",\"time\":++x,\"data\":[48.756080,2.302038]}";
  serializeJson(doc, json);     
  Serial.print(json);*/
}
void led(){
  digitalWrite(LED_BUILTIN , LOW);
  delay(300);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
}
