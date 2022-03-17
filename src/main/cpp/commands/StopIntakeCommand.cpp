#include <commands/StopIntakeCommand.h>

StopIntake::StopIntake(IntakeSubsystem* subsystem) : subsystem{subsystem}{
    AddRequirements({subsystem});
}

void StopIntake::Initialize() {
    subsystem->stop();
}

bool StopIntake::IsFinished() {
    return true;
}