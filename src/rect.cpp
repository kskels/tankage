/*
 * Snail Wail
 * 
 * (c) Copyright 2010 Peter Backman. All Rights Reserved. 
 */

#include "rect.h"

rect::rect(const vec2 & origin, const vec2 & halfSize)
   : origin(origin)
   , halfSize(halfSize)
{

}

void rect::getCoords(vec2 & upperLeft, vec2 & lowerRight) const {
   upperLeft = origin - halfSize;
   lowerRight = origin + halfSize;
}

bool rect::intersect(const rect & r1, const rect & r2) {
   vec2 r1u, r1l;
   vec2 r2u, r2l;
   
   r1.getCoords(r1u, r1l);
   r2.getCoords(r2u, r2l);
   
   return !(r1u.x > r2l.x || r1l.x < r2u.x || r1u.y > r2l.y || r1l.y < r2u.y);
}