#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
char ssid[] = "";  // your network SSID (name)
char pass[] = ""; // your network password
WiFiClient client;
// Channel details
unsigned long myChannelNumber = 1196429; //your public channel number
const char * myReadAPIKey = "Y2KI7J9511718T6R"; //read API
unsigned int FieldToMonitor = 1; //the field you want to monitor
long count;
void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

ThingSpeak.begin(client);
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
      WiFi.begin(ssid,pass);
      delay(5000);
    }
    Serial.println("connected to wi-fi");
  }
 Serial.println(WiFi.macAddress());
 Serial.println(WiFi.localIP());
  //read from channel
  count = ThingSpeak.readLongField(myChannelNumber, FieldToMonitor, myReadAPIKey);
  // Check the status of the read operation to see if it was successful
  int statusCode = 0;
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    Serial.println("Read: " + String(count));
  }
  else
  {
    Serial.println(F("Problem reading channel"));
  }
  delay(15000); // No need to read the counter too often.
}
