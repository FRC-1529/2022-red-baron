#include "commands/ShootCommand.h"

Shoot::Shoot(ShooterSubsystem* subsystem, std::function<double()> shot_power) : subsystem{subsystem}, trigger{std::move(shot_power)}{
    AddRequirements({subsystem});
}

void Shoot::Execute(){
    subsystem->shoot(trigger());
}