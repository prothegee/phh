set(PHH_OPENSSL_FOUND false)

# can't use config
# this is for the best option for linux & windows
find_package(OpenSSL)

if(OpenSSL_FOUND)
    set(PHH_OPENSSL_FOUND true)
    message(STATUS "OpenSSL found")
    string(APPEND PHH_FEATURES_LIST "- OpenSSL          : found\n")
else()
    string(APPEND PHH_FEATURES_LIST "- OpenSSL          : not found\n")
endif()
