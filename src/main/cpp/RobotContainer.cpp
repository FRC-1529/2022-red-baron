// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "commands/DrivetrainCommand.h"
#include "commands/IntakeCommand.h"
#include "commands/DeployIntakeCommand.h"
#include "commands/RetractIntakeCommand.h"
#include "commands/StopIntakeCommand.h"
#include "commands/TurnTurretCommand.h"
#include "commands/LaunchCommand.h"
#include "commands/StopTurretCommand.h"
#include "commands/ClimbMoveCommand.h"
#include "commands/ClimbStopCommand.h"

RobotContainer::RobotContainer()/* : m_autonomousCommand(&m_subsystem) */ {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  subsys_drivetrain.SetDefaultCommand(Drive(&subsys_drivetrain, [this] { return controller_driver.GetRightX(); }, [this] { return -controller_driver.GetLeftY(); }));
  subsys_climb.SetDefaultCommand(ClimbMove(&subsys_climb, [this] { return controller_operator.GetLeftY(); }, [this] { return controller_operator.GetRightY(); }));
  //subsys_turret.SetDefaultCommand(TurnTurret(&subsys_turret, [this] { return controller_operator.GetRightX()*0.1; }));
}

void RobotContainer::ConfigureButtonBindings() {
  frc2::Trigger([this] { return controller_operator.GetRightTriggerAxis() > .85; }).WhenActive(Launch(&subsys_turret), true).WhenInactive(StopTurret(&subsys_turret));

  frc2::JoystickButton(&controller_operator, frc::XboxController::Button::kA).WhenActive(Intake(&subsys_intake), true).WhenInactive(StopIntake(&subsys_intake));
  //frc2::JoystickButton(&controller_operator, frc::XboxController::Button::kRightBumper).WhenActive(ClimbUp(&subsys_climb)).WhenInactive(ClimbStop(&subsys_climb));
  //frc2::JoystickButton(&controller_operator, frc::XboxController::Button::kLeftBumper).WhenActive(ClimbDown(&subsys_climb)).WhenInactive(ClimbStop(&subsys_climb));


  frc2::JoystickButton(&controller_driver, frc::XboxController::Button::kRightBumper).WhenActive(DeployIntake(&subsys_intake));
  frc2::JoystickButton(&controller_driver, frc::XboxController::Button::kLeftBumper).WhenActive(RetractIntake(&subsys_intake));
  //frc2::JoystickButton(&controller_operator, frc::XboxController::Button::kX).WhenPressed(SpitOut(&subsys_intake));
}

// frc2::Command* RobotContainer::GetAutonomousCommand() {
//   // An example command will be run in autonomous
//   return &m_autonomousCommand;
// }

