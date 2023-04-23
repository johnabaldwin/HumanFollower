import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
#from rclpy.qos import qos_profile_default
from std_msgs.msg import String

class Driver(Node):
    def __init__(self):
        super().__init__('driver')
        self.publisher = self.create_publisher(Twist,'cmd_vel',0)
        base_cmd = Twist()

        base_cmd.linear.x = 100.0;
        base_cmd.linear.y = 0.0;
        base_cmd.linear.z = 0.0
        base_cmd.angular.x = 100.0;
        base_cmd.angular.y = 0.0;
        base_cmd.angular.z = 0.0
        print("Hello World")
        self.publisher.publish(base_cmd)




def main(args=None):
    #rclpy.init(args=args)
    #driver = Driver()
    #rclpy.spin(driver)

    #driver.destroy_node()
    #rclpy.shutdown()
    
    rclpy.init(args=args)
    node = rclpy.create_node('myNode')
    
    pub = node.create_publisher(Twist, 'cmd_vel',0)
    twist = Twist()
    twist.linear.x = 100.0
    twist.linear.y = 0.0
    twist.linear.z = 0.0
    twist.angular.x = 0.0
    twist.angular.y = 0.0
    twist.angular.z = 0.0
    print("Hello World!")
    pub.publish(twist)

if __name__ == '__main__':
    main()
