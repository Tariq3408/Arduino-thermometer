#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTTYPE DHT11
const int DHTPIN = 7;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 11, 5, 4, 3, 2);
DHT dht(DHTPIN, DHTTYPE);

int backlightPin = 9;

float prevTemperature = 0;
float temperature = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
   pinMode(backlightPin, OUTPUT);
  analogWrite(backlightPin, 255);
}

void loop() {
 delay(2000);
temperature = dht.readTemperature(true);
  lcd.setCursor(0, 0);
  lcd.clear();
lcd.print("Temp : ");
lcd.print(temperature);

if(temperature != prevTemperature)
{
  lcd.setCursor(0, 0);
  lcd.clear();
  
  lcd.print("Updating...");
  delay(1000);

  prevTemperature = temperature; 
  }

}

