set(PHH_STB_FOUND false)

set(PHH_STB_DIR)

set(_STB_VORBIS_SOURCE)

# this one is assume based on stb/stb_vorbis.c file
find_file(_STB_VORBIS_SOURCE "stb/stb_vorbis.c")

if(_STB_VORBIS_SOURCE)
    set(PHH_STB_FOUND true)
    message(STATUS "stb found")
    string(APPEND PHH_FEATURES_LIST "- stb                  : found\n")

    get_filename_component(PHH_STB_DIR "${_STB_VORBIS_SOURCE}" DIRECTORY)

    link_directories(BEFORE     "${PHH_STB_DIR}")
    include_directories(BEFORE  "${PHH_STB_DIR}")

    set(Stb_INCLUDE_DIR "${PROJECT_STB_IMAGE_DIR}")
else()
    string(APPEND PHH_FEATURES_LIST "- stb                  : not found\n")
endif()

