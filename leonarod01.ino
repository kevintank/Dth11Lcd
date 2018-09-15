#include <Mouse.h>

#define LED 3
#define ANALOG A0

int nA0_Value = 0;
const int xAxis = A0;
const int yAxis = A1;
void setup() {
  // put your setup code here, to run once:
pinMode(LED, OUTPUT);
Serial.begin(9600);
Mouse.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
nA0_Value = analogRead(ANALOG);
analogWrite(LED, nA0_Value /4);

Serial.println(nA0_Value);

 int x = readAxis(xAxis);
 int y = readAxis(yAxis);
 Serial.print(x);

 Mouse.move(x, 0, 0);
  
delay(10);
}

int readAxis(int thisAxis)
{
  int reading = analogRead(thisAxis);
 
  reading = map(reading, 0, 1023, 0, 12);
 
  int distance = reading - 6;
 
  if (abs(distance) < 2) {
    distance = 0;
  }
  return distance;
}
            
