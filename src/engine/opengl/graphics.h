#ifndef ENGINE_OPENGL_GRAPHICS_H
#define ENGINE_OPENGL_GRAPHICS_H

#include <engine/graphics.h>
#include <utils/singleton.h>
#include <utils/rect.h>
#include <vector>

namespace OpenGl {
class Graphics : public ::Graphics, public Singleton<Graphics> {
public:
  class Texture *createTexture(class Image *image);

  void clear(const class color4 &clearColor);
  void drawQuad(const class rect &quad, float dir);
  void drawQuad(const class rect &quad, const class rect &source);
  void drawQuads(const std::vector<rect> &quads);
  void drawQuads(unsigned components, unsigned vertices, float *coord, float *tc);
  
  void drawLinestrip(const std::vector<vec2> &lines);
  
  void drawCircle(const class vec2 &pos, float radius, float tess);
  
  void setTransform(const class vec2 &translation);
  void setOrtho(const class rect &size);
  void setViewport(const class rect &size);
  void setBlend(BlendMode mode);
  void setColor(const color4 &col);
  void setTexture(class Texture *texture);
  
  void enableTextures();
  void disableTextures();
};

}

#endif // !ENGINE_OPENGL_GRAPHICS_H
