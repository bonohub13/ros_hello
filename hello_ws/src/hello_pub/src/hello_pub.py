#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import rospy
from std_msgs.msg import String

class Hello_Pub:
    def __init__(self, publisher=None):
        self.pub = publisher
        self.pub_msg = 'Hello World!'

    def publish_msg(self):
        rate_n = 2
        rate = rospy.Rate(rate_n)
        while not rospy.is_shutdown():
            self.pub.publish(self.pub_msg)
            rate.sleep()

if __name__ == "__main__":
    rospy.init_node('hello_pub')
    pub = rospy.Publisher('/hello', String, queue_size=10)
    sub = Hello_Pub(publisher=pub)
    sub.publish_msg()