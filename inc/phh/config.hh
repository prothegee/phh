#ifndef PHH_CONFIG_HH
#define PHH_CONFIG_HH

// --------------------------------------------------------- //

#ifndef PHH_CXX_STANDARD
#define PHH_CXX_STANDARD 0
#endif // PHH_CXX_STANDARD

#ifndef PHH_IS_DEBUG
#define PHH_IS_DEBUG true
#endif // PHH_IS_DEBUG

#ifndef PHH_VERSION_MAJOR
#define PHH_VERSION_MAJOR 0
#endif // PHH_VERSION_MAJOR

#ifndef PHH_VERSION_MINOR
#define PHH_VERSION_MINOR 0
#endif // PHH_VERSION_MINOR

#ifndef PHH_VERSION_PATCH
#define PHH_VERSION_PATCH 0
#endif // PHH_VERSION_PATCH

#ifndef PHH_VERSION_RELEASE_DATE
#define PHH_VERSION_RELEASE_DATE 20250612
#endif // PHH_VERSION_RELEASE_DATE

#ifndef PHH_VERSION
#define PHH_VERSION "0.0.0.20250612"
#endif // PHH_VERSION

// --------------------------------------------------------- //

#ifndef PHH_BUILD_SYSTEM
// build system as in string
#define PHH_BUILD_SYSTEM "GNU / Linux"
#endif // PHH_BUILD_SYSTEM

#ifndef PHH_IS_LINUX
// system is linux
#define PHH_IS_LINUX true
#endif // PHH_IS_LINUX

#ifndef PHH_IS_MACOS
// system is macos
#define PHH_IS_MACOS false
#endif // PHH_IS_MACOS

#ifndef PHH_IS_WINDOWS
// system is windows
#define PHH_IS_WINDOWS false
#endif // PHH_IS_WINDOWS

#ifndef PHH_GNU
// compiler is gnu
#define PHH_GNU true
#endif // PHH_GNU

#ifndef PHH_MSVC
// compiler is msvc
#define PHH_MSVC false
#endif // PHH_MSVC

#ifndef PHH_CLANG
// compiler is clang
#define PHH_CLANG false
#endif // PHH_CLANG

// --------------------------------------------------------- //

#endif // PHH_CONFIG_HH
