#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/XboxController.h>
#include "rev/CANSparkMax.h"

class IntakeSubsystem : public frc2::SubsystemBase {
public:
    IntakeSubsystem();
    void intake();
    void spit_out();

private:
    rev::CANSparkMax intakeMotor{1, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax elevatorMotor{2, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax elevatorMotor2{7, rev::CANSparkMax::MotorType::kBrushless};
};

