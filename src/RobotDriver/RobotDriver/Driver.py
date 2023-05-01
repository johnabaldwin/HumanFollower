import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
#from rclpy.qos import qos_profile_default
from std_msgs.msg import String

class Driver(Node):
    def __init__(self):
        super().__init__('driver')
        self.publisher = self.create_publisher(Twist,'cmd_vel',10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.callback)
        self.base_cmd = Twist()

        self.base_cmd.linear.x = 0.0
        self.base_cmd.linear.y = 0.0
        self.base_cmd.linear.z = 0.0
        self.base_cmd.angular.x = 0.0
        self.base_cmd.angular.y = 0.0
        self.base_cmd.angular.z = 0.0
    
    def update(self, linear_x , angular_z):
        self.base_cmd.linear.x = linear_x
        self.base_cmd.angular.z = angular_z
        self.publisher.publish(self.base_cmd)
    
    def callback(self):
        self.update(5.0,5.0)





def main(args=None):
    rclpy.init(args=args)
    driver = Driver()
    
    rclpy.spin(driver)

    driver.destroy_node()
    rclpy.shutdown()
    
    #rclpy.init(args=args)
    #node = rclpy.create_node('myNode')
    
    #pub = node.create_publisher(Twist, 'cmd_vel',10)
    #while(1):
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
