#include "ai_control.h"
#include <game/common/snails.h>

AIControl::AIControl()
{
}

void AIControl::update() {
  Snail *target = context->snails()->snail(Snails::SNAIL_RIGHT);
  target->startState(Snail::STATE_MOVE_UP);
}
