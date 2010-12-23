/*
 * Snail Wail
 * 
 * (c) Copyright 2010 Peter Backman. All Rights Reserved. 
 */

#ifndef MISSILE_LAUNCHER_H
#define MISSILE_LAUNCHER_H

#include "projectile_weapon.h"
#include "ref.h"

class ObjectCreator;
class World;
class Snail;

class MissileLauncher : public ProjectileWeapon {
public:
  MissileLauncher(ObjectCreator &creator, World &world,
                  const Ref<Snail>::WeakPtr &shooter);
  
  void shoot();

private:
  ObjectCreator &creator;
  World &world;
  Ref<Snail>::WeakPtr shooter;
};


#endif // !MISSILE_LAUNCHER_H
