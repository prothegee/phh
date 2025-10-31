/// ### file: uuid.hh
/// 
/// ### author: Prana Ron
/// 
/// ---------------------------------------------------------
/// 
/// ### brief:
/// phh uuid header
/// 
/// ### note:
/// n/a
/// 
/// ---------------------------------------------------------
/// 
/// ### copyright:
/// 
/// - (c) 2025 Prana Ron // @prothegee // prothegee@proton.me
/// 
/// ### contributors:
/// 
/// - Prana Ron // @prothegee // prothegee@proton.me
/// 
#ifndef PHH_UUID_HH
#define PHH_UUID_HH
#include "numeric.hh"
#include "string.hh"
#include "buffer.hh"

#include <array>

namespace phh {

// --------------------------------------------------------- //

/// v1
/// i.e.: 18559ec8-b56f-11f0-8de9-0242ac120002
/// 1. 18559ec8      : time low
/// 2. b56f          : time mid
/// 3. 11f0          : time hi & version
/// 4. 8de9          : clock sequence variant
/// 5. 0242ac120002  : node (mac address) rfc compliance / random
///
/// byte: 0x18559ec8b56f11f08de90242ac120002
struct uuid_v1_t {
    /// bytes as if
    buffer_byte_t data;

    explicit constexpr uuid_v1_t() {
        // TODO: default constructor
    }

    ~uuid_v1_t() = default;

    // --------------------------------------------------------- //

    // TODO:
    // - compare operator [ == and != ]
    // - possible? to > and < 

    // --------------------------------------------------------- //

    constexpr buffer_byte_t to_bytes() { return data; }

    // /// @brief return data as numeric, so it can be compare by numeric value
    // /// 
    // /// @note i64_t is int64_t
    // /// @note ui64_t is uint64_t
    // TODO: constexpr ui64_t to_numeric() const { return 0; }

    // /// @brief return data as str36_t
    // /// 
    // /// @return str36_t - i.e. 18559ec8-b56f-11f0-8de9-0242ac120002
    // TODO: constexpr str36_t to_string() const { return ""; }

    // /// @brief return data as str32_t
    // /// 
    // /// @return str32_t - i.e. 18559ec8b56f11f08de90242ac120002
    // TODO: constexpr str32_t to_string() const { return ""; }

    // /// @brief return data as timestamp with nanosecond
    // TODO: constexpr str_t to_timestamp_ns() const { return "i.e.: YYYY-MM-DD HH:MM:SS.nnnnnnnnn"; }
}; // uuid_v1_t

// --------------------------------------------------------- //

/// v4
/// i.e.: 5413a081-05b6-468c-be79-0fdf50cd182c
/// 1. 5413a081      : random
/// 2. 05b6          : random
/// 3. 468c          : version
/// 4. be79          : variant
/// 5. 0fdf50cd182c  : random
///
/// byte: 0x5413a08105b6468cbe790fdf50cd182c
struct uuid_v4_t {
    /// bytes as if
    buffer_byte_t data;

    explicit constexpr uuid_v4_t() {
        // TODO: default constructor
    }

    ~uuid_v4_t() = default;

    // --------------------------------------------------------- //

    // TODO:
    // - compare operator [ == and != ]
    // - possible? to > and < 

    // --------------------------------------------------------- //

    constexpr buffer_byte_t to_bytes() { return data; }

    // /// @brief return data as numeric, so it can be compare by numeric value
    // /// 
    // /// @note i64_t is int64_t
    // /// @note ui64_t is uint64_t
    // TODO: constexpr ui64_t to_numeric() const { return 0; }

    // /// @brief return data as str36_t
    // /// 
    // /// @return str36_t - i.e. 5413a081-05b6-468c-be79-0fdf50cd182c
    // TODO: constexpr str36_t to_string() const { return ""; }

    // /// @brief return data as str32_t
    // /// 
    // /// @return str32_t - i.e. 5413a08105b6468cbe790fdf50cd182c
    // TODO: constexpr str32_t to_string() const { return ""; }
}; // uuid_v4_t

// --------------------------------------------------------- //

/// v7
/// i.e.: 019a345a-e32c-7624-8762-7d5d4d0b94b4
/// 1. 019a345a      : timestamp in ms since unix epoch
/// 2. e32c          : random 1
/// 3. 7624          : version
/// 4. 8762          : random 2
/// 5. 7d5d4d0b94b4  : random 3
///
/// byte: 0x019a345ae32c762487627d5d4d0b94b4
struct uuid_v7_t {
    /// bytes as if
    buffer_byte_t data;

    explicit constexpr uuid_v7_t() {
        // TODO: default constructor
    }

    ~uuid_v7_t() = default;

    // --------------------------------------------------------- //

    // TODO:
    // - compare operator [ == and != ]
    // - possible? to > and < 

    // --------------------------------------------------------- //

    constexpr buffer_byte_t to_bytes() { return data; }

    // /// @brief return data as numeric, so it can be compare by numeric value
    // /// 
    // /// @note i64_t is int64_t
    // /// @note ui64_t is uint64_t
    // TODO: constexpr ui64_t to_numeric() const { return 0; }

    // /// @brief return data as str36_t
    // /// 
    // /// @return str36_t - i.e. 019a345a-e32c-7624-8762-7d5d4d0b94b4
    // TODO: constexpr str36_t to_string() const { return ""; }

    // /// @brief return data as str32_t
    // /// 
    // /// @return str32_t - i.e. 019a345ae32c762487627d5d4d0b94b4
    // TODO: constexpr str32_t to_string() const { return ""; }

    // /// @brief return data as timestamp with milisecond
    // /// @brief return data as timestamp with milisecond
    // TODO: constexpr str_t to_timestamp_ns() const { return "i.e.: YYYY-MM-DD HH:MM:SS.nnn"; }
}; // uuid_v7_t

} // namespace phh

#endif // PHH_UUID_HH

