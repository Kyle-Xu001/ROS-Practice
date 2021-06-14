# ROS-Practice
This repository is created for programming assignments in ***ROS Theory and Practice***, which includes functional nodes and extended functions.  

## Assignment1
This part is about communication programming, which includes applications on publisher, subscriber, server and client.  
The function of each node is defined as follows:  
**turtle_call**:  Create a new turtle at specific location predefined in the code.   
**turtle_circle**: Control the existed turtle in circular motion, and subscribe the pose of turtle in real time.  
**turtle_control**: Control the real-time motion of existed turtle by inputting turtle name and velocity parameters in command line. (*Achieved by **Publisher** function*)  
**turtle_spawn**: Create a new turtle at a random location with the name defined in command line. (*Achieved by single **Client** function*)  
**turtle_spawn_client / turtle_spawn_server**： Create a new turtle at a random location with the name defined in command line. (*Achieved by combination of **Server** and **Client***)    
