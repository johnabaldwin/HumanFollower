#ROS2 Imports
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Float32MultiArray
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
        self.oak_camera_.poll()
        inDet = self.q.get()
        inRect = self.rectout.get()

        rectifiedRight = inRect.getCvFrame()
        height = rectifiedRight.shape[0]
        width = rectifiedRight.shape[1]
        print(height)
        print(width)

        detections = inDet.detections
        for detection in detections:
            roiData = detection.boundingBoxMapping
            roi = roiData.roi
            # These values are in mm
            # ALL VALUES WE NEED ARE BELOW
            z = detection.spatialCoordinates.z / 1000
            label = detection.label
            x1 = int(detection.xmin * width)
            print(x1)
            x2 = int(detection.xmax * width)
            print(x2)
            y1 = int(detection.ymin * height)
            print(y1)
            y2 = int(detection.ymax * height)
            print(y2)
            # print(int(detection.spatialCoordinates.z) / 1000)
            print("m")
            # print(roi.topLeft().x)
            # print(roi.topLeft().y)
            # print()
            # print(detection.label)
            print("\n")
            cv2.rectangle(rectifiedRight, (x1, y1), (x2, y2), (255,0,0), cv2.FONT_HERSHEY_SIMPLEX)

        cv2.imshow("rectified right", rectifiedRight)


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


