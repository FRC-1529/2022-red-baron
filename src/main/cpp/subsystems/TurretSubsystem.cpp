#include <subsystems/TurretSubsystem.h>

TurretSubsystem::TurretSubsystem() {
    turretMotor.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, true);
    turretMotor.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, true);

    turretMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, 0.5);
    turretMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, -0.5);
}

void TurretSubsystem::turn(double x) {
    turretMotor.Set(x);
}

void TurretSubsystem::spinLowerFlywheel(double x) {
    lowerFlywheelMotor.Set(x);
}

void TurretSubsystem::spinUpperFlywhell(double x) {
    upperFlywheelMotor.Set(x);
}
