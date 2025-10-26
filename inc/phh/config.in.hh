#ifndef PHH_CONFIG_HH
#define PHH_CONFIG_HH

// --------------------------------------------------------- //

#ifndef PHH_CXX_STANDARD
#define PHH_CXX_STANDARD @PHH_CXX_STANDARD@
#endif // PHH_CXX_STANDARD

#ifndef PHH_IS_DEBUG
#define PHH_IS_DEBUG @PHH_IS_DEBUG@
#endif // PHH_IS_DEBUG

#ifndef PHH_VERSION_MAJOR
#define PHH_VERSION_MAJOR @PHH_VERSION_MAJOR@
#endif // PHH_VERSION_MAJOR

#ifndef PHH_VERSION_MINOR
#define PHH_VERSION_MINOR @PHH_VERSION_MINOR@
#endif // PHH_VERSION_MINOR

#ifndef PHH_VERSION_PATCH
#define PHH_VERSION_PATCH @PHH_VERSION_PATCH@
#endif // PHH_VERSION_PATCH

#ifndef PHH_VERSION_RELEASE_DATE
#define PHH_VERSION_RELEASE_DATE @PHH_VERSION_RELEASE_DATE@
#endif // PHH_VERSION_RELEASE_DATE

#ifndef PHH_VERSION
#define PHH_VERSION "@PHH_VERSION_MAJOR@.@PHH_VERSION_MINOR@.@PHH_VERSION_PATCH@.@PHH_VERSION_RELEASE_DATE@"
#endif // PHH_VERSION

// --------------------------------------------------------- //

#ifndef PHH_BUILD_SYSTEM
// build system as in string
#define PHH_BUILD_SYSTEM "@PHH_BUILD_SYSTEM@"
#endif // PHH_BUILD_SYSTEM

#ifndef PHH_IS_LINUX
// system is linux
#define PHH_IS_LINUX @PHH_IS_LINUX@
#endif // PHH_IS_LINUX

#ifndef PHH_IS_MACOS
// system is macos
#define PHH_IS_MACOS @PHH_IS_MACOS@
#endif // PHH_IS_MACOS

#ifndef PHH_IS_WINDOWS
// system is windows
#define PHH_IS_WINDOWS @PHH_IS_WINDOWS@
#endif // PHH_IS_WINDOWS

#ifndef PHH_IS_ANDROID
// system is android
#define PHH_IS_ANDROID @PHH_IS_ANDROID@
#endif // PHH_IS_ANDROID

#ifndef PHH_IS_IOS
// system is ios
#define PHH_IS_IOS @PHH_IS_IOS@
#endif // PHH_IS_IOS

#ifndef PHH_GNU
// compiler is gnu
#define PHH_GNU @PHH_GNU@
#endif // PHH_GNU

#ifndef PHH_MSVC
// compiler is msvc
#define PHH_MSVC @PHH_MSVC@
#endif // PHH_MSVC

#ifndef PHH_CLANG
// compiler is clang
#define PHH_CLANG @PHH_CLANG@
#endif // PHH_CLANG

// --------------------------------------------------------- //

#ifndef PHH_ARGON2_FOUND
#define PHH_ARGON2_FOUND @PHH_ARGON2_FOUND@
#endif // PHH_ARGON2_FOUND

#ifndef PHH_CURL_FOUND
#define PHH_CURL_FOUND @PHH_CURL_FOUND@
#endif // PHH_CURL_FOUND

#ifndef PHH_CURL_EXEC_FOUND
#define PHH_CURL_EXEC_FOUND @PHH_CURL_EXEC_FOUND@
#endif // PHH_CURL_EXEC_FOUND

#ifndef PHH_DROGON_FOUND
#define PHH_DROGON_FOUND @PHH_DROGON_FOUND@
#endif // PHH_DROGON_FOUND

#ifndef PHH_JSONCPP_FOUND
#define PHH_JSONCPP_FOUND @PHH_JSONCPP_FOUND@
#endif // PHH_JSONCPP_FOUND

#ifndef PHH_OPENSSL_FOUND
#define PHH_OPENSSL_FOUND @PHH_OPENSSL_FOUND@
#endif // PHH_OPENSSL_FOUND

#ifndef PHH_PYTHON3_FOUND
#define PHH_PYTHON3_FOUND @PHH_PYTHON3_FOUND@
#endif // PHH_PYTHON3_FOUND

#ifndef PHH_PYTHON3_EXEC_FOUND
#define PHH_PYTHON3_EXEC_FOUND @PHH_PYTHON3_EXEC_FOUND@
#endif // PHH_PYTHON3_EXEC_FOUND

#ifndef PHH_STB_FOUND
#define PHH_STB_FOUND @PHH_STB_FOUND@
#endif // PHH_STB_FOUND

// --------------------------------------------------------- //

#endif // PHH_CONFIG_HH
