#ROS2 Imports
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Float32MultiArray
from geometry_msgs.msg import Point
from turtlebot4_interfaces.msg import BBCoordinates
from depthai import NNData
import depthai as dai

#Oak-D Imports
from depthai_sdk import OakCamera
from depthai_sdk.visualize.configs import BboxStyle, TextPosition
from depthai_sdk.classes import Detections, SpatialBbMappingPacket
#OpenCV Imports
import cv2
from cv_bridge import CvBridge

import numpy as np

class HumanLocator(Node):

    def __init__(self):
        super().__init__('HumanLocator')

        self.timer_period = 1/12  # frequency to call timer_callback
        self.camera_fps = self.timer_period**(-1) # set camera fps to the number of callbacks per second


        self.LocationPublisher_ = self.create_publisher(Point, "/humanLocation", 10)
        self.BBPublisher_ = self.create_publisher(BBCoordinates, "/BBCoordinates", 10)
        self.DepthImagePublisher_ = self.create_publisher(Image, "/DepthImage", 10)
        self.timer = self.create_timer(self.timer_period, self.timer_callback)
        #initialize Oak Camera, cannot use stereo mode with neural network blob detector
        self.oak_camera_ = OakCamera()
        self.color_camera_ = self.oak_camera_.create_camera('color', fps = self.camera_fps)
        self.stereo_camera_ = self.oak_camera_.create_stereo('480p', fps=60)
        # mobilenet-ssd is a depthai included neural net trained to recognize a number of blobs
        # for this project it is useful as it is trained for human recognition 
        self.nn_ = self.oak_camera_.create_nn('mobilenet-ssd', self.color_camera_, None, None, self.stereo_camera_, None, None)
        # visualizer = self.oak_camera_.visualize([self.nn_.out.spatials, self.nn_], fps=True)
        # visualizer = self.oak_camera_.visualize(self.stereo_camera_.out.depth, fps=True)
        # self.oak_camera_.start(blocking=True)

        pipeline = self.oak_camera_.build()

        # self.nn_.node.setNumInferenceThreads(2)

        out = pipeline.create(dai.node.XLinkOut)
        depthout = pipeline.create(dai.node.XLinkOut)
        rect = pipeline.create(dai.node.XLinkOut)

        out.setStreamName("detections")
        depthout.setStreamName("depth")
        rect.setStreamName("rect")

        self.nn_.node.out.link(out.input)
        self.nn_.node.passthroughDepth.link(depthout.input)
        self.nn_.node.passthrough.link(rect.input)

        # visualizer.detections(
        #     color=(0, 255, 0),
        #     thickness=2,
        #     bbox_style=BboxStyle.RECTANGLE,
        #     label_position=TextPosition.MID,

        # ).text(
        #     font_color=(255, 255, 0),
        #     auto_scale=True
        # ).tracking(
        #     line_thickness=5
        # )

        # start with blocking=false to allow camera to run in background
        self.oak_camera_.start(blocking=False)

        self.q = self.oak_camera_.device.getOutputQueue(name="detections", maxSize=4, blocking=False)
        self.depthout_ = self.oak_camera_.device.getOutputQueue(name="depth", maxSize=4, blocking=False)
        self.rectout = self.oak_camera_.device.getOutputQueue(name="rect", maxSize=4, blocking=False)

    def timer_callback(self):
        # get all detected blobs
        inDet = self.q.get()
        inRect = self.rectout.get()
        rectifiedRight = inRect.getCvFrame()
        height = rectifiedRight.shape[0]
        width = rectifiedRight.shape[1]
        detections = inDet.detections

        minDist = 1000
        pointMsg = Point()
        bbMsg = BBCoordinates()

        pointMsg.x = 0.0
        pointMsg.y = 0.0
        pointMsg.z = 0.0
        bbMsg.x = 0
        bbMsg.y = 0
        bbMsg.w = 0
        bbMsg.h = 0

        for detection in detections:
            roiData = detection.boundingBoxMapping
            roi = roiData.roi
            # These values are in mm
            # ALL VALUES WE NEED ARE BELOW
            z = detection.spatialCoordinates.z / 1000
            label = detection.label
            #print(label)
            x1 = int(detection.xmin * width)
            #print(x1)
            x2 = int(detection.xmax * width)
            #print(x2)
            y1 = int(detection.ymin * height)
            #print(y1)
            y2 = int(detection.ymax * height)
            #print(y2)
            # print(int(detection.spatialCoordinates.z) / 1000)
            #print("m")
            # print(roi.topLeft().x)
            # print(roi.topLeft().y)
            # print()
            # print(detection.label)
            print("\n")
            
            if(label == 15 and z < minDist): #Human
                x_c =  x1 + (x2 - x1)/2
                y_c = y1 + (y2 - y1)/2
                z = z
                pointMsg.x = x_c
                pointMsg.y = y_c
                pointMsg.z = z

                bbMsg.x = x1
                bbMsg.y = y1
                bbMsg.w = x2 - x1
                bbMsg.h = y2 - y1
                bbMsg.z = z
                print(pointMsg.x)
                print(bbMsg.x)
        if (not pointMsg.x == 0.0):
            self.LocationPublisher_.publish(pointMsg)
            self.BBPublisher_.publish(bbMsg)
        #cv2.rectangle(rectifiedRight, (x1, y1), (x2, y2), (255,0,0), cv2.FONT_HERSHEY_SIMPLEX)
        #cv2.imshow("rectified right", rectifiedRight)



    


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


