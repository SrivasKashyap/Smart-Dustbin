# Smart Dustbin

An automated, touch-free dustbin using Arduino Uno, servo, and ultrasonic sensor. The lid opens automatically when it detects objects nearby.

## Components
- Arduino Uno
- Servo Motor
- Ultrasonic Sensor (HC-SR04)
- Wires & Power Source

## How to Run
1. Connect components as per schematic.
2. Open SmartDustbin.ino in Arduino IDE.
3. Upload to Arduino Uno.

## Version 2 Improvements
- Averaged multiple ultrasonic sensor readings for more stable distance detection.
- Added LED indicator to show when the lid is triggered.
- Cleaned up code: fixed variable inconsistencies, added comments, and optimized servo control.
- Improved readability and monitoring via Serial output.
