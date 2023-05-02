import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from geometry_msgs.msg import Point
from std_msgs.msg import String
from cv_bridge import CvBridge
from turtlebot4_interfaces.msg import BBCoordinates

import cv2
import numpy as np


# from rclpy.qos import qos_profile_default


class PIDController:
    def __init__(self, kp, ki, kd):
        self.Kp = kp
        self.Ki = ki
        self.Kd = kd
        self.last_error = 0.0
        self.integral = 0.0

    def update(self, error):
        derivative = error - self.last_error
        self.integral += error
        output = self.Kp * error + self.Ki * self.integral + self.Kd * derivative
        self.last_error = error
        return output


class Driver(Node):
    def __init__(self):
        super().__init__('driver')
        self.publisher_ = self.create_publisher(Twist, 'cmd_vel', 10)
        # timer_period = 0.5  # seconds
        # self.timer = self.create_timer(timer_period, self.callback)
        self.location_subscriber_ = self.create_subscription(BBCoordinates, "/humanPredicition", self.callback, 10)
        self.base_cmd = Twist()

        # ideal distance from target
        self.target_distance = 1

        # distance controller PID
        self.z_pid = PIDController(5, 1, 1)

        # image description
        self.imgW = 300
        self.imgH = 300

        self.base_cmd.linear.x = 0.0
        self.base_cmd.linear.y = 0.0
        self.base_cmd.linear.z = 0.0
        self.base_cmd.angular.x = 0.0
        self.base_cmd.angular.y = 0.0
        self.base_cmd.angular.z = 0.0

    def update(self, linear_x, angular_z):
        self.base_cmd.linear.x = linear_x
        self.base_cmd.angular.z = angular_z
        print("Linear X: ")
        print(linear_x)
        print("\n")
        print("Angular Z: ")
        print(angular_z)
        print("\n")
        self.publisher_.publish(self.base_cmd)

    def callback(self, msg):
        # Kalman filtering done here?

        x = msg.x
        y = msg.y
        w = msg.w
        h = msg.h
        z = msg.z

        x_c, y_c  = (x + self.imgW/2), (y + self.imgH/2) 
        offset_x = x_c - self.imgW / 2
        theta = offset_x / self.imgW

        z_error = self.target_distance - z

        angular = -2.5 * theta
        linear = self.z_pid.update(z_error)

        if(z <= 0.5):
            linear = 0.0
            angular = 180.0
        else:
            linear = z - self.target_distance
        
        self.update(linear, angular)


def main(args=None):
    rclpy.init(args=args)
    driver = Driver()

    rclpy.spin(driver)

    driver.destroy_node()
    rclpy.shutdown()

    # rclpy.init(args=args)
    # node = rclpy.create_node('myNode')

    # pub = node.create_publisher(Twist, 'cmd_vel',10)
    # while(1):
    #    twist = Twist()
    #    twist.linear.x = 5.0
    #    twist.linear.y = 0.0
    #    twist.linear.z = 0.0
    #    twist.angular.x = 0.0
    #    twist.angular.y = 0.0
    #    twist.angular.z = 5.0
    #    print("Hello World!")
    #    pub.publish(twist)


if __name__ == '__main__':
    main()
