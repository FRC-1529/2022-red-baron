#include <subsystems/IntakeSubsystem.h>

IntakeSubsystem::IntakeSubsystem() {}

void IntakeSubsystem:: intake(){
    intakeMotor.Set(.7);
}
void IntakeSubsystem:: spit_out(){
    intakeMotor.Set(-1);
}