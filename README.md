# 🌱 Grass Cutting Robot using Arduino UNO

## Overview

This project is an autonomous grass cutting robot designed to reduce manual effort in maintaining lawns, gardens, and small agricultural fields.

The robot uses an Arduino UNO to control four DC motors and an ultrasonic sensor for obstacle detection. When an obstacle is detected, the robot changes its direction automatically and continues cutting grass.

---

## Features

- Autonomous Navigation
- Obstacle Detection
- Obstacle Avoidance
- Servo-based Ultrasonic Scanning
- Low-cost Design
- Rechargeable Battery Powered

---

## Components Used

- Arduino UNO
- L293D Motor Driver Shield
- HC-SR04 Ultrasonic Sensor
- Servo Motor
- DC Motors
- Grass Cutting Blade
- LiPo Battery

---

## Working

1. Robot moves forward.
2. Ultrasonic sensor continuously measures distance.
3. If an obstacle is detected within 20 cm:
   - Stop
   - Move backward
   - Scan left and right
   - Turn towards the free path
4. Continue cutting grass automatically.

---

## Future Improvements

- Solar Charging
- GPS Navigation
- Mobile App Control
- Image Processing
- Automatic Charging Station

---

## Technologies

- Arduino IDE
- Embedded C
- Arduino UNO
- HC-SR04
- Servo Motor
- L293D Motor Driver

---

## Author

**Sai Kiran**
ECE Student
