# ECE 1111 — Lab 04: Temperature-Based LED Control in Tinkercad

## Overview
This Engineering Computation I laboratory introduces circuit building and microcontroller programming in Tinkercad. Two separate implementations read an external **TMP36 analog temperature sensor** and activate one of three colored LEDs to indicate a temperature range: a **BBC micro:bit** programmed in MakeCode Python and an **Arduino Uno** programmed in Arduino C/C++.

The original laboratory identifies **p01 as the micro:bit** and **p02 as the Arduino Uno**. The source filenames supplied for both implementations were `p01.py` and `p01.ino`; they are retained here while stored in their corresponding device folders.

## Hardware and connections (from supplied source code)

| Device | Sensor input | Red LED control | Green LED control | Blue LED control |
| --- | --- | --- | --- | --- |
| BBC micro:bit | P0 (analog) | P1 | P16 | P8 |
| Arduino Uno | A0 (analog) | D2 | D3 | D4 |

Both programs use a TMP36 sensor. The source code establishes these pin assignments, but **does not establish the complete wiring**, including power, ground, resistor values, or LED orientation. Verified Tinkercad circuit screenshots/schematics should be added to `circuit_images/` before presenting this as complete circuit documentation.

## Behavior in the original code

| Indicator | BBC micro:bit | Arduino Uno |
| --- | --- | --- |
| Blue (cold) | Below 68°F | Below 60°F |
| Green (normal) | 68°F to below 86°F | 60°F through 80°F |
| Red (hot) | 86°F or higher | Above 80°F |

**Note:** The two implementations use different thresholds. These values are preserved from the supplied source code rather than silently standardized.

### Micro:bit — `p01_microbit/p01.py`
- Reads the external TMP36 sensor through analog pin P0.
- Applies an empirically calibrated ADC-to-Fahrenheit formula.
- Displays rounded temperature on the micro:bit LED matrix.
- Drives external LEDs through pins P8, P16, and P1.
- Uses MakeCode Python APIs (`pins`, `basic`, `Math`) rather than standard desktop Python.

### Arduino — `p02_arduino/p01.ino`
- Reads the TMP36 through Arduino analog input A0.
- Converts 10-bit ADC counts to voltage, then to °C and °F.
- Prints Fahrenheit readings to the serial monitor at 9600 baud.
- Drives external LEDs through digital pins D2, D3, and D4.
- Samples approximately every 500 ms.

## Circuit documentation

### Original BBC micro:bit circuit (Tinkercad)
![Original micro:bit circuit screenshot](circuit_images/microbit_circuit_original.png)

### Original Arduino Uno circuit (Tinkercad)
![Original Arduino Uno circuit screenshot](circuit_images/arduino_circuit_original.png)

### Optional presentation concept — red and black wires
![Stylized circuit presentation concept](circuit_images/circuit_presentation_concept.png)

**Important:** The two images above are screenshots of the supplied original Tinkercad circuits. The red-and-black illustration is an **AI-generated presentation concept**, not a verified wiring diagram or an actual screenshot of the built circuits. Its electrical connections, component values, and pin labels must not be relied upon for assembly or validation. The original screenshots and source code are the primary evidence of this project.

## Running the project
1. Open Tinkercad Circuits and load or recreate the correct hardware configuration from your saved circuit design.
2. For the micro:bit, paste `p01_microbit/p01.py` into the **MakeCode Python** environment supported by your project.
3. For Arduino, load `p02_arduino/p01.ino` in the Arduino code environment and open the serial monitor to observe temperature readings.
4. Change the TMP36 simulated temperature and observe which LED is active.

## Repository contents
- `p01_microbit/p01.py` — original supplied BBC micro:bit source code.
- `p02_arduino/p01.ino` — original supplied Arduino source code.
- `docs/Lab_04_Instructions.docx` — provided lab instructions.
- `circuit_images/` — two original Tinkercad screenshots plus one clearly labeled illustrative presentation concept.

## Verification status
The code is preserved as provided. The circuits and programs have **not been independently run or verified** for this portfolio packaging. Original Tinkercad circuit screenshots are included. Testing observations and independent electrical verification have not been added.

## Skills demonstrated
Analog sensor interfacing, microcontroller I/O, ADC conversion, conditional logic, temperature measurement, C/C++, MakeCode Python, Tinkercad circuit simulation, and hardware/software integration.
