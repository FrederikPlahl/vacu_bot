#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"



void rangeCheck(const sensor_msgs::LaserScan scan_msg)
{
  ros::NodeHandle node;

  geometry_msgs::Twist twist_msg;

  ros::Publisher pub = node.advertise<geometry_msgs::Twist>("cmd_vel", 1000);


  float max_range = 1.0;
  

  if (scan_msg.ranges[0] <= max_range)
  {
    //rückwärts und drehen
    
    ROS_INFO("Careful! There is a wall.");

    twist_msg.linear.x = -1;
    twist_msg.angular.x = -0.5;

  }
  else
  {
    //geradeaus fahren

    ROS_INFO("No wall! I'm going straight.");

    twist_msg.linear.x = 0.3;    
  }

  pub.publish(twist_msg);

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "range_checker");
  ros::NodeHandle n;

  ros::Publisher pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ros::Subscriber sub = n.subscribe("scan", 1000, rangeCheck); 

  ros::spin();

  return 0;
}