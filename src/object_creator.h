/*
 * Snail Wail
 * 
 * (c) Copyright 2010 Peter Backman. All Rights Reserved. 
 */

#ifndef OBJECT_CREATOR_H_FSSO9BSX
#define OBJECT_CREATOR_H_FSSO9BSX

#include <boost/shared_ptr.hpp>

class Bullet;
class Snail;
class World;

class ObjectCreator {
public:
   ObjectCreator(World & world);
   
   boost::shared_ptr<Bullet> createBullet();
   boost::shared_ptr<Snail> createSnail(float x, ObjectCreator & creator, World & world);
   
private:
   World & world;
};

#endif /* end of include guard: OBJECT_CREATOR_H_FSSO9BSX */
