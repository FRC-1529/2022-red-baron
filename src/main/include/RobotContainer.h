// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/XboxController.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/WaitUntilCommand.h>
#include <frc2/command/WaitCommand.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"
#include "subsystems/DrivetrainSubsystem.h"
#include "subsystems/IntakeSubsystem.h"
#include "subsystems/TurretSubsystem.h"
#include "subsystems/ClimbSubsystem.h"

class RobotContainer {
 public:
  RobotContainer();
  void onAutoInit();
  void onAutoExit();
  void onTeleopInit();
  void onTeleopExit();

  frc2::Command* GetAutonomousCommand();


 private:
  DrivetrainSubsystem subsys_drivetrain;
  IntakeSubsystem subsys_intake;
  TurretSubsystem subsys_turret;
  ClimbSubsystem subsys_climb;

  frc::Timer autoTimer;

  // frc2::SequentialCommandGroup m_autonomousCommand{
  //   m_autonomousCommandInit
  //   // m_autonomousCommandDrive,
  //   // m_autonomousCommandFire,
  //   // m_autonomousCommandExit,
  // };

  frc2::FunctionalCommand m_autonomousCommandInit = frc2::FunctionalCommand(
      // Reset encoders on command start
      [this] { autoTimer.Reset(); autoTimer.Start(); },
      // Drive forward while the command is executing
      [this] { subsys_turret.setFlywheelSpeed(-0.6, 0.6); },
      // Stop driving at the end of the command
      [this](bool interrupted) { },
      // End the command when the robot's driven distance exceeds the desired
      // value
      [this] {
        return autoTimer.HasElapsed(kAutoInitTime);
      },
      // Requires the drive subsystem
      {&subsys_turret});

  frc2::FunctionalCommand m_autonomousCommandDrive = frc2::FunctionalCommand(
      // Reset encoders on command start
      [this] { autoTimer.Reset(); autoTimer.Start(); },
      // Drive forward while the command is executing
      [this] { subsys_drivetrain.arcadeDrive(0, -0.6, false, false); },
      // Stop driving at the end of the command
      [this](bool interrupted) { subsys_drivetrain.arcadeDrive(0, 0.0, false, false);},
      // End the command when the robot's driven distance exceeds the desired
      // value
      [this] {
        return autoTimer.HasElapsed(kAutoTravelTime);
      },
      // Requires the drive subsystem
      {&subsys_drivetrain});

  frc2::FunctionalCommand m_autonomousCommandFire = frc2::FunctionalCommand(
      // Reset encoders on command start
      [this] { autoTimer.Reset(); autoTimer.Start(); },
      // Drive forward while the command is executing
      [this] { subsys_intake.runElevator(); },
      // Stop driving at the end of the command
      [this](bool interrupted) { subsys_intake.stopElevator(); },
      // End the command when the robot's driven distance exceeds the desired
      // value
      [this] {
        return autoTimer.HasElapsed(kAutoFireTime);
      },
      // Requires the drive subsystem
      {&subsys_intake});
  frc2::FunctionalCommand m_autonomousCommandExit = frc2::FunctionalCommand(
      // Reset encoders on command start
      [this] { autoTimer.Reset(); autoTimer.Start(); },
      // Drive forward while the command is executing
      [this] { subsys_turret.setFlywheelSpeed(0.0, 0.0); },
      // Stop driving at the end of the command
      [this](bool interrupted) { },
      // End the command when the robot's driven distance exceeds the desired
      // value
      [this] {
        return autoTimer.HasElapsed(kAutoInitTime);
      },
      // Requires the drive subsystem
      {&subsys_turret});
  // frc2::FunctionalCommand m_autonomousCommandShoot = frc2::FunctionalCommand(
  //   [this] { autoTimer.Reset(); autoTimer.Start(); },
  //   [this] { subsys_intake.runElevator(); },
  //   [this](bool interrupted) { subsys_turret.setFlywheelSpeed(0.0, 0.0); subsys_intake.stopElevator(); autoTimer.Stop(); },
  //   [this] { return autoTimer.HasElapsed(kAutoFireTime); },
  //   {&subsys_intake, &subsys_turret});
  // frc2::SequentialCommandGroup m_autonomousCommand =
  //     frc2::SequentialCommandGroup{
  //       frc2::InstantCommand([this] { autoTimer.Start(); }),
  //       frc2::InstantCommand([this] { autoTimer.Stop(); })
  //       // driveCommand,
  //       };

  frc::XboxController controller_driver{0};
  frc::XboxController controller_operator{1};


  void ConfigureButtonBindings();

};

