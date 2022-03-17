#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include "rev/CANSparkMax.h"

class ClimbSubsystem : public frc2::SubsystemBase {
public:
    ClimbSubsystem();
    void goUp();
    void goDown();
    void stop();

private:
    rev::CANSparkMax leftClimbMotor{7, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax rightClimbMotor{8, rev::CANSparkMax::MotorType::kBrushless};};

