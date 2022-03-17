#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ClimbSubsystem.h"

class ClimbStop : public frc2::CommandHelper<frc2::CommandBase, ClimbStop> {
public:
    explicit ClimbStop(ClimbSubsystem* subsystem);

    void Execute() override;
    bool IsFinished() override;

private:
    ClimbSubsystem* subsystem;
};
