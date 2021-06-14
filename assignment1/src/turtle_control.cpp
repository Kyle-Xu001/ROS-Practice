#include <ros/ros.h>
#include <geometry_msgs/Twist.h> 
#include <iostream>

int main(int argc, char **argv){
    ros::init(argc, argv, "turtle_control");
    ros::NodeHandle n;


    ROS_INFO("Please input the target turtle:");
    std::string name;
    std::getline(std::cin, name);
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/"+name+"/cmd_vel",1);
    ros::Rate loop_rate(10);

    ROS_INFO("Please input the angular velocity of turtle:");
    double w;
    std::cin>>w;

    ROS_INFO("Please input the linear velocity of turtle:");
    double x;
    std::cin>>x;

    geometry_msgs::Twist msg;
    msg.linear.x = (double)x;
    msg.linear.y = 0;
    msg.linear.z = 0;
    msg.angular.x = 0;
    msg.angular.y = 0;
    msg.angular.z = (double)w;
    
    while (ros::ok()){
        pub.publish(msg);
        loop_rate.sleep();
    }

    return 0;
}