
file(GLOB MD5_SOURCE "*.c")
add_library(md5 EXCLUDE_FROM_ALL
  ${MD5_SOURCE}
)

