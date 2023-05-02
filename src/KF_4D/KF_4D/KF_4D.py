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
from geometry_msgs.msg import Point

#import from KF_4D import 
# from rclpy.qos import qos_profile_default





class Kalman(Node):
    def __init__(self):
        super().__init__('Kalman')
        self.subscription = self.create_subscription(BBCoordinates, "/BBCoordinates", self.callback, 10)

        self.LocationPublisher_ = self.create_publisher(BBCoordinates, "/humanPredicition", 10)        

        self.filter = KF_4D(dt=0.15, u_x=1, u_y=1, u_w=1, u_h=1, std_acc=1, x_std_meas=0.1, y_std_meas=0.1, w_std_meas=0.1, h_std_meas=0.1)

    def callback(self, msg):
        # Kalman filtering done here?
        
        (x,y,w,h) = self.filter.predict()
        coord = BBCoordinates() 
                
        updCoord = np.matrix([[msg.x],[msg.y],[msg.w],[msg.h]])
        (x1,y1,w1,h1) = self.filter.update(updCoord)     
        coord.x = int(x1)
        coord.y = int(y1)
        coord.w = int(w1)
        coord.h= int(h1)
        coord.z = msg.z  
        self.LocationPublisher_.publish(coord)

def main(args=None):
    rclpy.init(args=args)
    driver = Kalman()

    rclpy.spin(driver)

    driver.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
