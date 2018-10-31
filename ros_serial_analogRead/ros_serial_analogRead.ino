#include<ros.h>
#include<std_msgs/UInt8MultiArray.h>

ros::NodeHandle node;
std_msgs::UInt8MultiArray value;
std_msgs::MultiArrayLayout layout;

ros::Publisher pub("arduino/analogPin/value",&value);

int analogPinA0=A0;
int analogPinA1=A1;
int analogPinA2=A2;
int analogPinA3=A3;
int analogPinA4=A4;
int analogPinA5=A5;
int analogPinA6=A6;

void setup(){
  /*layout.dim[0].label  = "height";
  layout.dim[0].size   = 1;
  layout.dim[0].stride = 7;
  layout.dim[1].label  = "width";
  layout.dim[1].size   = 7;
  layout.dim[1].stride = 7;
  layout.dim[2].label  = "channel";
  layout.dim[2].size   = 1;
  layout.dim[2].stride = 1;
  */
  value.data_length = 7;
  value.data = (uint8_t *)malloc(sizeof(uint8_t)*6);
  
pinMode(analogPinA0,INPUT);
pinMode(analogPinA1,INPUT);
pinMode(analogPinA2,INPUT);
pinMode(analogPinA3,INPUT);
pinMode(analogPinA4,INPUT);
pinMode(analogPinA5,INPUT);
pinMode(analogPinA6,INPUT);
node.initNode();
node.advertise(pub);
}

void loop(){
  
  value.data[0]=analogRead(analogPinA0);
  value.data[1]=analogRead(analogPinA1);
  value.data[2]=analogRead(analogPinA2);
  value.data[3]=analogRead(analogPinA3);
  value.data[4]=analogRead(analogPinA4);
  value.data[5]=analogRead(analogPinA5);
  value.data[6]=analogRead(analogPinA6);

  pub.publish(&value);

node.spinOnce();
delay(10);
}


