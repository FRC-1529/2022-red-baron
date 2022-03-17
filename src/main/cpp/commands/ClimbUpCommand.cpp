#include <commands/ClimbUpCommand.h>

ClimbUp::ClimbUp(ClimbSubsystem* subsystem) : subsystem{subsystem}{
    AddRequirements({subsystem});
}

void ClimbUp::Execute() {
    subsystem->goUp();
}

bool ClimbUp::IsFinished() {
    return true;
}