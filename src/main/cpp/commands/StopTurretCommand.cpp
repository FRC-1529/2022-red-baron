#include <commands/StopTurretCommand.h>

StopTurret::StopTurret(TurretSubsystem* subsystem) : subsystem{subsystem}{
    AddRequirements({subsystem});
}

void StopTurret::Execute() {
    subsystem->spinLowerFlywheel(0.0);
    subsystem->spinUpperFlywhell(0.0);
}

bool StopTurret::IsFinished() {
    return true;
}