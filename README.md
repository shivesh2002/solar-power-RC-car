# Solar-Powered RC Car with Battery Management System

A renewable energy-powered remote-controlled car featuring intelligent battery management, 
solar charging, and motor control system. Built as B.Tech final year project (May 2024).

![Project Photo](images/solar-car-main.jpg)

---

## 🎯 Project Overview

Designed and built an eco-friendly RC car powered by solar energy with an embedded 
battery recharging system for continuous operation. The system demonstrates practical 
application of renewable energy in mobile robotics.

**Key Achievement:** Self-sustaining vehicle capable of running on solar power with 
battery backup for low-light conditions.

---

## 🔋 Battery Management System (BMS)

### Specifications:
- **Battery Configuration:** 3S Li-ion (3 × 3.7V cells = 11.1V nominal, 12V system)
- **Cell Balancing:** 0.03V tolerance between cells
- **Voltage Range:** 2.7V - 4.2V per cell (safe operating range)
- **Balancing Method:** Load resistance (2.2Ω, 10W) + Flyback DC-DC converter
- **Protection:** Over-voltage, under-voltage, thermal monitoring

### Design Approach:
The BMS ensures all cells in series maintain equal voltage (within 0.03V) to:
- Prevent overcharging (>4.2V) → explosion risk
- Prevent over-discharging (<2.7V) → permanent capacity loss
- Maximize battery lifespan
- Safe operation under varying load conditions

---

## ⚙️ Hardware Components

| Component | Specification | Purpose |
|-----------|--------------|---------|
| **Microcontroller** | ESP8266 NodeMCU | WiFi-enabled control unit |
| **Motor Driver** | L298N Dual H-Bridge | Controls 4 DC motors (bidirectional) |
| **Solar Panel** | 13V, 10W | Primary power source |
| **Battery Pack** | 12V Li-ion (3S configuration) | Energy storage |
| **DC Motors** | 500 RPM, 12V (×4) | Vehicle propulsion |
| **DC-DC Converter** | Flyback topology | Battery charging & cell balancing |

---

## 📐 System Architecture
```
┌─────────────┐
│ Solar Panel │ (13V, 10W)
└──────┬──────┘
       │
       ▼
┌─────────────────┐
│ Charge Control  │
│ & Cell Balancing│ ◄── Flyback Converter
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ 12V Battery Pack│ (3S Li-ion)
│  (3 × 3.7V)     │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│  ESP8266 MCU    │ ◄── Bluetooth/WiFi Control
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ L298N Motor     │
│ Driver (H-Bridge)│
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│  4 × DC Motors  │ (500 RPM each)
└─────────────────┘
```

---

## 💻 Software Implementation

### Control System:
- **Platform:** Arduino IDE
- **Communication:** Serial UART (9600 baud) for Bluetooth control
- **Control Commands:** Forward (F), Backward (B), Right (R), Left (L), Stop (S)
- **Motor Control:** PWM-based speed control (0-255 range)

### Key Features:
- Wireless control via Bluetooth module
- Independent 4-motor control for maneuverability
- H-bridge configuration for bidirectional movement
- Real-time command processing

**Code:** See `solar_car_control.ino`

---

## 🔌 Power Electronics Design

### Flyback DC-DC Converter:
- **Purpose:** Charge individual cells from battery pack
- **Topology:** Isolated flyback (galvanic isolation)
- **Operation:** Discontinuous Conduction Mode (DCM)
- **Balancing Logic:** 
  - High voltage cell → discharge through load resistor (2.2Ω)
  - Low voltage cell → charge via flyback converter
  - Target: All cells within 0.03V

### Safety Features:
- Over-voltage cutoff (>4.2V per cell)
- Under-voltage protection (<2.7V per cell)
- Thermal monitoring
- Emergency stop capability

---

## 📊 Performance Characteristics

| Parameter | Value | Notes |
|-----------|-------|-------|
| **Operating Voltage** | 11.1V - 12.6V | 3S Li-ion range |
| **Motor Speed** | 500 RPM @ 12V | Per motor |
| **Solar Charging** | 13V input | Sunlight dependent |
| **Cell Balance Tolerance** | 0.03V | Industry standard for Li-ion |
| **Control Range** | ~10m | Bluetooth limitation |

