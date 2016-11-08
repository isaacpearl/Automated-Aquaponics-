#include <DallasTemperature.h>

#include <OneWire.h>

int temp_sensor = 5;

float temperature = 0;
int lowerLimit = 15;
int higherLimit = 35;

OneWire oneWirePin(temp_sensor);
DallasTemperature sensors(&oneWirePin);


void setup() {
  Serial.begin(9600);
  sensors.begin();
  
}

void loop() {
  Serial.print("Requesting Temperatures from sensors: ");
  sensors.requestTemperatures(); 
  Serial.println("DONE");
  temperature = sensors.getTempCByIndex(0);
  Serial.print(temperature);
  Serial.println("°C");
  delay(500);
}
