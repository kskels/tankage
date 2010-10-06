/*
 * Snail Wail
 * 
 * (c) Copyright 2010 Peter Backman. All Rights Reserved. 
 */

#ifndef HI_CONTROLLER_H_TRQG6TL3
#define HI_CONTROLLER_H_TRQG6TL3

#include <vector>
#include <boost/weak_ptr.hpp>

class ReferenceFrame2D;
class Triggerable;

class HiController {
public:
   HiController();
   
   void toggle(const std::string & key, int state);
   void startDirection(int dir);
   void stopDirection(int dir);
   void update(float dt);
   void setRefFrameDelegate(const boost::weak_ptr<ReferenceFrame2D> & newTarget);
   void setActionDelegate(const boost::weak_ptr<Triggerable> & newTarget);
   
private:
   boost::weak_ptr<ReferenceFrame2D> reframeDelegate;
   boost::weak_ptr<Triggerable> actionDelegate;
   std::vector<bool> activeDirs;
};


#endif /* end of include guard: HI_CONTROLLER_H_TRQG6TL3 */
