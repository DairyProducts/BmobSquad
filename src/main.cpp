#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

bool intakeActive = false;
bool flywheelActive = false;
bool spankerActive = false;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void toggleFlywheel(void) {
  if (flywheelActive) {
    flywheelActive = false;
    flywheel.stop(brakeType::coast);
  } else {
    flywheelActive = true;
    flywheel.setVelocity(1000, rpm);
    flywheel.spin(reverse);
  }
}

void toggleSpanker(void) {
  if (spankerActive) {
    spankerActive = false;
    spanker.spinToPosition(0, degrees);
  } else {
    spankerActive = true;
    spanker.setVelocity(100, percent);
    spanker.spinToPosition(90, degrees);
  }
}

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
/*
  toggleFlywheel();
  wait (5, seconds);
  toggleSpanker();
  wait (1, seconds);
  toggleSpanker();
  toggleFlywheel();
  */
  frontLeft.spin(vex::forward, 100, vex::percent);
  frontRight.spin(forward);
  // Drivetrain.driveFor(forward, 12, inches);
  intake.setVelocity(100, percent);
  intake.spinFor(forward, 180, degrees);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void toggleIntake(void) {
  if (intakeActive) {
    intakeActive = false;
    intake.stop(brakeType::coast);
  } else {
    intakeActive = true;
    intake.setVelocity(100, percent);
    intake.spin(forward);
  }
}




void usercontrol(void) {
  // User control code here, inside the loop

  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    Controller1.ButtonX.pressed(toggleIntake);
    Controller1.ButtonB.pressed(toggleFlywheel);
    Controller1.ButtonY.pressed(toggleSpanker);
    if (Controller1.ButtonR1.pressing()){
      intake.setVelocity(100, percent);
      intake.spin(forward);
    }
    else if (!Controller1.ButtonR2.pressing()){
      intake.stop(brakeType::coast);
    }
    if (Controller1.ButtonR2.pressing()){
      intake.setVelocity(100, percent);
      intake.spin(reverse);
    }
    else if (!Controller1.ButtonR1.pressing()){
      intake.stop(brakeType::coast);
    }
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }

}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
