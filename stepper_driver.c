/*
    Code by : Projects_learner
    Project name : Stepper Motor Control with Acceleration using Ardino UNO
    Modified Date : 08-06-2024
    Website : https://projectslearner.com/learn/arduino-uno-stepper-driver-module
*/

#include <AccelStepper.h>

// Define pin connections
const int dirPin = 2;
const int stepPin = 3;

// Define motor interface type
#define motorInterfaceType 1

// Creates an instance
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
  // Set the maximum speed and acceleration
  myStepper.setMaxSpeed(1000); // Maximum speed in steps per second
  myStepper.setAcceleration(500); // Acceleration in steps per second per second

  // Set initial speed and target position
  myStepper.setSpeed(200); // Initial speed in steps per second
  myStepper.moveTo(200); // Target position

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Display speed, acceleration, and target position in the serial monitor
  Serial.print("Speed: ");
  Serial.print(myStepper.speed());
  Serial.print(" steps/s, Acceleration: ");
  Serial.print(myStepper.acceleration());
  Serial.print(" steps/s^2, Target Position: ");
  Serial.println(myStepper.targetPosition());

  // If the motor reaches the target position, change direction
  if (myStepper.distanceToGo() == 0) 
    myStepper.moveTo(-myStepper.currentPosition());

  // Move the motor one step
  myStepper.run();
}
