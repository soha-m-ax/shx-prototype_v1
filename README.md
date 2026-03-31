# SHX // PROTOTYPE
### Designed by SohaMax // Solar Strike ⚡

The **SHX // PROTOTYPE** is a 7-key mechanical macro pad designed for custom inputs. This design utilizes a direct-solder architecture to maintain a slim profile and ensure structural stability. Every trace on the PCB was manually routed in KiCad 8.0.

---

## Visuals:

### 1. CAD View
The final assembly of the SHX PROTOTYPE keypad.
![Overall View](https://github.com/soha-m-ax/shx-prototype_v1/blob/main/assets/cad.png)

### 2. Schematic
The circuit diagram showing the XIAO RP2040 connected to the 7-key matrix.
![Schematic](https://github.com/soha-m-ax/shx-prototype_v1/blob/main/assets/schematic.png)

### 3. PCB Layout
The custom 2-layer board design featuring hand-routed traces and mascot art.
![PCB Layout](assets/pcb_view.png)


---

## Bill of Materials (BOM):

| Component | Quantity | Purpose |
| :--- | :--- | :--- |
| **Seeed Studio XIAO RP2040** | 1 | Microcontroller |
| **Through-hole 1N4148 Diodes** | 7 | Signal Logic |
| **Mechanical Switches (MX-Style)** | 6 | Key Inputs |
| **EC11 Rotary Encoders** | 1 | Knob Inputs |
| **0.91 inch OLED Display** | 1 | Screen view |
| **DSA keycaps (White)** | 1 | Keycap Fit|
| **SK6812 MINI-E LEDs** | 7 | Custom lighting |
| **M3x16mm Screws** | 3 | | 3D Case Fiting |
| **M3x5mx4mm Heatset Inserts** | 3 | | 3D Case Fiting |
| **3D Printed Top Cover & Main Case** | Each 1 | Enclosure |

---

## Technical Specifications:

* **MCU:** XIAO RP2040.
* **Architecture:** 7-key matrix include 1 knob key .
* **Firmware:** QMK (For now)
* **PCB Design:** KiCad 8.0.
* **CAD Design:** Fusion 360.

---

## Features: 
## 🚀 [SYSTEM_FEATURES] :: SPECIFICATIONS

The SHX // PROTOTYPE is configured with the following hardware capabilities:

* **7-Key Mechanical Matrix:** Fully programmable grid for high-speed macros and shortcuts.
* **Programmable Rotary Encoder:** Precision knob for timeline scrubbing, zooming, or volume control with a built-in "click" function.
* **3-Second Custom Splash Screen**: Professional "SOHAMAX SYSTEM ACTIVE" greeting on plug-in.
* **Reactive Bongo Cat Animation**: OLED character that syncs with real-time typing speed.
* **7-Zone Addressable RGB**: Custom lighting array with a static colour base and high-speed "Colour Flash" reactive triggers.
* **Rainbow Heartbeat**: Dedicated logic for LED 2 to maintain a constant color cycle regardless of key state.
* **Precision Volume Control**: Integrated rotary encoder for granular system audio management.
* **6-Key Gaming Layout**: Optimized 3x3 matrix featuring a secret "F24" dead key for advanced application macros.
* **RP2040 Speed Boost**: Leverages high-speed PIO drivers and Link Time Optimization (LTO) for zero-latency input.

---
> This firmware represents the stable **v1.0** release; I intend to further refine the animation states and expand the RGB functionality in future iterations to enhance the overall hardware-software integration.


---

```bash
