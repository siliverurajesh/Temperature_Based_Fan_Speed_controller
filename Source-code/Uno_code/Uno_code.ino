#include<LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>
LiquidCrystal lcd(14,15,16,17,18,19);  // set the LCD address to 0x3F for a 16 chars and 2 line display

#define ONE_WIRE_BUS 7
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);



const int fan = 6; 
const int inc = 4;
const int dec = 3;
int temp;
boolean flag;
int count;
boolean ctrl=0;
float tempstpt = 30;
float t;
void setup() 
{
  sensors.begin();
  Serial.begin(9600);
  pinMode(fan,OUTPUT);
  pinMode(inc,INPUT_PULLUP);
  pinMode(dec,INPUT_PULLUP);
  lcd.begin(16, 2);  
  lcd.setCursor(0,0); 
  lcd.print("Temperature ");
  lcd.setCursor(0,1); 
  lcd.print("Controlled Fan");
  delay(3000);
  lcd.clear();
  }
void loop() 
{
  lcd.setCursor(0,0);
  lcd.print("T.SET.PT:"); 
  lcd.print(tempstpt,0); 
  lcd.print(char(223));
  lcd.print("C ");
  
   sensors.requestTemperatures();
   lcd.setCursor(0, 1);
   lcd.print("T:");
   t = sensors.getTempCByIndex(0);
   lcd.print(t);
   lcd.print(char(223));
   lcd.print('C');
   
  
  if(digitalRead(inc)==LOW)
  {
    tempstpt = tempstpt+1;
    delay(500);
  }
  if(digitalRead(dec)==LOW)
  {
    if(tempstpt>0)
    tempstpt = tempstpt-1;
    delay(500);
  }
  lcd.setCursor(10,1);
  if(t>tempstpt)
  {
        if((t-tempstpt)>3)
        {
        analogWrite(fan,255);
        lcd.setCursor(10,1);
        lcd.print("F:HIGH");
        }
        else if((t-tempstpt)>2)
        {
          analogWrite(fan,128);
          lcd.setCursor(10,1);
          lcd.print("F:MED ");
        }
        else if((t-tempstpt)>1)
        {
          analogWrite(fan,100);
          lcd.setCursor(10,1);
          lcd.print("F:LOW ");
        }
  }
  else
  {
   lcd.setCursor(10,1);
   analogWrite(fan,0);
   lcd.print("F:OFF");
  }
  for(count = 0;count<5;count++)
  {
    Serial.print("*");
    Serial.print(t,0);
    Serial.print("#");
  }
}