/*pin ESP8266*/
//M0 = D3
//M1 = D4
//RX = D2
//TX = D1

/*pin ESP32*/
//RX = D17
//TX = D18
//M0 = D18 or GND
//M1 = D19 or GND

#include <EEPROM.h>
#include <DNSServer.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiManager.h>



/* pin ESP82266 */
//#include <SoftwareSerial.h> 

/* pin ESP82266 */
//SoftwareSerial receptor(D1, D2);

//int M0 = 18;
//int M1 = 19;

StaticJsonDocument<10000> doc;
//char data;

//Setting Server

String server = "http://192.168.1.8/tesjson/api.php";

/*Wifi connect*/
WiFiClient client;


void setup() {
/* pin ESP82266 */
//  pinMode(D3, OUTPUT);
//  pinMode(D4, OUTPUT);

//  pinMode(M0,OUTPUT);
 // pinMode(M1,OUTPUT);

  
  Serial.begin(9600);
 WiFi.mode(WIFI_STA);
 WiFiManager wm; 
 bool res;
// wm.resetSettings();
     res = wm.autoConnect("AutoConnectAP","password"); // password protected ap


    if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("connected...yey terkoneksi");
    }



  Serial.println();
  Serial.println("connect");
  Serial2.begin(9600);
  delay(100);

  delay(1000);
}

void loop() {
//  digitalWrite(M0,LOW);
//  digitalWrite(M1,LOW);

  /* pin ESP82266 */
//  digitalWrite(D3, LOW);
//  digitalWrite(D4, LOW);

    String terima = Serial2.readString();
    if (terima != "") {
      DeserializationError error = deserializeJson(doc, terima);
      if (error) {
        Serial.println("ERROR JSON");
      } else {
        String ID = doc["node"];
        Serial.println("ID Manufacture: " + ID);
        String FV = doc["header"];
        Serial.println("Versi Firmware: " + FV);
        String DT = doc["suhu"];
        Serial.println("Register Timestamp: " + DT);
        String MS = doc["kelembababn"];
        Serial.println("Member Status: " + MS);
        String RS = doc["atitude"];
        Serial.println("RSSI: " + RS);
        String tail = doc["Tail"];
        Serial.println("Tail: " + tail);
        Serial.println();
      }
    } else {
      Serial.println("DATA JSON KOSONG");
    }
  
}


//PostD Json
bool postD(String url, String data) {
  HTTPClient http;
  int httpCode = 0;
  if (http.begin(client, url)) {  // HTTP
    http.addHeader("Content-Type", "application/json");
    httpCode = http.POST(data);
    Serial.println(http.getString());
    http.end();
  } else {
    Serial.printf("[HTTP} Unable to connect\n");
  }
  Serial.println(httpCode);
  return (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY);
}
