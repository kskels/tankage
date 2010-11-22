/*
 * Snail Wail
 * 
 * (c) Copyright 2010 Peter Backman. All Rights Reserved. 
 */

#ifndef GRAPHICS_DEVICE_H
#define GRAPHICS_DEVICE_H

#include "ref.h"

namespace Graphics {
   class RenderContext;
   class Texture;
   class Mesh;
   
   class Device {
   public:
	   virtual ~Device() {}
	  
	   virtual Graphics::RenderContext * createContext() =0;
	   virtual Graphics::Texture * createTexture(const void * data, int width, int height, int bpp, int format) =0;
      virtual void drawMesh(const Ref<Graphics::Mesh>::SharedPtr & mesh) =0;
   };

}


#endif // !GRAPHICS_DEVICE_H
