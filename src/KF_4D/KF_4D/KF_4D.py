import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from geometry_msgs.msg import Point
from std_msgs.msg import String
from cv_bridge import CvBridge
from Kalman import KF_4D
from turtlebot4_interfaces.msg import BBCoordinates
import cv2
import numpy as np

#import from KF_4D import 
# from rclpy.qos import qos_profile_default





class Kalman(Node):
    def __init__(self):
        super().__init__('Kalman')
        self.subscription = self.create_subscription(BBCoordinates, "/BBCoordinates", self.callback, 10)
        

    def callback(self, msg):
        # Kalman filtering done here?


        x_c = msg.x
        y_c = msg.y
        z = msg.z

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


if __name__ == '__main__':
    main()
