//M0 = D3
//M1 = D4
//RX = D2
//TX = D1

#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial sender(D1, D2);

String ID="MKR2O21";
int FV=1;
String DT = "22 September 2021";
bool MS=1;
float RS=-60;
float jarak=3;
int MN=9;
int N1=3;
int N2=5;
bool BS=1;
float MA=10;
String tail="~";

void setup(){
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  Serial.begin(9600);
  sender.begin(9600);
}

void loop(){
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
  kirim();
  delay(5000);
}

void kirim() {
  DynamicJsonDocument doc(1000);
  doc["Manufacture ID"] = ID;
  doc["Firmware Version"] = FV;
  doc["Register Timestamp"] = DT;
  doc["Member Status"] = MS;
  doc["RSSI"] = RS;
  doc["JARAK"] = jarak;
  doc["Membership Number"] = MN;
  doc["Neighbour1_id"] = N1;
  doc["Neighbour2_id"] = N2;
  doc["Broadcast Status"] = BS;
  doc["Membership Age"] = MA;
  doc["Tail"] = tail;
  String data = "";
  serializeJson(doc, data);
  serializeJson(doc, Serial);
  serializeJson(doc, sender);
  Serial.println();
}
