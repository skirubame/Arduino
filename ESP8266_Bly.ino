#define BLYNK_PRINT Serial

#include <dht.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define dht_apin D3
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "w3mbEEzLZjdCMWqPLH_ie4KZIuhKC3jZ";
dht DHT;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "vivo 1726";
char pass[] = "123456789";
int Temperature;
int Humidity;
void setup()
{
  // Debug console
  Serial.begin(9600);
 pinMode(dht_apin, INPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  DHT.read11(dht_apin);
  Temperature = DHT.temperature; // Gets the values of the temperature
  Humidity = DHT.humidity; // Gets the values of the humidity 
  Serial.println(Temperature);
  Serial.println(Humidity);
  Blynk.virtualWrite(V0,Temperature);
  Blynk.virtualWrite(V1,Humidity);
  Blynk.virtualWrite(V2,Temperature);
  Blynk.virtualWrite(V3,Humidity);
  if(Humidity<=30)
  {
    Blynk.notify("The Humidity is Low");
    }
  Blynk.run();
}
