set(PHH_ARGON2_FOUND false)

set(_ARGON2_HEADER)
set(_ARGON2_LIB_SHARED)

# assume if this header exists
# the runtime or static library may be valid
find_file(_ARGON2_HEADER "argon2.h")
find_file(_ARGON2_LIB_SHARED
	NAMES "libargon2.so"
	PATHS
		/usr/lib
		/usr/local/lib
	DOC "path to argon shared lib"
)

if(_ARGON2_HEADER AND _ARGON2_LIB_SHARED)
    set(PHH_ARGON2_FOUND true)
    message(STATUS "Argon2 found")
    string(APPEND PHH_FEATURES_LIST "- Argon2               : found\n")
else()
    string(APPEND PHH_FEATURES_LIST "- Argon2               : not found\n")
endif()

