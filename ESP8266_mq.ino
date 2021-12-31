#include <ESP8266WiFi.h>
#include <MQTT.h>
const char ssid[] = "";
const char pass[] = "";
int value,ldr;            
// Initialize DHT sensor.
//DHT dht(dht_apin, DHTTYPE);                
WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

void connect() {


  Serial.print("\nconnecting...");
  while (!client.connect("kpriet", "try", "try")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");
client.subscribe("HumI");
client.subscribe("put");

//messageReceived(
  // client.unsubscribe("/hello");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
  value=payload.toInt();
  Serial.println(value);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
 pinMode(A0, INPUT);
 pinMode(D2,OUTPUT);

  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported by Arduino.
  // You need to set the IP address directly.
  client.begin("broker.hivemq.com", net);
  client.onMessage(messageReceived);

  connect();
}

void loop() {
   
  
  ldr =analogRead(A0); // Gets the values of the humidity 
 // Serial.println(Temperature);
  //Serial.println(Humidity);
  digitalWrite(D2,value);
  client.loop();
  delay(10);  
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    client.publish("LDR", (String)ldr);
    
  }
}
