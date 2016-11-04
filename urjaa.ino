int bulb=3;
int fan=4;
int infrared1=8;
int infrared2=7;
int person=0;
int i2state=LOW;
int i1state=LOW;
int flag1=0;
int flag2=0;
void setup() {
  pinMode(bulb, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(infrared1, INPUT);
  pinMode(infrared2, INPUT);
  Serial.begin(9600);
}


void loop() {
    if(digitalRead(infrared1) && flag2==0){
    delay(250);
    flag1=1;
    Serial.print("*flag1:*");
    Serial.println(flag1);
    }
    if ( digitalRead(infrared2) && flag1==1){
    delay(250);
    person++;
    Serial.println("no. of person entered:");  
    Serial.println(person);
    digitalWrite(bulb, HIGH);
    digitalWrite(fan, HIGH);
    Serial.println("lights on");
    flag1=0;
    }
  else if(digitalRead(infrared2) && !digitalRead(infrared1)){
    delay(250);
    flag2=3;
    Serial.print("*flag2:*");
    Serial.println(flag2);
    }
   if(digitalRead(infrared1) && flag2==3){
    delay(250);
    person--;
    Serial.println("no. person remaining:");
    Serial.println(person);   
    flag2=0;
  }
  if (person==0){
    digitalWrite(bulb, LOW);
    digitalWrite(fan, LOW);
    Serial.println("lights Off");
  }

}




