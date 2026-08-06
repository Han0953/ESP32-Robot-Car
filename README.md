# 🚗 ESP32 WiFi Robot Car

![Board](https://img.shields.io/badge/Board-ESP32-blue?style=flat-square&logo=expressif)
![Language](https://img.shields.io/badge/Language-C%2B%2B%20%2F%20Arduino-00599C?style=flat-square&logo=arduino)
![App](https://img.shields.io/badge/App-MIT%20App%20Inventor-orange?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)

A smart, wireless robotic car powered by the **ESP32** microcontroller[cite: 1]. The robot operates as an independent **WiFi Access Point** (Hotspot) and is controlled in real-time through an Android mobile application built using **MIT App Inventor**[cite: 1].

---

## 📸 Overview & Features

- 📶 **Standalone Access Point (AP) Mode:** The robot creates its own WiFi hotspot (`RobotESP32_WiFi`) with IP `192.168.4.1`[cite: 1]. No external router or internet connectivity required.
- 🕹️ **Full Motion Control:** Supports real-time commands: Forward, Backward, Turn Left, Turn Right, and Stop via HTTP GET requests[cite: 1].
- ⚡ **Variable Speed Control (PWM):** Smooth motor speed control using Pulse Width Modulation (PWM) configured via a slider on the mobile app[cite: 1].
- 📱 **Custom Android App:** Integrated graphical controller interface designed for mobile control[cite: 1].
- 🛡️ **Brownout Protected:** Recommended dual-power delivery setup to prevent system resets during high motor loads[cite: 1].

<p center">
  <img src="docs/images/Photo1.jpg" alt="ESP32 Robot Car" width="45%">
  <img src="docs/images/Circuit Diagram.png" alt="App Interface" width="45%">
</p>

---

## 🛠️ Hardware Components

| Component | Quantity | Notes / Specifications |
| :--- | :---: | :--- |
| **ESP32 Dev Board** | 1x | 30-pin microcontroller board[cite: 1] |
| **L298N Motor Driver** | 1x | Dual H-Bridge motor driver module[cite: 1] |
| **DC Gear Motors** | 2x | 3V–6V DC gear motors with wheels[cite: 1] |
| **Robot Chassis Kit** | 1x | Acrylic chassis with caster wheel[cite: 1] |
| **18650 Li-ion Batteries** | 2x | 3.7V batteries (Series connection for ~7.4V)[cite: 1] |
| **18650 Battery Holder** | 1x | Dual slot holder[cite: 1] |
| **Power Switch** | 1x | Rocker switch (On/Off)[cite: 1] |
| **Jumper Wires** | Set | Male-to-Male, Male-to-Female, Female-to-Female[cite: 1] |

---

## 📌 Pin Mapping & Wiring Table

Wire the ESP32 development board to the L298N motor driver according to the mapping below[cite: 1]:

| ESP32 Pin | L298N Terminal | Function |
| :---: | :---: | :--- |
| **VIN** | `5V` / External | ESP32 Power Input[cite: 1] |
| **GND** | `GND` | Common Ground (Must be shared)[cite: 1] |
| **GPIO 14** | `ENA` | Speed Control (PWM) - Right Motor[cite: 1] |
| **GPIO 27** | `IN1` | Direction Control - Right Motor[cite: 1] |
| **GPIO 26** | `IN2` | Direction Control - Right Motor[cite: 1] |
| **GPIO 25** | `IN3` | Direction Control - Left Motor[cite: 1] |
| **GPIO 33** | `IN4` | Direction Control - Left Motor[cite: 1] |
| **GPIO 32** | `ENB` | Speed Control (PWM) - Left Motor[cite: 1] |

---

## 💻 Software & Deployment

### 1. Firmware Setup (Arduino IDE)
1. Install **Arduino IDE** and add the **ESP32 Board Package**.
2. Open the firmware source code (`.ino`) provided in this repository[cite: 1].
3. Select your ESP32 board model and correct COM port.
4. Click **Upload** to flash the code onto the ESP32[cite: 1].

### 2. Mobile Controller Setup (MIT App Inventor)
1. Install the provided `.apk` application onto your Android device[cite: 1].
2. Alternatively, open [MIT App Inventor](https://appinventor.mit.edu/) and import the `.aia` project file to edit the visual blocks or GUI[cite: 1].
3. Ensure the target IP address in the app is configured to `192.168.4.1`[cite: 1].

### 3. Quick Start Guide
1. Power up the robot car using the battery pack[cite: 1].
2. On your smartphone, connect to the WiFi network **`RobotESP32_WiFi`**[cite: 1].
3. Open the controller app, set your desired speed, and start driving! 🚗

---

## ⚠️ Troubleshooting (Brownout Issues)

* **Problem:** ESP32 disconnects, restarts, or loses WiFi connection when the motors start moving.
* **Cause:** Voltage dip (*Brownout*) caused by motors drawing high surge currents through the L298N regulator, starving the ESP32.
* **Solution:** Separate the power sources! Use the 18650 battery pack strictly for the L298N driver (`+12V` terminal), and power the ESP32 via a dedicated 5V power supply (such as a small Power Bank via Micro-USB/USB-C). **Ensure the GND pin on the ESP32 and L298N remain connected.**

---

## 👤 Author & Acknowledgments

Designed and developed by **Muhammad Rehan**[cite: 1].

- **Course:** Mobile Development Program[cite: 1]
- **Institution:** Universitas Muhammadiyah Riau[cite: 1]
- **Lecturer / Advisor:** Fauzan Azim, S.Pd., M.Kom.[cite: 1]

---

## 📄 License
This repository is open-source and available under the [MIT License](LICENSE).
