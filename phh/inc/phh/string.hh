/// ### file: string.hh
/// 
/// ### author: Prana Ron
/// 
/// ---------------------------------------------------------
/// 
/// ### brief:
/// phh string header
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
#ifndef REPLACE_HH
#define REPLACE_HH
#include <cstddef>
#include <cstring>
#include <string>

#include "size.hh"

namespace phh {

/// @brief explicit dynamic size string type structure
struct _dynamic_str_t {
    char* data = nullptr;

    size_t _length = 0;
    size_t _capacity = 0;

    void reserve(size_t new_capacity) {
        if (new_capacity <= _capacity) return;
        char* new_data = new char[new_capacity];
        if (data) {
            std::memcpy(new_data, data, _length + 1);
            delete[] data;
        }
        data = new_data;
        _capacity = new_capacity;
    }

    explicit constexpr _dynamic_str_t(const char* value = "") {
        if (value) {
            _length = std::strlen(value);
            reserve(_length + 1);
            std::memcpy(data, value, _length + 1);
            data[_length] = '\0';
        }
        /// skip default
    }

    ~_dynamic_str_t() {
        if (data) { delete[] data; }
    }

    // --------------------------------------------------------- //

    constexpr const char* c_str() const { return data ? data : ""; }
    constexpr operator const char*() const { return c_str(); }

    constexpr char& operator[](size_t index) { return data[index]; }
    constexpr const char& operator[](size_t index) const { return data[index]; }

    constexpr bool operator==(const _dynamic_str_t& other) const {
        return std::strcmp(data, other.data) == 0;
    }
    constexpr bool operator!=(const _dynamic_str_t& other) const {
        return !(*this == other);
    }

    constexpr bool operator==(const char* other) const {
        return std::strcmp(data, other ? other : "") == 0;
    }
    constexpr bool operator!=(const char* other) const {
        return !(*this == other);
    }

    // --------------------------------------------------------- //

    /// @brief reset data[n]
    ///
    /// @return void
    constexpr void data_reset() { data[0] = '\0'; }

    /// @brief replace data with the input
    ///
    /// @param input
    ///
    /// @return void
    constexpr void data_replace(const char* input) const {
        size_t i = 0;

        if (!input) {
            data[0] = '\0';
            return;
        }

        for (; i < std::strlen(data) - 1 && input[i]; i++) {
            data[i] = input[i];
        }

        data[i] = '\0';
    }

    /// @brief actual data size that already stored
    /// 
    /// @return size_t
    constexpr size_t data_length() const { size_t i = 0; while (i < std::strlen(data) && data[i]) i++; return i; }

    /// @brief actual data size in this type that able to store
    /// 
    /// @return size_t 
    constexpr size_t data_capacity() { return std::strlen(data) - 1; };

    // --------------------------------------------------------- //

    /// @brief current data is empty
    ///
    /// @return bool
    constexpr bool is_empty() const { return data[0] == '\0'; }

    /// @brief find input character in data
    /// 
    /// @param input 
    /// @param start_pos 
    ///
    /// @return size_t 
    constexpr size_t find(char c, size_t start_pos = 0) const {
        for (size_t i = start_pos; i < std::strlen(data) && data[i]; i++) {
            if (data[i] == c) { return i; }
        }

        return static_cast<size_t>(-1);
    }

    /// @brief find input/substring in data
    ///
    /// @note maybe if size greater than 64 use something else
    ///
    /// @param input 
    /// @param start_pos 
    ///
    /// @return size_t
    constexpr size_t find(const char* input, size_t start_pos = 0) const {
        if (!input || !input[0]) return static_cast<size_t>(-1);

        size_t pattern_len = 0;
        while (input[pattern_len]) pattern_len++;

        if (pattern_len == 1) {
            return find(input[0], start_pos);
        }

        for (size_t i = start_pos; i < std::strlen(data) && data[i]; ++i) {
            bool found = true;
            for (size_t j = 0; input[j] && (i + j) < std::strlen(data); ++j) {
                if (data[i + j] != input[j]) {
                    found = false;
                    break;
                }
            }
            if (found) return i;
        }
        return static_cast<size_t>(-1);
    }

    /// @brief find input if contain in data
    ///
    /// @param input 
    ///
    /// @return bool
    constexpr bool contains(const char* input) const {
        return find(input) != static_cast<size_t>(-1);
    }

    constexpr std::string to_std_string() const {
        return static_cast<std::string>(std::string(data, _length));
    }
}; // struct _dynamic_str_t

// --------------------------------------------------------- //
// --------------------------------------------------------- //

/// @brief explicit fixed size string template type structure
template<size_t N>
struct _fixed_str_t {
    char data[N];

