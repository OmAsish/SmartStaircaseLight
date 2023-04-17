int step1 = 2;
int step2 = 3;
int step3 = 4;
int step4 = 5;
int step5 = 6;
int step6 = 7;
int step7 = 8;
int step8 = 9;
#define step9 A0
unsigned long firsttime1;
unsigned long secondtime1;
unsigned long firsttime2;
unsigned long secondtime2;
#define downsensor1pin 13
#define downsensor2pin 12
#define upsensor1pin 10
#define upsensor2pin 11
long time1=0;
long time2=0;
int peoplecount=0;
boolean state1 = true;
boolean state2 = true;
boolean state3 = true;
boolean state4 = true;

void toupon()
{
  digitalWrite(step1, 1); delay(100);
  digitalWrite(step2, 1); delay(100);
  digitalWrite(step3, 1); delay(100);
  digitalWrite(step4, 1); delay(100);
  digitalWrite(step5, 1); delay(100);
  digitalWrite(step6, 1); delay(100);
  digitalWrite(step7, 1); delay(100);
  digitalWrite(step8, 1); delay(100);
  digitalWrite(step9, 1); delay(100);
}

void todownon()
{
  digitalWrite(step9, 1); delay(100);
  digitalWrite(step8, 1); delay(100);
  digitalWrite(step7, 1); delay(100);
  digitalWrite(step6, 1); delay(100);
  digitalWrite(step5, 1); delay(100);
  digitalWrite(step4, 1); delay(100);
  digitalWrite(step3, 1); delay(100);
  digitalWrite(step2, 1); delay(100);
  digitalWrite(step1, 1); delay(100);
}

void toupoff()
{
  digitalWrite(step1, 0); delay(100);
  digitalWrite(step2, 0); delay(100);
  digitalWrite(step3, 0); delay(100);
  digitalWrite(step4, 0); delay(100);
  digitalWrite(step5, 0); delay(100);
  digitalWrite(step6, 0); delay(100);
  digitalWrite(step7, 0); delay(100);
  digitalWrite(step8, 0); delay(100);
  digitalWrite(step9, 0); delay(100);
}

void todownoff()
{
  digitalWrite(step9, 0); delay(100);
  digitalWrite(step8, 0); delay(100);
  digitalWrite(step7, 0); delay(100);
  digitalWrite(step6, 0); delay(100);
  digitalWrite(step5, 0); delay(100);
  digitalWrite(step4, 0); delay(100);
  digitalWrite(step3, 0); delay(100);
  digitalWrite(step2, 0); delay(100);
  digitalWrite(step1, 0); delay(100);
}


void setup() {
  Serial.begin(9600);
  pinMode(downsensor1pin,INPUT);
  pinMode(downsensor2pin,INPUT);
  pinMode(upsensor1pin,INPUT);
  pinMode(upsensor2pin,INPUT);
  pinMode(step1, OUTPUT);
  pinMode(step2, OUTPUT);
  pinMode(step3, OUTPUT);
  pinMode(step4, OUTPUT);
  pinMode(step5, OUTPUT);
  pinMode(step6, OUTPUT);
  pinMode(step7, OUTPUT);
  pinMode(step8, OUTPUT);
  pinMode(step9, OUTPUT);

  digitalWrite(step1, LOW);
  digitalWrite(step2, LOW);
  digitalWrite(step3, LOW);
  digitalWrite(step4, LOW);
  digitalWrite(step5, LOW);
  digitalWrite(step6, LOW);
  digitalWrite(step7, LOW);
  digitalWrite(step8, LOW);
  digitalWrite(step9, LOW);
}
void loop()
{
  
  if(!digitalRead(downsensor1pin) && state1)
  {
    state1=false;
    firsttime1=millis();
  }
  if(!digitalRead(downsensor2pin) && state2)
  {
    state2=false;
    secondtime1=millis();
  }
  time1=firsttime1-secondtime1;
  
  
    
  if(time1<0 && firsttime1!=0)
  {
//    Serial.println("Entry");
    peoplecount++;
    firsttime1=0;
    secondtime1=0;
    if(peoplecount==1)
    {
      toupon();
    }
  }
  if(time1>0 && secondtime1!=0)
  {
//    Serial.println("Exit");
    peoplecount--;
    secondtime1=0;
    firsttime1=0;
    if(peoplecount==0)
    {
      todownoff();
    }
  }
  
  
  if (digitalRead(downsensor1pin))
  {
     state1 = true;
     delay(100);
  }
  if (digitalRead(downsensor2pin))
  {
     state2 = true;
     delay(100);
  }
  
  
  if(!digitalRead(upsensor1pin) && state3)
  {
    state3=false;
    firsttime2=millis();
  }
  if(!digitalRead(upsensor2pin) && state4)
  {
    state4=false;
    secondtime2=millis();
  }
  time2=firsttime2-secondtime2;
  
  
  
  if(time2<0 && firsttime2!=0)
  {
//    Serial.println("Entry");
    peoplecount++;
    firsttime2=0;
    secondtime2=0;
    if(peoplecount==1)
    {
      todownon();
    }
  }
  if(time2>0 && secondtime2!=0)
  {
//    Serial.println("Exit");
    peoplecount--;
    secondtime2=0;
    firsttime2=0;
    if(peoplecount==0)
    {
      toupoff();
    }
  }
  
    
   if (digitalRead(upsensor1pin))
  {
     state3 = true;
     delay(100);
  }
  if (digitalRead(upsensor2pin))
  {
     state4 = true;
     delay(100);
  }
  Serial.println(peoplecount);
}
