set(PHH_PYTHON3_FOUND false)
set(PHH_PYTHON3_EXEC_FOUND false)

set(PHH_PYTHON3_EXEC)

find_package(Python3)

if(Python3_FOUND)
    set(PHH_PYTHON3_FOUND true)
    message(STATUS "Python3 found")
    string(APPEND PHH_FEATURES_LIST "- Python3              : found\n")
else()
    string(APPEND PHH_FEATURES_LIST "- Python3              : not found\n")
endif()

if(Python3_EXECUTABLE)
    set(PHH_PYTHON3_EXEC_FOUND true)
    set(PHH_PYTHON3_EXEC "${Python3_EXECUTABLE}")
    message(STATUS "Python3 exec found")
    string(APPEND PHH_FEATURES_LIST "- Python3 exec         : found\n")
else()
    string(APPEND PHH_FEATURES_LIST "- Python3 exec         : not found\n")
endif()


