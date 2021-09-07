#include <IRremote.h>
int RECV_PIN = 11;
int relay=7;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode(relay,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))
    {
     Serial.println(results.value);
     irrecv.resume(); // Receive the next value
    }
    switch(results.value)
    {
      case 50167935:
      digitalWrite(relay,HIGH);
      break;
      case 50151615:
      digitalWrite(relay,LOW);
      break;
      case 50184255:
      digitalWrite(relay,LOW);
      break;
      case 50143455:
      digitalWrite(relay,HIGH);
      break;



    }
}
