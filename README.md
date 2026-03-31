# SHX // PROTOTYPE
### Designed by SohaMax // Solar Strike ⚡

The **SHX // PROTOTYPE** is a 7-key mechanical macro pad designed for custom inputs. This design utilizes a direct-solder architecture to maintain a slim profile and ensure structural stability. Every trace on the PCB was manually routed in KiCad 8.0.

---

## Visuals

### 1. CAD View
The final assembly of the SHX keypad.
![Overall View](assets/hero_shot.png)

### 2. Schematic
The circuit diagram showing the XIAO RP2040 connected to the 7-key matrix.
![Schematic](assets/schematic_view.png)

### 3. PCB Layout
The custom 2-layer board design featuring hand-routed traces and mascot art.
![PCB Layout](assets/pcb_view.png)


---

## Bill of Materials (BOM)

| Component | Quantity | Purpose |
| :--- | :--- | :--- |
| **Seeed Studio XIAO RP2040** | 1 | Microcontroller |
| **Through-hole 1N4148 Diodes** | 7 | Signal Logic |
| **Mechanical Switches (MX-Style)** | 6 | Key Inputs |
| **EC11 Rotary Encoders** | 1 | Knob Inputs |
| **0.91 inch OLED Display** | 1 | Screen view |
| **DSA keycaps (White)** | 1 | keycap fit|
| **SK6812 MINI-E LEDs** | 7 | Custom lighting |
| **M3x16mm Screws** | 3 | | 3D CASE FITING |
| **M3x5mx4mm Heatset Inserts** | 3 | | 3D CASE FITING |
| **SHX v1 Custom PCB** | 1 | PCB Board |
| **3D Printed Top Cover & Main Case** | 1 | Enclosure |

---

## Technical Specifications

* **MCU:** XIAO RP2040.
* **Architecture:** 7-key matrix (No hotswap).
* **Firmware:** KMK / CircuitPython compatible.
* **PCB Design:** KiCad 8.0 (Hand-routed).
* **CAD Design:** Fusion 360 (XY-plane oriented).

---

## Project Log

The SHX project is a functional hardware tool. The design removes unnecessary hotswap layers to achieve a lower profile and a more stable electrical connection. All assets are contained within this repository for manufacturing and assembly.

---

```bash
# To clone this project:
git clone [https://github.com/soha-m-ax/shx-prototype_v1.git](https://github.com/soha-m-ax/shx-prototype_v1.git)
