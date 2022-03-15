// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/XboxController.h>

class DrivetrainSubsystem : public frc2::SubsystemBase {
 public:
  DrivetrainSubsystem();
  void Drive (double x, double y);



 private:
  ctre::phoenix::motorcontrol::can::WPI_TalonFX motor_front_left{2};
  ctre::phoenix::motorcontrol::can::WPI_TalonFX motor_front_right{0};
  ctre::phoenix::motorcontrol::can::WPI_TalonFX motor_back_left{4};
  ctre::phoenix::motorcontrol::can::WPI_TalonFX motor_back_right{1};
  frc::MotorControllerGroup motor_group_left{motor_front_left, motor_back_left};
  frc::MotorControllerGroup motor_group_right{motor_front_right, motor_back_right};
  frc::DifferentialDrive differential_drive{motor_group_left, motor_group_right};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
