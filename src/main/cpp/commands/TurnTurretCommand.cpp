// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TurnTurretCommand.h"

TurnTurret::TurnTurret(TurretSubsystem* subsystem, std::function<double()> x) : m_turret{subsystem}, param_x{std::move(x)} {
    AddRequirements({subsystem});
}

void TurnTurret::Execute() {
    m_turret->turn(param_x());
}

