#include <subsystems/IntakeSubsystem.h>

IntakeSubsystem::IntakeSubsystem() {}

void IntakeSubsystem::intake(){
    intakeMotor.Set(.7);
    elevatorMotor.Set(.5);
    elevatorMotor2.Set(.5);
}
void IntakeSubsystem::spit_out(){
    intakeMotor.Set(-1);
    elevatorMotor.Set(-.5);
    elevatorMotor2.Set(-.5);
}