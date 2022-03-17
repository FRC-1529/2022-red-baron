#include <subsystems/TurretSubsystem.h>

TurretSubsystem::TurretSubsystem() {}

void TurretSubsystem::turn(double x) {
    turretMotor.Set(x);
}

void TurretSubsystem::spinLowerFlywheel(double x) {
    lowerFlywheelMotor.Set(x);
}

void TurretSubsystem::spinUpperFlywhell(double x) {
    upperFlywheelMotor.Set(x);
}
