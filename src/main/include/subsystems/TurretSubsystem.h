#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include "rev/CANSparkMax.h"

class TurretSubsystem : public frc2::SubsystemBase {
public:
    TurretSubsystem();
    void onAutoInit();
    void onAutoExit();
    void onTeleopInit();
    void onTeleopExit();

    void zeroTurret();
    void turnTurret(double speed);
    void stopTurret();

    void setFlywheelSpeed(double lower, double upper);

    void saveEncoders();
    void loadEncoders();

private:
    rev::CANSparkMax lowerFlywheelMotor{4, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax upperFlywheelMotor{5, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax turretMotor{6, rev::CANSparkMax::MotorType::kBrushless};

    rev::SparkMaxRelativeEncoder turretEncoder = turretMotor.GetEncoder();
};

