// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

// ==== Drivetrain System ====
// Falcon 500 - Talon FX CAN IDs
const int kFrontRightMotorId = 0;
const int kBackRightMotorId  = 1;
const int kFrontLeftMotorId  = 2;
const int kBackLeftMotorId   = 3;

// ==== Cargo Transfer System ====
// REV SparkMax CAN IDs
const int kIntakeMotorId   = 1;
const int kConveyorMotorId = 2;
const int kElevatorMotorId = 3;

const double kIntakeSpeed = 0.6;
const double kConveyorSpeed = 0.6;
const double kElevatorSpeed = 0.5;

// Pnumatic CAN IDs
const int kCompressorId = 0;
const int kSolenoidIds[2] = {0, 1};

// ==== Turret System ====
// REV SparkMax CAN IDs
const int kLowerFlywheelMotorId  = 4;
const int kUpperFloywheelMotorId = 5;
const int kTurretMotorId         = 6;

const double kTurretLimitClockwise = 2.5;
const double kTurretLimitCounterclockwise = -2.5;

// ==== Climb System ====
// REV SparkMax CAN IDs
const int kLeftClimbMotorId  = 7;
const int kRightClimbMotorId = 8;

const double kClimbTopSoftStop = -80.0;
const double kClimbReleaseSpeed = 0.80;
const double kClimbRetractSpeed = 0.45;

// ==== Auto Constants ====
constexpr auto kAutoInitTime = 0.1_s;
constexpr auto kAutoTravelTime = 1.5_s;
constexpr auto kAutoFireTime = 0.5_s;

