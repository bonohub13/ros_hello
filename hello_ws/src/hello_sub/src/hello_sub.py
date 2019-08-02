#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import rospy
from std_msgs.msg import String

class Hello_Sub:
    def __init__(self):
        rospy.Subscriber('/hello', String, self.msg_callback)
        self.str_msg = String()

    def msg_callback(self, msg_data):
        self.str_msg = msg_data
    
    def main(self):
        rate_n = 2
        rate = rospy.Rate(rate_n)
        while not rospy.is_shutdown():
            print(self.str_msg.data)
            rate.sleep()

if __name__ == "__main__":
    rospy.init_node('hello_sub')
    sub = Hello_Sub()
    sub.main()