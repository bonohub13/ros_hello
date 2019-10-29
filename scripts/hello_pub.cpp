/* ファイル名はhello_sub.cppです */

#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"

class HelloPub
{
public:
	HelloPub();
	~HelloPub(){};
	void run();
private:
	ros::NodeHandle nh;
	ros::Publisher helloPub;
	std_msgs::String hello;
	std::string topicName;
};
HelloPub::HelloPub() : nh("~")
{
	topicName = "/hello";
	helloPub = nh.advertise<std_msgs::String>(topicName, 10);
	hello.data = "Hello World!";
}
void HelloPub::run()
{
	ros::AsyncSpinner spinner(0);
	ros::Rate rate(10);
	spinner.start();
	while (ros::ok())
	{
		helloPub.publish(hello);
		rate.sleep();
	}
	spinner.stop();
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "hello_pub");
	HelloPub hello_pub;
	hello_pub.run();

	return 0;
}
