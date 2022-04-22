// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <frc2/command/RunCommand.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/Trigger.h>

RobotContainer::RobotContainer()/* : m_autonomousCommand(&m_subsystem) */ {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
  
  subsys_drivetrain.SetDefaultCommand(frc2::RunCommand(
    [this] {
      subsys_drivetrain.arcadeDrive(controller_driver.GetRightX(), -controller_driver.GetLeftY(), controller_driver.GetLeftTriggerAxis() > .85, controller_driver.GetRightTriggerAxis() > .85);
    }, {&subsys_drivetrain}));

  subsys_turret.SetDefaultCommand(frc2::RunCommand(
    [this] {
      subsys_turret.turnTurret(controller_operator.GetRightX());
    }, {&subsys_turret}));

}

void RobotContainer::ConfigureButtonBindings() {
  //Drivers Commands
  frc2::JoystickButton(&controller_driver,frc::XboxController::Button::kLeftBumper)
    .WhenPressed(frc2::InstantCommand(
      [this] { 
        subsys_intake.retractIntake();
      }, {&subsys_intake}));
  frc2::JoystickButton(&controller_driver,frc::XboxController::Button::kRightBumper)
    .WhenPressed(frc2::InstantCommand(
      [this] { 
        subsys_intake.deployIntake();
      }, {&subsys_intake}));
  

  //Operators Commands

  frc2::Trigger([this] { return controller_operator.GetLeftTriggerAxis() >= 0.8; })
    .WhileActiveContinous([this] { subsys_turret.setFlywheelSpeed(-0.35, 0.35); }, {&subsys_turret})
    .WhenInactive([this] { subsys_turret.setFlywheelSpeed(0.0, 0.0); }, {&subsys_turret});

  frc2::Trigger([this] { return controller_operator.GetRightTriggerAxis() >= 0.8; })
    .WhileActiveContinous([this] { subsys_turret.setFlywheelSpeed(-0.65, 0.65); }, {&subsys_turret})
    .WhenInactive([this] { subsys_turret.setFlywheelSpeed(0.0, 0.0); }, {&subsys_turret});

  frc2::Trigger([this] { return controller_operator.GetPOV() == 0; })
    .WhenActive([this] { subsys_intake.deployIntake(); }, {&subsys_intake});

  frc2::Trigger([this] { return controller_operator.GetPOV() == 180; })
    .WhenActive([this] { subsys_intake.retractIntake(); }, {&subsys_intake});
    

  frc2::JoystickButton(&controller_operator, frc::XboxController::Button::kA)
    .WhenPressed(frc2::InstantCommand(
      [this] {
        subsys_intake.spinIntake();
        subsys_intake.runConveyor();
      }, {&subsys_intake}
    ))
    .WhenReleased(frc2::InstantCommand(
      [this] {
        subsys_intake.stopIntake();
        subsys_intake.stopConveyor();
      }, {&subsys_intake}));

  frc2::JoystickButton(&controller_operator, frc::XboxController::Button::kX)
    .WhenPressed(frc2::InstantCommand(
      [this] {
        subsys_intake.reverseElevator();
      }, {&subsys_intake}
    ))
    .WhenReleased(frc2::InstantCommand(
      [this] {
        subsys_intake.stopElevator();
      }, {&subsys_intake}));

  frc2::JoystickButton(&controller_operator, frc::XboxController::Button::kB)
    .WhenPressed(frc2::InstantCommand(
      [this] {
        subsys_intake.runElevator();
      }, {&subsys_intake}
    ))
    .WhenReleased(frc2::InstantCommand(
      [this] {
        subsys_intake.stopElevator();
      }, {&subsys_intake}));

  frc2::JoystickButton(&controller_operator, frc::XboxController::Button::kLeftBumper)
    .WhenPressed(frc2::InstantCommand(
      [this] {
        subsys_climb.retractLeft();
      }, {&subsys_climb}
    ))
    .WhenReleased(frc2::InstantCommand(
      [this] {
        subsys_climb.stop();
      }, {&subsys_climb}));

  frc2::JoystickButton(&controller_operator, frc::XboxController::Button::kRightBumper)
    .WhenPressed(frc2::InstantCommand(
      [this] {
        subsys_climb.retractRight();
      }, {&subsys_climb}
    ))
    .WhenReleased(frc2::InstantCommand(
      [this] {
        subsys_climb.stop();
      }, {&subsys_climb}));

  frc2::JoystickButton(&controller_operator,frc::XboxController::Button::kY)
    .WhenPressed(frc2::InstantCommand(
      [this] { 
        subsys_climb.release();
      }, {&subsys_climb}))
    .WhenReleased(frc2::InstantCommand(
      [this] { 
        subsys_climb.stop();
      }, {&subsys_climb}));

}

void RobotContainer::onAutoInit() {
  subsys_drivetrain.onAutoInit();
  subsys_intake.onAutoInit();
  subsys_turret.onAutoInit();
}
void RobotContainer::onAutoExit() {
  subsys_drivetrain.onAutoExit();
  subsys_intake.onAutoExit();
  subsys_turret.onAutoExit();
}
void RobotContainer::onTeleopInit() {
  subsys_drivetrain.onTeleopInit();
  subsys_intake.onTeleopInit();
  subsys_turret.onTeleopInit();
  subsys_climb.onTeleopInit();
}
void RobotContainer::onTeleopExit() {
  subsys_drivetrain.onTeleopExit();
  subsys_intake.onTeleopExit();
  subsys_turret.onTeleopExit();
  subsys_climb.onTeleopExit();
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // Runs the chosen command in autonomous
  return &m_autonomousCommandDrive;
}

