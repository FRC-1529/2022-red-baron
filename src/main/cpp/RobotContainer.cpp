// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "commands/DrivetrainCommand.h"
#include "commands/IntakeCommand.h"
#include "commands/SpitOutCommand.h"
#include "subsystems/IntakeSubsystem.h"
#include "commands/ShootCommand.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  subsys_drivetrain.SetDefaultCommand(Drive(&subsys_drivetrain, [this] { return -controller_driver.GetLeftY(); }, [this] { return controller_driver.GetRightY(); }));
  subsys_shooter.SetDefaultCommand(Shoot(&subsys_shooter, [this] {return controller_operator.GetRightTriggerAxis();}));
}

void RobotContainer::ConfigureButtonBindings() {
  frc2::JoystickButton(&controller_operator, frc::XboxController::Button::kA).WhenPressed(Intake(&subsys_intake));
  frc2::JoystickButton(&controller_operator, frc::XboxController::Button::kX).WhenPressed(SpitOut(&subsys_intake));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
