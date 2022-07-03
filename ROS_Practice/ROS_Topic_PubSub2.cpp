#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Empty.h"
#include <iostream>
#include <sstream>

class SubscribeAndPublish2
{
public:
	SubscribeAndPublish2()
	{
		pub_2 = n_2.advertise<std_msgs::String>("/user_to", 100);	
		sub_2 = n_2.subscribe("/node_from", 100, &SubscribeAndPublish2::callback2, this);
	}
	void callback2(const std_msgs::String& input)
	{		
		pub_2.publish(input);
	}

private:
	ros::NodeHandle n_2; 
	ros::Publisher pub_2;
	ros::Subscriber sub_2;
};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "topic2");
	SubscribeAndPublish2 SAPObject2; 
	ros::spin();
	return 0;
}