#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/IntakeSubsystem.h"

class StopIntake : public frc2::CommandHelper<frc2::CommandBase, StopIntake> {
public:
    explicit StopIntake(IntakeSubsystem* subsystem);

    void Initialize() override;
    bool IsFinished() override;

private:
    IntakeSubsystem* subsystem;



};
