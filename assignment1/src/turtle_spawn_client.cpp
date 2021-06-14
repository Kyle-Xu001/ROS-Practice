#include <ros/ros.h>
#include <turtlesim/Spawn.h>
#include <assignment1/turtlecall.h>
#include<iostream>

int main(int argc, char **argv){
    ros::init(argc, argv, "turtlecall_client");
    ros::NodeHandle n;

    ros::service::waitForService("/turtlecall");
    ros::ServiceClient client = n.serviceClient<assignment1::turtlecall>("/turtlecall");

    assignment1::turtlecall srv;

    std::string name;
    ROS_INFO("Please input the turtle name:");
    std::getline(std::cin,name);
    srv.request.name = name;

    ROS_INFO("Call service to add a turtle [%s]",srv.request.name.c_str());
    client.call(srv);

    ROS_INFO("Show response: [%s]",srv.response.result.c_str());



    return 0;
}