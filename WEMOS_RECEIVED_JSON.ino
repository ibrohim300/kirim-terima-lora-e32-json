//M0 = D3
//M1 = D4
//RX = D2
//TX = D1

#include <SoftwareSerial.h> 
#include <ArduinoJson.h>
SoftwareSerial receptor(D1, D2);

StaticJsonDocument<10000> doc;
char data;

void setup() {
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  Serial.begin(9600);
  receptor.begin(9600);
  delay(100);
  Serial.println();
  Serial.println("connect");
}

void loop() {
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  if (receptor.available()) {
    String terima = receptor.readString();
    if (terima != "") {
      DeserializationError error = deserializeJson(doc, terima);
      if (error) {
        Serial.println("ERROR JSON");
      } else {
        String ID = doc["Manufacture ID"];
        Serial.println("ID Manufacture: " + ID);
        String FV = doc["Firmware Version"];
        Serial.println("Versi Firmware: " + FV);
        String DT = doc["Register Timestamp"];
        Serial.println("Register Timestamp: " + DT);
        String MS = doc["Member Status"];
        Serial.println("Member Status: " + MS);
        String RS = doc["RSSI"];
        Serial.println("RSSI: " + RS);
        String jarak = doc["JARAK"];
        Serial.println("JARAK: " + jarak);
        String MN = doc["Membership Number"];
        Serial.println("Membership Number: " + MN);
        String N1 = doc["Neighbour1_id"];
        Serial.println("Neighbour1_id: " + N1);
        String N2 = doc["Neighbour2_id"];
        Serial.println("Neighbour2_id: " + N2);
        String BS = doc["Broadcast Status"];
        Serial.println("Broadcast Status: " + BS);
        String MA = doc["Membership Age"];
        Serial.println("Membership Age: " + MA);
        String tail = doc["Tail"];
        Serial.println("Tail: " + tail);
        Serial.println();
      }
    } else {
      Serial.println("DATA JSON KOSONG");
    }
  }
}
