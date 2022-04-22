#include <subsystems/ClimbSubsystem.h>
#include <frc/Preferences.h>
#include <frc/smartdashboard/SmartDashboard.h>

ClimbSubsystem::ClimbSubsystem() {
    leftClimbMotor.RestoreFactoryDefaults();
    rightClimbMotor.RestoreFactoryDefaults();

    leftClimbMotor.SetInverted(false);
    rightClimbMotor.SetInverted(false);
}

void ClimbSubsystem::onTeleopInit() {
    loadEncoders();
    frc::SmartDashboard::PutNumber("Left Position", leftClimbEncoder.GetPosition());
    frc::SmartDashboard::PutNumber("Right Position", rightClimbEncoder.GetPosition());


    // leftClimbMotor.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, true);
    // leftClimbMotor.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, true);

    // leftClimbMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, kClimbTopSoftStop);
    // leftClimbMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, 0.0);

    // rightClimbMotor.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, true);
    // rightClimbMotor.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, true);
    
    // rightClimbMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, kClimbTopSoftStop);
    // rightClimbMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, 0.0);
}

void ClimbSubsystem::onTeleopExit() {
    saveEncoders();
}

void ClimbSubsystem::zero(bool left, bool right) {
    if (left)
        leftClimbEncoder.SetPosition(0.0);
    if (right)
        rightClimbEncoder.SetPosition(0.0);
    saveEncoders();
}

void ClimbSubsystem::release() {
    leftClimbMotor.Set(-kClimbReleaseSpeed);
    rightClimbMotor.Set(-kClimbReleaseSpeed);
    frc::SmartDashboard::PutNumber("Left Position", leftClimbEncoder.GetPosition());
    frc::SmartDashboard::PutNumber("Right Position", rightClimbEncoder.GetPosition());
}

void ClimbSubsystem::retractLeft() {
    leftClimbMotor.Set(kClimbRetractSpeed);
    frc::SmartDashboard::PutNumber("Left Position", leftClimbEncoder.GetPosition());
    frc::SmartDashboard::PutNumber("Right Position", rightClimbEncoder.GetPosition());
}


void ClimbSubsystem::retractRight() {
    rightClimbMotor.Set(kClimbRetractSpeed);
    frc::SmartDashboard::PutNumber("Left Position", leftClimbEncoder.GetPosition());
    frc::SmartDashboard::PutNumber("Right Position", rightClimbEncoder.GetPosition());
}

void ClimbSubsystem::freemove(double left, double right) {
    if (left > 0.06 || left < -0.06) {
        leftClimbMotor.Set(-left);
    } else {
        leftClimbMotor.Set(0);
    }
    if (right > 0.06 || right < -0.06) {
        rightClimbMotor.Set(-right);
    } else {
        rightClimbMotor.Set(0);
    }
    frc::SmartDashboard::PutNumber("Left Position", leftClimbEncoder.GetPosition());
    frc::SmartDashboard::PutNumber("Right Position", rightClimbEncoder.GetPosition());
}

void ClimbSubsystem::stop() {
    leftClimbMotor.Set(0.0);
    rightClimbMotor.Set(0.0);
}

void ClimbSubsystem::saveEncoders() {
    frc::Preferences::SetDouble("climb.left.position", leftClimbEncoder.GetPosition());
    frc::Preferences::SetDouble("climb.right.position", rightClimbEncoder.GetPosition());
    frc::SmartDashboard::PutNumber("Left Position", leftClimbEncoder.GetPosition());
    frc::SmartDashboard::PutNumber("Right Position", rightClimbEncoder.GetPosition());
}

void ClimbSubsystem::loadEncoders() {
    leftClimbEncoder.SetPosition(frc::Preferences::GetDouble("climb.left.position"));
    rightClimbEncoder.SetPosition(frc::Preferences::GetDouble("climb.right.position"));
}