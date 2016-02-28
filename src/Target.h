/*
 * Target.h
 *
 *  Created on: Feb 27, 2016
 *      Author: kmckay
 */

#ifndef SRC_TARGET_H_
#define SRC_TARGET_H_

#include "WPILib.h"

	const int TargetX		= 248;
	const int TargetY		= 281;
	const int TargetWidth	= 88;
	const int TargetHeight	= 55;

	const float Area_d = 0.5;
	const float Aspect_d = 0.5;

	const float AngleRange	= 22; //Angle left or right of center that target can be seen

	const Range RING_HUE_RANGE_d = {240	, 255};	//Default hue range for ring light R
	const Range RING_SAT_RANGE_d = {225	, 255};	//Default saturation range for ring light G
	const Range RING_VAL_RANGE_d = {0	, 248};	//Default value range for ring light B


#endif /* SRC_TARGET_H_ */
