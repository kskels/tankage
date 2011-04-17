
UNSET(BOX2D_INCLUDE_DIR CACHE)
FIND_PATH(BOX2D_INCLUDE_DIR Box2D.h
   HINTS /usr/include /usr/local/include $ENV{BOX2D_ROOT}/include
   ${PROJECT_ROOT_DIR}/3pp/include
   PATH_SUFFIXES Box2D
)

UNSET(BOX2D_LIBRARY CACHE)
FIND_LIBRARY(BOX2D_LIBRARY Box2D
   HINTS /usr/lib /usr/local/lib $ENV{BOX2D_ROOT}/lib
   ${PROJECT_ROOT_DIR}/3pp/lib
)

#IF(BOX2D_LIBRARY AND BOX2D_LIBRARY)
   message(STATUS "Found Box2D: ${BOX2D_INCLUDE_DIR} ${BOX2D_LIBRARY}")
#ELSE(BOX2D_LIBRARY AND BOX2D_LIBRARY)
#   message(SEND_ERROR "Box2D couldn't be found")
#ENDIF(BOX2D_LIBRARY AND BOX2D_LIBRARY)

