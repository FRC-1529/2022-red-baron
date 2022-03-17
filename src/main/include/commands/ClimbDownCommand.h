#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ClimbSubsystem.h"

class ClimbDown : public frc2::CommandHelper<frc2::CommandBase, ClimbDown> {
public:
    explicit ClimbDown(ClimbSubsystem* subsystem);

    void Execute() override;
    bool IsFinished() override;

private:
    ClimbSubsystem* subsystem;
};
