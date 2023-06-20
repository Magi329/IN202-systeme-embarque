# Arduino Button and Dimmable LED Project

This Arduino project allows you to control the intensity and behavior of an LED using a button. The program can detect short, long, and very long presses from the button, providing different functionalities for each type of press. The LED can switch between an intensity decrease mode and an intensity increase mode, and it can also blink when a very long press is detected.

## Prerequisites

To run this project, you will need the following:

- Arduino board
- Bread board
- Button
- Dimmable LED
- Jumper wires

## Installation

1. Connect the button to the Arduino board. Ensure that the appropriate pin is used for the button connection.(in our code, pin button = 2)
2. Connect the dimmable LED to the Arduino board. Make sure to connect it to the correct pin. (in our code, pin LED = 12)
3. Upload the provided Arduino sketch (DimmableLed.ino) to your Arduino board using the Arduino IDE or your preferred method.

## Usage

1. Press the button briefly for a short click. The LED will increase or decrease its intensity based on the current mode.
2. Press and hold the button for a long click. The LED will switch between the intensity decrease mode and the intensity increase mode.
3. Press and hold the button for a very long click. The LED will start blinking for a while.

## Troubleshooting

If you encounter any issues with the project, consider the following troubleshooting steps:

- Check the connections between the Arduino board, button, and LED to ensure they are properly wired.
- Verify that the correct pins are used for the button and LED connections in the Arduino sketch.
- Make sure the Arduino board is powered on and connected to your computer.


## Acknowledgments

- Thanks a lot to professor Bruno MONSUEZ for his guidance and help.
- Thanks a lot to my partner Maryse Maugenest, it's been really nice working together.
- The Arduino community for their valuable resources and support.
