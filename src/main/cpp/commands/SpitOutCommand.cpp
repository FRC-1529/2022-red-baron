#include "commands/SpitOutCommand.h"

SpitOut::SpitOut(IntakeSubsystem* subsystem) : subsystem{subsystem}{
    AddRequirements({subsystem});
}

void SpitOut::Execute(){
    subsystem->spit_out();
}