#include<ros.h>
#include<std_msgs/UInt8.h>
#include<Servo.h>

Servo myservo;

ros::NodeHandle nh;
void messageCb(const std_msgs::UInt8& test_msg){
  if(0<=test_msg.data&&test_msg.data<=180){
  myservo.write(test_msg.data);
  delay(500);
  }
}

ros::Subscriber<std_msgs::UInt8> sub("testsub",messageCb);

void  setup(){

  pinMode(10,OUTPUT);
  myservo.attach(10);
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
}
