#include <commands/RetractIntakeCommand.h>

RetractIntake::RetractIntake(IntakeSubsystem* subsystem) : subsystem{subsystem}{
    AddRequirements({subsystem});
}

void RetractIntake::Initialize() {
    subsystem->retractIntake();
}

bool RetractIntake::IsFinished() {
    return true;
}