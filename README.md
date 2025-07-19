# Heater Control System

## Overview

The Heater Control System is an Arduino-based project designed to monitor and control a heating element using an NTC thermistor sensor. The system provides visual feedback via RGB LEDs and audible alerts using a buzzer to indicate the current state of the heater: Idle, Heating, Stabilizing, Target Reached, or Overheat.

## Features

- **Temperature Monitoring:** Reads temperature from an NTC thermistor.
- **Heater Control:** Automatically turns the heater ON/OFF based on temperature thresholds.
- **LED Indicators:** RGB LED displays system state (Idle, Heating, Stabilizing, Target Reached, Overheat).
- **Buzzer Alerts:** Sounds an alarm when overheating is detected.
- **Serial Output:** Displays temperature, system state, and heater status in the Serial Monitor.

## Hardware Requirements

- Arduino board (Uno, Nano, etc.)
- NTC thermistor (connected to analog pin A0)
- Heating element (connected to digital pin 10 via relay or transistor)
- RGB LED (connected to digital pins 8, 7, 6)
- Buzzer (connected to digital pin 9)
- Resistors as needed for LEDs and thermistor
- Breadboard and jumper wires

## Pin Configuration

| Component      | Arduino Pin |
|----------------|-------------|
| Red LED        | 8           |
| Green LED      | 7           |
| Blue LED       | 6           |
| Buzzer         | 9           |
| Heater         | 10          |
| NTC Thermistor | A0          |

## System States

- **Idle:** Temperature below 25°C. Heater OFF, LEDs OFF, buzzer OFF.
- **Heating:** Temperature between 25°C and 45°C. Heater ON, green LED ON, buzzer OFF.
- **Stabilizing:** Temperature between 45°C and 48°C. Heater ON, green LED ON, buzzer OFF.
- **Target Reached:** Temperature between 48°C and 50°C. Heater OFF, blue LED ON, buzzer OFF.
- **Overheat:** Temperature above 50°C. Heater OFF, red LED ON, buzzer ON.

## Usage

1. Connect all hardware components as per the pin configuration.
2. Upload `Heater_Control_System.ino` to your Arduino board.
3. Open the Serial Monitor at 9600 baud to view system status.
4. The system will automatically control the heater and provide feedback via LEDs and buzzer.

## Customization

- Adjust the temperature thresholds in the code to suit your application.
- Modify the `map()` function for accurate temperature readings based on your thermistor's characteristics.

## License

This project is provided for educational purposes. Please check hardware datasheets and safety guidelines before use.

## Author

Developed by Hemanth Kumar.