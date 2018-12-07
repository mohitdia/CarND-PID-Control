# CarND-PID-Control
PID controller project implementation

## Reflection

### Implementation

This project's goal was to implement the PID controller so the car in the simulator drives within the track.

The PID controller has been implemented by modifying the following files:
  - PID.h
  - PID.cpp
  - main.cpp

I started by implementing the Init method by initializing the error variables and the three coefficients(Kp, Ki, Kd).
Then I completed the UpdateError method which updates all three errors for the components and also finds the min and max error.
The TotalError method just returns the error for each component by weighting the error with the coefficient and summing the individual errors up.

### Effect of each of P,I and components and choice of hyperparameters

I tried tuning the hyperparameters to see their effect on the drive:

1. P only - When I only provided P coefficient to the Init method the car started oscillating after the first few seconds. The screenshots from that are provided under images/Screen Shot_only_P.png and images/Screen Shot_only_P2.png

2. I only - When I only provided P coefficient to the Init method the car started going in circles and getting stuck on the pavement. I think the effect of the I coefficient on the car is very minimal because there seems to be no systematic bias in the simulator.  The screenshots from that are provided under images/Screen Shot_only_I.png and images/Screen Shot_only_I2.png

3. D only - When I only provided  the differential D coefficient to the Init method the car the car drove straight for the first 3-4 seconds but then drove off into pavement and continued driving on the pavement. The screenshots from that are provided under images/Screen Shot_only_D.png, images/Screen Shot_only_D2.png and images/Screen Shot_only_D3.png

4. I tried changing the P value from 1 to 1.5 to 2.5 etc but found that it was causing a lot of oscillation. 
   I tried to increase the D coefficient also but the oscillation was not reducing but getting delayed in the track.
   I finally decided to lower the P value from 1 to see the effect and at around 0.4 I saw the effect of oscillation reducing and the car not going off track.
   I further lowered P to 0.3 to reduce the effect of oscillation and increased D to 2.5 to stabilize. That combination was enough to let the car drive on the track throughout the course.
After a few trial and errors I came up with the following parameters:
  - P: 0.3
  - I: 0.0 // As there is no bias in the simulator I set it to 0.
  - D: 2.5

### Simulation

With the parameters tuned the car was able to drive the track without going off.
Screenshots are images/Screen Shot_perfect_drive.png, images/Screen Shot_perfect_drive_2.png to images/Screen Shot_perfect_drive_5.png

*Note*: I could not record video of the different parameter combinations as the recording in the simulator wasn't working.