# 🚗 Line Following Robot (LFR)

A semester project for the **Computer Architecture & Organization** course — this Line Following Robot (LFR) was built using an **Arduino Uno**, **2 IR sensors**, and an **L298N motor driver**. It is designed to follow a black line on a white surface, handling straight lines and 90-degree turns.

---

## 🛠️ Hardware Components

- Arduino Uno R3  
- L298N Motor Driver  
- 2x IR Sensors  
- 2x DC Gear Motors  
- Chassis with wheels  
- Power source (battery pack)

---

## ⚙️ Working Principle

The LFR uses **2 IR sensors** placed on the bottom of the robot to detect the path:

- The IR sensors detect the **contrast between the black line and white surface**.
- Based on sensor readings, the Arduino controls the motors via the **L298N driver**, adjusting direction accordingly.

### Sensor Logic

| Left Sensor | Right Sensor | Movement      |
|-------------|--------------|---------------|
| Black       | Black        | Forward       |
| Black       | White        | Turn Left     |
| White       | Black        | Turn Right    |
| White       | White        | Stop / Search |

---

## 🧠 Learning Outcomes

- Embedded systems design
- Real-time sensor data handling
- Low-level motor control using Arduino
- Debugging and hardware-software integration

---

## 👨‍💻 Code

The code is written in **Arduino C** and available in the `code/` directory.

Key features:
- IR sensor reading logic
- Motor control using digital output pins
- Simple condition-based navigation

---

## 📷 Snap

![IMG_4756](https://github.com/user-attachments/assets/c1d221fd-5c13-493c-a5a5-6eaf800e49ea)


---

## 🧩 Future Improvements

- Integrate **PID control** for smoother turns and speed handling
- Upgrade to **3 or 5 IR sensors** for better line detection
- Add obstacle detection using ultrasonic sensors
- Wireless control or telemetry via Bluetooth/WiFi

---

This project was built by:
- **Muhammad Arham Rajput** – [LinkedIn](https://www.linkedin.com/in/arham-rajput-a20a09299) | [GitHub](https://github.com/Arhamurrahemeen)


---

## 📄 License

This project is open-source under the MIT License. Feel free to use, modify, and improve it!

