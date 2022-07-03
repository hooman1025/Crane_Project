#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Empty.h"
#include <iostream>
#include <sstream>

class SubscribeAndPublish
{
public:
	SubscribeAndPublish()
	{
		pub_ = n_.advertise<std_msgs::String>("/node_from", 100);	
		sub_ = n_.subscribe("/user_from", 100, &SubscribeAndPublish::callback, this);
	}
	void callback(const std_msgs::String& input)
	{		
		pub_.publish(input);
	}

private:
	ros::NodeHandle n_; 
	ros::Publisher pub_;
	ros::Subscriber sub_;
};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "topic");
	SubscribeAndPublish SAPObject; 
	ros::spin();
	return 0;
}