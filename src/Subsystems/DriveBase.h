#ifndef DriveBase_H
#define DriveBase_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveBase: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor *LeftDrive1;//Variable for left set of motors, this set contains 3 motors
	Victor *LeftDrive2;//Variable for left set of motors, this set contains 3 motors
	Victor *LeftDrive3;//Variable for left set of motors, this set contains 3 motors
	Victor *RightDrive1;//Variable for right set of motors, this set contains 3 motors
	Victor *RightDrive2;//Variable for right set of motors, this set contains 3 motors
	Victor *RightDrive3;//Variable for right set of motors, this set contains 3 motors

public:
	//Declares the parts of the robot necessary for this subsystem
	DoubleSolenoid* LeftShift;
	DoubleSolenoid* RightShift;

	DriveBase();
	void InitDefaultCommand();
	void Drive(double, double);//Function used to drive
	void ShiftLow();
	void ShiftHigh();
	void Stop();//Function used to stop the robot, no parameters necessary
	void Reset();
};

#endif
