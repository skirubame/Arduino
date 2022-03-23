#include <SoftwareSerial.h>
int IRSensor1 =9;
int IRSensor2 =10;
int IRSensor3=11;
int relay1=5;
int relay2=12;;
int relay3=8;
int a=0;
int b=0;
int c=0;
char value;
int TxD = 2;
int RxD = 3;
int flag=0;
int flag1=0;
int flag2=0;
SoftwareSerial bluetooth(TxD, RxD);

void setup() 
{
  pinMode (IRSensor1, INPUT);
  pinMode (IRSensor2, INPUT);
  pinMode (IRSensor3, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,HIGH);
  digitalWrite(relay3,HIGH);
  Serial.begin(9600);      
  bluetooth.begin(9600);
}

void loop()
{
  int statusSensor1 = digitalRead (IRSensor1);
  int statusSensor2 = digitalRead (IRSensor2);
  int statusSensor3 = digitalRead (IRSensor3);


  if (statusSensor1 == LOW)
  {
  a=1-a;
  if(a==1)
  {
  digitalWrite(relay1, LOW);
  Serial.println("When a is statussensor1 is low");
  Serial.println(a);
  flag=1;
  delay(750);
  }
  else
  {
  digitalWrite(relay1, HIGH);
  
  Serial.println("When a is statussensor1 is HIGH");
  Serial.println(a);
  delay(750);
  }
  }

  if (statusSensor2 == LOW)
  {
  b=1-b;
  if(b==1)
  {
  digitalWrite(relay2, LOW);

  Serial.println("When b is statussensor2 is low");
  Serial.println(b);
flag1=1;
   delay(750);
  }
  else
  {
  digitalWrite(relay2, HIGH);
  
  Serial.println("When b is statussensor2 is HIGH");
  Serial.println(b);
  delay(750);
  }
  }

  if (statusSensor3 == LOW)
  {
  c=1-c;
  if(c==1)
  {
  digitalWrite(relay3, LOW);
  flag2=1;
  Serial.println("When c is statussensor3 is low");
  Serial.println(c);
  delay(750);
  }
  else
  {
  digitalWrite(relay3, HIGH);
  
  Serial.println("When c is statussensor3 is HIGH");
  Serial.println(c);
  delay(750);
  }
  }

    if (bluetooth.available())
  {
  value = bluetooth.read();
  Serial.println(value);

  if(value == 'a' && flag==1 )
  {
    digitalWrite(relay1,HIGH);
   flag=0; 
  }
  else if(value=='b' && flag==0)
  {
    digitalWrite(relay1,LOW);
    flag=1;
  }

  if(value == 'd' && flag1==1)
  {
    digitalWrite(relay2,HIGH);
    flag1=0; 
  }
  else if(value=='c' && flag1==0)
  {
    digitalWrite(relay2,LOW);
    flag1=1;
  }

  if(value=='f' && flag2==1)
  {
   digitalWrite(relay3,HIGH);
   flag2=0; 
  }
  else if(value=='e' && flag2==0)
  {
    digitalWrite(relay3,LOW);
    flag2=1;
  }
  }
}
