/// ### file: error.hh
/// 
/// ### author: Prana Ron
/// 
/// ---------------------------------------------------------
/// 
/// ### brief:
/// phh error header
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
#ifndef PHH_ERROR_HH
#define PHH_ERROR_HH
#include "numeric.hh"

namespace phh {

enum class error_ec : i8_t {
    undefined,
    wrong_data,
}; // enum class error_ec

} // namespace phh

#endif // PHH_ERROR_HH

