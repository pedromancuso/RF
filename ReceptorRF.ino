#include <ESP8266WiFi.h>
#include <RCSwitch.h>
static const uint8_t D5   = 14;
RCSwitch mySwitch = RCSwitch();
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN,OUTPUT);
  mySwitch.enableReceive(D5);
  Serial.println("\nSketch Iniciado Receptor RF");  
}
//--------------------------LOOP--------------------------------
unsigned long previousMillis = 0;
void loop(){
  if (mySwitch.available()) {   
    int value = mySwitch.getReceivedValue();   
    if (value == 0) {
      Serial.print("Unknown encoding");
      digitalWrite(LED_BUILTIN,LOW);
    } else {
      digitalWrite(LED_BUILTIN,HIGH);
      Serial.print("Received ");
      Serial.print( mySwitch.getReceivedValue() );
      Serial.print(" / ");
      Serial.print( mySwitch.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.println( mySwitch.getReceivedProtocol() );
    }
    mySwitch.resetAvailable();
  }       
}
