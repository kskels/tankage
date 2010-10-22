/*
 * Snail Wail
 * 
 * (c) Copyright 2010 Peter Backman. All Rights Reserved. 
 */

#include "geom.h"

Physics::Geom::Geom(const rect & size)
   : size(size)
{
   
}

void Physics::Geom::setPosition(const vec2 & newPos) {
   
}

vec2 Physics::Geom::getPosition() const {
   return vec2::Zero;
}

void Physics::Geom::setOrientation(const mat2 & orient) {
   
}

mat2 Physics::Geom::getOrientation() const {
   return mat2::Identity;
}