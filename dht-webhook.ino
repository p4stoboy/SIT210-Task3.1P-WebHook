#include "Adafruit_DHT.h"

int dhtpin = 7;  
#define DHTTYPE DHT22	
#define EVENT_NAME "Argon-DHT-3.1"


DHT dht(dhtpin, DHTTYPE);

void setup() {
	dht.begin();
}

void loop() {
	delay(2000);

	float humidity = dht.getHumidity();
	float temp = dht.getTempCelcius();
  
    // Check if any reads failed and exit early (to try again).
	if (isnan(humidity) || isnan(temp)) {
		return;
	}

    char msg[256];
    snprintf(msg, sizeof(msg), "{\"field1\":\"%.1f\", \"field2\":\"%.1f\"}", temp, humidity);

    Particle.publish(EVENT_NAME, msg);
}
