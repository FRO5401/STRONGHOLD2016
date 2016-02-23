/*
 * Watery Tart subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Based off 2015 Vision Retro Sample
 * You can't expect to wield supreme executive power just because some watery tart threw a sword at you.
 */

#include "WateryTart.h"
#include "../RobotMap.h"
#include "Commands/LockTarget.h"
//#include "SmartDashboard/SmartDashboard.h"
//#include "LiveWindow/LiveWindow.h"

//#include <math.h>
//#include <vector>

	//Structure to represent the scores for the various tests used for target identification
	struct Scores {
		double Area;
		double Aspect;
	};

	BCGOptions_struct R_options;
	BCGOptions_struct G_options;
	BCGOptions_struct B_options;
	//	double XFirstPixel, YFirstPixel, XUpLeftCorner, YUpLeftCorner, XDownRightCorner, YDownRightCorner, RectHeight, RectWidth, Aspect;
	const float PixelAngleScale = 10;	//Pixels per degree angle, measured and subject to adjustment
	/*
	 * Target info - synch with Robot.cpp
	 */
	const int TargetX		= 100;
	const int TargetY		= 50;
	const int TargetWidth	= 100;
	const int TargetHeight	= 50;
	/************
	 * End Target info
	 ************/


//	IMAQdxSession session;
	IMAQdxError imaqErrorEnum;

	//Constants
	double AREA_MINIMUM = 0.5; //Default Area minimum for particle as a percentage of total image area
	double LONG_RATIO = 2.22; //Tote long side = 26.9 / Tote height = 12.1 = 2.22
	double SHORT_RATIO = 1.4; //Tote short side = 16.9 / Tote height = 12.1 = 1.4
	double SCORE_MIN = 75.0;  //Minimum score to be considered a tote
	double VIEW_ANGLE = 60; //View angle fo camera, set to Axis m1011 by default, 64 for m1013, 51.7 for 206, 52 for HD3000 square, 60 for HD3000 640x480
	double ASPECT_GOAL	= 1;  //Aspect Ratio of the target in our targeting range
	ParticleFilterCriteria2 criteria[1];
	ParticleFilterOptions2 filterOptions = {0,0,1,1};
	Scores scores;

WateryTart::WateryTart() :
		Subsystem("WateryTart")
{
//Motor and sensor declarations here
	//Images
	frame 		= imaqCreateImage(IMAQ_IMAGE_RGB, 0);   //TODO Try these in the search function along with a destroy to possibly save memory
	SecondFrame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	binaryFrame = imaqCreateImage(IMAQ_IMAGE_U8, 0);
	TargetFrame = imaqCreateImage(IMAQ_IMAGE_U8,0);
	R_options.brightness = 32;
	R_options.contrast = 45;
	R_options.gamma = 1.0;

	G_options.brightness = 32;
	G_options.contrast = 45;
	G_options.gamma = 1.0;

	B_options.brightness = 16;
	B_options.contrast = 45;
	B_options.gamma = 1.0;

	SmartDashboard::PutNumber("RedBrightness", R_options.brightness);
	SmartDashboard::PutNumber("Redcontrast", R_options.contrast);
	SmartDashboard::PutNumber("Redgamma", R_options.gamma);
	SmartDashboard::PutNumber("GreenBrightness", G_options.brightness);
	SmartDashboard::PutNumber("Greencontrast", G_options.contrast);
	SmartDashboard::PutNumber("Greengamma", G_options.gamma);
	SmartDashboard::PutNumber("BlueBrightness", B_options.brightness);
	SmartDashboard::PutNumber("Bluecontrast", B_options.contrast);
	SmartDashboard::PutNumber("Bluegamma", B_options.gamma);

	imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
	if(imaqErrorEnum != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
	}
	imaqError = IMAQdxConfigureGrab(session);
	if(imaqErrorEnum != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
	}
}

void WateryTart::InitDefaultCommand()
{
	//SetDefaultCommand(new LockTarget());
}

/* INTENT: Search function
 * Upon the press of a button, a command will invoke this function to check the image for the scoring U, and evaluate whether we have a shooting vector
 * It will return a rumble to the controller and splash a green box on the dashboard
 * Ideally, this will take place on an on board raspberry pi or arduino board, but that is version 2.0
 */
