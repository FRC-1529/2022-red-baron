#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include "rev/CANSparkMax.h"

class TurretSubsystem : public frc2::SubsystemBase {
public:
    TurretSubsystem();
    void turn(double x);
    void spinLowerFlywheel(double x);
    void spinUpperFlywhell(double y);

private:
    rev::CANSparkMax lowerFlywheelMotor{4, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax upperFlywheelMotor{5, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax turretMotor{6, rev::CANSparkMax::MotorType::kBrushless};
};

