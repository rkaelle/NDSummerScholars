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

int systemState;
int idlespeed = 111;


  //put your setup code here, to run once:
  pinMode(GREEN_LED,OUTPUT);
  pinMode(PWMA,OUTPUT);
  pinMode(AI2,OUTPUT);
  pinMode(AI1,OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(STDBY,HIGH);
  systemState = WAITING_FOR_START;
}


void loop () {
  digitalWrite(AI1,HIGH);
  digitalWrite(AI2,LOW);
  digitalWrite(STDBY,HIGH);
  
  switch(systemState){
    case WAITING_FOR_START:
      if(digitalRead(BUTTON) == LOW) {
        systemState = STARTING;
      }
      break;
    case STARTING:
      systemState = SEGMENT_1;
      break;
    case SEGMENT_1:
      if(digitalRead(STWO) == LOW) {
        systemState = SEGMENT_2;
        analogWrite(PWMA, 114);
      }
      break;
    case SEGMENT_2:
      if(digitalRead(STHREE) == LOW) {
        systemState = SEGMENT_3;
        analogWrite(PWMA, 125);
      }
      break;
    case SEGMENT_3:
      if(digitalRead(SFOUR) == LOW) {
        systemState = SEGMENT_4;
        analogWrite(PWMA, 145);
      }
      break;
    case SEGMENT_4:
      if(digitalRead(SFIVE) == LOW) {
        systemState = SEGMENT_5;
        analogWrite(PWMA, 147);
      }
      break;
    case SEGMENT_5:
      if(digitalRead(SONE) == LOW) {
        systemState = SEGMENT_1;
        analogWrite(PWMA, 120);
      }
      break;
  }
}
