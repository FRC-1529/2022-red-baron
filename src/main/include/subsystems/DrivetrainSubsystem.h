// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/AnalogGyro.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include "Constants.h"

class DrivetrainSubsystem : public frc2::SubsystemBase {
 public:
  DrivetrainSubsystem();
  void drive (double x, double y);



 private:
  ctre::phoenix::motorcontrol::can::WPI_TalonFX motor_front_right{kFrontRightMotorId};
  ctre::phoenix::motorcontrol::can::WPI_TalonFX motor_back_right{kBackRightMotorId};
  frc::MotorControllerGroup motor_group_right{motor_front_right, motor_back_right};

  ctre::phoenix::motorcontrol::can::WPI_TalonFX motor_front_left{kFrontLeftMotorId};
  ctre::phoenix::motorcontrol::can::WPI_TalonFX motor_back_left{kBackLeftMotorId};
  frc::MotorControllerGroup motor_group_left{motor_front_left, motor_back_left};
  
  frc::DifferentialDrive differential_drive{motor_group_left, motor_group_right};

  frc::AnalogGyro gyro{0};
  
  frc::DifferentialDriveKinematics kinematics{0.318_m};
  frc::DifferentialDriveOdometry odometry{gyro.GetRotation2d()};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
