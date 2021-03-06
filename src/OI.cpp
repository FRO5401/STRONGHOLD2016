#include "OI.h"
#include "RobotMap.h"
//Include all commands h files, because they will used to tell what to do when a button is pressed
//MORE MAY BE ADD, SOME MAY BE DELETED
//Updated as of 1/27/16 at 5 pm
#include "Commands/XboxMove.h"
#include "Commands/XboxMove.h"
#include "Commands/AbortReach.h"
#include "Autonomous/AutoDeliverBall.h"
#include "Commands/AutoLaunch.h"
#include "Commands/ChargeCompressor.h"
#include "Commands/DeployHook.h"
#include "Commands/DrivingWithEncoderInput.h"
#include "Commands/FeederStop.h"
#include "Commands/FeedInFromInner.h"
#include "Commands/FeedInFromOuter.h"
#include "Commands/FeedOutFromInner.h"
#include "Commands/FeedOutFromOuter.h"
#include "Commands/HookBumper.h"
#include "Commands/HookScale.h"
#include "Commands/LaunchSequence.h"
#include "Commands/LockTarget.h"
#include "Commands/PrepareToScale.h"
#include "Commands/ReachForBar.h"
#include "Commands/RetractHook.h"
#include "Commands/ShiftScaleToDrive.h"
#include "Commands/ShooterOverride.h"
#include "Commands/StopDriveForAutonomous.h"
#include "Commands/SPTShootingPosition.h"
#include "Commands/UpAndDownInfeeder.h"
#include "Commands/MoveSPTtoPosition.h"
#include "WPILib.h"

//const float SPTDeliveryPosition = 55;//-34.677 from start
//const float SPTFeederPosition = -21;//-112.146 from start

OI::OI()
{
	// Process operator interface input here.
	//AKA physical location of controllers from robot map
	//AKA physical locations of buttons too

	XboxController	= new Joystick(XboxController_Channel);
	MedalOfHonorController = new Joystick(MedalOfHonorController_Channel);

	//Gives the declared buttons a value that uses the joystick(controller) name and the port number determined
	//by drive station
	//Xbox buttons
//	JoystickButton * 	Unused1;  Commenting this out, I think this is a relic of the SimpleRobot Architecture and not needed.
						XboxA					= new JoystickButton(XboxController, 1);
						XboxB					= new JoystickButton(XboxController, 2);
						XboxX					= new JoystickButton(XboxController, 3);
						XboxY					= new JoystickButton(XboxController, 4);
						XboxUpperLeftTrig		= new JoystickButton(XboxController, 5);
						XboxUpperRightTrig		= new JoystickButton(XboxController, 6);
						XboxBack				= new JoystickButton(XboxController, 7);
						XboxStart				= new JoystickButton(XboxController, 8);
						XboxLeftStickButton		= new JoystickButton(XboxController, 9);
						XboxRightStickButton 	= new JoystickButton(XboxController, 10);
	//Medal Of Honor Controller (MOH) buttons
//	JoystickButton*		Unused2; Commenting this out, I think this is a relic of the SimpleRobot Architecture and not needed.
						MOHButtonSquare			= new JoystickButton(MedalOfHonorController, 1);
						MOHButtonX				= new JoystickButton(MedalOfHonorController, 2);
						MOHButtonCircle			= new JoystickButton(MedalOfHonorController, 3);
						MOHButtonTriangle		= new JoystickButton(MedalOfHonorController, 4);
						MOHLeftBumper			= new JoystickButton(MedalOfHonorController, 5);
						MOHRightBumper			= new JoystickButton(MedalOfHonorController, 6);
						MOHLeftTrigger			= new JoystickButton(MedalOfHonorController, 7);
						MOHRightTrigger			= new JoystickButton(MedalOfHonorController, 8);
						MOHSelectButton			= new JoystickButton(MedalOfHonorController, 9);
						MOHStartButton			= new JoystickButton(MedalOfHonorController, 10);
						MOHLeftStickButton		= new JoystickButton(MedalOfHonorController, 11);
						MOHRightStickButton		= new JoystickButton(MedalOfHonorController, 12);
						MOHHomeButton			= new JoystickButton(MedalOfHonorController, 13);

	//SPT Buttons
	//Feeder Buttons
	MOHRightTrigger	-> WhenPressed(new FeedInFromOuter());
	MOHRightTrigger	-> WhenReleased(new FeederStop());

	MOHLeftTrigger 	-> WhenPressed(new FeedOutFromOuter());
	MOHLeftTrigger 	-> WhenReleased(new FeederStop());

	MOHLeftBumper	-> WhenPressed(new FeedInFromInner());
	MOHLeftBumper	-> WhenReleased(new FeederStop());

	MOHRightBumper	-> WhenPressed(new FeedOutFromInner());
	MOHRightBumper   -> WhenReleased(new FeederStop());
	
	MOHButtonTriangle -> WhenPressed(new LockTarget());
	MOHButtonSquare   -> WhenPressed(new AutoLaunch());
	MOHStartButton	-> WhenPressed(new AutoDeliverBall(1.5));

	XboxX			-> 	 WhenPressed(new LaunchSequence());
	XboxRightStickButton -> WhenPressed(new ShooterOverride());
}

