cmake_minimum_required(VERSION 3.25)

project(phh)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_PDB_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

option(BUILD_TESTS "build the project tests; defailt: true" true)
option(BUILD_SHARED_LIBS "build shared libs; defailt: true" true)

include(scripts/cmake/init.cmake)

if(BUILD_TESTS)
    add_subdirectory(tests/unit_test)
endif()
