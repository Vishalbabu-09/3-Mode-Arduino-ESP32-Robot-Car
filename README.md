
# 🚗 3-Mode Smart Robot Car using Arduino Uno and ESP32

<p align="center">
  <img src="Images/Top view (Turned on).jpg" width="500" alt="3-Mode Smart Robot Car">
</p>

A multifunctional smart robot car capable of operating in **three independent modes**: **Obstacle Avoidance**, **Line Following**, and **Bluetooth Manual Control**.

The project combines an **Arduino Uno** for real-time motor and sensor control with an **ESP32 DevKit** for Bluetooth communication, creating a modular embedded system capable of both autonomous and manual operation.

> Developed by **Vishal** and **Nitish** as part of the **Value Added Course (VAC) – Arduino Microcontroller**.

---

# 🎥 Project Demonstration

Watch the complete working demonstration of the robot on YouTube.

[![Watch Demo](https://img.shields.io/badge/▶%20Watch%20Demo-red?style=for-the-badge&logo=youtube)](https://youtu.be/05GIOicuBzw)

---

# 📖 Project Overview

This project demonstrates the implementation of a multi-functional smart robot car capable of switching between three operating modes using dedicated rocker switches.

The robot combines autonomous navigation and wireless manual control into a single platform.

### Operating Modes

- 🚧 Obstacle Avoidance
- ➖ Line Following
- 📱 Bluetooth Manual Control

The **Arduino Uno** performs all real-time control operations including motor control, sensor processing, servo control, buzzer control and operating mode selection.

The **ESP32 DevKit** acts as a Bluetooth communication bridge by receiving commands from a smartphone and forwarding them to the Arduino Uno through UART serial communication.

---

# ✨ Features

- 🚗 Three independent operating modes
- 📡 Bluetooth manual control
- 🚧 Autonomous obstacle avoidance
- ➖ Automatic line following
- 🔄 Servo-mounted ultrasonic scanning
- 🔔 Buzzer alerts
- 🎛 Four rocker-switch controls
- ⚡ Battery-powered portable design
- 🤖 Arduino + ESP32 modular architecture

---

# 📋 Project Specifications

| Specification | Details |
|--------------|---------|
| Main Controller | Arduino Uno |
| Bluetooth Controller | ESP32 DevKit |
| Programming Language | C++ |
| Framework | Arduino Framework |
| Motor Driver | L298N |
| Communication | Bluetooth (UART) |
| Power Supply | 7.4V (2×18650 Li-ion Batteries) |
| Drive System | 4WD DC Gear Motors |
| Sensors | HC-SR04 + 3 IR Sensors |
| Operating Modes | 3 |

---

# 🛠 Hardware Components

| Component | Quantity | Purpose |
|-----------|:--------:|---------|
| Arduino Uno (CH340 Square Chip Version) | 1 | Main controller |
| ESP32 DevKit | 1 | Bluetooth communication bridge |
| L298N Motor Driver | 1 | Drives four DC motors |
| HC-SR04 Ultrasonic Sensor | 1 | Obstacle detection |
| Ultrasonic Sensor Holder | 1 | Mounts the ultrasonic sensor |
| SG90 Servo Motor | 1 | Rotates the ultrasonic sensor |
| IR Sensors | 3 | One center IR for obstacle assistance and two side IR sensors for line following |
| Active Buzzer | 1 | Audible feedback |
| Robot Chassis | 1 | Mechanical frame |
| DC Gear Motors | 4 | Robot movement |
| Robot Wheels | 4 | Locomotion |
| 18650 Li-ion Batteries (3.7V) | 2 | Power source |
| Dual 18650 Battery Holder | 1 | Provides ~7.4V |
| Rocker Switches | 4 | Power and mode selection |
| Breadboard | 1 | Power distribution |
| Jumper Wires | Multiple | Electrical connections |
| Hook-up Wires | As required | Component wiring |

---

# 🔋 Power Supply

The robot is powered using **two 3.7V 18650 Li-ion batteries connected in series**, providing approximately **7.4V**.

The battery output is distributed through the breadboard power rails and supplied directly to the **VIN** pin of both the **Arduino Uno** and the **ESP32 DevKit**.

The breadboard serves as a centralized power distribution board for the motor driver, sensors, servo motor, buzzer and other peripherals.

---

# 🎛 Operating Modes

The robot uses four rocker switches mounted on the chassis.

| Switch Position | Function |
|-----------------|----------|
| Left-most | Main Power ON/OFF |
| Second from Left | Bluetooth Manual Control |
| Middle | Obstacle Avoidance |
| Right-most | Line Following |

> **NOTE:** Only **one operating mode** should be enabled at a time. If two or more operating mode switches are turned ON simultaneously, the Arduino intentionally places the robot in a **STOP** state to prevent conflicting control logic and ensure safe operation.

---

# ⚙ Working Principle

## 🚧 Obstacle Avoidance Mode

The Arduino continuously monitors the ultrasonic sensor and center IR sensor.

When an obstacle is detected, the robot:

1. Stops and activates the buzzer.
2. Moves backward briefly.
3. Rotates the ultrasonic sensor using the servo motor.
4. Scans both directions.
5. Chooses the direction with greater clearance.
6. Turns accordingly.
7. Continues moving forward.

---

## ➖ Line Following Mode

The left and right IR sensors detect the line beneath the robot. The Arduino adjusts motor movement to keep the robot aligned with the path.

---

## 📱 Bluetooth Manual Control Mode

The ESP32 receives Bluetooth commands from a smartphone and forwards them to the Arduino through UART serial communication for movement and buzzer control.

---

# 📌 Sensor Configuration

| Sensor | Function |
|---------|----------|
| HC-SR04 | Obstacle distance measurement |
| SG90 Servo | Ultrasonic scanning |
| Center IR | Obstacle assistance |
| Left IR | Line detection |
| Right IR | Line detection |

---

# 📲 Bluetooth Commands

| Command | Action |
|---------|--------|
| F | Forward |
| B | Backward |
| L | Turn Left |
| R | Turn Right |
| S | Stop |
| H | Horn / Buzzer |

---

# 🏗 System Architecture

```text
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
      ┌────────┼────────┐
      │        │        │
    L298N   Sensors   Servo
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
| D11 | Servo Motor |
| D12 | Obstacle Mode Switch |
| D13 | Line Following Mode Switch |
| A0 | Left IR Sensor |
| A1 | Center IR Sensor |
| A2 | Right IR Sensor |
| A3 | Active Buzzer |
| A4 | Ultrasonic Echo |
| A5 | Ultrasonic Trigger |

> **Note:** The ENA and ENB pins of the L298N motor driver are electrically connected together and driven by Arduino pin **D6** due to a hardware issue with the ENB channel.

---

# 💻 Development Environment

- Arduino IDE
- C++
- Serial Monitor

---

# 📁 Repository Structure

```text
.
├── Arduino_Code/
│   └── Arduino_CarCode.ino
│
├── ESP32_Code/
│   └── ESP32_BluetoothCar_Code.ino
│
├── Images/
│   ├── Chassis.jpg
│   ├── Side view.jpg
│   ├── Top view(Turned on).jpg
│   ├── Top view(Turned off).jpg
│   ├── Wiring_Diagram.png
│   ├── Block_Diagram.png
│   └── Circuit.jpg
│
├── Video/
│   └── 3 Mode Smart car.mp4
│
├── README.md
└── LICENSE
```

---

# 📂 Source Code

## Arduino_CarCode.ino

Responsible for:

- Motor control
- Obstacle avoidance
- Line following
- Servo control
- Sensor processing
- Buzzer control
- Operating mode selection

## ESP32_BluetoothCar_Code.ino

Responsible for:

- Bluetooth communication
- Receiving commands from a smartphone
- Forwarding commands to the Arduino Uno through UART

---

# 🔌 Wiring Diagram

> Add the wiring diagram below.

<p align="center">
  <img src="Images/Wiring_Diagram.png" width="850" alt="Wiring Diagram">
</p>

---

# 🚀 Future Improvements

- PID-based line following
- Wi-Fi control using ESP32
- Mobile application
- Camera module integration
- Battery voltage monitoring
- Autonomous path planning

---

# 👥 Contributors

- **T S Vishal Babu**
- **Nitish M A**

Developed as part of the **Value Added Course (VAC) – Arduino Microcontroller**.

---

# 📄 License

This project is licensed under the **MIT License**.
