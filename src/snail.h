/*
 * Snail Wail
 * 
 * (c) Copyright 2010 Peter Backman. All Rights Reserved. 
 */

#ifndef SNAIL_H_7SGQH1KL
#define SNAIL_H_7SGQH1KL

#include "object.h"
#include "ref.h"
#include "physics/geom.h"
#include "physics/body.h"
#include "coord_system2.h"

namespace Graphics {class Subsystem; }

class Sprite;
class Geom;
class PlayerEntity;
class World;
class vec2;
class Helmet;
class HealthMeter;

class SnailEventHandler {
public:
  virtual ~SnailEventHandler() {}
   
  virtual void onHealthChange(float newValue, float diff) =0;
};


class Snail : public Object, public CoordSystem2, public GeomEventHandler {
public:
  Snail();
  
  void setTransform(const CoordSystemData2 & cs);
  CoordSystemData2 getTransform() const;
   
  void collided(const Ref<Geom>::SharedPtr & with);
  
  void setEventHandler(const Ref<SnailEventHandler> & newHandler);
  void increaseHealth(int add);
  
  Ref<SnailEventHandler> eventHandler;
  Ref<Sprite> sprite;
  Ref<Helmet> helmet;
  Ref<PlayerEntity> logic;
  Ref<Geom> physGeom;
  Ref<Body> physBody;
  Ref<Snail>::WeakPtr enemy;
  
private:
  int health;
};

#endif /* end of include guard: SNAIL_H_7SGQH1KL */
