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

namespace phh {
} // namespace phh

#endif // PHH_CONFIG_HH
