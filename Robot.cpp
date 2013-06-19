#include "Robot.h"
#include "Commands/AutonShootOnly.h"
#include <math.h>
#ifndef M_PI
# define M_PI 3.1415926535
#endif
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Drivetrain* Robot::drivetrain = 0;
Climber* Robot::climber = 0;
Shooter* Robot::shooter = 0;
Gatherer* Robot::gatherer = 0;
Camera* Robot::camera = 0;
Support* Robot::support = 0;
Cosmetic* Robot::cosmetic = 0;
OI* Robot::oi = 0;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Diagnostics* Robot::diag = 0;
bool Robot::gyroGood = true;
bool Robot::driveEncodersGood = true;
void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	drivetrain = new Drivetrain();
	climber = new Climber();
	shooter = new Shooter();
	gatherer = new Gatherer();
	camera = new Camera();
	support = new Support();
	cosmetic = new Cosmetic();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	oi = new OI();
	lw = LiveWindow::GetInstance();
	//diag = new Diagnostics();
	autonomousCommand = new AutonShootOnly();
	gyroGood = true;
	driveEncodersGood = true;
}
void Robot::DisabledInit() {
	Robot::ResetDistanceTraveled();
	if (Robot::diag) Robot::diag->FlushToDisk();
}
void Robot::DisabledPeriodic() {
	// FIXME Test gyro and encoders to verify they are working.
	// This can be done during pre-match setup: push the robot
	// forward and backward a few inches, then turn the robot left
	// and right a few degrees. A calibration switch on the robot
	// should be used to enter this verification mode.
}
void Robot::AutonomousInit() {
	RobotMap::supportCompressor->Start();
	Robot::ResetDistanceTraveled();
	Robot::drivetrain->EnableAutomaticShifting(false);
	Robot::drivetrain->ShiftIntoLowGear();
	if (autonomousCommand) autonomousCommand->Start();
}
void Robot::AutonomousPeriodic() {
	Robot::drivetrain->TakeSpeedSample();
	Robot::shooter->TakeSpeedSample();
	SmartDashboard::PutNumber("jaguarRPM", Robot::shooter->shooterSpeed);
	Scheduler::GetInstance()->Run();
}
void Robot::TeleopInit() {
	if (autonomousCommand) autonomousCommand->Cancel();
	RobotMap::supportCompressor->Start();
	Robot::ResetDistanceTraveled();
	Robot::drivetrain->EnableAutomaticShifting(true);
}
void Robot::TeleopPeriodic() {
	Robot::drivetrain->TakeSpeedSample();
	Robot::drivetrain->ShiftAutomatically();
	Robot::shooter->TakeSpeedSample();
	SmartDashboard::PutNumber("jaguarRPM", Robot::shooter->shooterSpeed);
#if 1
	SmartDashboard::PutNumber("gyro", Robot::support->gyro->GetAngle());
	SmartDashboard::PutNumber("leftEncoder", Robot::drivetrain->leftEncoder->GetRate());
	SmartDashboard::PutNumber("rightEncoder", Robot::drivetrain->rightEncoder->GetRate());
	SmartDashboard::PutNumber("facing", Robot::AngleFacing());
	SmartDashboard::PutNumber("distance", Robot::DistanceTraveled());
#endif
	Robot::drivetrain->drive->leftRightAdjust = SmartDashboard::GetNumber("LeftRightAdjust");
	Scheduler::GetInstance()->Run();
}
void Robot::TestInit() {
}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot);
void Robot::Snapshot(char *mode, double start, double end) {
	const char *format = (end - start >= 0.018) ? "%s,%.4f,%.4f,SLOW\n" : "%s,%.4f,%.4f\n";
	if (Robot::diag) Robot::diag->BufferPrintf(format, mode, start, end);
}
void Robot::ResetDistanceTraveled() {
	Robot::support->gyro->Reset();
	Robot::drivetrain->leftEncoder->Reset();
	Robot::drivetrain->rightEncoder->Reset();
}
double Robot::DistanceTraveled() {
	double leftDist = Robot::drivetrain->leftEncoder->GetDistance();
	double rightDist = Robot::drivetrain->rightEncoder->GetDistance();
	double dist = max(leftDist, rightDist);
	return dist;
}
double Robot::AngleFacing() {
	if (Robot::gyroGood) {
		return Robot::support->gyro->GetAngle();
	}
	else if (Robot::driveEncodersGood) {
		const double RobotWidth = 26.0;
		double rad = (Robot::drivetrain->leftEncoder->GetDistance() -
					  Robot::drivetrain->rightEncoder->GetDistance()) / RobotWidth;
		return rad * (180.0 / M_PI);
	}
	else {
		return 0.0;
	}
}
