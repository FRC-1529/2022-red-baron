#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/IntakeSubsystem.h"

class SpitOut : public frc2::CommandHelper<frc2::CommandBase, SpitOut> {
public:
    explicit SpitOut(IntakeSubsystem* subsystem);

    void Execute() override;

private:
    IntakeSubsystem* subsystem;
};