using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor frontLeft;
extern motor frontRight;
extern motor backLeft;
extern motor backRight;
extern controller Controller1;
extern drivetrain Drivetrain;
extern motor intake;
extern motor flywheel;
extern motor spanker;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );