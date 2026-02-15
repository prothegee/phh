cmake_minimum_required(VERSION 3.25)

set(PHH_VERSION_MAJOR 0)
set(PHH_VERSION_MINOR 1)
set(PHH_VERSION_PATCH 0)
set(PHH_VERSION_RELEASE_DATE 20260203)

project(phh
    VERSION "${PHH_VERSION_MAJOR}.${PHH_VERSION_MINOR}.${PHH_VERSION_PATCH}"
    DESCRIPTION "c++ module library treatment"
    HOMEPAGE_URL "https://codeberg.org/prothegee/phh || https://github.com/prothegee/phh"
    LANGUAGES CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_PDB_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

option(BUILD_TESTS "build the project tests; default: OFF" OFF)
option(BUILD_TOOLS "build the project tools; default: OFF" OFF)
option(BUILD_SHARED_LIBS "build shared libs; default: ON" ON)

option(PHH_USE_CURL "phh use curl lib & exec; default: OFF" OFF)
option(PHH_USE_ARGON2 "phh use argon2; default: OFF" OFF)
option(PHH_USE_OPENSSL "phh use openssl; default: OFF" OFF)
option(PHH_USE_JSONCPP "phh use jsoncpp; default: OFF" OFF)
option(PHH_USE_CRYPTOPP "phh use cryptopp; default: OFF" OFF)
option(PHH_USE_CRYPTOPP "phh use cryptopp; default: OFF" OFF)
option(PHH_USE_ZXINGCPP "phh use zxingcpp; default: OFF" OFF)

include(GNUInstallDirs)
include(CheckLibraryExists)
include(CheckIncludeFileCXX)
include(CMakeDependentOption)
include(GenerateExportHeader)
include(CMakeDependentOption)
include(CMakeFindDependencyMacro)
include(CMakePackageConfigHelpers)
include(FindPackageHandleStandardArgs)

include(scripts/cmake/definitions.cmake)
include(scripts/cmake/packages.cmake)

include(inc/phh-headers.cmake)
include(src/phh-sources.cmake)

link_directories(BEFORE "${CMAKE_SOURCE_DIR}/inc")
include_directories(BEFORE "${CMAKE_SOURCE_DIR}/inc")

if(NOT BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} ${PHH_SOURCES_FILES})
else()
    add_library(${PROJECT_NAME} SHARED ${PHH_SOURCES_FILES})
endif()

configure_file(
    ${CMAKE_SOURCE_DIR}/inc/phh/config.in.hh
    ${CMAKE_SOURCE_DIR}/inc/phh/config.hh
)

generate_export_header(phh
    EXPORT_FILE_NAME
        ${PROJECT_SOURCE_DIR}/inc/phh/export.hh
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>/inc
)

if(BUILD_TESTS)
    add_subdirectory(tests/unit_test)
endif()

if(BUILD_TOOLS)
    # add_subdirectory(tools/phh-uuid)
endif()
