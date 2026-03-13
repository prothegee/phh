#include <chrono>
#include <phh/utils/gen.hh>
#include <phh/utils/uuid.hh>

namespace phh {
namespace utils {
namespace uuid {

constexpr UUID::UUID() {}

constexpr UUID::UUID(std::array<uint8_t, 16> bytes) : data(bytes) {}

UUID::UUID(const std::string &str) {
    if (str.length() != 36)
        throw std::invalid_argument("Invalid UUID string length");

    auto hex_to_byte = [](char c) -> uint8_t {
        if (c >= '0' && c <= '9')
            return c - '0';
        if (c >= 'a' && c <= 'f')
            return c - 'a' + 10;
        if (c >= 'A' && c <= 'F')
            return c - 'A' + 10;
        throw std::invalid_argument("Invalid hex character");
    };

    size_t byte_idx = 0;
    for (size_t i = 0; i < str.length() && byte_idx < 16; ++i) {
        if (str[i] == '-')
            continue;
        if (i + 1 >= str.length())
            throw std::invalid_argument("Truncated UUID");
        data[byte_idx++] = (hex_to_byte(str[i]) << 4) | hex_to_byte(str[i + 1]);
        ++i; // skip next hex char (already consumed)
    }
    if (byte_idx != 16)
        throw std::invalid_argument("UUID must contain 16 bytes");
}

std::string UUID::string() const {
    static const char *hex = "0123456789abcdef";
    std::string result(36, '-');
    size_t pos = 0;
    for (int i = 0; i < 16; ++i) {
        if (i == 4 || i == 6 || i == 8 || i == 10)
            ++pos;
        result[pos++] = hex[(data[i] >> 4) & 0x0F];
        result[pos++] = hex[data[i] & 0x0F];
    }
    return result;
}

std::string UUID::ref() const {
    static const char *hex = "0123456789abcdef";
    std::string result;
    result.reserve(32);
    for (uint8_t b : data) {
        result += hex[(b >> 4) & 0x0F];
        result += hex[b & 0x0F];
    }
    return result;
}

int UUID::version() const noexcept { return (data[6] >> 4) & 0x0F; }

bool UUID::is_rfc4122() const noexcept { return (data[8] & 0xC0) == 0x80; }

// --------------------------------------------------------- //

UUID v1() {
    std::array<uint8_t, 16> bytes{};
    phh::utils::gen::secure_random_bytes(bytes.data(), bytes.size());

    constexpr uint64_t UUID_EPOCH_OFFSET = 0x01B21DD213814000ULL;
    auto now = std::chrono::system_clock::now();
    uint64_t ts_100ns =
        static_cast<uint64_t>(
            std::chrono::duration_cast<std::chrono::microseconds>(
                now.time_since_epoch())
                .count() *
            10) +
        UUID_EPOCH_OFFSET;

    // RFC 4122 layout: time_low, time_mid, time_hi_and_version (big-endian)
    bytes[0] = static_cast<uint8_t>((ts_100ns >> 24) & 0xFF);
    bytes[1] = static_cast<uint8_t>((ts_100ns >> 16) & 0xFF);
    bytes[2] = static_cast<uint8_t>((ts_100ns >> 8) & 0xFF);
    bytes[3] = static_cast<uint8_t>(ts_100ns & 0xFF);
    bytes[4] = static_cast<uint8_t>((ts_100ns >> 40) & 0xFF);
    bytes[5] = static_cast<uint8_t>((ts_100ns >> 32) & 0xFF);
    bytes[6] = static_cast<uint8_t>((ts_100ns >> 56) & 0xFF);
    bytes[7] = static_cast<uint8_t>((ts_100ns >> 48) & 0xFF);

    bytes[6] = (bytes[6] & 0x0F) | 0x10; // version 1
    bytes[8] = (bytes[8] & 0x3F) | 0x80; // variant
    return UUID{bytes};
}

UUID v4() {
    std::array<uint8_t, 16> bytes{};
    phh::utils::gen::secure_random_bytes(bytes.data(), bytes.size());
    bytes[6] = (bytes[6] & 0x0F) | 0x40; // version 4
    bytes[8] = (bytes[8] & 0x3F) | 0x80; // variant RFC 4122
    return UUID{bytes};
}

UUID v7() {
std::array<uint8_t, 16> bytes{};
    uint64_t ts_ms = phh::utils::gen::unix_timestamp_ms();

    // big-endian 48-bit timestamp in bytes 0-5
    bytes[0] = static_cast<uint8_t>((ts_ms >> 40) & 0xFF);
    bytes[1] = static_cast<uint8_t>((ts_ms >> 32) & 0xFF);
    bytes[2] = static_cast<uint8_t>((ts_ms >> 24) & 0xFF);
    bytes[3] = static_cast<uint8_t>((ts_ms >> 16) & 0xFF);
    bytes[4] = static_cast<uint8_t>((ts_ms >> 8)  & 0xFF);
    bytes[5] = static_cast<uint8_t>(ts_ms & 0xFF);

    // random + monotonic counter for sub-millisecond uniqueness
    phh::utils::gen::secure_random_bytes(bytes.data() + 6, 10);
    uint16_t counter = phh::utils::gen::monotonic_counter();
    bytes[7] = (bytes[7] & 0xF0) | (counter & 0x0F); // embed 4-bit counter

    bytes[6] = (bytes[6] & 0x0F) | 0x70; // version 7
    bytes[8] = (bytes[8] & 0x3F) | 0x80; // variant RFC 4122
    return UUID{bytes};
}

} // namespace uuid
} // namespace utils
} // namespace phh
