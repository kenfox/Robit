#include "../Robot.h"
#include "Drivetrain.h"
#include "../Robotmap.h"
#include "../Commands/BackgroundDrive.h"
#include <math.h>
Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	for (int j = 0; j < NUM_SPEED_SAMPLES; j++) {
		speedHistory[j] = 0.0;
	}
	nextSampleNum = 0;
	automaticShiftingEnabled = true;
	shiftPoint = 40.0;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftMotorA = RobotMap::drivetrainLeftMotorA;
	leftMotorB = RobotMap::drivetrainLeftMotorB;
	rightMotorA = RobotMap::drivetrainRightMotorA;
	rightMotorB = RobotMap::drivetrainRightMotorB;
	drive = RobotMap::drivetrainDrive;
	shiftGear = RobotMap::drivetrainShiftGear;
	leftEncoder = RobotMap::drivetrainLeftEncoder;
	rightEncoder = RobotMap::drivetrainRightEncoder;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}    
void Drivetrain::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new BackgroundDrive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Drivetrain::ShiftIntoLowGear() {
	shiftGear->Set(DoubleSolenoid::kForward);
}
void Drivetrain::ShiftIntoHighGear() {
	shiftGear->Set(DoubleSolenoid::kReverse);
}
void Drivetrain::ToggleShiftGears() {
	DoubleSolenoid::Value newGear = (shiftGear->Get() == DoubleSolenoid::kForward) ? DoubleSolenoid::kReverse : DoubleSolenoid::kForward;
	shiftGear->Set(newGear);
}
void Drivetrain::TakeSpeedSample() {
	double left = Robot::drivetrain->leftEncoder->GetRate();
	double right = Robot::drivetrain->rightEncoder->GetRate();
	double v = (fabs(left) > fabs(right)) ? left : right;
	speedHistory[nextSampleNum++] = v;
	if (nextSampleNum == NUM_SPEED_SAMPLES) nextSampleNum = 0;
}
void Drivetrain::ShiftAutomatically() {
	if (automaticShiftingEnabled) {
		double averageSpeed = 0.0;
		for (int j = 0; j < NUM_SPEED_SAMPLES; j++)
			averageSpeed += speedHistory[j];
		averageSpeed = averageSpeed / (double)NUM_SPEED_SAMPLES;
		if (fabs(averageSpeed) > shiftPoint) {
			shiftPoint = BASELINE_SHIFT_POINT - 5.0;
			Robot::drivetrain->ShiftIntoHighGear();
		}
		else {
			shiftPoint = BASELINE_SHIFT_POINT;
			Robot::drivetrain->ShiftIntoLowGear();
		}
	}
}
void Drivetrain::EnableAutomaticShifting(bool enabled) {
	shiftPoint = BASELINE_SHIFT_POINT;
	automaticShiftingEnabled = enabled;
}
void Drivetrain::Snapshot(){
	MotorSnapshot(leftMotorA);
	MotorSnapshot(leftMotorB);
	MotorSnapshot(rightMotorA);
	MotorSnapshot(rightMotorB);
}
void Drivetrain::MotorSnapshot(CANJaguar* motor)
{
	if (Robot::diag) {
		int motorNumber = motor->m_deviceNumber;
		int status = motor->m_lastReceiveStatus;
		float busVoltage = motor->GetBusVoltage();
		float outputCurrent = motor->GetOutputCurrent();
		Robot::diag->BufferPrintf("m,%d,%d,%.2f,%.2f\n", motorNumber, status, busVoltage, outputCurrent);
	}
}
