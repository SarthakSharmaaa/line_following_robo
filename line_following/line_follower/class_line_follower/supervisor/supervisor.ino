
#include "alphabot_drivers.h"
#include "line_follower.h"

#define NUM_SENSORS 5
int sensorValues[NUM_SENSORS];
Line_follower__main_out _res;
Line_follower__main_mem _mem;

const int irsen0=8;
const int irsen1=7;
unsigned long previoustime=millis();

int irsen0_reading;
int irsen1_reading;

void setup()
{
init_devices();
forward();
Serial.begin(115200);
}

void loop()
{
AnalogRead(sensorValues);
irsen0_reading=digitalRead(irsen0);
irsen1_reading=digitalRead(irsen1);
unsigned long currenttime=millis();
bool sec=false;
if(currenttime-previoustime>=500)
{
sec=true;
previoustime=currenttime;
}
Line_follower__main_step(sensorValues[0], sensorValues[1], sensorValues[2], sensorValues[3], sensorValues[4], irsen0_reading, irsen1_reading, sec, &_res, &_mem);
Serial.print(_res.v_l);
Serial.print(" ");
Serial.print(_res.v_r);
Serial.print(" ");
// Serial.println(_res.pidvalue);

Serial.print(sensorValues[0]);
Serial.print(" ");
Serial.print(sensorValues[1]);
Serial.print(" ");
Serial.print(sensorValues[2]);
Serial.print(" ");
Serial.print(sensorValues[3]);
Serial.print(" ");
Serial.print(sensorValues[4]);
Serial.print(" ");
Serial.print(irsen0_reading);
Serial.print(" ");
Serial.print(irsen1_reading);
Serial.print(" ");
Serial.print(_res.v_l);
Serial.print(" ");
Serial.print(_res.v_r);
Serial.print(" ");


Serial.println(" ");

if(_res.dir == 3){
left();
}
else if(_res.dir == 4){
right();
}
else if(_res.dir == 5){
backward();
}
else if(_res.dir == 6){
backward();
}

  else if(_res.dir==15){
    delay(10);
    right();
    //delay(5);
  }
  else if(_res.dir==14){
    delay(10);
    left();
  }
else
forward();
SetSpeed(_res.v_l,_res.v_r);

delay(20);
}