# 🗑 Smart Waste Bin Monitoring System

An IoT-based Smart Waste Bin Monitoring System built with **ESP32** and **HLK-LD2410B Radar Sensor**.

The system measures the distance between the radar sensor and the waste, calculates the fill level, determines the bin status, and displays all information on a built-in web dashboard.

---

# 📸 Project Preview

> 🚧 Photos of the hardware and dashboard will be added soon.

---

# ✨ Current Features

- 📡 HLK-LD2410B Radar integration
- 📏 Distance measurement
- 📊 Automatic fill percentage calculation
- 🗑 Smart bin status detection
- 🌐 Built-in Web Dashboard
- 🧠 Moving Average Filter for stable measurements
- ⚡ Modular project architecture
- 🔧 Easy to extend

---

# 🧠 Smart Logic

The system automatically classifies the waste level.

| Fill Level | Status |
|------------|---------|
| 0–24% | 🟢 Empty |
| 25–49% | 🟡 Half Full |
| 50–79% | 🟠 Almost Full |
| 80–100% | 🔴 Full |

---

# 🖥 Web Dashboard

The ESP32 hosts its own web server.

The dashboard displays:

- 📏 Distance
- 📊 Fill Percentage
- 🗑 Bin Status
- 📡 Radar Status

The data updates automatically without refreshing the page.

---

# 🔧 Hardware

- ESP32 DevKit V1
- HLK-LD2410B Radar Sensor
- TP4056 Charging Module
- 18650 Li-ion Battery
- MT3608 Boost Converter
- SX1278 LoRa Module *(coming soon)*

---

# 📂 Project Structure

```
firmware/
│
├── smart_waste_bin.ino
├── config.h
├── radar.cpp
├── radar.h
├── filter.cpp
├── filter.h
├── smart_logic.cpp
├── smart_logic.h
├── web.cpp
└── web.h
```

---

# ⚙ Technologies

- ESP32
- Arduino IDE
- C++
- HTML
- CSS
- JavaScript
- Git
- GitHub
- IoT

---

# 🚀 Roadmap

## ✅ Version 1.0

- Radar Reading
- Fill Percentage
- Bin Status
- Web Dashboard

---

## 🔄 Version 2.0

- Better Filtering
- Cleaner Code Structure
- Faster Web Dashboard
- Improved Smart Logic

---

## 🚧 Version 3.0

- 📡 LoRa Communication
- 🤖 Telegram Notifications
- 🔋 Battery Monitoring
- ⚙ EEPROM Settings
- 📈 Data Logging

---

## 🌍 Future Goals

- Mobile Application
- Cloud Dashboard
- Solar Powered System
- GPS Integration
- AI Prediction
- Multiple Smart Bins
- City Waste Monitoring Network

---

# 🎯 Project Goal

The goal of this project is to reduce unnecessary garbage truck trips by providing real-time information about waste bin fill levels.

This can reduce:

- Fuel consumption
- Traffic
- CO₂ emissions
- Waste collection costs

---

# 📚 Learning Goals

This project helps me improve my skills in:

- Embedded Systems
- IoT
- ESP32 Programming
- C++
- Git & GitHub
- Web Development
- Electronics

---

# 👨‍💻 Author

**Timuchin Sezgin**

Student from Kazakhstan 🇰🇿

Learning:

- IoT
- ESP32
- Arduino
- C++
- Python
- Embedded Systems

---

# ⭐ Support

If you like this project, consider giving it a ⭐ on GitHub.

Thank you for visiting!
