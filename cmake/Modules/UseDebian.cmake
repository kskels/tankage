
SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Peter & Co")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A 2D game where tow snails fight to the death.")

SET(CPACK_PACKAGE_NAME "snail-wail")

SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "1")

# From the maintainers guide package should have following naming convention
# <foo>_<VersionNumber>-<DebianRevisionNumber>_<DebianArchitecture>.deb
SET(CPACK_PACKAGE_FILE_NAME 
	"${CPACK_PACKAGE_NAME}_${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}-1_i383"
)

# Quick and dirty fix to create /usr/share/snail-wail/data folder otherwise
# package complains that folder doesn't exist 
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA 
	"${PROJECT_ROOT_DIR}/cmake/Scripts/preinst;${PROJECT_ROOT_DIR}/cmake/Scripts/postrm;"
)

# Dependencies needed on Ubuntu 10.10 (probably version can be lowered)
SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libglfw2 (>= 2.6-2), libdevil1c2 (>= 1.7.8-6)")

INCLUDE(CPack)

