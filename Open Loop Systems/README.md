# Lab 6: Open Loop Systems

## Fan Control
The fan was controlled by manipulating the fan's supply voltage rather than using PWM. The PWM output from the microprocessor was sent through the negative voltage wire of the fan while the positive voltage remained fixed at 12 V. As the PWM rose or fell, the voltage supplied across the van changed accordingly and allowed for effective control of the fan speed as the temperature changed. 

## Temperature Reading
Voltage readings were taken directly from the output pin of the LM35 temperature sensor and displayed on the DMM. The voltages were then converted to celcius temperatures by multiplying the voltage by 100. This was done in real time in order to get accurate temperature readings. 

## System Modeling
To model the system, the voltage regulator was first allowed to heat to approximately 71 degrees celcius. The fan was then turned on 100% PWM and the system was allowed to cool to its lowest temperature of 36.6 degrees celcius. From there, the PWM of the fan was lowered by 10% in continuous increments until the voltage regulator once more reached 71 degrees celcius. The data used to model the system is shown below in table form including the values used for the CCR0 and CCR1 timer registers. 

            ![openlooptable](https://user-images.githubusercontent.com/31484781/33510704-5d5cc100-d6dd-11e7-8b1d-72c537166e94.JPG)

## Open Loop Control System
From the data in the table above, an algorithm was developed to determine the proper PWM of the system given a specific temperature at which to set the system. The equation used is shown in the following image.

            ![pwm vs temperature](https://user-images.githubusercontent.com/31484781/33510880-af21f97c-d6df-11e7-9fb8-4d2419b15790.JPG)

The code to control the system is simplistic in design. The desired temperature is assigned to the variable temp. The variable temp is then substituted into the equation above in place of x. The function is then modified to convert the PWM value (a sample answer to the equation as is would be 30) to a duty cycle value that would be a percentage of 25000. Since the value of temp remains constant once the program begins to run, TA0CCR1 will be fixed at the same duty cycle for the amount of time the program is running. It is unlikely therefore that the temperature would remain fixed at the desired temperature. Instead, a user would have to manually adjust the variable temp to maintain a consistent temperature. 
