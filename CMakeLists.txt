cmake_minimum_required(VERSION 3.18)

set(PHH_VERSION_MAJOR
    0
)
set(PHH_VERSION_MINOR
    0
)
set(PHH_VERSION_PATCH
    0
)
set(PHH_VERSION_RELEASE_DATE
    20250612
)

set(PHH_FEATURES_LIST)
set(PHH_COMPILER_NAME)

project(phh)

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
    set(CMAKE_CXX_STANDARD 17)
endif()
# force c++ standard can't be less 17
if(${CMAKE_CXX_STANDARD} LESS 17)
    message(FATAL_ERROR "cxx standard can't be less than c++17")
endif()
if(${CMAKE_CXX_STANDARD} STRLESS 17)
    message(FATAL_ERROR "cxx standard can't be less than c++17")
endif()

# helper preproc c++ standard if cxx flags is not found
set(PHH_CXX_STANDARD)
set(PHH_CXX_STANDARD_ARGS)
if(MSVC)
    set(PHH_CXX_STANDARD_ARGS "/std:c++${CMAKE_CXX_STANDARD}")
else()
    set(PHH_CXX_STANDARD_ARGS "-std=c++${CMAKE_CXX_STANDARD}")
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
if(LINUX)
    add_definitions(-D_LINUX)
    message(STATUS "build system: linux")
elseif(WIN32)
    add_definitions(-D_WIN32)
    add_definitions(-D_WINDOWS)
    message(STATUS "build system: windows")
elseif(APPLE)
    add_definitions(-D_APPLE)
    add_definitions(-D_MACOS)
    message(STATUS "build system: macos")
else()
    # not meant to be
    message(AUTHOR_WARNING "build system: unknown")
endif()

# package handler
include(script/cmake/package-handler.conf.cmake)

# library
add_library(${PROJECT_NAME}
    "src/lib.cc"
)

# compiler options
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-value
        -Wno-unused-variable
        -Wno-reorder
        -Wno-parentheses
        -Wno-switch
        -Wno-format
        -Wno-invalid-offsetof
        -Wno-multichar
        -Wno-char-subscripts
        -Wno-empty-body
        -Wno-unused-function
        -Wunused-parameter
        -Wno-deprecated-declarations
    )
    set(PHH_COMPILER_NAME "GNU")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
    )
    add_definitions(-D_MSVC)
    set(PHH_COMPILER_NAME "MSVC")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "[Cc]lang")
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-value
        -Wno-unused-variable
        -Wno-reorder
        -Wno-parentheses
        -Wno-switch
        -Wno-format
        -Wno-invalid-offsetof
        -Wno-multichar
        -Wno-char-subscripts
        -Wno-empty-body
        -Wno-unused-function
        -Wunused-parameter
        -Wno-deprecated-declarations
    )
    add_definitions(-D_CLANG)
    set(PHH_COMPILER_NAME "CLANG")
else()
    message(NOTICE
        "-- ${PROJECT_NAME}:
        -DCMAKE_CXX_COMPILER_ID is not supported as ${CMAKE_CXX_COMPILER_ID}
        "
    )
    set(PHH_COMPILER_NAME "UNKNOWN")
endif()
string(APPEND PHH_FEATURES_LIST "- Compiler         : ${PHH_COMPILER_NAME}\n")

# target link library

# test subdir
if(PHH_BUILD_TEST)
    #
endif()

# tool subdir
if(PHH_BUILD_TOOL)
    #
endif()

# check last CMAKE_CXX_FLAGS
string(APPEND PHH_FEATURES_LIST "- CMAKE_CXX_FLAGS  : ${CMAKE_CXX_FLAGS}\n")

# check status
message(NOTICE "# ${PROJECT_NAME} configuration status:\n"
    "${PHH_FEATURES_LIST}"
)
