# Lab 6: Precision Control
Some applications require large amounts of voltage or current, so switching techniques must be used in order to provide the desired output. Other cases however require a finer control over the voltage or current going into them (some even require a control over resistance). So far you have looked at PWM to control the brightness of an LED, is there a way to use this to output a specified voltage or current, or even a specific waveform?

## PWM Part 2
The code for this portion of the lab takes in one of several characters over UART (user's choice) and then assigns a number to CCR1 according to a certain PWM percentage. For example, if a user wanted a 20% PWM, they would send the character C over UART. The microprocessor would then send this PWM value through pin P2.0 into the circuit, which contains an LED. The LED's brightness was controlled over UART with the various characters and as this happened the voltage exiting the processor over pin P2.0 was measured. The results can be seen in the following table:

![pwm2chart](https://user-images.githubusercontent.com/31484781/33511634-2ee08a0a-d6ec-11e7-9968-c90fdaddee60.JPG)

## R2R DAC
What if your system is noise sensitive or possibly needs more precision than just a PWM signal, you might need to look into using an actual Digital-to-Analog converter. One of the simplest DAC architectures is a R2R ladder. The R2R ladder built and tested in lab is shown in the following schematic and breadboard photo. 

![schematic r2r](https://user-images.githubusercontent.com/31484781/33511585-33fef806-d6eb-11e7-9bc8-6bec8315f937.JPG)

![2017-12-01 16 21 17](https://user-images.githubusercontent.com/31484781/33511587-35c46ce8-d6eb-11e7-8625-e21fb6423e6a.jpg)

The code for this portion of the lab generates a triangle wave and sends it across each of the 8 inputs to the R2R ladder. The resulting waveform at the output of the DAC/R2R ladder from the oscilloscope is shown in the image below:

![2017-12-01 16 21 05](https://user-images.githubusercontent.com/31484781/33511583-2dca9e36-d6eb-11e7-86f6-864d7ab07d51.jpg)
