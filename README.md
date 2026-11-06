# Ultrasonic Parking Assistance System

I built this project to try out the basic idea behind a parking proximity warning: measure how close an object is, then give an audible alert.

An Arduino takes readings from an HC-SR04 ultrasonic sensor and controls a buzzer based on the measured distance. The setup is built on a breadboard as a learning prototype.

## How it works

1. The sensor sends out an ultrasonic pulse.
2. The Arduino measures how long the echo takes to return and uses that time to estimate the distance.
3. The program uses the distance reading to control the buzzer.

## Components

- Arduino board
- HC-SR04 ultrasonic sensor
- Buzzer and resistor
- Breadboard and jumper wires
- USB cable for programming and power

## Demo and photos

[Watch the parking assistance demo](parking-assistance-demo.mp4)

The photos in this repository show the full setup and close-ups of the wiring.

## Running the project

1. Use the pin assignments in the Arduino sketch to connect the sensor and buzzer.
2. Open the included `.ino` file in the Arduino IDE.
3. Connect the Arduino to your computer, select the correct board and port, and upload the sketch.
4. Move an object toward and away from the sensor to test the buzzer's response.

## What I practiced

This project gave me practice with reading a sensor, working with digital inputs and outputs, and using distance measurements to control an audible warning. Building the circuit also helped me connect what the code was doing with what I could see and hear from the hardware.

