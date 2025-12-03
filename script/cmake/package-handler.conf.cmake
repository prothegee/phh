# info: seperator
string(APPEND PHH_FEATURES_LIST "#----------------------------------#\n")

include(${CMAKE_SOURCE_DIR}/script/cmake/package/argon2.conf.cmake)
include(${CMAKE_SOURCE_DIR}/script/cmake/package/blake.conf.cmake)
include(${CMAKE_SOURCE_DIR}/script/cmake/package/curl.conf.cmake)
include(${CMAKE_SOURCE_DIR}/script/cmake/package/drogon.conf.cmake)
include(${CMAKE_SOURCE_DIR}/script/cmake/package/jsoncpp.conf.cmake)
include(${CMAKE_SOURCE_DIR}/script/cmake/package/openssl.conf.cmake)
include(${CMAKE_SOURCE_DIR}/script/cmake/package/python3.conf.cmake)
include(${CMAKE_SOURCE_DIR}/script/cmake/package/stb.conf.cmake)

