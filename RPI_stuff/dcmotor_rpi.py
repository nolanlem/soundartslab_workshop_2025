#!/bin/env/python  

import time 
from adafruit_motorkit import MotorKit
from numpy import mean
from numpy import random


myMotor = MotorKit() # default address is 0x60, 90


num_iters = 10
for i in range(num_iters):
	myMotor.throttle = 1  # turn motor on, try changing throttle (between 0 and 1, and see what happens)
	time.sleep(0.5) # wait for 0.5 sec, try changing this
	myMotor.throttle = 0  # turn motor off
	time.sleep(0.5) # wait for 0.5 sec 

print('done')


