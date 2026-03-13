/// ### file: uuid
///
/// ### author: Prana Ron
///
/// ---------------------------------------------------------
///
/// ### brief:
/// n/a
///
/// ### note:
/// n/a
///
/// ---------------------------------------------------------
///
/// ### copyright:
///
/// - (c) 2026 Prana Ron // @prothegee // prothegee@proton.me
///
/// ### contributors:
///
/// - Prana Ron // @prothegee // prothegee@proton.me
///
#ifndef PHH_UTILS_UUID_HH
#define PHH_UTILS_UUID_HH
#include <array>
#include <cstdint>
#include <phh/config.hh>
#include <phh/export.hh>
#include <string>

namespace phh {
namespace utils {
namespace uuid {

/// @brief phh UUID type
struct UUID {
    std::array<uint8_t, 16> data{};

    constexpr UUID();
    constexpr explicit UUID(std::array<uint8_t, 16> bytes);

    explicit UUID(const std::string &str);

    constexpr bool operator==(const UUID &other) const = default;
    constexpr auto operator<=>(const UUID &other) const = default;

    constexpr uint8_t *data_ptr() noexcept { return data.data(); }
    constexpr const uint8_t *data_ptr() const noexcept { return data.data(); }
    constexpr const std::array<uint8_t, 16> &bytes() const noexcept {
        return data;
    }

    // convert to canonical string: "550e8400-e29b-41d4-a716-446655440000"
    std::string string() const;

    // convert to ref format (no hyphens, lowercase):
    // "550e8400e29b41d4a716446655440000"
    std::string ref() const;

    // extract version nibble (1, 4, 7, etc.)
    int version() const noexcept;

    // check if variant is RFC 4122 (10xx)
    bool is_rfc4122() const noexcept;
}; // struct UUID

// --------------------------------------------------------- //

/// @brief generate uuid v1
UUID v1();

/// @brief generate uuid v4
UUID v4();

/// @brief generate uuid v7
UUID v7();

} // namespace uuid
} // namespace utils
} // namespace phh

#endif // PHH_UTILS_UUID_HH
