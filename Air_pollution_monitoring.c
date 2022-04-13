#include <MQ135.h>
#define DEBUG true
#include <SoftwareSerial.h>
SoftwareSerial esp(9,10); // This makes pin 9 of Arduino as RX pin and pin 10 of Arduino as the TX pin
const int sensorPin=A0;
int air_quality;
#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 12, 5, 4, 2, 3);

void setup() 
{
 pinMode(8, OUTPUT);
 lcd.begin(16,2);
 lcd.setCursor (0,0);
 lcd.print ("Group 10");
 lcd.setCursor (0,1);
 lcd.print ("Wait..For Ready");
 delay(1500);
 pinMode(sensorPin, INPUT); //Gas sensor will be an input to the arduino
 lcd.clear();
}

void loop() 
{
  MQ135 gasSensor =MQ135(A0); 
  float air_quality = gasSensor.getPPM();

 lcd.setCursor(0, 0);
 lcd.print("Air quality is "); 
 lcd.print(air_quality); 
 lcd.print("PPM"); 
 lcd.setCursor(0,1); 
 if (air_quality <=1000)
 {
  lcd.print("Fresh Air"); 
  digitalWrite(8, LOW);
  } 
  else if( air_quality>=1000 && air_quality <= 2000)
  {
    lcd.print("Poor Air, Open Windows"); 
    digitalWrite(8, HIGH);
   }
  else if (air_quality>=2000)
  {
    lcd.print("Danger! Move to Fresh Air"); 
    digitalWrite(8, HIGH); //turn the LED on
  } 
  lcd.scrollDisplayLeft(); 
  delay(500);
 }
