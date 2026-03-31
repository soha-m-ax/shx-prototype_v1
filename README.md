# SHX // PROTOTYPE
### Designed by SohaMax // Solar Strike ⚡

The **SHX // PROTOTYPE** is a 7-key mechanical macro pad designed for custom inputs in 3D animation and CAD. This design utilizes a direct-solder architecture to maintain a slim profile and ensure structural stability. Every trace on the PCB was manually routed in KiCad 8.0.

---

## Required Visuals

### 1. Overall View
The final assembly of the SHX keypad.
![Overall View](assets/hero_shot.png)

### 2. Schematic
The circuit diagram showing the XIAO RP2040 connected to the 7-key matrix.
![Schematic](assets/schematic_view.png)

### 3. PCB Layout
The custom 2-layer board design featuring hand-routed traces and mascot art.
![PCB Layout](assets/pcb_view.png)

### 4. Case and Assembly
The 3D-printed top cover designed in Fusion 360, shown fitting onto the PCB.
![Case Assembly](assets/assembly_view.png)

---

## Bill of Materials (BOM)

| Component | Quantity | Purpose |
| :--- | :--- | :--- |
| **Seeed Studio XIAO RP2040** | 1 | Microcontroller |
| **Mechanical Switches (MX)** | 7 | Key Inputs |
| **1N4148 Diodes** | 7 | Signal Logic |
| **SHX v1 Custom PCB** | 1 | Main Board |
| **3D Printed Top Cover** | 1 | Enclosure |
| **USB-C Cable** | 1 | Power/Data Link |

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
