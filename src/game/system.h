#ifndef GAME_SYSTEM_H
#define GAME_SYSTEM_H


class SystemContext {
public:
  SystemContext();

  enum {
    SYSTEM_SNAILS,
    SYSTEM_BACKGROUND,
    SYSTEM_CONTROL,
    SYSTEM_ITEMS,
    SYSTEM_PARTICLES,
    SYSTEM_TEXTURE_LOADER,
    SYSTEM_MAX
  };
  
  void set(unsigned id, class System *system);

  template<typename T>
  T *system(unsigned id) const {
    return reinterpret_cast<T *>(resolveSystem(id));
  }
  
  void init(class Portal &modules);

  class Items *items() const {
    return system<Items>(SystemContext::SYSTEM_ITEMS);
  }

  class Snails *snails() const {
    return system<Snails>(SystemContext::SYSTEM_SNAILS);
  }

  class Particles *particles() const {
    return system<Particles>(SystemContext::SYSTEM_PARTICLES);
  }

  class TextureLoader *textureLoader() const {
    return system<TextureLoader>(SystemContext::SYSTEM_TEXTURE_LOADER);
  }
  
private:
  class System *resolveSystem(unsigned id) const;
  
  class System *systems[SYSTEM_MAX];
  
  bool ready;
};

class System {
public:
  virtual ~System() {}

  virtual void init(const class Portal &modules) =0;
  
  friend class SystemContext;
protected:
  const SystemContext *context;
};

#endif // !GAME_SYSTEM_H
