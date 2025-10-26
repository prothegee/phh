project(phh)

# headers
# headers functions
if(NOT DEFINED PHH_HEADER_FUNCTIONS_FILES)
    set(PHH_HEADER_FUNCTIONS_FILES)
endif()
list(APPEND PHH_HEADER_FUNCTIONS_FILES
    "${CMAKE_SOURCE_DIR}/inc/phh/functions/utility.hh"
)

# source files
if(NOT DEFINED PHH_SOURCE_FILES)
    set(PHH_SOURCE_FILES)
endif()
list(APPEND PHH_SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/src/phh/lib.cc"
    # functions
    "${CMAKE_SOURCE_DIR}/src/phh/functions/utility.cc"
    # interfaces
    # modules
)

# output name
set(PHH_OUTPUT_NAME "phh")

# object core lib
add_library(${PROJECT_NAME} OBJECT ${PHH_SOURCE_FILES})
# static core lib
add_library(phh_static STATIC $<TARGET_OBJECTS:${PROJECT_NAME}>)
# shared core lib
add_library(phh_shared SHARED $<TARGET_OBJECTS:${PROJECT_NAME}>)

# target properties
if(NOT WIN32)
    set_target_properties(phh_static PROPERTIES
        OUTPUT_NAME "${PHH_OUTPUT_NAME}"
    )
    set_target_properties(phh_shared PROPERTIES
        VERSION     "${PHH_VERSION_MAJOR}.${PHH_VERSION_MINOR}.${PHH_VERSION_PATCH}"
        SOVERSION   "${PHH_VERSION_MAJOR}.${PHH_VERSION_MINOR}.${PHH_VERSION_PATCH}"
        OUTPUT_NAME "${PHH_OUTPUT_NAME}"
    )
else()
    set_target_properties(phh_static PROPERTIES
        ARCHIEVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
        OUTPUT_NAME "${PHH_OUTPUT_NAME}"
    )
    set_target_properties(phh_shared PROPERTIES
        ARCHIEVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        OUTPUT_NAME "${PHH_OUTPUT_NAME}"
    )
endif()

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

generate_export_header(phh
    EXPORT_FILE_NAME
        ${CMAKE_SOURCE_DIR}/inc/phh/export.hh
)
generate_export_header(phh_static
    EXPORT_FILE_NAME
        ${CMAKE_SOURCE_DIR}/inc/phh/export_static.hh
)
generate_export_header(phh_shared
    EXPORT_FILE_NAME
        ${CMAKE_SOURCE_DIR}/inc/phh/export_shared.hh
)

configure_file(
    ${CMAKE_SOURCE_DIR}/inc/phh/config.in.hh
    ${CMAKE_SOURCE_DIR}/inc/phh/config.hh
)

target_compile_definitions(phh_shared PRIVATE PHH_SHARED)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_SOURCE_DIR}/inc
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>/inc
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/phh
        ${CMAKE_SOURCE_DIR}/src/phh/functions
        ${CMAKE_SOURCE_DIR}/src/phh/modules
)

# each target
foreach(PHH_TARGET phh_static phh_shared)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(${PHH_TARGET} PRIVATE
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
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        target_compile_options(${PHH_TARGET} PRIVATE
            /W4
        )
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "[Cc]lang")
        target_compile_options(${PHH_TARGET} PRIVATE
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
    else()
        message(NOTICE "-- ${PHH_TARGET}: -DCMAKE_CXX_COMPILER_ID is not supported as ${CMAKE_CXX_COMPILER_ID}")
    endif()

    # argon2
    if(PHH_ARGON2_FOUND)
        target_link_libraries(${PHH_TARGET} PRIVATE argon2)
    endif()

    # curl
    if(PHH_CURL_FOUND)
        target_link_libraries(${PHH_TARGET} PRIVATE curl)
    endif()

    # drogon
    if(PHH_DROGON_FOUND)
        target_link_libraries(${PHH_TARGET} PRIVATE Drogon::Drogon)
    endif()

    # jsoncpp
    if(PHH_JSONCPP_FOUND)
        target_link_libraries(${PHH_TARGET} PRIVATE jsoncpp)
    endif()

    # openssl
    if(PHH_OPENSSL_FOUND)
        target_link_libraries(${PHH_TARGET} PRIVATE OpenSSL::SSL OpenSSL::Crypto)
    endif()

    # python3

    # stb
    if(PHH_STB_FOUND)
        target_include_directories(${PHH_TARGET} PRIVATE ${PHH_STB_DIR})
    endif()
endforeach()

