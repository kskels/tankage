#ifndef PLATFORM_IMAGE_LOADER_H
#define PLATFORM_IMAGE_LOADER_H

#include <platform/interface.h>
#include <platform/image_loader.h>

class ImageLoader : public Interface {
public:
  static std::string id() {
    return "image_loader";
  }

  virtual class Image *loadImage(const std::string &filename) =0;
};

#endif // !PLATFORM_IMAGE_LOADER_H