//Defines the functions for the axis's declared in the h file
double OI::ReadXboxLeftStickX()
{
	double Slew =	XboxController	-> GetRawAxis(0);
	return Slew;
}

double OI::ReadXboxRightStickY(){
	return	XboxController	->	GetRawAxis(5);
}

double OI::GetLeftTrigger()
{
	double Throttle = XboxController	->	GetRawAxis(2);
	return Throttle;
}

double OI::GetRightTrigger()
{
	double Throttle = XboxController	->	GetRawAxis(3);
	return Throttle;
}

bool OI::GetPrecision()
{
	return XboxController	->	GetRawButton(LBumper_ID);
}

bool OI::GetBrake()
{
	return XboxController	->	GetRawButton(RBumper_ID);
}

double OI::GetUpOrDownValueInfeeder(){
	double UpOrDownValue = MedalOfHonorController -> GetRawAxis(1);
	return UpOrDownValue;
}

bool OI::DummyButtonReadFunction(){
	return true;
}

double OI::DummyJoystickReadFunction(){
	return 0;
}//Define function once we figure out controller

//New stuff
bool OI::GetButtonB(){
	return XboxController	->	GetRawButton(XboxB_ID);
}

bool OI::GetButtonA(){
	return XboxController	->	GetRawButton(XboxA_ID);
}

bool OI::GetButtonX(){
	return XboxController	->	GetRawButton(XboxX_ID);
}

bool OI::GetButtonStart(){
	return XboxController	-> GetRawButton(Start_ID);
}

bool OI::GetButtonBack(){
	return XboxController	->	GetRawButton(Back_ID);
}

bool OI::GetButtonL3(){
	return XboxController	->	GetRawButton(XboxL3_ID);
}

bool OI::GetButtonR3(){
	return XboxController	->	GetRawButton(XboxR3_ID);
}

void OI::GetPOVState(){
	int POV = MedalOfHonorController	->	GetPOV();
	int state = 0;

	if (POV == 225 || POV == 180 || POV == 135){
		std::cout << "DOWN\n";
		state = -1;	//down
	}
	else if (POV == 315 || POV == 0 || POV == 45){
		std::cout << "UP\n";
		state = 1; 	//up
	}

	if (POV != 0){
		if (POV == 1){
			MoveSPTtoPosition(55.0);
		} else {
			MoveSPTtoPosition(-21.0);
		}
	}
}

void OI::SendXboxRumble(int j){
	for ( int i = 0; i < j; i++ ) {
		XboxController	->	SetRumble(Joystick::kLeftRumble, 1);
		XboxController	->	SetRumble(Joystick::kRightRumble, 1);
		Wait(2);
		XboxController	->	SetRumble(Joystick::kLeftRumble, 0);
		XboxController	->	SetRumble(Joystick::kRightRumble, 0);
		Wait(2);
	}
}

void OI::SendMOHRumble(int j){
	for ( int i = 0; i < j; i++ ) {  // @REVIEW NJL: This is called from LockTarget::Execute.  It must return promptly (<<20ms).  Delays and loops are not appropriate here.
		MedalOfHonorController	->	SetRumble(Joystick::kLeftRumble, 1);
		MedalOfHonorController	->	SetRumble(Joystick::kRightRumble, 1);
		Wait(2);
		MedalOfHonorController	->	SetRumble(Joystick::kLeftRumble, 0);
		MedalOfHonorController	->	SetRumble(Joystick::kRightRumble, 0);
		Wait(2);
	}
}

bool OI::GetMOHButtonStart(){
	return MedalOfHonorController	->	GetRawButton(MOHStartID);
}

double OI::ReadMOHRightStickY(){
	return MedalOfHonorController -> GetRawAxis(3);
}

bool OI::GetMOHRightStickButton(){ //probably not used
	return MedalOfHonorController -> GetRawButton(12);
}

/*bool OI::GetMOHLeftStickButton(){ //SPT Override soft stops
	return MedalOfHonorController -> GetRawButton(11);
}*/


bool OI::GetMOHButtonL3(){
	return MedalOfHonorController -> GetRawButton(MOHL3_ID);
}


