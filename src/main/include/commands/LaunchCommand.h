#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/TurretSubsystem.h"

class Launch : public frc2::CommandHelper<frc2::CommandBase, Launch> {
public:
    explicit Launch(TurretSubsystem* subsystem);

    void Execute() override;
    bool IsFinished() override;

private:
    TurretSubsystem* subsystem;
};
