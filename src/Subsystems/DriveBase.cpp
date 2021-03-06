/* Drive Base subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Subsystem's got two empty halves of coconut and is bangin' 'em together.
 */

#include "DriveBase.h"
#include "../RobotMap.h"
#include <Commands/XboxMove.h>

const double DPPLeft		= (-1/6.318); //919.636		//TODO Must tune left? this
const double DPPRight		= (1/6.318); //914.618
const float GyroScalar		= 10; 		//Preliminarily tuned
const float GyroLinearAdj	= -0.696; 	//Adjusts for Gyro Creep = m
const float GyroOffset		= -6.1395;	// = b
float initialGyro			= 0;

const double AutoDriveSpeed	= 0.5;
const double AutoTurnSpeed	= 0.95;
const float DefaultTurnPrecision = 0.5;
const double AngleThreshold	= 2; 		//Turn angle in degrees //TODO Must tune this
const double AutoDistThresh	= 2; 		//Distance threshold in inches //TODO Must tune this

//Offset for drive motors when driving autonomously
const float kPLeft = .835;	//For going forwards
const float kPRight = .9; //For going backwards

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
 	DS_ForDriveBase -> GetInstance();
 	TimeCount = new Timer();
 	TimeCount -> Reset();
 	MainGyro  -> Reset();
 	AutoTurnPrecision = DefaultTurnPrecision;
 //	LeftEnc -> Reset();Doesn't work when enabling and disabling
 //	RightEnc -> Reset();
 	
 	//kP = 0;			//Uncomment for getting value from dashboard
 	//SmartDashboard::PutNumber("kP Value", kP);

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

  //kP = SmartDashboard::GetNumber("kP Value", kP); //Uncomment for getting value from dashboard

  LeftDrive1 	-> Set(LeftDriveDesired); //passes desired state to speed controllers
  LeftDrive2	-> Set(LeftDriveDesired);
  RightDrive1 	-> Set(-1 * RightDriveDesired);
  RightDrive2	-> Set(-1 * RightDriveDesired);

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
  	LeftDrive1	-> Set(0);
  	LeftDrive2	-> Set(0);
  	RightDrive1	-> Set(0);
  	RightDrive2	-> Set(0);

  	TimeCount -> Reset();
  	MainGyro  -> Reset();
  	LeftEnc	  -> Reset();
  	RightEnc  -> Reset();

  }
  //New stuff
  //A function to use the encoders in driving, the robot will drive in a certain direction depending on the distance left to travel
void DriveBase::AutoDriveDistance(float DesiredDistance){
//	SmartDashboard::GetNumber("Distance for Encoder Drive", DashAutoDistance); //Remove this and 2 lines below once we calibrate, this is just to do it from the dashboard for various distances without recompiling over and over
//	DesiredDistance = DashAutoDistance;

	EncoderReset();
	MainGyro -> Reset();

	float DistanceTraveled = 0;
	if (fabs(DesiredDistance) <= AutoDistThresh){
		std::cout << "DesiredDistance to small!!!\n";
	} else {
		while ((DesiredDistance > 0) ? (DistanceTraveled < fabs(DesiredDistance) - AutoDistThresh) : (DistanceTraveled > AutoDistThresh - fabs(DesiredDistance))){
			if (DesiredDistance > 0){ //DesiredDistance is positive, go forward
				Drive(AutoDriveSpeed * kPLeft, AutoDriveSpeed);
			} else if (DesiredDistance < 0){ //DesiredDistance is negative, go backward
				Drive(-AutoDriveSpeed, -AutoDriveSpeed * kPRight);//There is no kp value here because the kp value makes the robot run curved when going backwards
			} else { //error or exactly 0
				std::cout << "AutoDriveDistance Error!!!\n";
				break;
			}
		DistanceTraveled = (RightEnc -> GetDistance());//XXX TODO re-add leftenc for competition robot
		}
	}
	Stop();
}

  void DriveBase::EncoderReset(){
	  LeftEnc -> Reset();
	  RightEnc -> Reset();

	  //Might not be needed
	  LeftEnc 	-> SetDistancePerPulse(DPPLeft);
	  RightEnc 	-> SetDistancePerPulse(DPPRight);
  }

float DriveBase::AutoTurnToAngle(float DesiredAngle)//Turns to an absolute angle based on encoder calibration
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
}

float DriveBase::AutoTurnAngle(float DesiredTurnAngle, float TurnPrecision)	//Turns a number of degrees relative to current position
{
	AutoTurnPrecision = TurnPrecision;
	//Not using ReportGyro as it possibly doesn't work; if this code works, try ReportGyro()
	float CurrentAngle = 0;
	float InitAngle = MainGyro -> GetAngle();

	if (fabs(DesiredTurnAngle) <= AngleThreshold){
		std::cout << "DesiredTurnAngle too small!!!\n";
	} else {
		// @REVIEW NJL: Recommend (1) Break out separate if statement instead of ?: in while.  (2) Use parentheses instead of relying on operator precedence.  These make the code easier to read.
		// @REVIEW NJL: This is called from AutoLaunch::Execute.  Execute must return quickly, so a loop that takes time is not appropriate here.
		while ((DesiredTurnAngle > 0) ? (CurrentAngle < fabs(DesiredTurnAngle) - AngleThreshold) : (CurrentAngle > AngleThreshold - fabs(DesiredTurnAngle))){
			if (DesiredTurnAngle > 0){
				Drive(AutoTurnSpeed * AutoTurnPrecision, -AutoTurnSpeed * AutoTurnPrecision);
			} else if (DesiredTurnAngle < 0) {
				Drive(-AutoTurnSpeed * AutoTurnPrecision, AutoTurnSpeed * AutoTurnPrecision);
			} else { //error or exactly 0
				std::cout << "AutoTurnAngle Error!!!\n";
				break;
			}
		CurrentAngle = MainGyro -> GetAngle() - InitAngle;
		}
	}

	Stop(); //Stop motors for autonomous
	return (0); //not sure what return does
}

float DriveBase::ReportGyro()
{
  	float Angle = (GyroScalar * MainGyro	->	GetAngle());
   	double Time = TimeCount -> Get();
   	float AdjAngle = Angle - (GyroLinearAdj * Time + GyroOffset);//Compensates for gyro creep - basically subtracts out mx+b the linear creep function
  	return AdjAngle;
}
