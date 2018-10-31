#include<ros.h>
#include<std_msgs/UInt8.h>

ros::NodeHandle node;
std_msgs::UInt8 value;
ros::Publisher pub("arduinopsd",&value);

int analogPin=A0;

void setup(){
pinMode(analogPin,INPUT);
node.initNode();
node.advertise(pub);
}

void loop(){
  value.data=analogRead(A0);
  pub.publish(&value);

node.spinOnce();
delay(10);
}


