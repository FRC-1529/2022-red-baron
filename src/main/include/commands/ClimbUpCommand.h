#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ClimbSubsystem.h"

class ClimbUp : public frc2::CommandHelper<frc2::CommandBase, ClimbUp> {
public:
    explicit ClimbUp(ClimbSubsystem* subsystem);

    void Execute() override;
    bool IsFinished() override;

private:
    ClimbSubsystem* subsystem;
};
