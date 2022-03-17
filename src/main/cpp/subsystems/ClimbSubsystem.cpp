#include <subsystems/ClimbSubsystem.h>

ClimbSubsystem::ClimbSubsystem() {}

void ClimbSubsystem::goUp() {
    leftClimbMotor.Set(-0.2);
    rightClimbMotor.Set(0.2);
}

void ClimbSubsystem::goDown() {
    leftClimbMotor.Set(0.2);
    rightClimbMotor.Set(-0.2);
}

void ClimbSubsystem::stop() {
    leftClimbMotor.Set(0.0);
    rightClimbMotor.Set(0.0);
}