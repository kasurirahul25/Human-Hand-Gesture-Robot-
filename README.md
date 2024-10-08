# Hand Gesture Controlled Toy Car

This project involves the development of a hand gesture-controlled toy car using an Arduino and various components. The car can move forward, backward, left, and right based on hand movements detected by an MPU6050 sensor. The communication between the transmitter (hand gesture controller) and the receiver (toy car) is established using the nRF24L01 wireless module.

## Table of Contents
- [Overview](#overview)
- [Functionality](#functionality)
- [Hardware Components](#hardware-components)
- [Code Structure](#code-structure)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Overview

The hand gesture-controlled toy car uses an MPU6050 sensor to detect hand movements and an nRF24L01 module for wireless communication. The transmitter reads the acceleration values from the MPU6050 to determine the direction and speed of the car, while the receiver interprets these signals to control the motors accordingly.

## Functionality

- **Forward Movement**: The car moves forward when the hand is tilted forward.
- **Backward Movement**: The car moves backward when the hand is tilted backward.
- **Left Turn**: The car turns left when the hand is tilted to the left.
- **Right Turn**: The car turns right when the hand is tilted to the right.
- **Speed Control**: The speed of the car can be adjusted based on the degree of tilt.

## Hardware Components

1. **Arduino Uno**: The microcontroller used for the project.
2. **nRF24L01 Module**: For wireless communication between the transmitter and receiver.
3. **MPU6050 Sensor**: To detect hand movements (accelerometer and gyroscope).
4. **DC Motors**: For driving the wheels of the toy car.
5. **Motor Driver (L298N)**: To control the direction and speed of the motors.
6. **Power Supply**: Battery or other suitable power source for the motors and Arduino.
7. **Jumper Wires**: For connecting components.

## Code Structure

### Transmitter Code
The transmitter code reads the values from the MPU6050 sensor and sends them to the receiver using the nRF24L01 module. 

```cpp
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "Wire.h"
#include "MPU6050.h"

// Hardware configuration
RF24 radio(CE_GPIO, CSN_GPIO);                           
MPU6050 accelgyro;

// Variables for sensor data
int16_t ax, ay, az; 
int16_t gx, gy, gz;

const byte Address[6] = "00001";
int Pot_Val_Y = 0, Pot_Val_X = 0;
unsigned char Tx_command = 0, Speed_index = 0;

void setup() {
  Serial.begin(115200);
  // Initialize components
}

void loop() {
  // Read sensor data and send to receiver
}
