#ifndef DriveBase_H
#define DriveBase_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveBase: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	float GyroScalar;
	float DashAutoDistance;
	float kP;

public:
	//Declares the parts of the robot necessary for this subsystem
	Victor *LeftDrive1;//Variable for left set of motors, this set contains 3 motors
	Victor *LeftDrive2;
	Victor *RightDrive1;//Variable for right set of motors, this set contains 3 motors
	Victor *RightDrive2;
//	DoubleSolenoid* LeftShift;
//	DoubleSolenoid* RightShift;
	ADXRS450_Gyro*	MainGyro;

	//New Stuff
	Encoder *LeftEnc;
	Encoder *RightEnc;

	//Timer
	Timer *TimeCount;

	DriverStation *DS_ForDriveBase;
	DriveBase();
	void InitDefaultCommand();
	//Drive has changed
	void Drive(double, double);//Function used to drive
	void ShiftLow();
	void ShiftHigh();
	void Stop();//Function used to stop the robot, no parameters necessary
	void Reset();
	void AutoDriveDistance(float);
	float AutoTurnToAngle(float);//Turns to an absolute angle based on encoder calibration
	float AutoTurnAngle(float);	//Turns a number of degrees relative to current position
	void EncoderReset();
	float ReportGyro();
};

#endif
