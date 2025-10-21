set(PHH_ARGON2_FOUND false)

set(_ARGON2_HEADER)

# assume if this header exists
# the runtime or static library may be valid
find_file(_ARGON2_HEADER "argon2.h")

if(_ARGON2_HEADER)
    set(PHH_ARGON2_FOUND true)
    message(STATUS "Argon2 found")
    string(APPEND PHH_FEATURES_LIST "- Argon2           : found\n")
else()
    string(APPEND PHH_FEATURES_LIST "- Argon2           : not found\n")
endif()