float WateryTart::Search(Range Hue, Range Sat, Range Val, float AreaIn, float AspectIn, double WaitTime)
  {
/*	R_options.brightness = 32;
	R_options.contrast = 45;
	R_options.gamma = 1.0;

	G_options.brightness = 32;
	G_options.contrast = 45;
	G_options.gamma = 1.0;

	B_options.brightness = 16;
	B_options.contrast = 45;
	B_options.gamma = 1.0;
*/
	R_options.brightness = SmartDashboard::GetNumber("RedBrightness", R_options.brightness);
	R_options.contrast = SmartDashboard::GetNumber("Redcontrast", R_options.contrast);
	R_options.gamma = SmartDashboard::GetNumber("Redgamma", R_options.gamma);
	G_options.brightness = SmartDashboard::GetNumber("GreenBrightness", G_options.brightness);
	G_options.contrast = SmartDashboard::GetNumber("Greencontrast", G_options.contrast);
	G_options.gamma = SmartDashboard::GetNumber("Greengamma", G_options.gamma);
	B_options.brightness = SmartDashboard::GetNumber("BlueBrightness", B_options.brightness);
	B_options.contrast = SmartDashboard::GetNumber("Bluecontrast", B_options.contrast);
	B_options.gamma = SmartDashboard::GetNumber("Bluegamma", B_options.gamma);
	double XFirstPixel, YFirstPixel, XUpLeftCorner, YUpLeftCorner, XDownRightCorner, YDownRightCorner, RectHeight, RectWidth, Aspect = 0;
	double Angle = -180;
	int Particle_No = 0;
	//Put default values to SmartDashboard so fields will appear
	SmartDashboard::PutNumber("Tote hue min", Hue.minValue);
	SmartDashboard::PutNumber("Tote hue max", Hue.maxValue);
	SmartDashboard::PutNumber("Tote sat min", Sat.minValue);
	SmartDashboard::PutNumber("Tote sat max", Sat.maxValue);
	SmartDashboard::PutNumber("Tote val min", Val.minValue);
	SmartDashboard::PutNumber("Tote val max", Val.maxValue);

	SmartDashboard::PutNumber("Target Area min %", AreaIn);
	SmartDashboard::PutNumber("Target Aspect %", AspectIn);
	SmartDashboard::PutNumber("Wait Time", WaitTime);

	//read file in from disk. For this example to run you need to copy image.jpg from the SampleImages folder to the
	//directory shown below using FTP or SFTP: http://wpilib.screenstepslive.com/s/4485/m/24166/l/282299-roborio-ftp
	//Two different pictures here, just referring to one or the other based on commented line, leave commented and uncomment section below to use camera
//	imaqError = imaqReadFile(frame, "//home//lvuser//SampleImages//Goalimage20.png", NULL, NULL);
//	imaqError = imaqReadFile(frame, "//home//lvuser//SampleImages//GrailCapture.JPG", NULL, NULL);
// This starts acquisition from the camera, uncomment once calibrated with the files above.

	IMAQdxStartAcquisition(session);
//	IMAQdxConfigureGrab(session);
//	IMAQdxGrab(session, frame, true, NULL); //Takes the image from "session" and stores it in "frame"
	IMAQdxSnap(session, frame);//Not sure the difference between snap and grab, but I'm hoping Snap takes a smaller/shorter sample?"
	if(imaqErrorEnum != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
	}
	IMAQdxStopAcquisition(session);

//This is the box at the top
//	imaqError = imaqDrawShapeOnImage(frame, frame, {0, 0, 135, 840}, DrawMode::IMAQ_PAINT_INVERT, ShapeMode::IMAQ_SHAPE_RECT, 0.0f);
//This is the box along the left side
//	imaqError = imaqDrawShapeOnImage(frame, frame, {0, 0, 600, 70}, DrawMode::IMAQ_PAINT_INVERT, ShapeMode::IMAQ_SHAPE_RECT, 0.0f);

	LCameraServer::GetInstance()->SetImage(frame);  //Send original image to dashboard to assist in tweaking mask.
	Wait(WaitTime); //Part of test code to cycle between the filtered image and the color image
	imaqError = imaqCopyRect(SecondFrame, frame, {135, 70, 465, 770}, {0, 0});
	imaqError = imaqSetImageSize(SecondFrame, 840, 600);
	LCameraServer::GetInstance()->SetImage(SecondFrame);  //Send original image to dashboard to assist in tweaking mask.
	Wait(WaitTime); //Part of test code to cycle between the filtered image and the color image
//XXX
	SmartDashboard::GetNumber("RBrightness", R_options.brightness);
	SmartDashboard::GetNumber("GBrightness", G_options.brightness);
	SmartDashboard::GetNumber("BBrightness", B_options.brightness);
	imaqError = imaqColorBCGTransform(SecondFrame, SecondFrame, &R_options, &G_options, &B_options, NULL);
	LCameraServer::GetInstance() -> SetImage(SecondFrame);
	Wait(WaitTime);

	//Threshold the image looking for ring light color
	imaqError = imaqColorThreshold(binaryFrame, SecondFrame, 255, IMAQ_RGB, &Hue, &Sat, &Val);

	//Send particle count to dashboard
	int numParticles = 0;
	imaqError = imaqCountParticles(binaryFrame, 1, &numParticles);
	SmartDashboard::PutNumber("Masked particles", numParticles);

	//Replaces the SendtoDashboard function without error handling
	LCameraServer::GetInstance()->SetImage(binaryFrame); //Send masked image to dashboard to assist in tweaking mask.
	Wait(WaitTime); //Part of test code to cycle between the filtered image and the color image

	//filter out small particles
	float areaMin = SmartDashboard::GetNumber("Area min %", AreaIn);
	criteria[0] = {IMAQ_MT_AREA_BY_IMAGE_AREA, areaMin, 100, false, false};
//	criteria[0] = {IMAQ_MT_AREA_BY_IMAGE_AREA, AreaIn, 100, false, false};
	imaqError = imaqParticleFilter4(binaryFrame, binaryFrame, criteria, 1, &filterOptions, NULL, NULL);

	if(numParticles > 0) {

	//Send particle count after filtering to dashboard
		imaqError = imaqCountParticles(binaryFrame, 1, &numParticles);
		SmartDashboard::PutNumber("Filtered particles", numParticles);
		imaqMeasureParticle(binaryFrame, Particle_No, false, IMAQ_MT_FIRST_PIXEL_X, &XFirstPixel);
		imaqMeasureParticle(binaryFrame, Particle_No, false, IMAQ_MT_FIRST_PIXEL_Y, &YFirstPixel);
		imaqMeasureParticle(binaryFrame, Particle_No, false, IMAQ_MT_BOUNDING_RECT_LEFT, &XUpLeftCorner);
		imaqMeasureParticle(binaryFrame, Particle_No, false, IMAQ_MT_BOUNDING_RECT_TOP, &YUpLeftCorner);
		imaqMeasureParticle(binaryFrame, Particle_No, false, IMAQ_MT_BOUNDING_RECT_RIGHT, &XDownRightCorner);
		imaqMeasureParticle(binaryFrame, Particle_No, false, IMAQ_MT_BOUNDING_RECT_BOTTOM, &YDownRightCorner);
		imaqMeasureParticle(binaryFrame, Particle_No, false, IMAQ_MT_BOUNDING_RECT_WIDTH, &RectHeight);
		imaqMeasureParticle(binaryFrame, Particle_No, false, IMAQ_MT_BOUNDING_RECT_HEIGHT, &RectWidth);
		SmartDashboard::PutNumber("First Pixel - X", XFirstPixel);
		SmartDashboard::PutNumber("First Pixel - Y", YFirstPixel);
		SmartDashboard::PutNumber("LeftRectTop-X", XUpLeftCorner);
		SmartDashboard::PutNumber("LeftRectTop-Y", YUpLeftCorner);
		SmartDashboard::PutNumber("RightRectDown-X", XDownRightCorner);
		SmartDashboard::PutNumber("RightRectDown - Y", YDownRightCorner);
		SmartDashboard::PutNumber("Rectangle Height", RectHeight);
		SmartDashboard::PutNumber("Rectangle Width", RectWidth);
		SmartDashboard::PutNumber("Aspect Ratio", Aspect);
		Aspect = (RectWidth / RectHeight);
		scores.Aspect = (Aspect / ASPECT_GOAL);

//		SmartDashboard::PutBoolean("IsTarget", isTarget);
//		double WateryTart::computeDistance (Image *image, ParticleReport report) {

		imaqError = imaqDrawShapeOnImage(TargetFrame, binaryFrame, {YUpLeftCorner, XUpLeftCorner, RectWidth, RectHeight}, DrawMode::IMAQ_PAINT_INVERT, ShapeMode::IMAQ_SHAPE_RECT, 0.0f);
		LCameraServer::GetInstance()->SetImage(TargetFrame); //Send masked image to dashboard to assist in tweaking mask.
		Wait(WaitTime); //Part of test code to cycle between the filtered image and the color image

		double normalizedWidth, targetWidth;
		int xRes, yRes;

		imaqGetImageSize(binaryFrame, &xRes, &yRes);
		normalizedWidth = 2*(XDownRightCorner - XUpLeftCorner)/xRes;
		//imaqMeasureParticle();
		SmartDashboard::PutNumber("Width", normalizedWidth);
		targetWidth = 7;

		double distance =  targetWidth/(normalizedWidth*12*tan(VIEW_ANGLE*M_PI/(180*2)));
		SmartDashboard::PutNumber("Distance", distance);
		Angle = (XUpLeftCorner - TargetX)/ PixelAngleScale;
		}//TODO Version 2, try not to have to run this whole thing a second time
//	} else {
//		SmartDashboard::PutBoolean("IsTarget", false);
//	}
	SmartDashboard::PutNumber("Angle", Angle);
	return Angle;
  }


