
include_directories(
  ${PROJECT_ROOT_DIR}/3pp/include
)

add_library(twitcurl
  base64.cpp
  HMAC_SHA1.cpp
  oauthlib.cpp
  SHA1.cpp
  urlencode.cpp
  twitcurl.cpp
)

target_link_libraries(twitcurl
  curl
)

