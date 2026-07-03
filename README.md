# 🚗 3-Mode Arduino-ESP32 Smart Robot Car

A multifunctional smart robot car capable of operating in **three independent modes**: **Obstacle Avoidance**, **Line Following**, and **Bluetooth Manual Control**. The project integrates an **Arduino Uno** for real-time motor and sensor control with an **ESP32 DevKit** for wireless Bluetooth communication.

> Developed as part of the **Value Added Course (VAC) on Arduino MCU** project by me (Vishal) and my teammate (Nitish).

---

## 🎥 Project Demonstration

> **📹 Demo Video:** *(YouTube link will be added after upload)*

<!-- Replace the placeholder with your YouTube link later -->

[![Watch the Demo](https://img.shields.io/badge/Watch-Demo-red?style=for-the-badge&logo=youtube)](https://youtu.be/YOUR_VIDEO_LINK)

---

## 📖 Project Overview

This project demonstrates the implementation of a **multi-functional autonomous robot car** capable of switching between different operating modes using dedicated hardware switches.

The robot combines sensor-based automation and wireless manual control into a single platform.

The three operating modes are:

- 🚧 Obstacle Avoidance
- ➖ Line Following
- 📱 Bluetooth Manual Control

The Arduino Uno performs all real-time control operations, including motor driving, sensor processing, servo movement, and buzzer control, while the ESP32 acts as a Bluetooth communication bridge between a smartphone and the Arduino through UART serial communication.

---

# ✨ Features

- 🚗 Three independent operating modes
- 📡 Bluetooth-based manual control
- 🚧 Autonomous obstacle avoidance
- ➖ Automatic line following
- 🔄 Servo-based ultrasonic scanning
- 🔔 Buzzer alerts
- 🎛 Physical hardware mode selection switches
- ⚡ Battery-powered portable design
- 🤖 Modular Arduino + ESP32 architecture

---

# 🛠 Hardware Components

| Component | Quantity | Purpose |
|-----------|:--------:|---------|
| Arduino Uno (Square CH340 Chip) | 1 | Main controller |
| ESP32 DevKit | 1 | Bluetooth communication module |
| L298N Motor Driver | 1 | Controls DC motors |
| HC-SR04 Ultrasonic Sensor | 1 | Distance measurement |
| Ultrasonic Sensor Holder | 1 | Mounts the ultrasonic sensor |
| SG90 Servo Motor | 1 | Rotates ultrasonic sensor |
| IR Sensors | 3 | Line detection and obstacle assistance |
| Active Buzzer | 1 | Audible feedback |
| Robot Chassis | 1 | Robot frame |
| DC Gear Motors | 4 | Robot movement |
| Robot Wheels | 4 | Locomotion |
| 18650 Li-ion Battery (3.7V) | 2 | Power source |
| Dual 18650 Battery Holder | 1 | Provides approximately 7.4V supply |
| Breadboard | 1 | Power distribution |
| Slide Power Switch | 1 | Main power ON/OFF |
| Bluetooth Mode Switch | 1 | Enables Bluetooth mode |
| Obstacle Avoidance Switch | 1 | Enables obstacle avoidance mode |
| Line Following Switch | 1 | Enables line following mode |
| Jumper Wires | Multiple | Electrical connections |
| Hook-up Wires | As required | Component wiring |

---

# 🔋 Power Distribution

The robot is powered using **two 3.7V 18650 Li-ion batteries connected in series**, providing an operating voltage of approximately **7.4V**.

The breadboard is primarily used as a **power distribution board**, where its horizontal power rails are dedicated to supplying regulated power and ground connections to the Arduino Uno, ESP32, motor driver, sensors, and other peripheral components.

---

# 🎛 Operating Modes

The robot features dedicated hardware switches that allow the user to select one operating mode at a time.

| Switch | Function |
|---------|----------|
| Left-most Switch | Main Power ON/OFF |
| Bluetooth Switch | Enables Bluetooth Manual Control |
| Obstacle Switch | Enables Obstacle Avoidance Mode |
| Line Switch | Enables Line Following Mode |

Only **one operating mode** should be enabled during operation.

---

# 📌 Sensor Configuration

The robot utilizes multiple sensors for different operating modes.

| Sensor | Function |
|---------|----------|
| Ultrasonic Sensor | Detects obstacles and measures distance |
| Servo Motor | Rotates ultrasonic sensor for left/right scanning |
| Center IR Sensor | Assists obstacle detection during obstacle avoidance |
| Left IR Sensor | Line detection |
| Right IR Sensor | Line detection |

