#include <print>
#include <cassert>

#include <phh/buffer.hh>

int main() {
    std::println("start: unit_test_buffer.cc");

    // check size
    {
        // force literal check
        assert(sizeof(phh::buffer_byte_t) == 32);
        assert(sizeof(phh::buffer_char_t) == 32);
        assert(sizeof(phh::buffer_data_t) == 32);

        std::println("checking size passed.");

        std::println("phh::buffer_byte_t default size is {}", sizeof(phh::buffer_byte_t));
        std::println("phh::buffer_char_t default size is {}", sizeof(phh::buffer_char_t));
        std::println("phh::buffer_data_t default size is {}", sizeof(phh::buffer_data_t));
    }

    return 0;
}

