#include <commands/DeployIntakeCommand.h>

DeployIntake::DeployIntake(IntakeSubsystem* subsystem) : subsystem{subsystem}{
    AddRequirements({subsystem});
}

void DeployIntake::Initialize() {
    subsystem->deployIntake();
}

bool DeployIntake::IsFinished() {
    return true;
}