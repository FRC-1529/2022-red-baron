#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/XboxController.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/PneumaticsModuleType.h>
#include "rev/CANSparkMax.h"
#include "Constants.h"

class IntakeSubsystem : public frc2::SubsystemBase {
public:
    IntakeSubsystem();
    void onAutoInit();
    void onAutoExit();
    
    void onTeleopInit();
    void onTeleopExit();

    void deployIntake();
    void retractIntake();

    void spinIntake();
    void reverseIntake();
    void stopIntake();

    void runConveyor();
    void reverseConveyor();
    void stopConveyor();

    void runElevator();
    void reverseElevator();
    void stopElevator();

private:
    rev::CANSparkMax intakeMotor{kIntakeMotorId, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax conveyorMotor{kConveyorMotorId, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax elevatorMotor{kElevatorMotorId, rev::CANSparkMax::MotorType::kBrushless};


    frc::Compressor pcmCompressor{kCompressorId, frc::PneumaticsModuleType::CTREPCM}; 
    frc::DoubleSolenoid IntakeSolenoidPCM{frc::PneumaticsModuleType::CTREPCM, kSolenoidIds[0], kSolenoidIds[1]};
};