#include <subsystems/IntakeSubsystem.h>

IntakeSubsystem::IntakeSubsystem() {
    //pcmCompressor.EnableDigital();
}

void IntakeSubsystem::onAutoInit() {
    deployIntake(); 
}
void IntakeSubsystem::onAutoExit() {}

void IntakeSubsystem::onTeleopInit() {}
void IntakeSubsystem::onTeleopExit() {}

void IntakeSubsystem::deployIntake() {
    IntakeSolenoidPCM.Set(frc::DoubleSolenoid::Value::kForward);
}
void IntakeSubsystem::retractIntake() {
    IntakeSolenoidPCM.Set(frc::DoubleSolenoid::Value::kReverse);
}

void IntakeSubsystem::spinIntake() {
    intakeMotor.Set(kIntakeSpeed);
}
void IntakeSubsystem::reverseIntake() {
    intakeMotor.Set(-0.2);
}
void IntakeSubsystem::stopIntake() {
    intakeMotor.Set(0.0);
}

void IntakeSubsystem::runConveyor() {
    conveyorMotor.Set(kConveyorSpeed);
}
void IntakeSubsystem::reverseConveyor() {
    conveyorMotor.Set(-kConveyorSpeed);
}
void IntakeSubsystem::stopConveyor() {
    conveyorMotor.Set(0.0);
}

void IntakeSubsystem::runElevator() {
    elevatorMotor.Set(kElevatorSpeed);
}
void IntakeSubsystem::reverseElevator() {
    elevatorMotor.Set(-(kElevatorSpeed/4));
}
void IntakeSubsystem::stopElevator() {
    elevatorMotor.Set(0.0);
}