    explicit constexpr _fixed_str_t(const char* value = "") {
        size_t i = 0;

        for (; i < N - 1 && value && value[i]; i++) {
            data[i] = value[i];
        }

        data[i] = '\0';
    }

    // --------------------------------------------------------- //

    constexpr const char* c_str() const { return data; }
    constexpr operator const char*() const { return data; }

    constexpr char& operator[](size_t index) { return data[index]; }
    constexpr const char& operator[](size_t index) const { return data[index]; }

    constexpr bool operator==(const _fixed_str_t& other) const {
        return std::strcmp(data, other.data) == 0;
    }
    constexpr bool operator!=(const _fixed_str_t& other) const {
        return !(*this == other);
    }

    constexpr bool operator==(const char* other) const {
        return std::strcmp(data, other ? other : "") == 0;
    }
    constexpr bool operator!=(const char* other) const {
        return !(*this == other);
    }

    // --------------------------------------------------------- //

    /// @brief reset data[n]
    ///
    /// @return void
    constexpr void data_reset() { data[0] = '\0'; }

    /// @brief replace data with the input
    ///
    /// @param input
    ///
    /// @return void
    constexpr void data_replace(const char* input) const {
        size_t i = 0;

        if (!input) {
            data[0] = '\0';
            return;
        }

        for (; i < N - 1 && input[i]; i++) {
            data[i] = input[i];
        }

        data[i] = '\0';
    }

    /// @brief actual data size that already stored
    /// 
    /// @return size_t
    constexpr size_t data_length() const { size_t i = 0; while (i < N && data[i]) i++; return i; }

    /// @brief actual data size in this type that able to store
    /// 
    /// @return size_t 
    constexpr size_t data_capacity() { return N - 1; };

    // --------------------------------------------------------- //

    /// @brief current data is empty
    ///
    /// @return bool
    constexpr bool is_empty() const { return data[0] == '\0'; }

    /// @brief find input character in data
    /// 
    /// @param input 
    /// @param start_pos 
    ///
    /// @return size_t 
    constexpr size_t find(char c, size_t start_pos = 0) const {
        for (size_t i = start_pos; i < N && data[i]; i++) {
            if (data[i] == c) { return i; }
        }

        return static_cast<size_t>(-1);
    }

    /// @brief find input/substring in data
    ///
    /// @note maybe if size greater than 64 use something else
    ///
    /// @param input 
    /// @param start_pos 
    ///
    /// @return size_t
    constexpr size_t find(const char* input, size_t start_pos = 0) const {
        if (!input || !input[0]) return static_cast<size_t>(-1);

        size_t pattern_len = 0;
        while (input[pattern_len]) pattern_len++;

        if (pattern_len == 1) {
            return find(input[0], start_pos);
        }

        for (size_t i = start_pos; i < N && data[i]; ++i) {
            bool found = true;
            for (size_t j = 0; input[j] && (i + j) < N; ++j) {
                if (data[i + j] != input[j]) {
                    found = false;
                    break;
                }
            }
            if (found) return i;
        }
        return static_cast<size_t>(-1);
    }

    /// @brief find input if contain in data
    ///
    /// @param input 
    ///
    /// @return bool
    constexpr bool contains(const char* input) const {
        return find(input) != static_cast<size_t>(-1);
    }

    constexpr std::string to_std_string() const {
        return static_cast<std::string>(std::string(data, N));
    }
}; // struct _fixed_str_t

// --------------------------------------------------------- //

/// @brief explicit fixed width string
using str_t = _dynamic_str_t;

/// @brief explicit fixed 8 width string
using str8_t = _fixed_str_t<PHH_SIZE_8_WIDTH>;

/// @brief explicit fixed 16 width string
using str16_t = _fixed_str_t<PHH_SIZE_16_WIDTH>;

/// @brief explicit fixed 32 width string
using str32_t = _fixed_str_t<PHH_SIZE_32_WIDTH>;

/// @brief explicit fixed 36 width string
/// 
/// @note mostly for uuid-kind
using str36_t = _fixed_str_t<PHH_SIZE_36_WIDTH>;

/// @brief explicit fixed 64 width string
using str64_t = _fixed_str_t<PHH_SIZE_64_WIDTH>;

/// @brief explicit fixed 128 width string
using str128_t = _fixed_str_t<PHH_SIZE_128_WIDTH>;

} // namespace phh

#endif // REPLACE_HH

