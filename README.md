# 🎨 Arduino Color Detector
### Real-time RGB Color Detection using TCS3200 + LCD Display

<p align="center">
  <img src="https://img.shields.io/badge/Arduino-UNO-00979D?style=for-the-badge&logo=arduino&logoColor=white"/>
  <img src="https://img.shields.io/badge/Sensor-TCS3200-FF6B6B?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Display-LCD%2016x2-4ECDC4?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus"/>
</p>

---

## 📖 About The Project

This project uses an **Arduino UNO** with a **TCS3200 color sensor** to detect and display colors in real time on a **16x2 LCD screen**. It identifies **9 colors** including Red, Green, Blue, Yellow, Orange, Pink, Violet, White, and Black — making it a great beginner-to-intermediate electronics project for learning about sensors, PWM reading, and display interfacing.

---

## ✨ Features

- 🌈 Detects **9 colors**: RED, GREEN, BLUE, YELLOW, ORANGE, PINK, VIOLET, WHITE, BLACK
- 📟 Displays **color name** and **RGB values** live on LCD
- 🎚️ Potentiometer-controlled **LCD contrast adjustment**
- ⚡ Smooth, **flicker-free** display updates
- 🔧 Fully **calibrated** color thresholds for accurate detection

---

## 🧰 Components Required

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| TCS3200 / TCS230 Color Sensor Module | 1 |
| 16x2 LCD Display | 1 |
| Potentiometer (10kΩ) | 1 |
| 220Ω Resistor (for LCD backlight) | 1 |
| Jumper Wires | Several |
| Breadboard | 1 |

---

## 🔌 Wiring & Connections

### 🟦 LCD (16x2) → Arduino

| LCD Pin | Connect To |
|---|---|
| VSS | GND |
| VDD | 5V |
| V0 (Contrast) | Potentiometer Middle Pin |
| RS | Pin 7 |
| RW | GND |
| E | Pin 8 |
| D4 | Pin 9 |
| D5 | Pin 10 |
| D6 | Pin 11 |
| D7 | Pin 12 |
| A (LED+) | 5V via 220Ω resistor |
| K (LED−) | GND |

---

### 🎚️ Potentiometer (LCD Contrast Control)

| Pot Pin | Connect To |
|---|---|
| Left | GND |
| Right | 5V |
| Middle (Wiper) | LCD V0 |

> 💡 **Tip:** Adjust the potentiometer until the text on the LCD is clearly visible.

---

### 🌈 TCS3200 Color Sensor → Arduino

| Sensor Pin | Connect To |
|---|---|
| VCC | 5V |
| GND | GND |
| S0 | Pin 3 |
| S1 | Pin 4 |
| S2 | Pin 5 |
| S3 | Pin 6 |
| OUT | Pin 2 |
| LED | 5V (or auto if module controls it) |

---

## 📁 Project Structure

```
arduino-color-detector/
│
├── color_sensor.ino       # Main Arduino sketch
└── README.md              # Project documentation
```

---

## 🚀 Getting Started

### 1. Clone this repository
```bash
git clone https://github.com/YOUR_USERNAME/arduino-color-detector.git
```

### 2. Open in Arduino IDE
- Launch **Arduino IDE**
- Open `color_sensor.ino`
- Select **Board:** Arduino UNO
- Select the correct **COM Port**

### 3. Install Required Library
Make sure the **LiquidCrystal** library is installed:
> Arduino IDE → Sketch → Include Library → Search: `LiquidCrystal`

### 4. Upload & Run
- Click **Upload** ✅
- Adjust potentiometer until LCD text appears clearly
- Hold any colored object under the sensor and watch it detect!

---

## ⚙️ How It Works

```
TCS3200 sensor reads light frequency for R, G, B channels
         ↓
Arduino maps raw frequency values → 0–255 scale
         ↓
Threshold-based logic identifies the color name
         ↓
LCD displays color name + R G B values in real time
```

The TCS3200 outputs a **square wave** whose frequency is proportional to light intensity. Using `pulseIn()`, the Arduino measures these frequencies for Red, Green, and Blue filtered light separately. These are then **mapped and constrained** to the 0–255 range and compared against calibrated thresholds.

---

## 🎨 Color Detection Logic (Calibrated Thresholds)

| Color | R Range | G Range | B Range |
|---|---|---|---|
| ⚫ BLACK | < 90 | < 80 | < 90 |
| ⚪ WHITE | > 240 | > 240 | > 240 |
| 🟡 YELLOW | > 240 | > 230 | > 210 |
| 🟠 ORANGE | > 240 | 175–210 | 160–200 |
| 🩷 PINK | > 235 | 170–200 | > 220 |
| 🔴 RED | > 230 | 120–160 | 140–180 |
| 🟢 GREEN | > 150 | > 190 | > 150 |
| 🔵 BLUE | < 150 | < 150 | > 200 |
| 🟣 VIOLET | > 200 | < 170 | > 210 |

> ⚠️ These thresholds are calibrated for specific lighting conditions. You may need to fine-tune the `map()` range values in the code to match your sensor and environment.

---

## 📷 Circuit Preview

```
                  ┌─────────────┐
                  │  Arduino UNO│
   TCS3200 ───────┤ D2–D6       │
   LCD 16x2 ──────┤ D7–D12      │
   Potentiometer──┤ (via LCD V0)│
                  └─────────────┘
```

---

## 🛠️ Troubleshooting

| Problem | Solution |
|---|---|
| LCD shows nothing / blocks | Adjust potentiometer for contrast |
| All colors show "UNKNOWN" | Recalibrate `map()` values in code |
| Colors are wrong | Check sensor wiring (S2/S3 pins) |
| Flickering display | Ensure stable 5V power supply |
| Sensor not responding | Verify S0=HIGH, S1=LOW for 20% frequency scaling |

---

## 📜 License

This project is open-source under the **MIT License** — feel free to use, modify, and share!

---

## 🙌 Acknowledgements

- [Arduino](https://www.arduino.cc/) — the amazing open-source hardware platform
- [TCS3200 Datasheet](https://ams.com/tcs3200) — TAOS / ams-OSRAM color sensor
- [LiquidCrystal Library](https://www.arduino.cc/en/Reference/LiquidCrystal) — Arduino official library

---

<p align="center">Made with ❤️ and a lot of colorful objects to test with</p>
