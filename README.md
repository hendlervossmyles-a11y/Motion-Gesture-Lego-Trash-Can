# Motion-Gesture Lego Trash Can

An Arduino-based automation project that utilizes an ultrasonic distance sensor to detect incoming objects and smoothly operate a lid or door using a servo motor. The system uses an optimized software state machine to ensure reactive, single-cycle movements without infinite looping or jitter.

## Features
* **Smart State Machine:** Tracks the physical state of the door (`isOpen`) so the motor only triggers once when an object approaches and stays open until they leave.
* **Dynamic Calibration:** Measures the room's baseline environment on startup to automatically calculate detection thresholds.
* **Smooth Servo Sweeps:** Uses timed loop intervals to open and close the mechanism gracefully, protecting the physical gears and hinges from sudden alignment snaps.
* **Echo Cross-Talk Protection:** Implements localized sensor delays to clear acoustic reflections, ensuring stable distance tracking.

## Hardware Components
* **Microcontroller:** Arduino Uno / Nano / compatible board
* **Sensor:** HC-SR04 Ultrasonic Distance Sensor
* **Actuator:** Standard RC Servo Motor SG90 

### Pin Configuration
* Servo Signal -> **Digital Pin 2**
* Ultrasonic Trigger -> **Digital Pin 12**
* Ultrasonic Echo -> **Digital Pin 13**
