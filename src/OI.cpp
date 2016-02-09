#include "OI.h"
#include "RobotMap.h"
#include "Commands/XboxMove.h"
#include "Commands/DrivingWithEncoderInput.h"
#include "WPILib.h"
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
	JoystickButton * 	Unused1;
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
	JoystickButton*		Unused2;
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



	//New stuff
	XboxB = WhenPressed(new DrivingWithEncoderInput());
	XboxB = WhenReleased(new XboxMove());

}

//Defines the functions for the axis's declared in the h file
double OI::ReadXboxLeftStickX()
{
	double Slew =	XboxController	-> GetRawAxis(0);
	return Slew;
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
	return XboxController	->	GetRawButton(RBumper_ID);
}

bool OI::GetBrake()
{
	return XboxController	->	GetRawButton(LBumper_ID);
}

double OI::GetUpOrDownValueInfeeder(){
	double UpOrDownValue = XboxController -> GetRawAxis(5);
	return UpOrDownValue;
}

bool OI::DummyButtonReadFunction(){
	return true;
}

double OI::DummyJoystickReadFunction(){
	return 0;
}//Define function once we figure out controller

//New stuff
bool OI::GetButtonForEncoderDrive(){
	return XboxController	->	GetRawButton(XboxB_ID);
}

//bool OI::GetStart()
//{
	//return XboxController -> GetRawButton();
//}
