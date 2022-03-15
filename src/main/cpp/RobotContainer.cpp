// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "commands/DrivetrainCommand.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  subsys_drivetrain.SetDefaultCommand(Drive(&subsys_drivetrain, [this] { return controller_driver.GetRightX(); }, [this] { return controller_driver.GetLeftY(); }));
  
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}
