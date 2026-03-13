#include <phh/utils/gen.hh>
#include <random>
#include <chrono>
#include <atomic>

namespace phh {
namespace utils {
namespace gen {

void secure_random_bytes(uint8_t *dst, size_t len) {
    static thread_local std::random_device rd;
    static thread_local std::uniform_int_distribution<int> dist(0, 255);
    for (size_t i = 0; i < len; ++i)
        dst[i] = static_cast<uint8_t>(dist(rd));
}

uint64_t unix_timestamp_ms() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
}

uint64_t monotonic_counter() {
    static std::atomic<uint16_t> counter{0};
    return counter.fetch_add(1, std::memory_order_relaxed) & 0x0FFF;
}

} // namespace gen
} // namespace utils
} // namespace phh
