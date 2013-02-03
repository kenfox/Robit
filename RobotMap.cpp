// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
CANJaguar* RobotMap::drivetrainLeftMotorA = NULL;
CANJaguar* RobotMap::drivetrainLeftMotorB = NULL;
CANJaguar* RobotMap::drivetrainRightMotorA = NULL;
CANJaguar* RobotMap::drivetrainRightMotorB = NULL;
RobotDrive* RobotMap::drivetrainDrive = NULL;
DoubleSolenoid* RobotMap::drivetrainShiftGear = NULL;
Encoder* RobotMap::drivetrainLeftEncoder = NULL;
Encoder* RobotMap::drivetrainRightEncoder = NULL;
Servo* RobotMap::climberSafetyMotor = NULL;
DoubleSolenoid* RobotMap::climberEngageClaw = NULL;
CANJaguar* RobotMap::shooterMainMotor = NULL;
CANJaguar* RobotMap::shooterFeedMotor = NULL;
AnalogChannel* RobotMap::shooterFrisbeeDirection = NULL;
DoubleSolenoid* RobotMap::shooterDeploy = NULL;
CANJaguar* RobotMap::gathererMotor = NULL;
DoubleSolenoid* RobotMap::gathererDeploy = NULL;
Servo* RobotMap::cameraElevation = NULL;
Servo* RobotMap::cameraDirection = NULL;
DigitalOutput* RobotMap::supportPerfTimer = NULL;
DigitalOutput* RobotMap::supportDiagTimer = NULL;
Accelerometer* RobotMap::supportAccel = NULL;
Gyro* RobotMap::supportGyro = NULL;
Compressor* RobotMap::supportCompressor = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	drivetrainLeftMotorA = new CANJaguar(2);
	
	
	drivetrainLeftMotorB = new CANJaguar(3);
	
	
	drivetrainRightMotorA = new CANJaguar(4);
	
	
	drivetrainRightMotorB = new CANJaguar(5);
	
	
	drivetrainDrive = new RobotDrive(drivetrainLeftMotorA, drivetrainLeftMotorB,
              drivetrainRightMotorA, drivetrainRightMotorB);
	
	drivetrainDrive->SetSafetyEnabled(true);
        drivetrainDrive->SetExpiration(0.5);
        drivetrainDrive->SetSensitivity(0.5);
        drivetrainDrive->SetMaxOutput(1.0);
	drivetrainShiftGear = new DoubleSolenoid(1, 1, 2);      
	
	
	drivetrainLeftEncoder = new Encoder(1, 1, 1, 2, false, Encoder::k4X);
	lw->AddSensor("Drivetrain", "LeftEncoder", drivetrainLeftEncoder);
	drivetrainLeftEncoder->SetDistancePerPulse(1.0);
        drivetrainLeftEncoder->SetPIDSourceParameter(Encoder::kRate);
        drivetrainLeftEncoder->Start();
	drivetrainRightEncoder = new Encoder(1, 3, 1, 4, false, Encoder::k4X);
	lw->AddSensor("Drivetrain", "RightEncoder", drivetrainRightEncoder);
	drivetrainRightEncoder->SetDistancePerPulse(1.0);
        drivetrainRightEncoder->SetPIDSourceParameter(Encoder::kRate);
        drivetrainRightEncoder->Start();
	climberSafetyMotor = new Servo(1, 3);
	lw->AddActuator("Climber", "SafetyMotor", climberSafetyMotor);
	
	climberEngageClaw = new DoubleSolenoid(1, 3, 4);      
	
	
	shooterMainMotor = new CANJaguar(6);
	
	
	shooterFeedMotor = new CANJaguar(7);
	
	
	shooterFrisbeeDirection = new AnalogChannel(1, 3);
	lw->AddSensor("Shooter", "FrisbeeDirection", shooterFrisbeeDirection);
	
	shooterDeploy = new DoubleSolenoid(1, 5, 6);      
	
	
	gathererMotor = new CANJaguar(8);
	
	
	gathererDeploy = new DoubleSolenoid(1, 7, 8);      
	
	
	cameraElevation = new Servo(1, 1);
	lw->AddActuator("Camera", "Elevation", cameraElevation);
	
	cameraDirection = new Servo(1, 2);
	lw->AddActuator("Camera", "Direction", cameraDirection);
	
	supportPerfTimer = new DigitalOutput(1, 11);
	
	
	supportDiagTimer = new DigitalOutput(1, 12);
	
	
	supportAccel = new Accelerometer(1, 2);
	lw->AddSensor("Support", "Accel", supportAccel);
	supportAccel->SetSensitivity(1.0);
        supportAccel->SetZero(2.5);
	supportGyro = new Gyro(1, 1);
	lw->AddSensor("Support", "Gyro", supportGyro);
	supportGyro->SetSensitivity(0.007);
	supportCompressor = new Compressor(1, 5, 1, 1);
	
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
