// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/button/JoystickButton.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/DrivetrainSubsystem.h"
#include "subsystems/IntakeSubsystem.h"
#include "subsystems/TurretSubsystem.h"
#include "subsystems/ClimbSubsystem.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;
  DrivetrainSubsystem subsys_drivetrain;
  IntakeSubsystem subsys_intake;
  TurretSubsystem subsys_turret;
  ClimbSubsystem subsys_climb;

  frc::XboxController controller_driver{0};
  frc::XboxController controller_operator{1};

  void ConfigureButtonBindings();

};

