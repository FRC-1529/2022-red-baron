#include <subsystems/IntakeSubsystem.h>

IntakeSubsystem::IntakeSubsystem() {
    //pcmCompressor.EnableDigital();
}

void IntakeSubsystem::intake(){
    intakeMotor.Set(.7);
    conveyorMotor.Set(.3);
}

void IntakeSubsystem::stop() {
    intakeMotor.Set(0);
    conveyorMotor.Set(0);
}

void IntakeSubsystem::deployIntake() {
    IntakeSolenoidPCM.Set(frc::DoubleSolenoid::Value::kForward);
}

void IntakeSubsystem::retractIntake() {
    IntakeSolenoidPCM.Set(frc::DoubleSolenoid::Value::kReverse);
}