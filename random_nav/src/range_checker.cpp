#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"



void rangeCheck(const sensor_msgs::LaserScan scan_msg)
{
  ros::NodeHandle node;

  geometry_msgs::Twist twist_msg;

  ros::Publisher pub = node.advertise<geometry_msgs::Twist>("cmd_vel", 1000);


  float max_range = 1.7;
  //int len = sizeof(scan_msg.ranges)/sizeof(scan_msg.*ranges);
  int scan_width_end = 400; //0,5° Steps starting at the back
  int scan_width_start = 320;

  for (int i = scan_width_start; i < scan_width_end; i++){
    if (i<(scan_width_start+scan_width_end)/2){
      if (scan_msg.ranges[i] <= max_range)
      {
        //rückwärts rchts und drehen
        ROS_INFO("Careful! There is a wall.%i", i);
        twist_msg.linear.x = -0.3;
        twist_msg.angular.z = 3;
      }
      else
    {
      //geradeaus fahren
      ROS_INFO("No wall! I'm going straight.%i", i);
      twist_msg.linear.x = 0.3;    
    }
    }
    else
    {
      if (scan_msg.ranges[i] <= max_range)
      {
        //rückwärts links und drehen
        ROS_INFO("Careful! There is a wall.%i", i);
        twist_msg.linear.x = -0.3;
        twist_msg.angular.z = -3;
      }
      else
      {
      //geradeaus fahren
      ROS_INFO("No wall! I'm going straight.%i", i);
      twist_msg.linear.x = 0.3;    
      }
    }
    pub.publish(twist_msg);
  }
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
