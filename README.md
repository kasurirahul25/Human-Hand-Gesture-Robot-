
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
```

### Receiver Code
The receiver code interprets the signals received from the transmitter and controls the motors accordingly.

```cpp
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 rx_data(8, 10);
const byte address[6] = "00001";

struct data {
  int Xaxis;
  int Yaxis;
};
data receive;

void setup() {
  Serial.begin(9600);
  // Initialize components
}

void loop() {
  // Read received data and control motors
}
```

## Installation

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/yourusername/hand-gesture-toy-car.git
   ```

2. Open the Arduino IDE and load both transmitter and receiver code files.

3. Ensure that the necessary libraries (`RF24`, `MPU6050`, and `Wire`) are installed via the Library Manager.

4. Connect the hardware components according to the wiring diagram provided in the repository.

5. Upload the transmitter code to the gesture controller Arduino and the receiver code to the toy car Arduino.

## Usage

1. Power on the toy car and the hand gesture controller.
2. Move your hand in the desired direction:
   - Forward: Tilt hand forward.
   - Backward: Tilt hand backward.
   - Left: Tilt hand left.
   - Right: Tilt hand right.
3. Observe the car moving according to your hand gestures.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Special thanks to the contributors of the libraries used in this project, including the RF24 and MPU6050 libraries.
