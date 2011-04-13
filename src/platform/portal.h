#ifndef PLATFORM_PORTAL_H
#define PLATFORM_PORTAL_H

#include <map>
#include <string>

class Portal {
public:
  template<typename InterfaceT>
  void registerInterface() {
    InterfaceT &instance = InterfaceT::instance();
    addInterface(InterfaceT::id(), &instance);
  }

  template<typename InterfaceT>
  InterfaceT *requestInterface() const {
    return reinterpret_cast<InterfaceT *>(getInterface(InterfaceT::id()));
  }

private:
  typedef std::map<std::string, class Interface *> InterfaceMap;
  InterfaceMap interfaces;

  class Interface *getInterface(const std::string &id) const;
  void addInterface(const std::string &id, class Interface *interface);
};

#endif // !PLATFORM_PORTAL_H
