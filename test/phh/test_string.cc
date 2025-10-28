#include <print>
#include <cassert>

#include <phh/string.hh>

int main() {
    std::println("start: test_string.cc");

    // check size
    {
        // force literal check
        assert(sizeof(phh::str8_t) == 9);
        assert(sizeof(phh::str16_t) == 17);
        assert(sizeof(phh::str32_t) == 33);
        assert(sizeof(phh::str64_t) == 65);
        assert(sizeof(phh::str128_t) == 129);

        std::println("checking size passed.");

        std::println("phh:str8_t size is {}", sizeof(phh::str8_t));
        std::println("phh:str16_t size is {}", sizeof(phh::str16_t));
        std::println("phh:str32_t size is {}", sizeof(phh::str32_t));
        std::println("phh:str64_t size is {}", sizeof(phh::str64_t));
        std::println("phh:str128_t size is {}", sizeof(phh::str128_t));
    }

    return 0;
}

