#include <ESP8266WiFi.h>
#include <MQTT.h>
#include <dht.h>
#define dht_apin D1  
const char ssid[] = "";
const char pass[] = "";
dht DHT;
               
// Initialize DHT sensor.
//DHT dht(dht_apin, DHTTYPE);                

float Temperature;
float Humidity;
WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("arduino", "try", "try")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

//client.subscribe("TemP");
client.subscribe("HumI");
//messageReceived(
  // client.unsubscribe("/hello");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
  
  analogWrite(D2,payload.toInt());
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
 pinMode(dht_apin, INPUT);
 pinMode(D2,OUTPUT);

  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported by Arduino.
  // You need to set the IP address directly.
  client.begin("broker.shiftr.io", net);
  client.onMessage(messageReceived);

  connect();
}

void loop() {
   DHT.read11(dht_apin);
  Temperature = DHT.temperature; // Gets the values of the temperature
  Humidity = DHT.humidity; // Gets the values of the humidity 
 // Serial.println(Temperature);
  //Serial.println(Humidity);
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }
  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    client.publish("TemP", (String)Temperature);
client.publish("HumI", (String)Humidity);
    
  }
}
