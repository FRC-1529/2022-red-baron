#include <commands/ClimbStopCommand.h>

ClimbStop::ClimbStop(ClimbSubsystem* subsystem) : subsystem{subsystem}{
    AddRequirements({subsystem});
}

void ClimbStop::Execute() {
    subsystem->stop();
}

bool ClimbStop::IsFinished() {
    return true;
}