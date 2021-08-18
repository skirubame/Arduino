int input,flag=0,flag1;
char m;
void setup()
{
 
  //Setup usb serial connection to computer
  Serial.begin(9600);

  //Setup Bluetooth serial connection to android
 
}

void loop()
{
 if(Serial.available() > 0)
  {
    
    input = Serial.read();
    Serial.println(input);
  m=char(input); 
  }
    if(m=='a' && flag==0)
  {
    Serial.println("HIGH");
  flag=1;
  }
   if(m=='b' && flag==1)
  {
    Serial.println("LOW");
  flag=0;
  }
  
  
 }
