// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ClimbMoveCommand.h"

ClimbMove::ClimbMove(ClimbSubsystem* subsystem, std::function<double()> x, std::function<double()> y) : subsystem{subsystem}, param_x{std::move(x)}, param_y{std::move(y)} {
    AddRequirements({subsystem});
}

void ClimbMove::Execute() {
    subsystem->move(param_x(), param_y());
}