void WateryTart::Manual()
  {
/*
 * While a button is pressed, this will show a display with a crosshair that will allow manual aiming
 */

  }

 void WateryTart::Stop()
  {
/*
 * Not sure this will be needed but reserving a space for it so that we can clear image, or reinitialize variables, or anything associated with stopping
 */
		IMAQdxStopAcquisition(session);

  }

  void WateryTart::Reset()
  {

/*
 * Not sure what thsi might do or what might trigger it, but want to see if there's any kind of clear image cache or something
 */

  }
/*  COMMENT EVERYTHING

	//Comparator function for sorting particles. Returns true if particle 1 is larger
	static bool WateryTart::CompareParticleSizes(ParticleReport particle1, ParticleReport particle2)
	{
		//we want descending sort order
		return particle1.PercentAreaToImageArea > particle2.PercentAreaToImageArea;
	}

	/**
	 * Converts a ratio with ideal value of 1 to a score. The resulting function is piecewise
	 * linear going from (0,0) to (1,100) to (2,0) and is 0 for all inputs outside the range 0-2
	 */
  /* COMMENT EVERYTHING
	double WateryTart::ratioToScore(double ratio)
	{
		return (fmax(0, fmin(100*(1-fabs(1-ratio)), 100)));
	}


	double WateryTart::AreaScore(ParticleReport report)
	{
		double boundingArea = (report.BoundingRectBottom - report.BoundingRectTop) * (report.BoundingRectRight - report.BoundingRectLeft);
		//Tape is 7" edge so 49" bounding rect. With 2" wide tape it covers 24" of the rect.
		return ratioToScore((49/24)*report.Area/boundingArea);
	}

	/**
	 * Method to score if the aspect ratio of the particle appears to match the retro-reflective target. Target is 7"x7" so aspect should be 1
	 */
  /* COMMENT EVERYTHING
	double WateryTart::AspectScore(ParticleReport report)
	{
		return ratioToScore(((report.BoundingRectRight-report.BoundingRectLeft)/(report.BoundingRectBottom-report.BoundingRectTop)));
	}


	/**
	 * Computes the estimated distance to a target using the width of the particle in the image. For more information and graphics
	 * showing the math behind this approach see the Vision Processing section of the ScreenStepsLive documentation.
	 *
	 * @param image The image to use for measuring the particle estimated rectangle
	 * @param report The Particle Analysis Report for the particle
	 * @return The estimated distance to the target in feet.
	 */
  /* COMMENT EVERYTHING
	double WateryTart::computeDistance (Image *image, ParticleReport report) {
		double normalizedWidth, targetWidth;
		int xRes, yRes;

		imaqGetImageSize(image, &xRes, &yRes);
		normalizedWidth = 2*(report.BoundingRectRight - report.BoundingRectLeft)/xRes;
		SmartDashboard::PutNumber("Width", normalizedWidth);
		targetWidth = 7;

		return  targetWidth/(normalizedWidth*12*tan(VIEW_ANGLE*M_PI/(180*2)));
	}
//};*/
