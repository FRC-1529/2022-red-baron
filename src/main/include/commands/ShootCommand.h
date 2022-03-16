#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ShooterSubsystem.h"

class Shoot : public frc2::CommandHelper<frc2::CommandBase, Shoot>{
public:
    explicit Shoot(ShooterSubsystem* subsystem, std::function<double()> shot_power);

    void Execute() override;

private:
    ShooterSubsystem* subsystem;
    std::function<double()> trigger;
};