const int rmf = 9;                        //Left motor forward
const int rmb = 10;                        //Left motor backward
const int lmf = 5;                       //Right motor forward
const int lmb = 3;                        //Right motor backward
const int trigPin_l = 11;                 //right sensor trigger pin
const int echoPin_l = 12;                //right sensor echo pin
const int trigPin_r = 7;                  //left sensor trigger pin
const int echoPin_r = 6;                 //sraight sensor echo pin
const int trigPin_s = 4;                  //straight sensor trigger pin
const int echoPin_s = 8;                 //left sensor echo pin
long duration_r, cm_r, duration_l, cm_l, duration_s, cm_s;  //establish variables for duration of the ping, and the distance result in cm
int lm_status, rm_status;         //left motor status, right motor status, 0 = none , 1 = forward, -1 = backward 

/*const int trigPin= 11;
const int echoPin= 12;

const int trigPin2= 7;
const int echoPin2= 6;
*/ 
void setup() {
  Serial.begin(9600);
  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(trigPin_l, OUTPUT);
  pinMode(trigPin_s, OUTPUT);
  pinMode(trigPin_r, OUTPUT);
  pinMode(echoPin_l, INPUT);
  pinMode(echoPin_s, INPUT);
  pinMode(echoPin_r, INPUT);
}

void loop() {
  
  digitalWrite(trigPin_l, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_l, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_l, LOW);
  duration_l = pulseIn(echoPin_l, HIGH);
  cm_l = microsecondsToCentimeters(duration_l);
  if(cm_l > 1000){
    cm_l = 0;
  }

  digitalWrite(trigPin_r, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_r, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_r, LOW);
  duration_r = pulseIn(echoPin_r, HIGH);
  cm_r = microsecondsToCentimeters(duration_r);
  if(cm_r > 500){
    cm_r = 0;
  }

  digitalWrite(trigPin_s, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_s, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_s, LOW);
  duration_s = pulseIn(echoPin_s, HIGH);
  cm_s = microsecondsToCentimeters(duration_s);
  /*if(cm_s > 1000){
    cm_s = 0;
  }*/

  /*Serial.print(cm_l);
  Serial.print("cm , ");
  Serial.print(cm_s);
  Serial.print("cm , ");
  Serial.print(cm_r);
  Serial.println("cm");*/

  if(cm_l > 50){ 
    /*if(cm_s > 15){
      forward_s(100);
    }*/
    leftTurn(70);
    forward_s(80);
    stopBot();
  }
  else if(cm_s < 25 && cm_r > 50){
    if(cm_s > 25){
      forward_s(80);
    }
    rightTurn(70);
    forward_s(70); 
    stopBot();
  }
  else{
    forward();   
  }
  
}

void leftTurn(int time) {
  analogWrite(lmf, 0);
  analogWrite(rmb, 0);
  analogWrite(lmb, 220);
  analogWrite(rmf, 220);
  delay(time);
}

void rightTurn(int time) {
  analogWrite(lmb, 0);
  analogWrite(rmf, 0);
  analogWrite(lmf, 230);
  analogWrite(rmb, 230);
  delay(time);
}

void forward_s(int time){
  analogWrite(lmb, 0);
  analogWrite(rmb, 0);
  analogWrite(lmf, 150);
  analogWrite(rmf, 150);
  delay(time);
}

void forward() {
  digitalWrite(trigPin_s, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_s, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_s, LOW);
  duration_s = pulseIn(echoPin_s, HIGH);
  cm_s = microsecondsToCentimeters(duration_s);

  digitalWrite(trigPin_l, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_l, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_l, LOW);
  duration_l = pulseIn(echoPin_l, HIGH);
  cm_l = microsecondsToCentimeters(duration_l);
  //Serial.print(cm_l);
  //Serial.print("cm , ");

  digitalWrite(trigPin_r, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_r, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_r, LOW);
  duration_r = pulseIn(echoPin_r, HIGH);
  cm_r = microsecondsToCentimeters(duration_r);
  //Serial.print(cm_r);
  //Serial.println("cm");

  if(cm_l > 500){cm_l = 0;}
  if(cm_l < 25){
    rightTurn(30);
  }
  else if(cm_r < 25){
    leftTurn(30); 
  }
  
  analogWrite(lmb, 0);
  analogWrite(rmb, 0);
  analogWrite(lmf, 150);
  analogWrite(rmf, 150);
  delay(50);
}

void stopBot(){
  analogWrite(lmb, 0);
  analogWrite(rmb, 0);
  analogWrite(lmf, 0);
  analogWrite(rmf, 0);
}
long microsecondsToCentimeters(long microseconds){
    return microseconds / 29 / 2;
  }
