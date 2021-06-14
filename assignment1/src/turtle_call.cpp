#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char **argv){

    ros::init(argc, argv, "turtle_call");
    ros:: NodeHandle n;

    ros::service::waitForService("/spawn");
    ros::ServiceClient client = n.serviceClient<turtlesim::Spawn>("/spawn");

    turtlesim::Spawn srv;
    srv.request.x = 5.0;
    srv.request.y = 5.0;
    srv.request.theta = 0;
    srv.request.name = "Bob";
    
    ROS_INFO("Call service to spawn a turtle at [%f, %f], name %s", (float)(srv.request.x), (float)(srv.request.y), srv.request.name.c_str());
    client.call(srv);
    ROS_INFO("Turtle Spawn: OK!");


    return 0;
}