if(NOT LINUX)
    message(AUTHOR_WARNING "none linux platform is not officially support")
endif()

if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()
if(NOT DEFINED PHH_IS_DEBUG)
    set(PHH_IS_DEBUG true)
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    set(PHH_IS_DEBUG false)
endif()

if(NOT DEFINED CMAKE_CXX_STANDARD_REQUIRED)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(NOT DEFINED CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif()

if(NOT DEFINED CMAKE_CXX_FLAGS)
    set(CMAKE_CXX_FLAGS "-std=c++${CMAKE_CXX_STANDARD}")
    # future use
    # if(MSVC)
    #     set(CMAKE_CXX_FLAGS "/std:c++${CMAKE_CXX_STANDARD}")
    # endif()
endif()

# force c++23
if(CMAKE_CXX_STANDARD LESS 23)
    message(FATAL_ERROR "PHH ERROR: this project meant to be used with c++23 or greater")
endif()
