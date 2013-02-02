// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Robot.h"
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
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();
	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutonomousCommand();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
}

#include <stdio.h>

void Robot::AutonomousInit() {
#if 0
	FILE *log;
	if (0 != (log = fopen("/3322-timing.txt", "w"))) {
		const int numIterations = 100000;
		fprintf(log, "TIMING TEST\n");

		double startFPGA = Timer::GetFPGATimestamp();
		double start = Timer::GetPPCTimestamp();

		double last = Timer::GetFPGATimestamp();
		double max = 0.0;
		for (int i = 0; i < numIterations; ++i) {
			double now = Timer::GetFPGATimestamp();
			double dt = now - last;
			if (dt > max) {
				max = dt;
			}
			last = now;
		}

		double stop = Timer::GetPPCTimestamp();
		double stopFPGA = Timer::GetFPGATimestamp();
		fprintf(log, "FPGA Clock start=%.8f\n", last);
		fprintf(log, "elapsed=%.8f (%.8f) each=%.8f max dt=%.8f\n",
				stop - start, stopFPGA - startFPGA, (stop - start) / (numIterations + 1), max);

		startFPGA = Timer::GetFPGATimestamp();
		start = Timer::GetPPCTimestamp();

		last = Timer::GetPPCTimestamp();
		max = 0.0;
		for (int i = 0; i < numIterations; ++i) {
			double now = Timer::GetPPCTimestamp();
			double dt = now - last;
			if (dt > max) {
				max = dt;
			}
			last = now;
		}

		stop = Timer::GetPPCTimestamp();
		stopFPGA = Timer::GetFPGATimestamp();
		fprintf(log, "PPC Clock example=%.8f\n", last);
		fprintf(log, "elapsed=%.8f (%.8f) each=%.8f max dt=%.8f\n",
				stop - start, stopFPGA - startFPGA, (stop - start) / (numIterations + 1), max);

		startFPGA = Timer::GetFPGATimestamp();
		start = Timer::GetPPCTimestamp();

		last = ::GetTime();
		max = 0.0;
		for (int i = 0; i < numIterations; ++i) {
			double now = ::GetTime();
			double dt = now - last;
			if (dt > max) {
				max = dt;
			}
			last = now;
		}

		stop = Timer::GetPPCTimestamp();
		stopFPGA = Timer::GetFPGATimestamp();
		fprintf(log, "vwWorks Clock example=%.8f\n", last);
		fprintf(log, "elapsed=%.8f (%.8f) each=%.8f max dt=%.8f\n",
				stop - start, stopFPGA - startFPGA, (stop - start) / (numIterations + 1), max);

		fclose(log);
	}
#endif
#if 0
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
#endif
}
	
void Robot::AutonomousPeriodic() {
#if 0
	Scheduler::GetInstance()->Run();
#endif
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
	autonomousCommand->Cancel();
	RobotMap::supportCompressor->Start();
	//Robot::support->gyro->SetSensitivity(0.05);
	Robot::support->gyro->Reset();
}
	
void Robot::TeleopPeriodic() {
	SmartDashboard::PutNumber("gyro", Robot::support->gyro->GetAngle());
	if (autonomousCommand != NULL)
		Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot);
