# embedded-development-for-EBD
This repository consists of embedded code built for Atmega328p using embedded C. The system is a very simplified Electronic Brake Force Distribution.

# What is the model
The system is a very simple Electronic Brake Force Distribution System. The system monitors the wheel loads using the built-in ADC module. And corresponding to the wheel loads, adjust the brake force at a particular wheel. To model the brake force distribution, built in PWM modules have been used. Higher the duty cycle at a PWM channel, higher is the quantity of brake fluid being pumped into the wheel cylinder.

The system consists of a yaw rate sensor that can be used to model the car turning left or right. If the car is turned right, the wheel loads on the left wheels (outer wheels) will increase. The simulation video shows that the the duty cycle for the left wheels increase. The same can be shown for the right wheels as well.

There is also a Slip Ratio Potentiometer to indicate the wheel slip ratio at a particualar time. Since having a very high slip ratio close to 1 is not desirable, as the slip value becomes high, the EBD stops working. This is because, at conditions close to wheel lock, the ABS system needs to take over. The EBD resumes operation when the slip values are not to high.

The whole operation is controlled by the brake pedal and the EBD system shall not turn on without the application of the brake pedal. In the simulation video, the pressing of the brake pedal has been modelled by closing a switch.

# Contents of the repository
There are 3 main folders.

1. SRC folder - contains the source code i.e. '.c' and '.h' files
2. Driver folder - contains the driver code for the peripherals i.e. '.c' and '.h' files
3. Main Project Folder - contains all the files and the codeblocks project. a '.simu' file is also included for the simulation. Need simulIDE software to perform the simulation
4. A report has been added along with the code explaining the requirements and software architecture.
5. Video file has also been included demonstrating the simulation's working, in case simulIDE is not available with a userhttps://www.youtube.com/watch?v=BuHlaRQ9g5s&t=8s
Link: https://www.youtube.com/watch?v=BuHlaRQ9g5s&t=8s

