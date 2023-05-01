import rclpy
from rclpy.node import Node
import cv2
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from depthai_ros_msgs.msg import SpatialDetectionArray


class ImageSubber(Node):

    def __init__(self):
        super().__init__('imagesubber')
        self.subscription = self.create_subscription(
            Image,
            '/color/preview/image',
            self.listener_callback,
            10)
        self.bridge = CvBridge()

    def listener_callback(self, msg):
        imCV = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        print("I AM HERE")
        cv2.imshow("DISPLAY", imCV)
        


def main(args=None):
    print("I AM HERE 1")
    rclpy.init(args=args)
    print("I AM HERE 2")

    imagesubber = ImageSubber()
    print("I AM HERE 3")

    rclpy.spin(imagesubber)
    print("I AM HERE 4")

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    imagesubber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()