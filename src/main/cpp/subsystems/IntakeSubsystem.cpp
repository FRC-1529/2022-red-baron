#include <subsystems/IntakeSubsystem.h>

IntakeSubsystem::IntakeSubsystem() {}

void IntakeSubsystem::intake(){
    intakeMotor.Set(.7);
    elevatorMotor.Set(.5);
}
void IntakeSubsystem::spit_out(){
    intakeMotor.Set(-1);
    intakeMotor.Set(-1);
}