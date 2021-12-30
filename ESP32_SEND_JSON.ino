/*pin ESP8266*/
//M0 = D3
//M1 = D4
//RX = D2
//TX = D1

/*pin ESP32*/
//RX = D16
//TX = D17
//M0 = D18
//M1 = D19

//#include <SoftwareSerial.h>
#include <ArduinoJson.h>
//SoftwareSerial sender(D1, D2);
int M0 = 18;
int M1 = 19;

String ID="MKR2O21";
int FV=1;
String DT = "22 September 2021";
bool MS=1;
float RS=-60;
float jarak=3;
int MN=900;
int N1=300;
int N2=500;
bool BS=1;
float MA=100;
String tail="~";

void setup(){
  pinMode(M0,OUTPUT);
  pinMode(M1,OUTPUT);
  Serial.begin(9600);
  Serial2.begin(9600);
}

void loop(){
  digitalWrite(M0,LOW);
  digitalWrite(M1,LOW);
  kirim();
  delay(5000);
}

void kirim() {
  DynamicJsonDocument doc(1000);
  doc["node"] = ID;
  doc["header"] = FV;
  doc["suhu"] = DT;
  doc["kelembaban"] = MS;
  doc["atitude"] = RS;
  doc["Tail"] = tail;
  String data = "";
  serializeJson(doc, data);
  serializeJson(doc, Serial);
  serializeJson(doc, Serial2);
  Serial.println();
}
