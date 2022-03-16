#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/XboxController.h>
#include "rev/CANSparkMax.h"

class ShooterSubsystem : public frc2::SubsystemBase {
public:
    ShooterSubsystem();
    void shoot(double shot_power);

private:
    rev::CANSparkMax lowerFlywheel{3, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax upperFlywheel{4, rev::CANSparkMax::MotorType::kBrushless};
};