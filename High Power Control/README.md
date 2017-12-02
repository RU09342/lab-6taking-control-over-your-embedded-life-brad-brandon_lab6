# Lab 6: "High Power" Control

The MSP430 Devices safely run off of 3.3V. Higher voltages can damage the microprocessor, but they are sometimees required for other components of a circuit. The question is how can a MSP430 microprocessor be used to drive something that requires a high voltage or a higher current, while protecting the device. A solution to this lies with switching. 

## Switching

This lab looks at two types of switching:
1. Relays
2. MOSFET Switching

### Relays

A relay is an electro-mechanical system which can open and close a switch depending on its input. The way this works is by a magnetic is by supplying a voltage through a coil in the relay, producing a magnetic field that causes the switch to change to open. When the voltage is turned off through the coil, the field is weakened and the switch changes to closed. For this lab a relay is used to drive a 100 ohm power resistor with 12V from the function generator. Using the G2553 to control the gate of an NMOS is how the user can control the state of the relay, whether it is open or closed. 

A schematic of the relay circuit can be seen below:
![relayschematic](https://user-images.githubusercontent.com/31701000/33510010-179d41e2-d6d5-11e7-943e-1b9d66e985ff.png)


A picture of the circuit constructed on a breadboard can be seen here:

![20171120_222229](https://user-images.githubusercontent.com/31701000/33510005-01d9d550-d6d5-11e7-9e20-9374e115bff2.jpg)

When the frequency was increased, the sound of the relay switching remained audible until 330Hz.


### MOSFET Switching
The MOSFET switch is a very simple circuit which can be used in a multitude of applications. One of the most important features of the MOSFET Switch is the near zero current it takes to switch the MOSFET from an on to an off state. There are two main architectures, low-side and high-side switch, each requiring a different type of MOSFET. The first circuit tested in the lab was the low-side switch. When the input voltage from the microcontroller was high, the output of the low-side switch was low. This can be seen from the schematic and simulation below. As the voltage rises from 0 to 5 V on the input, the output decreases linearly. 

![lss](https://user-images.githubusercontent.com/31484781/33511171-3ccb527e-d6e4-11e7-972e-266b95c37500.JPG)

![sim1](https://user-images.githubusercontent.com/31484781/33511172-410a5862-d6e4-11e7-8e95-0dfe54b5ff24.JPG)

The exact opposite effect was observed in the high-side switch when it was tested. The Mosfet switching speed was very limited compared to that of the relay. At a frequency of just 1.5Hz, the switch was unable to keep up and the output of the circuit began to hang at a high output or low output for extended periods of time. 

## Limiting Current Draw
To help lesson the current, an additional resistor can be applied in series with the Power Resistor.
