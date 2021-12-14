/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

#include <Servo.h>

// You should get Auth Token in the Blynk App.

// Go to the Project Settings (nut icon).

char auth[] = "FVQ8CIIZi9oDIQ0KHPTrOmPYgQi5Xcna";

// Your WiFi credentials.

// Set password to "" for open networks.

char ssid[] = "vivo806";

char pass[] = "arun123456";

Servo servo;
int value;

void setup() {

// Debug console Serial.begin(115200);

Blynk.begin(auth, ssid, pass);

// You can also specify server:

//Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);

//Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

servo.attach(15); // 15 means D8 pin of ESP8266

}

void loop()

{
analogWrite(D8,value);
Blynk.run(); // You can inject your own code or combine it with other sketches.

}
BLYNK_WRITE(V0)
{
   value=param.asInt();
}
