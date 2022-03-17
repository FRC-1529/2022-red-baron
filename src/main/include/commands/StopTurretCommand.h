#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/TurretSubsystem.h"

class StopTurret : public frc2::CommandHelper<frc2::CommandBase, StopTurret> {
public:
    explicit StopTurret(TurretSubsystem* subsystem);

    void Execute() override;
    bool IsFinished() override;
    void End();

private:
    TurretSubsystem* subsystem;
};
