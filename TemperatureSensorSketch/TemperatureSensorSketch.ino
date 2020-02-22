#include <dht.h>

dht DHT;

int TempSensorPin = 7;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Ez a sor kell, különben nem olvassa be az adatokat és minden 0 lesz.
  DHT.read11(TempSensorPin);
  Serial.print("Homerseklet: "); Serial.print(DHT.temperature); Serial.print("  ");
  Serial.print("Nedvesseg: "); Serial.print(DHT.humidity); Serial.print("  ");
  Serial.println("");

  // A leggyorsabb megengedett sebesség egy olvasás 2 másodpercenként
  delay(2000);
}
