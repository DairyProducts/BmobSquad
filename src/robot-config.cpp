#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor leftMotorA = motor(PORT8, ratio18_1, false);
motor leftMotorB = motor(PORT9, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT7, ratio18_1, true);
motor rightMotorB = motor(PORT10, ratio18_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 317.5, 190.5, mm, 1);

//intake motor
motor intake = motor(PORT6, ratio18_1, false);

//flywheel motor
motor flywheel = motor(PORT5, ratio6_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3 + Axis1
      // right = Axis3 - Axis1
      int forward = Controller1.Axis3.position(vex::percent);
      int sideways = Controller1.Axis4.position(vex::percent);
      int turn = Controller1.Axis1.position(vex::percent);

      rightMotorA.spin(vex::forward, forward - sideways + turn, vex::percent);
      leftMotorA.spin(vex::forward, forward + sideways - turn, vex::percent);
      rightMotorB.spin(vex::forward, forward + sideways + turn, vex::percent);
      leftMotorB.spin(vex::forward, forward - sideways - turn, vex::percent);
      Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(0, 0);
      Controller1.Screen.newLine();
      Controller1.Screen.print("LMA ", (int)leftMotorA.velocity(rpm), " RMA ", (int)rightMotorA.velocity(rpm));
      Controller1.Screen.newLine();
      Controller1.Screen.print("LMB ", (int)leftMotorB.velocity(rpm), " RMB ", (int)rightMotorB.velocity(rpm));

      /*int drivetrainLeftSideSpeed = Controller1.Axis3.position() + Controller1.Axis1.position();
      int drivetrainRightSideSpeed = Controller1.Axis3.position() - Controller1.Axis1.position();
      
      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
          LeftDriveSmart.stop();
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller1 = true;
      }
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller1) {
          // stop the right drive motor
          RightDriveSmart.stop();
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller1 = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, percent);
        LeftDriveSmart.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        RightDriveSmart.setVelocity(drivetrainRightSideSpeed, percent);
        RightDriveSmart.spin(forward);
      }*/
    }
    // wait before repeating the process
    wait(5, msec);
  }
  return 0;
}

void printBrainInfo(){
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(0, 0);
  if (Brain.Battery.capacity(percent) < 15) Brain.Screen.setFillColor(red);
  else if (Brain.Battery.capacity(percent) < 25) Brain.Screen.setFillColor(orange);
  else Brain.Screen.setFillColor(blue);
  Brain.Screen.print("Battery: ", Brain.Battery.capacity(percent));

  if (leftMotorA.temperature(celsius) > 50) Brain.Screen.setFillColor(red);
  else if (leftMotorA.temperature(celsius) > 40) Brain.Screen.setFillColor(orange);
  else Brain.Screen.setFillColor(blue);
  Brain.Screen.print("LMA: ", leftMotorA.temperature(celsius), "C");

  if (leftMotorB.temperature(celsius) > 50) Brain.Screen.setFillColor(red);
  else if (leftMotorB.temperature(celsius) > 40) Brain.Screen.setFillColor(orange);
  else Brain.Screen.setFillColor(blue);
  Brain.Screen.print("LBA: ", leftMotorB.temperature(celsius), "C");

  if (rightMotorA.temperature(celsius) > 50) Brain.Screen.setFillColor(red);
  else if (rightMotorA.temperature(celsius) > 40) Brain.Screen.setFillColor(orange);
  else Brain.Screen.setFillColor(blue);
  Brain.Screen.print("LMA: ", rightMotorA.temperature(celsius), "C");

  if (rightMotorB.temperature(celsius) > 50) Brain.Screen.setFillColor(red);
  else if (rightMotorB.temperature(celsius) > 40) Brain.Screen.setFillColor(orange);
  else Brain.Screen.setFillColor(blue);
  Brain.Screen.print("LMA: ", rightMotorB.temperature(celsius), "C");
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}