
#define GREEN_LED 17 
#define PWMA 5
#define AI2 4 
#define AI1 3 
#define STDBY 2 
#define SONE 12
#define STWO 11
#define STHREE 10
#define BUTTON 6
int speed = 250;
int lowspeed = 113;
void setup () {
  //put your setup code here, to run once:
  pinMode(GREEN_LED,OUTPUT);

  pinMode(PWMA,OUTPUT);
  pinMode(AI2,OUTPUT);
  pinMode(AI1,OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(STDBY,HIGH);
  
}


void loop () {
  digitalWrite(AI1,HIGH);
  digitalWrite(AI2,LOW);
  digitalWrite(STDBY,HIGH);
  if(digitalRead(BUTTON) == LOW){
    digitalWrite(GREEN_LED,HIGH);
    analogWrite(PWMA, speed);
  } else {
      digitalWrite(GREEN_LED,LOW);
      analogWrite(PWMA, lowspeed);
  }
  



  
} 


	
