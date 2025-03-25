import time
from adafruit_motorkit import MotorKit

kit = MotorKit()

# This assumes you're using M1 + M2 for stepper connection
stepper = kit.stepper1

# SINGLE, DOUBLE, INTERLEAVE, MICROSTEP
for i in range(100):
    stepper.onestep(direction=1, style=stepper.SINGLE)
    time.sleep(0.01)