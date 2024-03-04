#include <OneWire.h>
#include <DallasTemperature.h>
#include <dht.h>
#include <LiquidCrystal.h>
dht DHT;

#define ONE_WIRE_BUS 2
#define DHT11_PIN 3

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

LiquidCrystal lcd(12,11,10,9, 8, 7);
void setup() {
  Serial.begin(9600);

  sensors.begin();
  lcd.begin(16,2);

}

void loop() {
  sensors.requestTemperatures(); 
  int chk = DHT.read11(DHT11_PIN);

  Serial.println(DHT.temperature);
  Serial.println(sensors.getTempCByIndex(0)); 
  lcd.setCursor(0, 0);
  lcd.print(sensors.getTempCByIndex(0));
  lcd.setCursor(8, 0);
  lcd.print("In");
  lcd.setCursor(0, 1);  
  lcd.print(DHT.temperature);
  lcd.setCursor(8, 1);
  lcd.print("Out");  
}
