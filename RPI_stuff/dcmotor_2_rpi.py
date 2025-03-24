#!/bin/env/python  

import time 
from adafruit_motorkit import MotorKit
from numpy import random


kit = MotorKit() # default address is 0x60, 90
myMotor = kit.motor1

num_iters = 10
print('starting loop')
for i in range(num_iters):
	print(f'iteration {i}')
	print('turning motor on')
	myMotor.throttle = 1  # turn motor on, try changing throttle (between 0 and 1, and see what happens)	
	print('waiting')
	wait_time = random.uniform(0.1, 1)
	time.sleep(wait_time) # wait for N sec, try changing this
	print('turning motor off')
	myMotor.throttle = 0  # turn motor off
	print('waiting')
	wait_time = random.uniform(0.1, 2)
	time.sleep(wait_time) # wait for 0.5 sec 

print('done')


