/*
 * Snail Wail
 * 
 * (c) Copyright 2010 Peter Backman. All Rights Reserved. 
 */

#include "player_entity.h"
#include <algorithm>

PlayerEntity::PlayerEntity(float x) {
   xPos = x;
   shooting = 0;
   tshot = 0.0f;
}

void PlayerEntity::setTarget(const boost::weak_ptr<ReferenceFrame2D> & newTarget) {
   this->target = newTarget;
}

#include <iostream>
void shoot() {
   std::cout << "SHOOT" << std::endl;
}

void PlayerEntity::update(float dt) {
   tshot += dt;
   
   
   if (shooting == 1 || shooting == 3) {
      tshot = 0.0f;
      shoot();
      
      if (shooting == 1)
         shooting = 2;
      else
         shooting = 0;
   }
   else if (shooting == 2) {
      if (tshot >= 0.5) {
         tshot = 0.0f;
         shoot();
      }
   }
   
   
   if (boost::shared_ptr<ReferenceFrame2D> acquiredTarget = target.lock()) {
      vec2 pos = acquiredTarget->getPosition();
      pos.x = std::max(pos.x, -10.0f);
      pos.x = std::min(pos.x, 890.0f);
      pos.y = std::max(pos.y, 10.0f);
      pos.y = std::min(pos.y, 600.0f - 10.0f);


      vec2 delta = vec2(xPos, pos.y) - pos;

      if (delta.getMagnitude() > 50.0f) {
         delta.normalize();
         delta = delta * 50.0f;
      }
         
      acquiredTarget->setPosition(pos + delta * 5.0f * dt);
   }   
}

void PlayerEntity::setPosition(const vec2 & newPos) {
   if (boost::shared_ptr<ReferenceFrame2D> acquiredTarget = target.lock()) {
      acquiredTarget->setPosition(newPos);
   }
}

vec2 PlayerEntity::getPosition() const {
   if (boost::shared_ptr<ReferenceFrame2D> acquiredTarget = target.lock()) {
      return acquiredTarget->getPosition();
   }

   return vec2::Zero;
}

// 1 = on, 0 = off, -1 = one-shot
void PlayerEntity::trigger(const std::string & action, int state) {
   if (shooting == 2 && state == 0) // event triggered already, remove
      shooting = 0;
   else if (shooting == 0 && state == 1) // not been set for shooting yet
      shooting = 1;
   else if (shooting == 1 && state == 0)
      shooting = 3;
}
