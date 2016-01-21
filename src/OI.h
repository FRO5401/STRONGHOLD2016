#ifndef OI_H
#define OI_H

#include "WPILib.h"
//Includes all commands because this is where the commands will be activated to occur
#include "Commands/XboxMove.h"

class OI
{
private:

public:
	//Declares controller
	//The class joystick is misleading, it's just another term for controller
	Joystick *XboxController;

	//All the buttons that are possible that the drive station can be read from the controller
	//Only declares the buttons
	Button *XboxA;
	Button *XboxB;
	Button *XboxX;
	Button *XboxY;
	Button *UpperLeftTrig;
	Button *UpperRightTrig;
	Button *XboxBack;
	Button *XboxStart;
	Button *LeftStickButton;
	Button *RightStickButton;

	OI();
	//Functions to read axes, which cannot be listed like buttons
	//Only declares
	double ReadXboxLeftStickX();
	double GetLeftTrigger();
	double GetRightTrigger();
	bool GetPrecision();
	bool GetBrake();
	double GetUpOrDownValueInfeeder();
	bool DummyButtonReadFunction();
};

#endif
