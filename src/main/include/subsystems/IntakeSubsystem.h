#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/XboxController.h>
#include <frc/motorcontrol/PWMSparkMax.h>

class IntakeSubsystem : public frc2::SubsystemBase {

IntakeSubsystem();
public:
    void Intake();

private:
    frc::PWMSparkMax motor_intake{0};

};

