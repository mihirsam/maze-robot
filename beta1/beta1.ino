/*
Coders : Mihir (Xenon)
         Rishav Anand (xTesseract)
*/

int m1 = 8; //motor_port_1
int m2 = 9; //motor_port_2
int fsv; //front_sensor_value
int lsv; //left_sensor_value
int rsv; //right_sensor_value
int fsp = 1; //forward_sensor_port
int lsp = 2;  //left_sensor_port
int rsp = 3;  //right_sensor_port
int ls = 0; //left space
int rs = 0; //right_space
int fs = 0; //forward_space
int tw = 30; //assumed_total_width
int bot_length = 13;

void setup()
{
    pinMode(m1,OUTPUT);
    pinMode(m2,OUTPUT);
    pinMode(fsv,INPUT);
    pinMode(lsv,INPUT);
    pinMode(rsv,INPUT);

    lsv = analogRead(lsp);
    rsv = analogRead(rsp);
    if(lsv < 30 && rsv < 30){
    tw = lsv+bot_length+rsv; // setting total width of the path else going with assumtion

    }

}

void loop()
{   //assuming that for lsv=4.5 this loop will make lsv=5. same for rsv
    //for too small total width wrt to robot, m1 & m2 will be interchanged
    if(lsv<5)
    {
        digitalWrite(m2,0);
        digitalWrite(m1,1);
        delay(300);
        digitalWrite(m1,1);
        digitalWrite(m2,1);
        delay(400);
        digitalWrite(m1,0);
        digitalWrite(m2,1);
        delay(150);
    }
    if(rsv<5)
    {
        digitalWrite(m1,0);
        digitalWrite(m2,1);
        delay(300);
        digitalWrite(m1,1);
        digitalWrite(m2,1);
        delay(400);
        digitalWrite(m2,0);
        digitalWrite(m1,1);
        delay(150);
    }
}
