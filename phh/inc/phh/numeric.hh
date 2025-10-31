/// ### file: numeric.hh
/// 
/// ### author: Prana Ron
/// 
/// ---------------------------------------------------------
/// 
/// ### brief:
/// phh numeric header
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
#ifndef PHH_NUMERIC_HH
#define PHH_NUMERIC_HH
#include <cstdint>

namespace phh {

using i8_t = int8_t;
using i16_t = int16_t;
using i32_t = int32_t;
using i64_t = int64_t;

using ui8_t = uint8_t;
using ui16_t = uint16_t;
using ui32_t = uint32_t;
using ui64_t = uint64_t;

using f32_t = float;
using f64_t = double;

#ifndef PHH_BOOL_T
#define PHH_BOOL_T
enum bool_t : i8_t {
    false_t = 0, true_t = 1
}; // bool_t
#endif // PHH_BOOL_T

} // namespace phh

#endif // PHH_NUMERIC_HH