---

## 🎓 Learning Outcomes

### Technical Skills Developed:
1. **Battery Management:** Cell balancing, charge control, safety systems
2. **Power Electronics:** DC-DC converter design (flyback topology)
3. **Motor Control:** H-bridge drivers, PWM, multi-motor coordination
4. **Embedded Systems:** ESP8266 programming, UART communication
5. **Renewable Energy:** Solar panel integration, energy harvesting
6. **System Integration:** Hardware-software co-design

### Real-World Applications:
- Electric vehicle battery systems
- Solar-powered IoT devices
- Power-constrained mobile robotics
- Renewable energy management

---

## 🛠️ Build Instructions

### Hardware Assembly:
1. Connect solar panel to charge controller input
2. Wire 3S battery pack with balancing leads
3. Connect battery to ESP8266 and L298N motor driver
4. Wire 4 motors to L298N outputs
5. Connect Bluetooth module to ESP8266 (RX/TX pins)
6. Add voltage monitoring for each cell

### Software Setup:
1. Install Arduino IDE
2. Add ESP8266 board support:
```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
```
3. Upload `solar_car_control.ino` to ESP8266
4. Pair Bluetooth module with control device
5. Test motor control commands

---

## ⚠️ Safety Considerations

**Li-ion Battery Warnings:**
- Never discharge below 2.7V per cell (permanent damage)
- Never charge above 4.2V per cell (fire/explosion risk)
- Monitor temperature during operation
- Use fuse protection (recommended: 5A fuse)
- Charge in ventilated area

**Operational Safety:**
- Test motor control in open area first
- Keep water away from electronics
- Monitor battery temperature during charging
- Emergency stop readily accessible

---

## 🔮 Future Improvements

### Potential Enhancements:
1. **MPPT Solar Charge Controller** - maximize solar energy harvest
2. **Regenerative Braking** - recover energy during deceleration
3. **Advanced BMS** - SOC estimation, remaining runtime prediction
4. **GPS Integration** - autonomous navigation capability
5. **Data Logging** - battery health monitoring, performance analytics
6. **Mobile App** - real-time monitoring and control
7. **Larger Battery** - extended runtime capability

---

## 📚 Technical Documentation

### Key References:
- Li-ion Battery Management: Cell balancing requirements (0.03V tolerance)
- Flyback Converter Design: Galvanic isolation for safety
- H-Bridge Motor Control: Bidirectional DC motor operation
- ESP8266 Documentation: WiFi microcontroller specifications

### Project Report:
- Institution: Amity University Madhya Pradesh
- Department: Electronics & Communication Engineering
- Supervisor: Dr. Ajay Kumar Dadoria
- Completion: May 2024

---

## 🤝 Team

**Project Team (B.Tech ECE 2021-2025):**
- Shivesh Kumar Sharma (A60205121007)
- Sheelam Goyal Kumar (A60205121009)
- Aditya Raj Singhal (A60205121001)

**Supervisor:** Dr. Ajay Kumar Dadoria, Assistant Professor

---

## 📝 License

MIT License - Feel free to use this project for learning purposes.

---

## 📧 Contact

**Shivesh Kumar Sharma**
- 📱 +91 9101000018
- 📧 shiveshsharma2002@gmail.com
- 📍 Bangalore, India
- 💼 Currently: Backend Physical Design Training @ Takshila VLSI

**Seeking opportunities in:** Embedded Systems, Physical Design, Battery Management, 
Power Electronics, Automotive Semiconductors

---

## 🏷️ Tags

`battery-management-system` `solar-power` `electric-vehicle` `embedded-systems` 
`power-electronics` `dc-dc-converter` `motor-control` `esp8266` `renewable-energy` 
`li-ion-battery` `h-bridge` `arduino` `iot` `robotics` `cell-balancing`

---

**⭐ If you find this project interesting, please star the repository!**
```

---
