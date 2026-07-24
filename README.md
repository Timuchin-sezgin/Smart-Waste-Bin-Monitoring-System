# Smart-Waste-Bin-Monitoring-System
IoT waste bin monitoring system using ESP32 and HLK-LD2410B radar.
# Smart Presence Detection System using ESP32 + HLK-LD2410B

A simple IoT project that uses an ESP32 and the Hi-Link LD2410B 24GHz radar sensor to detect people and display live data in a web browser.

---

## Features

- 📡 Human presence detection
- 🚶 Motion detection
- 🧍 Stationary target detection
- 📏 Distance measurement (cm)
- 🌐 Built-in web interface
- 📱 Works from any phone connected to the same Wi-Fi
- 🔄 Live auto-refresh

---

## Hardware

- ESP32 DevKit V1
- Hi-Link LD2410B 24GHz Radar
- USB Cable
- Jumper wires

---

## Wiring

| LD2410B | ESP32 |
|---------|--------|
| VCC | 5V |
| GND | GND |
| TX | GPIO16 (RX2) |
| RX | GPIO17 (TX2) |

Baud Rate:

```
256000
```

## What the website shows

- Target Status
- Motion Distance
- Motion Energy
- Stationary Distance
- Stationary Energy
- Detection Distance

The values update automatically every second.

---

## Technologies

- ESP32
- Arduino IDE
- C++
- Wi-Fi
- HTML
- CSS
- JavaScript
- UART Communication

---

## Future Improvements

- Telegram notifications
- LoRa communication
- Battery power
- Cloud database
- Mobile App
- Smart Waste Bin Monitoring integration

---

## Project Photos

*(Upload the photos here later.)*

---

## Author

**Timuchin Sezgin**

Student from Kazakhstan 🇰🇿

Learning:

- C++
- ESP32
- Arduino
- IoT
- Embedded Systems
  
GitHub:
https://github.com/Timuchin-sezgin
