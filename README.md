# IoT Temperature-Based Fan Speed Control and Monitoring System

An automated IoT system that reads real-time temperature data from sensors and dynamically adjusts fan speed accordingly. Built using ESP32/ESP8266 microcontrollers and DHT11/DS18B20 sensors, the system eliminates manual fan control and enables continuous environmental monitoring.

---

## Problem It Solves

Manual fan speed adjustment in temperature-sensitive environments (server rooms, labs, storage units) is inefficient and error-prone. This system automates that process — sensing temperature continuously and adjusting fan speed in real time without human intervention.

---

## How It Works

1. Temperature sensors (DHT11 / DS18B20) read ambient temperature continuously
2. Data is sent to the ESP32/ESP8266 microcontroller
3. The microcontroller maps temperature ranges to fan speed levels
4. Fan speed is adjusted automatically via PWM (Pulse Width Modulation) signal
5. Temperature readings and fan status are logged for monitoring

---

## Tech Stack

| Component | Technology |
|---|---|
| Microcontroller | ESP32 / ESP8266 |
| Temperature Sensors | DHT11, DS18B20 |
| Programming Language | Java / C++ (Arduino IDE) |
| Communication | Serial / Wi-Fi |
| Fan Control | PWM Signal |

---

## Hardware Requirements

- ESP32 or ESP8266 development board
- DHT11 temperature and humidity sensor
- DS18B20 digital temperature sensor
- DC fan with PWM speed control
- Jumper wires and breadboard
- USB cable for programming

---

## Project Structure

```
Temperature_Based_Fan_Speed_controller/
│
├── main/                  # Core microcontroller code
├── README.md
```

---

## Getting Started

### Prerequisites

- Arduino IDE installed
- ESP32/ESP8266 board package installed in Arduino IDE
- Required libraries: `DHT sensor library`, `OneWire`, `DallasTemperature`

### Setup

1. Connect DHT11 and DS18B20 sensors to the ESP32/ESP8266 as per the pin configuration in the code
2. Connect the fan to the PWM output pin
3. Open the project in Arduino IDE
4. Select the correct board (ESP32 or ESP8266) and COM port
5. Upload the code to the microcontroller

### Run

Once uploaded, the system starts automatically on power-on. Temperature is read every few seconds and fan speed adjusts in real time.

---

## Key Features

- Real-time temperature sensing using dual sensor support (DHT11 + DS18B20)
- Automatic fan speed adjustment based on configurable temperature thresholds
- Continuous data logging for environmental monitoring
- Low-power embedded design suitable for long-term deployment

---

## Temperature-to-Speed Mapping (Example)

| Temperature Range | Fan Speed |
|---|---|
| Below 25°C | Off |
| 25°C – 30°C | Low (30%) |
| 30°C – 35°C | Medium (60%) |
| Above 35°C | High (100%) |

---

## Future Improvements

- Add Wi-Fi dashboard to monitor temperature and fan status remotely
- Integrate mobile push notifications for temperature threshold breaches
- Add humidity-based control logic
- Support multiple fan zones for larger environments

---

## Author

**Siliveru Rajesh**
- GitHub: [@siliverurajesh](https://github.com/siliverurajesh)
- LinkedIn: [siliveru-rajesh2907](https://linkedin.com/in/siliveru-rajesh2907)
- Email: siliverurajesh143@gmail.com
