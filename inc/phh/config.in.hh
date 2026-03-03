#ifndef PHH_CONFIG_HH
#define PHH_CONFIG_HH

#ifndef CPP_STANDARD
#define CPP_STANDARD @CMAKE_CXX_STANDARD@
#endif // CPP_STANDARD

// --------------------------------------------------------- //

#ifndef PHH_USE_CURL
#define PHH_USE_CURL @PHH_USE_CURL@
#endif // PHH_USE_CURL

#ifndef PHH_USE_ARGON2
#define PHH_USE_ARGON2 @PHH_USE_ARGON2@
#endif // PHH_USE_ARGON2

#ifndef PHH_USE_OPENSSL
#define PHH_USE_OPENSSL @PHH_USE_OPENSSL@
#endif // PHH_USE_OPENSSL

#ifndef PHH_USE_JSONCPP
#define PHH_USE_JSONCPP @PHH_USE_JSONCPP@
#endif // PHH_USE_JSONCPP

#ifndef PHH_USE_CRYPTOPP
#define PHH_USE_CRYPTOPP @PHH_USE_CRYPTOPP@
#endif // PHH_USE_CRYPTOPP

#ifndef PHH_USE_RAPIDJSON
#define PHH_USE_RAPIDJSON @PHH_USE_RAPIDJSON@
#endif // PHH_USE_RAPIDJSON

#ifndef PHH_USE_ZXINGCPP
#define PHH_USE_ZXINGCPP @PHH_USE_ZXINGCPP@
#endif // PHH_USE_ZXINGCPP

// --------------------------------------------------------- //

#if defined(__GNUC__) || defined(__clang__)
#ifndef DEPRECATED
#define DEPRECATED(msg) __attribute__((deprecated(msg)))
#endif // DEPRECATED

#ifndef PRAGMA_MESSAGE_IMPL
#ifndef PRAGMA_MESSAGE
#define PRAGMA_MESSAGE_IMPL(str) _Pragma(#str)
// compiler independetn message
#define PRAGMA_MESSAGE(msg) PRAGMA_MESSAGE_IMPL(message msg)
#endif // PRAGMA_MESSAGE
#endif // PRAGMA_MESSAGE_IMPL
#elif defined(_MSC_VER)
#ifndef DEPRECATED
#define DEPRECATED(msg) __declspec(deprecated(msg))
#endif // DEPRECATED

#ifndef PRAGMA_MESSAGE
// compiler independetn message
#define PRAGMA_MESSAGE(msg) __pragma(message(msg))
#endif // PRAGMA_MESSAGE
#else
// n/a
#endif

// --------------------------------------------------------- //

namespace phh {
} // namespace phh

#endif // PHH_CONFIG_HH
