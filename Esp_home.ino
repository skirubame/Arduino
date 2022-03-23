#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);

/* WIFI settings */
const char* ssid = "";   //WIFI SSID
const char* password = "";    //WIFI PASSWORD

/* data received from application */
String  data =""; 

int Relay1 = D2;
int Relay2=D3;

void setup()
{
Serial.begin(115200);
  WiFi.begin(ssid,password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");

  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT); 
  
  digitalWrite(Relay1,LOW);
  digitalWrite(Relay2,LOW);
  
  /* start server communication */
  
   server.begin();
}

void loop()
{
    /* If the server available, run the "checkClient" function */  
     /*unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >=interval){
    switch (WiFi.status()){
      case WL_NO_SSID_AVAIL:
        Serial.println("Configured SSID cannot be reached");
        break;
      case WL_CONNECTED:
        Serial.println("Connection successfully established");
        break;
      case WL_CONNECT_FAILED:
        Serial.println("Connection failed");
        break;
    }
    Serial.printf("Connection status: %d\n", WiFi.status());
    Serial.print("RRSI: ");
    Serial.println(WiFi.RSSI());*/    
  
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
 

/********************************** RECEIVE DATA FROM the APP ******************************************/
String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}
