import time
from adafruit_motorkit import MotorKit

kit = MotorKit()
motor = kit.motor1

print("Press Enter to spin the motor or type 'q' to quit.")
try:
    while True:
        cmd = input(">> ")
        if cmd.lower() == 'q':
            break
        print("Spinning motor for 1 second...")
        motor.throttle = 1.0
        time.sleep(1)
        motor.throttle = 0
finally:
    motor.throttle = 0
    print("Exiting...")