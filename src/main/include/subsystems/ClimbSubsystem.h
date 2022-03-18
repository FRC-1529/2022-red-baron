#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include "rev/CANSparkMax.h"
#include "Constants.h"

class ClimbSubsystem : public frc2::SubsystemBase {
public:
    ClimbSubsystem();
    void move(double x, double y);
    void stop();

private:
    rev::CANSparkMax leftClimbMotor{kLeftClimbMotorId, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax rightClimbMotor{kRightClimbMotorId, rev::CANSparkMax::MotorType::kBrushless};

    rev::SparkMaxRelativeEncoder leftClimbEncoder = leftClimbMotor.GetEncoder();
    rev::SparkMaxRelativeEncoder rightClimbEncoder = rightClimbMotor.GetEncoder();


};

