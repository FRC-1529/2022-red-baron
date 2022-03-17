#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/XboxController.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/PneumaticsModuleType.h>
#include "rev/CANSparkMax.h"

class IntakeSubsystem : public frc2::SubsystemBase {
public:
    IntakeSubsystem();
    void intake();
    void spit_out();
    void stop();

    void deployIntake();
    void retractIntake();

private:
    rev::CANSparkMax intakeMotor{1, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax conveyorMotor{2, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax elevatorMotor{3, rev::CANSparkMax::MotorType::kBrushless};

    frc::Compressor pcmCompressor{0, frc::PneumaticsModuleType::CTREPCM}; 
    frc::DoubleSolenoid IntakeSolenoidPCM{frc::PneumaticsModuleType::CTREPCM, 0, 1};
};
