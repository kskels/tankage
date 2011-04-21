# -*- cmake -*-

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A 2D game where two tanks fight to the death.")
SET(CPACK_PACKAGE_NAME "tankage")
SET(CPACK_PACKAGE_VERSION_MAJOR ${BUILD_VERSION_MAJVAL})
SET(CPACK_PACKAGE_VERSION_MINOR ${BUILD_VERSION_MINVAL})

# From the maintainers guide package should have following naming convention
# <foo>_<VersionNumber>-<DebianRevisionNumber>_<DebianArchitecture>.deb
SET(CPACK_PACKAGE_FILE_NAME 
	"${CPACK_PACKAGE_NAME}_${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}-1_i386"
)




IF(APPLE)
  SET(CPACK_GENERATOR "Bundle")
  SET(CPACK_BUNDLE_NAME "Tankage")
  SET(CPACK_BUNDLE_PLIST "${PROJECT_ROOT_DIR}/build/osx_bundle/Info.plist")
  SET(CPACK_BUNDLE_ICON "${PROJECT_ROOT_DIR}/build/osx_bundle/Tankage.icns")
  SET(CPACK_BUNDLE_STARTUP_COMMAND "${PROJECT_ROOT_DIR}/build/osx_bundle/launcher.sh")
  SET(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}_${BUILD_VERSION}")
ELSE(APPLE)
  SET(CPACK_GENERATOR "DEB")
  SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Sillybat")

  # Dependencies needed on Ubuntu 10.10 (probably version can be lowered)
  SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libglfw2 (>= 2.6-2), libdevil1c2 (>= 1.7.8-6)")

  # Use the same install prefix for packages
  SET(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})

ENDIF(APPLE)




INCLUDE(CPack)

