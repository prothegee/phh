/// ### file: is
///
/// ### author: Prana Ron
///
/// ---------------------------------------------------------
///
/// ### brief:
/// bunch of colletion of utils that start with `is` keyword
///
///
/// ### note:
/// n/a
///
/// ---------------------------------------------------------
///
/// ### copyright:
///
/// - (c) 20260303 Prana Ron // @prothegee // prothegee@proton.me
///
/// ### contributors:
///
/// - Prana Ron // @prothegee // prothegee@proton.me
///
#ifndef PHH_UTILS_IS_HH
#define PHH_UTILS_IS_HH
#include <phh/config.hh>
#include <phh/export.hh>
#include <string>

namespace phh {
namespace utils {
namespace is {

/// @brief return true if file exists
///
/// @param file_path
///
/// @return bool
bool file_exists(const std::string &file_path);

/// @brief check if input is numeric or not
///
/// @param input
///
/// @return bool
bool numeric(const std::string &input);

/// @brief check if input is numeric unsigned or not
///
/// @param input
///
/// @return bool
bool numeric_unsigned(const std::string &input);

/// @brief check if input is numeric decimal or not
///
/// @param input
///
/// @return bool
bool numeric_decimal(const std::string &input);

} // namespace is
} // namespace utils
} // namespace phh

#endif // PHH_UTILS_IS_HH
