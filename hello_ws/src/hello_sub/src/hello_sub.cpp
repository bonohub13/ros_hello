#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"

class HelloSub
{
public:
	HelloSub();
	~HelloSub(){};
	void run();
private:
	ros::NodeHandle nh;
	ros::Subscriber helloSub;
	std_msgs::String hello;
	std::string topicname;
private:
	void helloCallback(const std_msgs::String data::ConstPtr& data);
};
HelloSub::HelloSub() : nh("~")
{
	topicname = "/hello";
	helloSub = nh.subscribe(topicname, 10, &HelloSub::helloCallback, this);
}
void HelloSub::helloCallback(const std_msgs::String::ConstPtr& data)
{
	hello.data -> data.data;
}
void HelloSub::run()
{
	ros::AsyncSpinner spinner(0);
	ros::Rate rate(10);
	spinner.start();
	while (ros::ok())
	{
		std::cout << "recieved data: " << hello.data << std::endl;
		rate.sleep();
	}
	spinner.stop();
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "hello_sub");
	HelloSub hello_sub;
	hello_sub.run();

	return 0;
}
