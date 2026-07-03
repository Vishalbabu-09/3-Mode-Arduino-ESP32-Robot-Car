# 🚗 3-Mode Smart Robot Car using Arduino Uno & ESP32

<p align="center">
  <img src="images/robot.jpg" width="700">
</p>

A multifunctional smart robot car capable of operating in **three independent modes**: **Obstacle Avoidance**, **Line Following**, and **Bluetooth Manual Control**.

The project combines an **Arduino Uno** for real-time motor and sensor control with an **ESP32 DevKit** for Bluetooth communication, creating a modular embedded system capable of both autonomous and manual operation.

> Developed by **Vishal** and **Nitish** as part of the **Value Added Course (VAC) – Arduino Microcontroller**.

---

# 🎥 Project Demonstration

> 📹 Demo video will be added after uploading to YouTube.

[![Watch Demo](https://img.shields.io/badge/Watch-Demo-red?style=for-the-badge&logo=youtube)](https://youtu.be/YOUR_VIDEO_LINK)

---

# 📖 Project Overview

This project demonstrates the implementation of a **multi-functional smart robot car** capable of switching between three operating modes using dedicated rocker switches.

The robot combines autonomous navigation and wireless manual control into a single platform.

### Operating Modes

- 🚧 Obstacle Avoidance
- ➖ Line Following
- 📱 Bluetooth Manual Control

The **Arduino Uno** performs all real-time control operations including:

- Motor control
- Servo control
- Ultrasonic sensing
- IR sensor processing
- Buzzer control
- Mode selection

The **ESP32 DevKit** functions as a Bluetooth communication bridge by receiving commands from a smartphone and forwarding them to the Arduino Uno through UART serial communication.

---

# ✨ Features

- 🚗 Three independent operating modes
- 📡 Bluetooth-based manual control
- 🚧 Autonomous obstacle avoidance
- ➖ Automatic line following
- 🔄 Servo-based ultrasonic scanning
- 🔔 Buzzer alerts
- 🎛 Physical rocker-switch mode selection
- ⚡ Battery-powered portable design
- 🤖 Modular Arduino + ESP32 architecture

---

# 📋 Project Specifications

| Specification | Details |
|--------------|---------|
| Main Controller | Arduino Uno |
| Bluetooth Controller | ESP32 DevKit |
| Programming Language | C++ |
| Framework | Arduino |
| Motor Driver | L298N |
| Power Supply | 7.4V (2×18650 Li-ion Batteries) |
| Communication | Bluetooth UART |
| Drive System | 4WD DC Gear Motors |
| Sensors | HC-SR04 + 3 IR Sensors |
| Operating Modes | 3 |

---

# 🛠 Hardware Components

| Component | Quantity | Purpose |
|-----------|:--------:|---------|
| Arduino Uno (CH340 Square Chip Version) | 1 | Main controller |
| ESP32 DevKit | 1 | Bluetooth communication bridge |
| L298N Motor Driver | 1 | Controls four DC motors |
| HC-SR04 Ultrasonic Sensor | 1 | Obstacle distance measurement |
| Ultrasonic Sensor Mount | 1 | Holds ultrasonic sensor |
| SG90 Servo Motor | 1 | Rotates ultrasonic sensor |
| IR Sensors | 3 | One center IR for obstacle assistance, two side IR sensors for line following |
| Active Buzzer | 1 | Audible feedback |
| Robot Chassis | 1 | Mechanical frame |
| DC Gear Motors | 4 | Robot locomotion |
| Robot Wheels | 4 | Robot movement |
| 18650 Li-ion Battery (3.7V) | 2 | Power source |
| Dual 18650 Battery Holder | 1 | Provides approximately 7.4V |
| Rocker Switches | 4 | Power and mode selection |
| Breadboard | 1 | Power distribution |
| Jumper Wires | Multiple | Electrical connections |
| Hook-up Wires | As required | Permanent wiring |

---

# 🔋 Power Supply

The robot is powered using **two 3.7V 18650 Li-ion batteries connected in series**, providing an operating voltage of approximately **7.4V**.

The battery output is distributed through the breadboard power rails and supplied directly to the **VIN pin of the Arduino Uno** and the **VIN pin of the ESP32 DevKit**.

The breadboard serves as a centralized power distribution board, providing common power and ground connections to the motor driver, sensors, servo motor, buzzer, and other peripheral components.

---

# 🎛 Operating Modes

The robot features four rocker switches mounted on the chassis.

| Switch Position | Function |
|-----------------|----------|
| Left-most | Main Power ON/OFF |
| Second from Left | Bluetooth Manual Control |
| Middle | Obstacle Avoidance |
| Right-most | Line Following |

> **Important:** Only **one operating mode** should be enabled at any given time. If two or more mode switches are activated simultaneously, the Arduino intentionally places the robot in a **STOP** state to prevent conflicting control logic and ensure safe operation.

---

# ⚙ Working Principle

The robot supports **three independent operating modes**, each selected using dedicated rocker switches.

## 🚧 Obstacle Avoidance Mode

When the obstacle avoidance mode is enabled, the Arduino continuously monitors both the **HC-SR04 ultrasonic sensor** and the **center IR sensor**.

Upon detecting an obstacle, the robot:

1. Stops and activates the buzzer.
2. Moves backward briefly.
3. Rotates the ultrasonic sensor using the SG90 servo.
4. Measures the available distance on both the left and right sides.
5. Compares both distances.
6. Turns toward the direction with greater clearance.
7. Continues moving forward.

---

## ➖ Line Following Mode

The left and right IR sensors detect the line beneath the robot.

Based on the sensor readings, the Arduino continuously adjusts the motor directions to keep the robot aligned with the track.

---

## 📱 Bluetooth Manual Control Mode

The ESP32 receives commands wirelessly from a Bluetooth-enabled smartphone.

These commands are forwarded to the Arduino Uno through UART serial communication, allowing manual control of the robot's movement and buzzer.

---

# 📌 Sensor Configuration

| Sensor | Function |
|---------|----------|
| HC-SR04 Ultrasonic Sensor | Measures obstacle distance |
| SG90 Servo Motor | Rotates ultrasonic sensor for scanning |
| Center IR Sensor | Assists obstacle detection |
| Left IR Sensor | Line detection |
| Right IR Sensor | Line detection |

---

# 📲 Bluetooth Commands

| Command | Action |
|---------|--------|
| F | Move Forward |
| B | Move Backward |
| L | Turn Left |
| R | Turn Right |
| S | Stop |
| H | Activate Buzzer |

---

# 🏗 System Architecture

```
          Smartphone
               │
          Bluetooth
               │
        ESP32 DevKit
               │
        UART Communication
               │
          Arduino Uno
               │
     ┌─────────┼─────────┐
     │         │         │
  L298N     Sensors    Servo
     │
 4 DC Gear Motors
```

---

# 📍 Arduino Pin Mapping

| Arduino Pin | Connected Device |
|--------------|------------------|
| D2 | L298N IN4 |
| D4 | L298N IN3 |
| D6 | ENA & ENB (Common PWM) |
| D7 | L298N IN2 |
| D8 | L298N IN1 |
| D11 | SG90 Servo |
| D12 | Obstacle Mode Switch |
| D13 | Line Following Switch |
| A0 | Left IR Sensor |
| A1 | Center IR Sensor |
| A2 | Right IR Sensor |
| A3 | Active Buzzer |
| A4 | Ultrasonic Echo |
| A5 | Ultrasonic Trigger |

> **Note:** The ENA and ENB enable pins of the L298N motor driver are electrically connected together and controlled using Arduino digital pin **D6**. This modification was implemented due to a hardware issue with the ENB enable channel, allowing both motor channels to share the same PWM speed control signal.

---

# 💻 Development Environment

- Arduino IDE
- ESP32 Arduino Core
- C++
- Serial Monitor

---

# 📁 Repository Structure

```
.
├── Arduino/
│   └── SmartRobotCar.ino
│
├── ESP32/
│   └── ESP32_Bluetooth.ino
│
├── images/
│   ├── robot.jpg
│   ├── wiring-diagram.png
│   └── block-diagram.png
│
├── videos/
│   └── demo.mp4
│
├── README.md
└── LICENSE
```

---

# 📂 Source Code

The project consists of two independent firmware programs.

### Arduino Uno

Responsible for:

- Motor control
- Obstacle avoidance
- Line following
- Servo control
- Sensor processing
- Mode selection
- Buzzer control

### ESP32 DevKit

Responsible for:

- Bluetooth communication
- Receiving commands from a smartphone
- Forwarding commands to the Arduino Uno through UART

---

# 🔌 Wiring Diagram

> Complete wiring diagram of the robot.

<p align="center">
  <img src="images/wiring-diagram.png" width="850">
</p>

---

# 🚀 Future Improvements

- PID-based line following
- Wi-Fi control using ESP32
- Mobile application with graphical interface
- Camera module integration
- Battery voltage monitoring
- Autonomous path planning

---

# 👥 Contributors

- **Vishal**
- **Nitish**

Developed as part of the **Value Added Course (VAC) – Arduino Microcontroller**.

---

# 📄 License

This project is licensed under the **MIT License**.