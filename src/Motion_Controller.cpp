#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

void chatterCallback(const geometry_msgs::Twist::ConstPtr& Speed)
{
  ROS_INFO("Linear Velocity: x = %f, y = %f, z = %f", Speed->linear.x, Speed->linear.y, Speed->linear.z);
  ROS_INFO("Angular Velocity: x = %f, y = %f, z = %f", Speed->angular.x, Speed->angular.y, Speed->angular.z);
}
int main(int argc,char **argv)
{
  ros::init(argc,argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub=n.subscribe("chatter",1000,chatterCallback);
  ros::spin();

  return 0;
}