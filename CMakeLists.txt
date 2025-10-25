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

# strict policy
## C0301: long value in cmake file/s

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

if(LINUX)
    set(PHH_IS_LINUX true)
    set(PHH_BUILD_SYSTEM "GNU / Linux")
    message(STATUS "build system: linux")
elseif(APPLE)
    set(PHH_IS_MACOS true)
    set(PHH_BUILD_SYSTEM "Apple MacOS")
    message(STATUS "build system: macos")
elseif(WIN32)
    set(PHH_IS_WINDOWS)
    set(PHH_BUILD_SYSTEM "Windows")
    message(STATUS "build system: windows")
else()
    set(PHH_BUILD_SYSTEM "UNKNOWN")
    # not meant to be
    message(AUTHOR_WARNING "build system: unknown")
endif()

# package handler
include(script/cmake/package-handler.conf.cmake)

# library static
add_library(${PROJECT_NAME}
    "src/lib.cc"
)
# MAYBE: library shared

# compiler options
set(PHH_GNU false)
set(PHH_MSVC false)
set(PHH_CLANG false)

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
    set(PHH_GNU true)
    set(PHH_MSVC false)
    set(PHH_CLANG false)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
    )

    set(PHH_COMPILER_NAME "MSVC")
    set(PHH_GNU false)
    set(PHH_MSVC true)
    set(PHH_CLANG false)
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

    set(PHH_COMPILER_NAME "CLANG")
    set(PHH_GNU false)
    set(PHH_MSVC false)
    set(PHH_CLANG true)
else()
    message(NOTICE
        "-- ${PROJECT_NAME}:
        -DCMAKE_CXX_COMPILER_ID is not supported as ${CMAKE_CXX_COMPILER_ID}
        "
    )
    set(PHH_COMPILER_NAME "UNKNOWN")
endif()

# target link library

# test subdir
if(PHH_BUILD_TEST)
    #
endif()

# tool subdir
if(PHH_BUILD_TOOL)
    #
endif()

configure_file(
    ${CMAKE_SOURCE_DIR}/inc/phh/config.in.hh
    ${CMAKE_SOURCE_DIR}/inc/phh/config.hh
)

# info: compiler info
string(APPEND PHH_FEATURES_LIST "- Compiler             : ${PHH_COMPILER_NAME}\n")
# info: build system
string(APPEND PHH_FEATURES_LIST "- Build system         : ${PHH_BUILD_SYSTEM}\n")
# info: last CMAKE_CXX_FLAGS
string(APPEND PHH_FEATURES_LIST "- CMAKE_CXX_FLAGS      : ${CMAKE_CXX_FLAGS}\n")
# info: last CMAKE_CXX_FLAGS
string(APPEND PHH_FEATURES_LIST "- CMAKE_CXX_STANDARD   : ${CMAKE_CXX_STANDARD}\n")

# check status
message(NOTICE "# ${PROJECT_NAME} configuration status:\n"
    "${PHH_FEATURES_LIST}"
)

