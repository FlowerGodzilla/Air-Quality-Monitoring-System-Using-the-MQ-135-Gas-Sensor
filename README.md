# Smart Air Quality Monitoring System Using MQ-135 Gas Sensor

## Overview

This project utilizes the MQ-135 gas sensor to measure ammonia (NH3) levels in the air, displaying the results on a 16x2 LCD screen. The system calculates the concentration of NH3 in parts per million (ppm) based on the sensor's resistance changes. This readme provides a brief explanation of the code, its setup, and usage.

## Date

- Dated: 27-04-2023

## Components Required

1. **Arduino Board**
2. **MQ-135 Gas Sensor**
3. **16x2 LCD Display**
4. **Resistor (47KΩ)**
5. **Connecting Wires**
6. **Breadboard**

## Circuit Diagram

1. **MQ-135 Sensor:**
   - Connect the analog output of the MQ-135 sensor to the Arduino's analog input pin (A0).
   - The sensor's other connections include VCC (5V) and GND.

2. **LCD Display:**
   - Connect the LCD pins to the Arduino as follows:
     - RS: Pin 8
     - E: Pin 9
     - D4: Pin 10
     - D5: Pin 11
     - D6: Pin 12
     - D7: Pin 13

## Code Explanation

The program reads the voltage drop across the MQ-135 sensor and calculates the corresponding NH3 concentration in ppm.

### Key Variables
- `RL`: Load resistance connected in series with the sensor (47KΩ).
- `m` and `b`: Slope and intercept for the sensor's calibration curve.
- `Ro`: The sensor's resistance in clean air.
- `MQ_sensor`: Analog input pin connected to the sensor.

### Setup Function
- Initializes the LCD and displays a welcome message.
- Sets up the serial communication for debugging.

### Loop Function
- Reads the sensor voltage and calculates the sensor resistance (`Rs`).
- Computes the ratio of sensor resistance in gas to the resistance in clean air (`Ro`).
- Calculates the gas concentration in ppm using the calibration formula.
- Displays the NH3 concentration and the sensor voltage on the LCD.

## Usage Instructions

1. Connect the hardware components according to the circuit diagram.
2. Upload the code to the Arduino board.
3. Monitor the NH3 concentration displayed on the LCD screen.

## Note

Ensure that the MQ-135 sensor is properly calibrated for accurate measurements. The calibration constants (`m`, `b`, and `Ro`) are specific to each sensor and may need to be adjusted based on your sensor and environment.
