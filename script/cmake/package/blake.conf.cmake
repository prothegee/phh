#[[
this blake configured for blake2 & blake3
]]#
set(PHH_BLAKE2_FOUND false)
set(PHH_BLAKE3_FOUND false)

set(_BLAKE2_HEADER)
set(_BLAKE2_LIB_SHARED)

set(_BLAKE3_HEADER)
set(_BLAKE3_LIB_SHARED)

find_file(_BLAKE2_HEADER "blake2.h")
find_file(_BLAKE2_LIB_SHARED
	NAMES "libb2.so"
	PATHS
		/usr/lib
		/usr/local/lib
	DOC "path to blake2 shared lib"
)

if(_BLAKE2_HEADER AND _BLAKE2_LIB_SHARED)
    set(PHH_BLAKE2_FOUND true)
    message(STATUS "blake2 found")
    string(APPEND PHH_FEATURES_LIST "- blake2               : found\n")
else()
    string(APPEND PHH_FEATURES_LIST "- Argon2               : not found\n")
endif()

find_file(_BLAKE3_HEADER "blake3.h")
find_file(_BLAKE3_LIB_SHARED
	NAMES "libblake3.so"
	PATHS
		/usr/lib
		/usr/local/lib
	DOC "path to blake3 shared lib"
)

if(_BLAKE3_HEADER AND _BLAKE3_LIB_SHARED)
    set(PHH_BLAKE3_FOUND true)
    message(STATUS "blake3 found")
    string(APPEND PHH_FEATURES_LIST "- blake3               : found\n")
else()
    string(APPEND PHH_FEATURES_LIST "- blake3               : not found\n")
endif()

