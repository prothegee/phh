set(PHH_STB_FOUND false)

set(_STB_VORBIS_SOURCE)

# this one is assume based on stb/stb_vorbis.c file
find_file(_STB_VORBIS_SOURCE "stb/stb_vorbis.c")

if(_STB_VORBIS_SOURCE)
    set(PHH_STB_FOUND true)
    message(STATUS "stb found")
    string(APPEND PHH_FEATURES_LIST "- stb                  : found\n")
else()
    string(APPEND PHH_FEATURES_LIST "- stb                  : not found\n")
endif()
