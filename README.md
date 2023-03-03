# Bmob Squad
Code for team 11551A for the 2022-23 VRC Game Spin Up.
Repository public as the season is ending soon. Will be archived in the future.
Contact Dairy#6166 on Discord if you have questions.

Code created mostly in VS Code with the [Vex Robotics extention](https://www.vexrobotics.com/vexcode/vscode-extension "Vex Robotics extention"). [VEXCode Pro V5](https://www.vexrobotics.com/vexcode/pro-v5 "VEXCode Pro V5") was used to generate the competition template. The project uses the [V5 API](https://api.vexcode.cloud/v5/ "V5 API"). 

## Quickstart - Load onto V5 Brain
By default, the program loads itself into slot 2 on the brain, overwriting any project there if one should exist.
### Vexcode Pro V5
Use Ctrl + O (⌘ + O for MacOS) to open a project, and select the v5code file.

With either the V5 Controller or the V5 Brain connected to your device, select the download button on the top right.
### VS Code
With the VEX extension installed (see above), connect either a V5 Controller or V5 Brain and select the download button on the bottom left. You will have to open the project with the "Import Project" option in the VEX extension tab.

# Checklists
## Standard Operation
- Ensure all wire connectors illuminate with a solid red light.
- Ensure that the mecanum-style drivetrain works properly. 
	* Axis 3 should control forward and backwards motion 
	* Axis 4 should allow for strafing
	* Axis 1 should rotate the robot in place
- Ensure there are no loose components or structure
- Ensure cables and wires are not placed in a way that would pose a risk of entanglement or damage.

## Troubleshooting
- Ensure wires are configured correctly as per `src/robot-config.cpp`
- Ensure all wire connectors illuminate solid red.
- Verify the connection between the robot brain and the controller.
- Check if motors are overheating.
- Check if motors are jammed.
- Restart the program, the controller, and/or the brain.
** If the robot performs sudden, unexpected movements or any other action that could potentially be hazardous, terminate the program immediately by pressing and holding the square power button in the middle of the controller. **
