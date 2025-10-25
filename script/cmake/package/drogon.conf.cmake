set(PHH_DROGON_FOUND false)

find_package(Drogon CONFIG)

if(Drogon_FOUND)
    set(PHH_DROGON_FOUND true)
    message(STATUS "Drogon Framework found")
    string(APPEND PHH_FEATURES_LIST "- Drogon Framework     : found\n")
else()
    string(APPEND PHH_FEATURES_LIST "- Drogon Framework     : not found\n")
endif()

