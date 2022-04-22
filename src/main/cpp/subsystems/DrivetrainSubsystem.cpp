// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DrivetrainSubsystem.h"

DrivetrainSubsystem::DrivetrainSubsystem() {
  gyro.Reset();
}

void DrivetrainSubsystem::onAutoInit() {}
void DrivetrainSubsystem::onAutoExit() {
  rawSet(0.0, 0.0);
}
void DrivetrainSubsystem::onTeleopInit() {}
void DrivetrainSubsystem::onTeleopExit() {}

void DrivetrainSubsystem::arcadeDrive (double fwd, double rot, bool slow, bool turbo)
{
  double modifier = 0.75;
  if (turbo)
    modifier = 1.0;
  if (slow)
    modifier = 0.45;
  differential_drive.ArcadeDrive(fwd*modifier,rot*modifier, true);
}

void DrivetrainSubsystem::rawSet(double power_l, double power_r) {
  motor_front_left.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, power_l);
  motor_back_left.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, power_l);
  motor_front_right.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, power_r);
  motor_back_right.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, power_r);
}

