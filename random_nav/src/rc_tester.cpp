#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"


int main(int argc, char **argv)
{

  ros::init(argc, argv, "range_test");

  ros::NodeHandle n;


  ros::Publisher test_pub = n.advertise<sensor_msgs::LaserScan>("scan", 1000);

  ros::Rate loop_rate(2);
  
  sensor_msgs::LaserScan msg;
  int count = 1;
  msg.ranges.push_back(1);
  
  while (ros::ok())
  {
    msg.header.stamp = ros::Time::now();

    if(count % 5 == 0){
      msg.ranges[0] = 0.5;
      ROS_INFO("Range is 0.5 m");
    }
    else{
      msg.ranges[0] = 2.0;
      ROS_INFO("Range is 2.0 m");
    }

    test_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}

