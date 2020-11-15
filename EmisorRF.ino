#include <ESP8266WiFi.h>
#include <RCSwitch.h>
static const uint8_t D5   = 14;
RCSwitch mySwitch = RCSwitch();
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(D5, INPUT);
  mySwitch.enableTransmit(D5);
  mySwitch.setPulseLength(320);
  mySwitch.setProtocol(6);
  mySwitch.setRepeatTransmit(15);
  Serial.println("\nSketch Iniciado Emisor RF");
}
//--------------------------LOOP--------------------------------
int incoming=1;int incomingByte;
void loop(){
  incomingByte=Serial.read();
  Serial.print("incomingByte: ");
  Serial.println(incomingByte);
  if(incomingByte=='0'){mySwitch.send("142631973");digitalWrite(LED_BUILTIN,LOW);delay(10);}
  if(incomingByte=='1'){mySwitch.send("1306904");digitalWrite(LED_BUILTIN,LOW);delay(10);}
  if(incomingByte=='2'){mySwitch.send("243424296");digitalWrite(LED_BUILTIN,LOW);delay(10);}
  if(incomingByte=='3'){mySwitch.send("143680549");digitalWrite(LED_BUILTIN,LOW);delay(10);}
  if(incomingByte=='4'){mySwitch.send("176186405");digitalWrite(LED_BUILTIN,LOW);delay(10);}
  if(incomingByte=='5'){mySwitch.send("38298184");digitalWrite(LED_BUILTIN,LOW);delay(10);}
  if(incomingByte=='6'){}
  digitalWrite(LED_BUILTIN,HIGH);
}
