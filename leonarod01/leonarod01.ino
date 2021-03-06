#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT11.h>
//폴더이름과 파일이름이 같아야 함
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN            9
DHT11 dht11(DHTPIN); 

void setup()
{
  Serial.begin(9600);
  // initialize the LCD
  lcd.begin();
}

void loop()
{
    int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0)
  {
    lcd.backlight();
    lcd.display();
    lcd.print("TEMP:     ");
    lcd.print(temp);
    lcd.setCursor(0,1);
    lcd.print("HUMIDITY: ");
    lcd.print(humi);
 
    Serial.print("temp: ");
    Serial.print(temp);
    Serial.print("humi: ");
    Serial.print(humi);
    Serial.println();
  }
  else
  {
    lcd.backlight();
    lcd.display();
    lcd.print("ERROR NO.: ");
    lcd.print(err);
  }
  delay(10000); //10초마다 Refresh
  lcd.clear();
 
}
