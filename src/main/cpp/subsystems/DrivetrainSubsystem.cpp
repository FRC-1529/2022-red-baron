// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DrivetrainSubsystem.h"

DrivetrainSubsystem::DrivetrainSubsystem() {
  // Implementation of subsystem constructor goes here.
}

void DrivetrainSubsystem::Drive (double x, double y)
{
  differential_drive.ArcadeDrive(x*0.75,y*0.75, true);
}

