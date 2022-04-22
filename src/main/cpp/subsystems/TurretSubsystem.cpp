#include <subsystems/TurretSubsystem.h>
#include <frc/Preferences.h>
#include "Constants.h"

TurretSubsystem::TurretSubsystem() {
    turretMotor.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, true);
    turretMotor.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, true);

    turretMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, kTurretLimitClockwise);
    turretMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, kTurretLimitCounterclockwise);
}

void TurretSubsystem::onAutoInit() {
    loadEncoders();
}
void TurretSubsystem::onAutoExit() {
    saveEncoders();
}
void TurretSubsystem::onTeleopInit() {
    loadEncoders();
}
void TurretSubsystem::onTeleopExit() {
    saveEncoders();
}

void TurretSubsystem::zeroTurret() {
    turretEncoder.SetPosition(0.0);
    saveEncoders();
}
void TurretSubsystem::turnTurret(double speed) {
    turretMotor.Set(speed*0.2);
}
void TurretSubsystem::stopTurret() {
    turretMotor.Set(0.0);
}

void TurretSubsystem::setFlywheelSpeed(double lower, double upper) {
    lowerFlywheelMotor.Set(lower);
    upperFlywheelMotor.Set(upper);
}

void TurretSubsystem::saveEncoders() {
    frc::Preferences::SetDouble("turret.position", turretEncoder.GetPosition());
}
void TurretSubsystem::loadEncoders() {
    turretEncoder.SetPosition(frc::Preferences::GetDouble("turret.position"));
}