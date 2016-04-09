/* Drive Base subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Subsystem's got two empty halves of coconut and is bangin' 'em together.
 */

#include "DriveBase.h"
#include "../RobotMap.h"
#include <Commands/XboxMove.h>

const float GyroScalar		= 10; 		//Preliminarily tuned
const float GyroLinearAdj	= 0;//-0.696; 	//Adjusts for Gyro Creep = m //XXX Zeroed out as gyro creep is not present
const float GyroOffset		= 0;//-6.1395;	// = b //XXX Zeroed out as gyro creep is not present
float initialGyro			= 0;

const double AutoDriveSpeed	= 0.5;
const float DefaultTurnPrecision = 0.5;

DriveBase::DriveBase() :
		Subsystem("DriveBase")
{
	LeftDrive1 	= new Victor(LeftMotor1);
	LeftDrive2	= new Victor(LeftMotor2);
	RightDrive1	= new Victor(RightMotor1);
	RightDrive2	= new Victor(RightMotor2);
//	LeftShift 	= new DoubleSolenoid(SolenoidCAN_ID, Shift_LeftFwd, Shift_LeftRev); //Gear shifting is OUT of design
//	RightShift 	= new DoubleSolenoid(SolenoidCAN_ID, Shift_RightFwd, Shift_RightRev);

	//Sensors
	LeftEnc		= new Encoder(Enc_Left_A,Enc_Left_B, true, Encoder::k1X);
	RightEnc	= new Encoder(Enc_Right_A,Enc_Right_B,true,Encoder::k1X);
	//Displays the Distance for Encoder Drive for user input
	double DashAutoDistance = 0;//Remove or comment this and below it, this is for calibrating the auto drive
	SmartDashboard::PutNumber("Distance for Encoder Drive", DashAutoDistance);
	SmartDashboard::PutNumber("Initial Gyro Value", initialGyro);

	MainGyro	= new ADXRS450_Gyro();
 //	DS_ForDriveBase -> GetInstance();
 	TimeCount = new Timer();
 	TimeCount -> Reset();
 	MainGyro  -> Reset();
 //	LeftEnc -> Reset();Doesn't work when enabling and disabling
 //	RightEnc -> Reset();
 	
 	//Offset for drive motors when driving autonomously
 	kP_Right = .9;			//Uncomment for getting value from dashboard
 	kP_Left = .835;
 	DPPRight = (1/6.318);
 	DPPLeft = (-1/6.318);
 	SmartDashboard::PutNumber("kP Backwards Value", kP_Right);
 	SmartDashboard::PutNumber("kP Forwards Value", kP_Left);
 	SmartDashboard::PutNumber("DPPRight", DPPRight);
 	SmartDashboard::PutNumber("DPPLeft", DPPLeft);

}

void DriveBase::InitDefaultCommand()
{
	SetDefaultCommand(new XboxMove());
	LeftEnc	  -> Reset();
	RightEnc  -> Reset();
	//MainGyro  -> Calibrate();
	MainGyro  -> Reset();
	TimeCount -> Start();
}

void DriveBase::Drive(double LeftDriveDesired, double RightDriveDesired)
  {

  LeftDrive1 	-> Set(-1 * LeftDriveDesired); //passes desired state to speed controllers
  LeftDrive2	-> Set(-1 * LeftDriveDesired);
  RightDrive1 	-> Set(RightDriveDesired);
  RightDrive2	-> Set(RightDriveDesired);

  //New stuff
  //Sets the ratio for pulses to inches
  LeftEnc 	-> SetDistancePerPulse(DPPLeft);
  RightEnc 	-> SetDistancePerPulse(DPPRight);

  //Displays certain values in the encoder onto the SmartDashboard
  SmartDashboard::PutNumber("Left Encoder Raw Count Value", 	LeftEnc 	-> Get());
  SmartDashboard::PutNumber("Right Encoder Raw Count Value", 	RightEnc 	-> Get());
  SmartDashboard::PutNumber("Left Encoder Distance Traveled", 	LeftEnc 	-> GetDistance());
  SmartDashboard::PutNumber("Right Encoder Distance Traveled", 	RightEnc 	-> GetDistance());

  SmartDashboard::GetNumber("Initial Gyro Value", initialGyro);
  //SmartDashboard::PutNumber("Gyro Angle", ReportGyro());	//doesn't work for some reason
  SmartDashboard::PutNumber("Gyro GetAngle", MainGyro -> GetAngle());
  SmartDashboard::PutNumber("Gyro ReportGyro", ReportGyro());
  }
/*
 * Pneumatic shfting is out of design at this point
void DriveBase::ShiftLow()
{
	LeftShift  ->	Set(DoubleSolenoid::Value::kForward);
	RightShift ->	Set(DoubleSolenoid::Value::kForward);
}

void DriveBase::ShiftHigh()
{
	LeftShift  ->	Set(DoubleSolenoid::Value::kReverse);
	RightShift ->	Set(DoubleSolenoid::Value::kReverse);
}
*/
void DriveBase::Stop()
{

  LeftDrive1	-> Set(0);
  LeftDrive2	-> Set(0);
  RightDrive1	-> Set(0);
  RightDrive2	-> Set(0);
//  TimeCount 	-> Stop();

}

void DriveBase::Reset()
{
  	Stop();

  	TimeCount -> Reset();
  	MainGyro  -> Reset();
  	LeftEnc	  -> Reset();
  	RightEnc  -> Reset();
}

void DriveBase::EncoderReset(){
	LeftEnc -> Reset();
	RightEnc -> Reset();

	//Might not be needed
	LeftEnc 	-> SetDistancePerPulse(DPPLeft);
	RightEnc 	-> SetDistancePerPulse(DPPRight);
}

//No longer being used, but kept as may be needed in the future
/*float DriveBase::AutoTurnToAngle(float DesiredAngle)//Turns to an absolute angle based on encoder calibration
{
	float RawErr = (DesiredAngle - ReportGyro());
	float AbsErr = fabs(RawErr);
	if (AbsErr > 180) {
		AbsErr = 360 - AbsErr; //This determines the shortest distance between the angles
	}
if ((RawErr >= 0 && RawErr <=180) || (RawErr >= -360 && RawErr <= -180)) {//Determines sign of angle difference
	return AutoTurnAngle(AbsErr, DefaultTurnPrecision); //AutoTurnAngle returns the final angle difference, then this returns that return
	} else {
		return AutoTurnAngle(-AbsErr, DefaultTurnPrecision);
		}
}*/

float DriveBase::ReportGyro()
{
	//This adjusts for gyro creep which is current nonexistant
 /*	float Angle = (GyroScalar * MainGyro	->	GetAngle());
   	double Time = TimeCount -> Get();
   	float AdjAngle = Angle - (GyroLinearAdj * Time + GyroOffset);//Compensates for gyro creep - basically subtracts out mx+b the linear creep function
  	return AdjAngle;
*/
	return MainGyro -> GetAngle();
}

float DriveBase::GetEncoderDistance(){
	return ((RightEnc -> GetDistance()));// + LeftEnc -> GetDistance())/2);
}
