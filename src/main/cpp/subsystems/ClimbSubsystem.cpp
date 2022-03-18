#include <subsystems/ClimbSubsystem.h>
#include <frc/smartdashboard/SmartDashboard.h>

ClimbSubsystem::ClimbSubsystem() {
    leftClimbMotor.RestoreFactoryDefaults();
    rightClimbMotor.RestoreFactoryDefaults();

    leftClimbMotor.SetInverted(true);
    rightClimbMotor.SetInverted(true);

    leftClimbMotor.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, true);
    leftClimbMotor.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, true);

    leftClimbMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, 50.0);
    leftClimbMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, 0);

    rightClimbMotor.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, true);
    rightClimbMotor.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, true);
    
    rightClimbMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, 50.0);
    rightClimbMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, 0);

    frc::SmartDashboard::PutNumber("Left Climb Position", leftClimbEncoder.GetPosition());
    frc::SmartDashboard::PutNumber("Right Climb Position", rightClimbEncoder.GetPosition());
}

void ClimbSubsystem::move(double x, double y) {
    if (x > 0.06 || x < -0.06) {
        leftClimbMotor.Set(-x);
    } else {
        leftClimbMotor.Set(0);
    }
    if (y > 0.06 || y < -0.06) {
        rightClimbMotor.Set(-y);
    } else {
        rightClimbMotor.Set(0);
    }
    frc::SmartDashboard::PutNumber("Left Climb Position", leftClimbEncoder.GetPosition());
    frc::SmartDashboard::PutNumber("Right Climb Position", rightClimbEncoder.GetPosition());
};

void ClimbSubsystem::stop() {
    leftClimbMotor.Set(0.0);
    rightClimbMotor.Set(0.0);

    frc::SmartDashboard::PutNumber("Left Climb Position", leftClimbEncoder.GetPosition());
    frc::SmartDashboard::PutNumber("Right Climb Position", rightClimbEncoder.GetPosition());
}