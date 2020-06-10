#include "DHT.h"
 
#define DHTPIN 12
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float humi = 0; 
float temp = 0;
 
void setDht() {
    dht.begin();
}

void setTempAndHumi() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if(!isnan(t)) {
        temp = t;
    }
    if(!isnan(h)) {
        humi = h;
    }
}
 
float getTemperature() {
    return temp;
}

float getHumidity() {
    return humi;
}