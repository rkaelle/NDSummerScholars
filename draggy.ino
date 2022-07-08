#define GREEN_LED 17
#define PWMA 5
#define AI2 4
#define AI1 3
#define STDBY 2
#define SONE 12
#define STWO 13
#define STHREE 14
#define BUTTON 6
#define BUTTON2 7
#define SFOUR 15
#define SFIVE 16
#define WAITING_FOR_START 0
#define STARTING 1
#define SEGMENT_1 2
#define SEGMENT_2 3
#define SEGMENT_3 4
#define SEGMENT_4 6
#define SEGMENT_5 7
#define DONE 5
#define speed
#define Serial

int systemState;
int idlespeed = 112;
int onespeed = 113;
int twospeed =113;
int threespeed = 130;
int fourspeed = 130;
int fivespeed = 130;
int brakespeed = 0;
int nitroracer = 255;


void setup () {
  //put your setup code here, to run once:
  pinMode(GREEN_LED,OUTPUT);
  pinMode(PWMA,OUTPUT);
  pinMode(AI2,OUTPUT);
  pinMode(AI1,OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(STDBY,HIGH);
  systemState = STARTING;
}

void loop () {
  digitalWrite(AI1,HIGH);
  digitalWrite(AI2,LOW);
  digitalWrite(STDBY,HIGH);
  switch(systemState){
    case STARTING:
      systemState = SEGMENT_1;
      break;
    case SEGMENT_1:
      if(digitalRead(STWO) == LOW) {
        systemState = SEGMENT_2;
        analogWrite(PWMA, nitroracer);
        delay(300);
        digitalWrite(AI1,LOW);
        digitalWrite(AI2,HIGH);
        analogWrite(PWMA,255);
        delay(180);
        digitalWrite(AI1,HIGH);
        digitalWrite(AI2,LOW);
        analogWrite(PWMA, brakespeed);
      }
      break;}}
