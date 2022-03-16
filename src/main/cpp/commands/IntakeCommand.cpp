#include <commands/IntakeCommand.h>

Intake::Intake(IntakeSubsystem* subsystem) : subsystem{subsystem}{
    AddRequirements({subsystem});
}

void Intake::Execute(){
    subsystem->intake();
}