#include <ros/ros.h>
#include <assignment1/turtlecall.h>
#include <turtlesim/Spawn.h>
#include <ctime>

class turtlecall{
public:
    turtlecall(){
        client = n.serviceClient<turtlesim::Spawn>("/spawn");
        service= n.advertiseService("/turtlecall", &turtlecall::Callback,this);


    }
    bool Callback(assignment1::turtlecall::Request &req, assignment1::turtlecall::Response &res){
    srand((unsigned int)time(NULL));
    turtlesim::Spawn srv;
    srv.request.x = 0.5 + (rand()%100)/10;
    srv.request.y = 0.5 + (rand()%100)/10;
    srv.request.theta = rand()%360;
    srv.request.name = req.name;

    if (client.call(srv)){
        ROS_INFO("Successfully call a turtle!");
        res.result = "Success!";
    }else{
        res.result = "Wrong!";
    }
    return true;
}
private:
    ros::NodeHandle n;
    ros::ServiceClient client;
    ros::ServiceServer service;
};

int main(int argc, char **argv){

    ros::init(argc, argv, "turtlecall_service");

    ros::service::waitForService("/spawn");
    ROS_INFO("Ready to call the turtle");
    turtlecall A;
    ros::spin();


    return 0;
}