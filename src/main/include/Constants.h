// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once


// ==== Drivetrain System ====
// Falcon 500 - Talon FX CAN IDs
const int kFrontRightMotorId = 0;
const int kBackRightMotorId  = 1;
const int kFrontLeftMotorId  = 2;
const int kBackLeftMotorId   = 4;

// ==== Cargo Transfer System ====
// REV SparkMax CAN IDs
const int kIntakeMotorId   = 1;
const int kConveyorMotorId = 2;
const int kElevatorMotorId = 3;

// Pnumatic CAN IDs
const int kCompressorId = 0;
const int kSolenoidIds[2] = {0, 1};

// ==== Turret System ====
// REV SparkMax CAN IDs
const int kLowerFlywheelMotorId  = 4;
const int kUpperFloywheelMotorId = 5;
const int kTurretMotorId         = 6;

// ==== Climb System ====
// REV SparkMax CAN IDs
const int kLeftClimbMotorId  = 7;
const int kRightClimbMotorId = 8;


