#include <commands/IntakeCommand.h>

Intake::Intake(IntakeSubsystem* subsystem) : subsystem{subsystem}{
    AddRequirements({subsystem});
}

void Intake::Initialize() {
    subsystem->intake();
}

bool Intake::IsFinished() {
    subsystem->stop();
    return true;
}