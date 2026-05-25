#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

char ssid[] = "Testing"; //SSID here
char pass[] = "12345678"; // Passowrd here

unsigned long Channel_ID =  2508712; // Your Channel ID
const char * myWriteAPIKey = "T4DNB0P637YRMU04"; //Your write API key
const int Field_Number_1 = 1;
String value1 = "";
int value_1 = 0, value_2 = 0,value_3 = 0;
int x, y;
WiFiClient  client;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);//for on th
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  internet();
}
void loop()
{
    internet();
    delay(100);
    while (Serial.available() > 0)
    {
      value1 = Serial.readString();
      value_1 = ((value1[0] - 0x30) * 10 + (value1[1] - 0x30));      
    }
  upload();
}
void internet()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      delay(5000);
    }
  }
}
void upload()
{
  ThingSpeak.writeField(Channel_ID, Field_Number_1, value_1, myWriteAPIKey);
  delay(1000);
}