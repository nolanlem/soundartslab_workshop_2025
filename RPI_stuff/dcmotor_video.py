import time
import vlc
from adafruit_motorkit import MotorKit

# Set up motor
kit = MotorKit()
motor = kit.motor1

# Path to your video file
video_path = "/home/pi/Videos/demo_video.mp4"

# Set up VLC player
instance = vlc.Instance()
player = instance.media_player_new()
media = instance.media_new(video_path)
player.set_media(media)

# Start playback
print("Starting video and motor...")
player.play()

# Give VLC a moment to start
time.sleep(1)

# Optional: Wait until media is actually playing
while player.get_state() != vlc.State.Playing:
    time.sleep(0.1)

# Start motor
motor.throttle = 1.0

# Wait for playback to finish
while player.get_state() not in [vlc.State.Ended, vlc.State.Error]:
    # Optional: add motion choreography here
    time.sleep(0.1)

# Stop motor
motor.throttle = 0
print("Playback complete. Motor stopped.")