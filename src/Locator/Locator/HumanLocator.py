#ROS2 Imports
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Float32MultiArray

#Oak-D Lite SDK Imports
from depthai_sdk import OakCamera

#OpenCV Imports
import cv2
from cv_bridge import CvBridge



#Publisher class for 3 tuple of blob X Y Z coordinates
class LocationMsg(Float32MultiArray):
    def __init__(self, x, y, z):
        super().__init__()
        self.data = [x, y, z]



class HumanLocator(Node):

    def __init__(self):
        super().__init__('HumanLocator')

        self.timer_period = 1/20  # frequency to call timer_callback
        self.camera_fps = self.timer_period**(-1) # set camera fps to the number of callbacks per second


        self.LocationPublisher_ = self.create_publisher(LocationMsg, "/humanLocation", 10)
        self.DepthImagePublisher_ = self.create_publisher(Image, "/DepthImage", )
        self.timer = self.create_timer(timer_period, self.timer_callback)


        #initialize Oak Camera, cannot use stereo mode with neural network blob detector
        self.oak_camera_ = OakCamera()
        self.color_camera_ = self.oak_camera_.create_camera('color', fps = self.camera_fps)

        # mobilenet-ssd is a depthai included neural net trained to recognize a number of blobs
        # for this project it is useful as it is trained for human recognition 
        self.nn_ = self.oak_camera_.create_nn('mobilenet-ssd', self.color_camera_, spatial=True)
        
        # start with blocking=false to allow camera to run in background
        self.oak_camera_.start(blocking=False)

    def timer_callback(self):
        #get all detected blobs
        objects = self.nn_.get_objects()

        # filter non-human blobs
        blobs = [obj for obj in objects if obj.label == 'person']

        if len(blobs) > 0:

            # determine closest blob
            blob = blobs[0]
            distance = 100
            for i in len(blobs):
                if blobs[i].spatialCoordinates.z < distance:
                    blob = blobs[i]
            location_msg = LocationMsg(blob.spatialCoordinates.x, blob.spatialCoordinates.y, blob.spatialCoordinates.z)
            

            # draw bounding box around selected blob
            color_frame = self.color_camera_.get_latest_frame()
            bb = blob.boundingBox
            cv2.rectangle(color_frame,  (int(bb.xmin), int(bb.ymin)), (int(bb.xmax), int(bb.ymax)), (0, 255, 0), 2)
            image_msg = self.bridge_.cv2_to_imgmsg(color_frame, encoding='bgr8')
            
            # publish location and visualization
            print("XYZ = " + str(blob.spatialCoordinates.x) + " " + str(blob.spatialCoordinates.y) + " " + str(blob.spatialCoordinates.z))
            self.LocationPublisher_.publish(location_msg)
            self.DepthImagePublisher_.pubish(image_msg)
            
            

def main(args=None):
    rclpy.init(args=args)

    publisher = HumanLocator()

    rclpy.spin(publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()


