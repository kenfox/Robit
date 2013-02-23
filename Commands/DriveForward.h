// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVEFORWARD_H
#define DRIVEFORWARD_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class DriveForward: public Command {
public:
	double defaultDistance;
	double distance;
	double distanceRemaining;
	double keepGoingUntilTime;		 //minimum time that robot should drive forward
	double defaultSpeed;
	double speed;
	DriveForward(double distance = 0.0, double speed = 0.0); //negative means drive backwards
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
