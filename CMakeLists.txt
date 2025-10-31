cmake_minimum_required(VERSION 3.25)

set(PHH_VERSION_MAJOR 0)
set(PHH_VERSION_MINOR 1)
set(PHH_VERSION_PATCH 0)
set(PHH_VERSION_RELEASE_DATE 20251031)

set(PHH_FEATURES_LIST)
set(PHH_CXX_COMPILER_NAME)

# strict policy
## C0301: long value in cmake file/s

project(phh-project)

# options
option(PHH_BUILD_TEST
    "phh build test"
    OFF
)
option(PHH_BUILD_TOOL
    "phh build tool"
    OFF
)
# option(PHH_ZXING_QRCODE_IMAGE_EMBEDDED
#     "phh zxing-cpp able to embedded an image"
#     OFF
# ) # postpone

# debug stat preproc
if(NOT DEFINED PHH_IS_DEBUG)
    set(PHH_IS_DEBUG true)
endif()

# release build type only to disable debug
if(CMAKE_BUILD_TYPE STREQUAL "Release"
    OR
    CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    set(PHH_IS_DEBUG false)
else()
    set(PHH_IS_DEBUG true)
endif()

if(NOT DEFINED CMAKE_CXX_STANDARD_REQUIRED)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(NOT DEFINED CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

if(NOT DEFINED CMAKE_CXX_FLAGS)
    set(CMAKE_CXX_FLAGS)
endif()

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif()
# force c++ standard can't be less 23
if(${CMAKE_CXX_STANDARD} LESS 23)
    message(FATAL_ERROR "cxx standard can't be less than c++23")
endif()
if(${CMAKE_CXX_STANDARD} STRLESS 23)
    message(FATAL_ERROR "cxx standard can't be less than c++23")
endif()

# helper preproc c++ standard if cxx flags is not found
set(PHH_CXX_STANDARD)
set(PHH_CXX_STANDARD_ARGS)
set(PHH_CXX_STANDARD_ARGS "-std=c++${CMAKE_CXX_STANDARD}")
if (MSVC) # overwrite for msvc windows
    set(PHH_CXX_STANDARD_ARGS "/std:c++${CMAKE_CXX_STANDARD}")
endif()
string(FIND
    "${CMAKE_CXX_FLAGS}"
    "${PHH_CXX_STANDARD_ARGS}"
    PHH_CXX_STANDARD
)
if(PHH_CXX_STANDARD EQUAL -1)
    set(CMAKE_CXX_FLAGS
        "${PHH_CXX_STANDARD_ARGS}"
    )
endif()

include(CheckIncludeFileCXX)
include(GenerateExportHeader)
include(CMakeDependentOption)
include(CMakeFindDependencyMacro)
include(CMakePackageConfigHelpers)
include(FindPackageHandleStandardArgs)

# build system
set(PHH_BUILD_SYSTEM)
set(PHH_IS_LINUX false)
set(PHH_IS_MACOS false)
set(PHH_IS_WINDOWS false)
set(PHH_IS_ANDROID false)
set(PHH_IS_IOS false)

if(LINUX)
    set(PHH_IS_LINUX true)
    set(PHH_BUILD_SYSTEM "GNU / Linux")
    message(STATUS "build system: linux")
elseif(ANDROID)
    set(PHH_IS_ANDROID true)
    set(PHH_BUILD_SYSTEM "Android")
    message(STATUS "build system: android")
    message(WARNING "build system is not supported, you are on your own risk")
elseif(APPLE)
    set(PHH_IS_MACOS true)
    set(PHH_BUILD_SYSTEM "Apple MacOS")
    message(STATUS "build system: macos")
    message(WARNING "build system is not supported, you are on your own risk")

    if(IOS)
        set(PHH_IS_IOS true)
        set(PHH_BUILD_SYSTEM "Apple iOs")
    endif()
elseif(WIN32)
    set(PHH_IS_WINDOWS)
    set(PHH_BUILD_SYSTEM "Windows")
    message(WARNING "build system is not supported, you are on your own risk")
else()
    set(PHH_BUILD_SYSTEM "UNKNOWN")
    # not meant to be
    message(AUTHOR_WARNING "build system: unknown")
    message(WARNING "build system is not supported, you are on your own risk")
endif()

# package handler
include(script/cmake/package-handler.conf.cmake)

# library: phh
add_subdirectory(phh _lib)

# test subdir
if(PHH_BUILD_TEST)
    add_subdirectory(test/phh _test)
endif()

# tool subdir
if(PHH_BUILD_TOOL)
    message(NOTICE "NOTE: -DPHH_BUILD_TOOL is ON")
endif()

# info: seperator
string(APPEND PHH_FEATURES_LIST "#----------------------------------#\n")
# info: compiler info
string(APPEND PHH_FEATURES_LIST "- Compiler             : ${CMAKE_CXX_COMPILER_ID}\n")
# info: build sys, test, & tool
string(APPEND PHH_FEATURES_LIST "- Build sys            : ${PHH_BUILD_SYSTEM}\n")
string(APPEND PHH_FEATURES_LIST "- Build test           : ${PHH_BUILD_TEST}\n")
string(APPEND PHH_FEATURES_LIST "- Build tool           : ${PHH_BUILD_TOOL}\n")
# info: last CMAKE_CXX_FLAGS
string(APPEND PHH_FEATURES_LIST "- CMAKE_CXX_FLAGS      : ${CMAKE_CXX_FLAGS}\n")
# info: last CMAKE_CXX_FLAGS
string(APPEND PHH_FEATURES_LIST "- CMAKE_CXX_STANDARD   : ${CMAKE_CXX_STANDARD}\n")

# check status
message(NOTICE "#----------------------------------#")
message(NOTICE "  ${PROJECT_NAME} configuration status\n"
    "${PHH_FEATURES_LIST}"
)

