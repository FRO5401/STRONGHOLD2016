#ifndef Drivebase_H
#define Drivebase_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drivebase: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	//Declares the parts of the robot necessary for this subsystem
	Victor *LeftDrive;//Variable for left set of motors, this set contains 3 motors
	Victor *RightDrive;//Variable for right set of motors, this set contains 3 motors
	Encoder *RightEncoder;
	Encoder *LeftEncoder

	Drivebase();
	void InitDefaultCommand();
	void Drive(double, double, double, double);//Function used to drive, parameters unknown
	void Stop();//Function used to stop the robot, no parameters necessary
	void Reset();
};

#endif
