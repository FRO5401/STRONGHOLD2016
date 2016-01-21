#include "OI.h"
#include "RobotMap.h"
#include "Commands/XboxMove.h"

OI::OI()
{
	// Process operator interface input here.
	//AKA physical location of controllers from robot map
	//AKA physical locations of buttons too

	XboxController	= new Joystick(XboxController_Channel);

	//Gives the declared buttons a value that uses the joystick(controller) name and the port number determined
	//by drive station
	JoystickButton * 	Unused;
						XboxA				= new JoystickButton(XboxController, 1);
						XboxB				= new JoystickButton(XboxController, 2);
						XboxX				= new JoystickButton(XboxController, 3);
						XboxY				= new JoystickButton(XboxController, 4);
						UpperLeftTrig		= new JoystickButton(XboxController, 5);
						UpperRightTrig		= new JoystickButton(XboxController, 6);
						XboxBack			= new JoystickButton(XboxController, 7);
						XboxStart			= new JoystickButton(XboxController, 8);
						LeftStickButton		= new JoystickButton(XboxController, 9);
						RightStickButton 	= new JoystickButton(XboxController, 10);
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


//bool OI::GetStart()
//{
	//return XboxController -> GetRawButton();
//}
