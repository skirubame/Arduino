#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <ThingSpeak.h>


#include <dht.h>
dht DHT;

const char* ssid = ""; //Your Network SSID
const char* password = ""; //Your Network Password
#define dht_apin D3
//dht DHT;
float Temperature;
int Humidity;
WiFiClient client;

unsigned long myChannelNumber = 1678204; //Your Channel Number (Without Brackets)

const char * myWriteAPIKey = "D387ACW6UTNH61HN"; //Your Write API Key
void setup()

{
pinMode(dht_apin,INPUT); 
//Blynk.begin(auth,ssid,password);
Serial.begin(9600);
delay(10);

// Connect to WiFi network

//WiFi.begin(ssid);
 
WiFi.mode(WIFI_STA);

ThingSpeak.begin(client);

//timing

}



void loop()

{
   
  
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Connecting to ");
    Serial.print(ssid);
    Serial.println(" ....");
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid,password);
      delay(5000);
    }
    Serial.println("connected to wi-fi");
  }
 Serial.println(WiFi.macAddress());
 Serial.println(WiFi.localIP());
   DHT.read11(dht_apin);
  
 Humidity=DHT.humidity;
 Temperature=DHT.temperature;
 
  
Serial.println(Temperature); //Print on Serial Monitor

delay(1000);
Serial.println(Humidity); //Print on Serial Monitor
delay(1000);


ThingSpeak.writeField(myChannelNumber, 1,Temperature, myWriteAPIKey); //Update in ThingSpeak
delay(500);
ThingSpeak.writeField(myChannelNumber, 2,Humidity, myWriteAPIKey); //Update in ThingSpeak
delay(500);

 //Blynk.virtualWrite(V0, Temperature);
 // Blynk.virtualWrite(V1, Humidity);
  //Blynk.virtualWrite(V2, Temperature);
  //Blynk.virtualWrite(V3, Humidity);
   //Blynk.virtualWrite(V4,data);
//Blynk.virtualWrite(V5,"Pure Air");
   
  //Blynk.run();
  //newData=true;
}
