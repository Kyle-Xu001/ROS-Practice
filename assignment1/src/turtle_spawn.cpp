#include <ros/ros.h>
#include <turtlesim/Spawn.h>
#include <iostream>
#include <ctime>

int main(int argc, char **argv){
    //Set the real random seed
    srand((unsigned int)time(NULL));

    //Initiate the ROS node
    ros::init(argc, argv, "turtle_spawn");
    ros::NodeHandle n;

    //Construct the service client to call service "spawn"
    ros::service::waitForService("/spawn");
    ros::ServiceClient client = n.serviceClient<turtlesim::Spawn>("/spawn");

    //Define the request msg
    turtlesim::Spawn srv;
    srv.request.x = 0.5 + (rand()%100) / 10;
    srv.request.y = 0.5 + (rand()%100) / 10 ;
    srv.request.theta = rand()%360;

    //Input the name in command line and transfer to request
    std::string name;
    ROS_INFO("Please input the turtle name: ");
    std::getline(std::cin, name); 
    srv.request.name = name;

    if (client.call(srv)){
        ROS_INFO("Response: [%s]", srv.request.name.c_str());
    }else{
        ROS_INFO("Failed to create a turtle!");
    }

    return 0;
}