#include <commands/LaunchCommand.h>

Launch::Launch(TurretSubsystem* subsystem) : subsystem{subsystem}{
    AddRequirements({subsystem});
}

void Launch::Execute() {
    subsystem->spinLowerFlywheel(-0.5);
    subsystem->spinUpperFlywhell(0.5);
}

bool Launch::IsFinished() {
    return true;
}