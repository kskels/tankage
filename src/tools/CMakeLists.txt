
include_directories(
  ${PROJECT_ROOT_DIR}/3pp
)

file(GLOB HASHER_SOURCE "hasher/*.cpp")
add_executable(hasher
  ${HASHER_SOURCE}
)
target_link_libraries(hasher /home/kaspars/Desktop/md5-1.3.0/libmd5.a)

file(GLOB NETER_SOURCE "neter/*cpp")
add_executable(neter
  ${NETER_SOURCE}
)
target_link_libraries(neter enet)

