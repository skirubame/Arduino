#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);

/* WIFI settings */
const char* ssid = "c";   //WIFI SSID
const char* password = "66666666";    //WIFI PASSWORD

/* data received from application */
String  data =""; 

int Relay1 = D2;
int Relay2=D3;

void setup()
{
  /* initialize motor control pins as output */
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT); 
  
  digitalWrite(Relay1,LOW);
  digitalWrite(Relay2,LOW);
  
  /* start server communication */
  Serial.begin(115200);
  connectWiFi();
  server.begin();
}

void loop()
{
    /* If the server available, run the "checkClient" function */  
    client = server.available();
    if (!client) return; 
    data = checkClient ();
Serial.print(data);
/************************ Run function according to incoming data from application *************************/

    
    if (data == "Relay1On")
    { 
      digitalWrite(Relay1,HIGH);
      }
    
    else if (data == "Relay1Off")
    {
      digitalWrite(Relay1,LOW);
      }

    else if (data == "Relay2On")
    {
      digitalWrite(Relay2,HIGH);
      }
      
    else if (data == "Relay2Off")
    {
      digitalWrite(Relay2,LOW);
      }
      
} 

void connectWiFi()
{
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("NodeMCU Local IP is : ");
  Serial.print((WiFi.localIP()));
}
/********************************** RECEIVE DATA FROM the APP ******************************************/
String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}
