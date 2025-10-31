/// ### file: buffer.h
/// 
/// ### author: Prana Ron
/// 
/// ---------------------------------------------------------
/// 
/// ### brief:
/// phh buffer header
/// 
/// ### note:
/// - every variable & function that has _ prefix
///     meant to be as private accessor
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
#ifndef PHH_BUFFER_HH
#define PHH_BUFFER_HH
#include "numeric.hh"
#include "string.hh"

// #ifndef PHH_ARRAY_T
// #define PHH_ARRAY_T
// // #include <array>
// #endif // PHH_ARRAY_T

#ifndef PHH_VECTOR_T
#define PHH_VECTOR_T
// #include <vector>
#endif // PHH_VECTOR_T

#include <stdexcept>

namespace phh {

#ifdef PHH_ARRAY_T
// @brief alter type of std::array
template <typename T, std::size_t N>
using array_t = std::array<T, N>;
#endif // PHH_ARRAY_T


// --------------------------------------------------------- //

/// @brief phh internal vector type
template <typename T>
struct vector_t {
    T* _data = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;

    constexpr void _reallocate(size_t new_capacity) {
        T* new_data = new T[new_capacity];

        for (size_t i = 0; i < _size; i++) {
            new_data[i] = std::move(_data[i]);
        }
    }

    vector_t() = default;

    explicit constexpr vector_t(size_t count, const T& value = T{}) {
        reserve(count);
        for (size_t i = 0; i < count; i++) {
            push_back(value);
        }
    }
    /// vector_t copy constructor
    constexpr vector_t(const vector_t& other) {
        reserve(other._capacity);
        _size = other._size;

        for (size_t i = 0; i < _size;i++) {
            _data[i] = other._data[i];
        }
    }
    /// move constructor
    constexpr vector_t(vector_t&& other) noexcept : _data(other._data)
                                        , _size(other._size)
                                        , _capacity(other._capacity) {
        other._data = nullptr;
        other._size = 0;
        other._capacity = 0;
    }

    ~vector_t() { delete[] _data; }

    // --------------------------------------------------------- //

    constexpr vector_t& operator=(const vector_t& other) {
        if (this != other) {
            delete [] _data;
            reserve(other._capacity);
            _size = other._size;

            for (size_t i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        }

        return *this;
    }
    constexpr vector_t& operator=(vector_t&& other) noexcept {
        if (this != &other) {
            delete[] _data;
            _data = other._data;
            _size = other._size;
            _capacity = other._capacity;
            
            other._data = nullptr;
            other._size = 0;
            other._capacity = 0;
        }

        return *this;
    }

    constexpr T& operator[](size_t pos) { return _data[pos]; }
    constexpr T& operator[](size_t pos) const { return _data[pos]; }

    // --------------------------------------------------------- //

    constexpr T* begin() { return _data; }
    constexpr T* begin() const { return _data; }
    constexpr T* end() { return _data + _size; }
    constexpr const T* end() const { return _data + _size; }

    // --------------------------------------------------------- //

    constexpr T& at(size_t pos) {
        if (pos >= _size) {
            throw std::out_of_range("vector index out of range");
        }

        return _data[pos];
    }
    constexpr T& at(size_t pos) const {
        if (pos >= _size) {
            throw std::out_of_range("vector index out of range");
        }
        return _data[pos];
    }

    constexpr T& front() { return _data[0]; }
    constexpr const T& front() const { return _data[0]; }
    
    constexpr T& back() { return _data[_size - 1]; }
    constexpr const T& back() const { return _data[_size - 1]; }
    
    constexpr T* data() { return _data; }
    constexpr const T* data() const { return _data; }

    constexpr size_t data_size() const { return _size; }
    constexpr size_t data_capacity() const { return _capacity; }

    // --------------------------------------------------------- //

    constexpr bool is_empty() const { return _size == 0; }

    constexpr void reserve(size_t new_capacity) {
        if (new_capacity > _capacity) {
            _reallocate(new_capacity);
        }
    }

    constexpr void shrink_to_fit() {
        if (_capacity > _size) {
            _reallocate(_size);
        }
    }

    constexpr void clear() {
        _size = 0;
    }

    constexpr void resize(size_t count, const T& value = T{}) {
        if (count > _capacity) {
            reserve(count);
        }

        if (count > _size) {
            for (size_t i = 0; i < count; i++) {
                _data[i] = value;
            }
        }

        _size = count;
    }

    constexpr void push_back(const T& value) {
        if (_size >= _capacity) {
            reserve(_capacity == 0 ? 1 : _capacity * 2);
        }
        _data[_size++] = value;
    }
    constexpr void push_back(const T&& value) {
        if (_size >= _capacity) {
            reserve(_capacity == 0 ? 1 : _capacity * 2);
        }
        _data[_size++] = std::move(value);
    }

    constexpr void pop_back() {
        if (_size > 0) {
            _size--;
        }
    }
}; // struct vector_t

// --------------------------------------------------------- //
// --------------------------------------------------------- //

/// @brief explicit buffer type structure
template<typename T>
struct _buffer_t {
    vector_t<T> data;
    size_t _position = 0;

    explicit constexpr _buffer_t(size_t capacity) : data(capacity) {}

    ~_buffer_t() = default;

    // --------------------------------------------------------- //

    constexpr bool operator==(const _buffer_t& other) const {
        return !(*this == other);
    }
    constexpr bool operator!=(const _buffer_t& other) const {
        return !(*this == other);
    }

    // --------------------------------------------------------- //

    constexpr size_t size() const { return data.size(); }

    constexpr size_t position() const { return _position; }

    constexpr void write(const T* source, size_t count) {
        std::copy(source, source + count, data.begin() + _position);
    }

    constexpr const T* read(size_t count) {
        auto* result = data.data() + _position;
        _position += count;
        return result;
    } 
}; // struct _buffer_t

// --------------------------------------------------------- //
// --------------------------------------------------------- //

/// @brief buffer byte data type
///
/// @note for binary data
using buffer_byte_t = _buffer_t<ui8_t>;

/// @brief buffer char data type
///
/// @note for text data
using buffer_char_t = _buffer_t<char_t>;

/// @brief buffer data type
///
/// @note for generic data
using buffer_data_t = _buffer_t<uchar_t>;

} // namespace phh

#endif // PHH_BUFFER_HH

