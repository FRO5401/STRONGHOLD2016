#ifndef DriveBase_H
#define DriveBase_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveBase: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	//Declares the parts of the robot necessary for this subsystem
	Victor *LeftDrive;//Variable for left set of motors, this set contains 3 motors
	Victor *RightDrive;//Variable for right set of motors, this set contains 3 motors
	DoubleSolenoid* LeftShift;
	DoubleSolenoid* RightShift;

	//New Stuff
	Encoder *LeftEnc;
	Encoder *RightEnc;

	DriveBase();
	void InitDefaultCommand();
	//Drive has changed
	void Drive(double, double, double);//Function used to drive
	void ShiftLow();
	void ShiftHigh();
	void Stop();//Function used to stop the robot, no parameters necessary
	void Reset();
	//New stuff
	void EncoderDrive(double);
	void EncoderReset();
};

#endif
