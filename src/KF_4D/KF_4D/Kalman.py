"""
Kalman 4D filter : Stevan Djuraskovic
"""

import numpy as np

class KF_4D(object):
    def __init__(self, dt, u_x, u_y, u_w, u_h, std_acc, x_std_meas, y_std_meas, w_std_meas, h_std_meas):

        self.dt = dt
        self.u = np.matrix([[u_x],[u_y],[u_w],[u_h]])
        self.x = np.matrix([[0],[0],[0],[0],[0],[0],[0],[0]]) 

        self.A = np.matrix([[1,0,0,0,self.dt,0,0,0],[0,1,0,0,0,self.dt,0,0],
                            [0,0,1,0,0,0,self.dt,0],[0,0,0,1,0,0,0,self.dt],
                            [0,0,0,0,1,0,0,0],[0,0,0,0,0,1,0,0],
                            [0,0,0,0,0,0,1,0],[0,0,0,0,0,0,0,1]])
        self.B = np.matrix([[(self.dt**2)/2,0,0,0],[0,(self.dt**2)/2,0,0],
                            [0,0,(self.dt**2)/2,0],[0,0,0,(self.dt**2)/2],
                            [self.dt,0,0,0],[0,self.dt,0,0],
                            [0,0,self.dt,0],[0,0,0,self.dt]])
        self.H = np.matrix([[1,0,0,0,0,0,0,0],[0,1,0,0,0,0,0,0],
                            [0,0,1,0,0,0,0,0],[0,0,0,1,0,0,0,0]])
        self.Q = np.matrix([[(self.dt**4)/4,0,0,0,(self.dt**3)/2,0,0,0],
                            [0,(self.dt**4)/4,0,0,0,(self.dt**3)/2,0,0],
                            [0,0,(self.dt**4)/4,0,0,0,(self.dt**3)/2,0],
                            [0,0,0,(self.dt**4)/4,0,0,0,(self.dt**3)/2],
                            [(self.dt**3)/2,0,0,0,self.dt**2,0,0,0],
                            [0,(self.dt**3)/2,0,0,0,self.dt**2,0,0],
                            [0,0,(self.dt**3)/2,0,0,0,self.dt**2,0],
                            [0,0,0,(self.dt**3)/2,0,0,0,self.dt**2]])

        self.R = np.matrix([[x_std_meas**2,0,0,0],[0,y_std_meas**2,0,0],
                            [0,0,w_std_meas**2,0],[0,0,0,h_std_meas]])

        self.P = np.eye(self.A.shape[1])


    def predict(self):
        ## complete this function
        # Update time state (self.x): x_k =Ax_(k-1) + Bu_(k-1)
        self.x = np.dot(self.A, self.x) + np.dot(self.B, self.u)
        # Calculate error covariance (self.P): P= A*P*A' + Q
        self.P = np.dot(np.dot(self.A, self.P), self.A.T) + self.Q
        return self.x[0:4]

    def update(self, z):
        ## complete this function
        self.y = z - np.dot(self.H, self.x)
        # Calculate S = H*P*H'+R
        self.S = np.dot(self.H, np.dot(self.P, self.H.T)) + self.R
        # Calculate the Kalman Gain K = P * H'* inv(H*P*H'+R)
        self.K = np.dot(np.dot(self.P,self.H.T), np.linalg.inv(self.S))
        # Update self.x
        self.x = self.x + np.dot(self.K, self.y)
        # Update error covariance matrix self.P
        self.P = self.P - np.dot(np.dot(self.K, self.H), self.P)
        return self.x[0:4]

    
