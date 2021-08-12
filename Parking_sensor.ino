#define ledGreen1 4
#define ledGreen2 5
#define trigPin 7
#define echoPin 6
#define ledYellow1 13
#define ledYellow2 12
#define ledRed1 11
#define ledRed2 10
#define ledWhite1 9
#define ledWhite2 8
#define buzzer 3

int sound = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledWhite1, OUTPUT);
  pinMode(ledWhite2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledGreen1, OUTPUT);
  pinMode(ledGreen2, OUTPUT);
  pinMode(ledYellow1, OUTPUT);
  pinMode(ledYellow2, OUTPUT);
  pinMode(ledRed1, OUTPUT);
  pinMode(ledRed2, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long timeTaken, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  timeTaken = pulseIn(echoPin, HIGH);//determine distance of wave
  distance = (timeTaken/2)/29.1;//using timeTaken calc distance of object

  /*determine corressponding leds to light up with respect to the distance
  of object*/

  if(distance<81){
      digitalWrite(ledGreen1, HIGH); sound = 600;
    }else{
      digitalWrite(ledGreen1, LOW);
      }

   if(distance<71){
      digitalWrite(ledGreen2, HIGH); sound = 800;
    }else{
      digitalWrite(ledGreen2, LOW);
      }
  
  if(distance<61){
      digitalWrite(ledYellow1, HIGH); sound = 1000;
    }else{
      digitalWrite(ledYellow1, LOW);
      }
      
   if(distance<51){
      digitalWrite(ledYellow2, HIGH); sound = 1200;
    }else{
      digitalWrite(ledYellow2, LOW);
      }

    if(distance<41){
      digitalWrite(ledRed1, HIGH); sound = 1400;
    }else{
      digitalWrite(ledRed1, LOW);
      }

    if(distance<31){
      digitalWrite(ledRed2, HIGH); sound = 1600;
    }else{
      digitalWrite(ledRed2, LOW);
      }

    if(distance<21){
      digitalWrite(ledWhite1, HIGH); sound = 1800;
    }else{
      digitalWrite(ledWhite1, LOW);
      }

    if(distance<11){
      digitalWrite(ledWhite2, HIGH); sound = 2000;
    }else{
      digitalWrite(ledWhite2, LOW);
      }

      /*buzzer tone*/
      if(distance>80||distance<=0){
          noTone(buzzer);
         
        }else{
          tone(buzzer, sound);
         
        }
        
      
      delay(500);
}
