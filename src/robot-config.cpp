#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor frontLeft = motor(PORT8, ratio18_1, false);
motor backLeft = motor(PORT9, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(frontLeft, backLeft);
motor frontRight = motor(PORT7, ratio18_1, true);
motor backRight = motor(PORT10, ratio18_1, true);
motor_group RightDriveSmart = motor_group(frontRight, backRight);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 317.5, 190.5, mm, 1);

//intake motor
motor intake = motor(PORT6, ratio18_1, false);

//flywheel motor
motor flywheel = motor(PORT18, ratio6_1, false);

//spanker motor
motor spanker = motor(PORT4, ratio18_1, false);

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
      
      int forward = Controller1.Axis3.position(vex::percent);
      int sideways = Controller1.Axis4.position(vex::percent);
      int turn = Controller1.Axis1.position(vex::percent);
      /*
      rightMotorA.spin(vex::forward, forward - sideways + turn, vex::percent);
      leftMotorA.spin(vex::forward, forward + sideways - turn, vex::percent);
      rightMotorB.spin(vex::forward, forward + sideways + turn, vex::percent);
      leftMotorB.spin(vex::forward, forward - sideways - turn, vex::percent);*/
      int x = Controller1.Axis4.position(vex::percent);
      int y = Controller1.Axis3.position(vex::percent);
      int r = Controller1.Axis1.position(vex::percent);
      
      frontRight.spin(vex::forward, forward + sideways + turn, vex::percent);
      frontLeft.spin(vex::forward,  forward - sideways - turn, vex::percent);
      backRight.spin(vex::forward,  forward - sideways + turn, vex::percent);
      backLeft.spin(vex::forward,   forward + sideways - turn, vex::percent);

    }
    // wait before repeating the process
    wait(5, msec);
  }
  return 0;
}

void printBrainInfo(){
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}