project(phh)

# header files

add_library(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/src/lib.cc")

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
    message(NOTICE "-- ${PROJECT_NAME}: -DCMAKE_CXX_COMPILER_ID is not supported as ${CMAKE_CXX_COMPILER_ID}")
    set(PHH_COMPILER_NAME "UNKNOWN")
endif()

# target link library

configure_file(
    ${CMAKE_SOURCE_DIR}/inc/phh/config.in.hh
    ${CMAKE_SOURCE_DIR}/inc/phh/config.hh
)

