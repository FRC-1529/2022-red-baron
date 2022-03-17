#include <commands/ClimbDownCommand.h>

ClimbDown::ClimbDown(ClimbSubsystem* subsystem) : subsystem{subsystem}{
    AddRequirements({subsystem});
}

void ClimbDown::Execute() {
    subsystem->goDown();
}

bool ClimbDown::IsFinished() {
    return true;
}