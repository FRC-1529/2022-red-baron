#include "subsystems/ShooterSubsystem.h"

ShooterSubsystem::ShooterSubsystem() {}

void ShooterSubsystem::shoot(double shot_power){
    lowerFlywheel.Set(-shot_power);
    upperFlywheel.Set(shot_power);
}