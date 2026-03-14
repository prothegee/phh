/// ### file: generateerate.hh
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
#ifndef PHH_UTILS_GENERATE_HH
#define PHH_UTILS_GENERATE_HH
#include <cstddef>
#include <cstdint>

namespace phh {
namespace utils {
namespace generate {

/// @brief generate random bytes to dst param
///
/// @param dst - destination data pointer
void secure_random_bytes(uint8_t *dst, size_t len);

uint64_t unix_timestamp_ms();

uint64_t monotonic_counter();

} // namespace generate
} // namespace utils
} // namespace phh

#endif // PHH_UTILS_GENERATE_HH
