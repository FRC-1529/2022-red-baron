// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ClimbSubsystem.h"

class ClimbMove
    : public frc2::CommandHelper<frc2::CommandBase, ClimbMove> {
 public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit ClimbMove(ClimbSubsystem* subsystem, std::function<double()> x, std::function<double()> y);

  void Execute() override;

 private:
  ClimbSubsystem* subsystem;
  std::function<double()> param_x;
  std::function<double()> param_y;
};
