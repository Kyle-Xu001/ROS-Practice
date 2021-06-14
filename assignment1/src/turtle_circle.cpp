#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>

//callback function
void chatterCallback(const turtlesim::Pose& msg){
    ROS_INFO("Turtle is at [%f, %f, %f]", (float)(msg.x), (float)(msg.y), (float)(msg.theta));
}


int main(int argc, char **argv){
    ros::init(argc, argv, "turtle_circle");

    ros::NodeHandle n;

    ros::Publisher turtle_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",1);
    ros::Subscriber turtle_sub = n.subscribe("/turtle1/pose", 1, chatterCallback);
    ros::Rate loop_rate(10);
    while(ros::ok()){
        geometry_msgs::Twist msg;
        msg.linear.x = 1;
        msg.linear.y = 0;
        msg.linear.z = 0;
        msg.angular.x = 0;
        msg.angular.y = 0;
        msg.angular.z = 1;
        turtle_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
            }
    return 0;
}