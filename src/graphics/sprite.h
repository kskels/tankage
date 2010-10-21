/*
 * Snail Wail
 * 
 * (c) Copyright 2010 Peter Backman. All Rights Reserved. 
 */

#ifndef SPRITE_H_CD2WG4HZ
#define SPRITE_H_CD2WG4HZ

#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include "vec2.h"
#include "reference_frame2.h"
#include "graphics/vertex.h"
#include "rect.h"

class Texture;

namespace Graphics {
   class BoundedSprite;

   class Subsystem;

   class SpriteEventHandler {
   public:
      virtual ~SpriteEventHandler() {}
      
      virtual void enteredView() {}
      virtual void leftView() {}
   };
   

   class Sprite : public ReferenceFrame2 {
   private:
      Sprite(const boost::shared_ptr<Texture> & texture, BoundedSprite * sceneNode);

      friend class Graphics::Subsystem;

   public:
      std::vector<Vertex2T2> constructVertices() const;

      void enteredView();
      void leftView();
      
      // ReferenceFrame2 --------------------------------------------
      void setPosition(const vec2 & newPos);
      vec2 getPosition() const;
      void setOrientation(const mat2 & orient);
      mat2 getOrientation() const;
      // ------------------------------------------------------------
      
      rect getSize() const;

      void setEventHandler(const boost::weak_ptr<SpriteEventHandler> & eventHandler);
      
   private:
      boost::weak_ptr<SpriteEventHandler> eventHandler;
      boost::shared_ptr<Texture> texture;
      vec2 position;
      mat2 orientation;
      BoundedSprite * sceneNode;
   };
   
}

#endif /* end of include guard: SPRITE_H_CD2WG4HZ */
