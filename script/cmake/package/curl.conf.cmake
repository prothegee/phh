set(PHH_CURL_FOUND false)
set(PHH_CURL_EXEC_FOUND false)

find_package(CURL)

if(CURL_FOUND)
    set(PHH_CURL_FOUND true)
    message(STATUS "curl found")
    string(APPEND PHH_FEATURES_LIST "- Curl                 : found\n")
else()
    string(APPEND PHH_FEATURES_LIST "- Curl                 : not found\n")
endif()

# windows might need .exe; don't care for now
set(CURL_EXEC_NAME "curl")

find_program(CURL_EXECUTABLE 
    NAMES ${CURL_EXEC_NAME}
    PATHS 
        /usr/bin
        /usr/sbin
        /usr/local/bin
        /bin
        /sbin
        /opt/local/bin
    DOC "path to curl executable"
)

if(CURL_EXECUTABLE)
    set(PHH_CURL_EXEC_FOUND true)
    message(STATUS "curl exec found: ${CURL_EXECUTABLE}")
    string(APPEND PHH_FEATURES_LIST "- Curl exec            : found\n")
else()
    string(APPEND PHH_FEATURES_LIST "- Curl exec            : not found\n")
    message(WARNING "curl executable not found! Searched in standard paths.")
endif()

