#include <algorithm>
#include <cstdio>
#include <exception>
#include <fstream>
#include <phh/utils/is.hh>

namespace phh {
namespace utils {
namespace is {

bool file_exists(const std::string &file_path) {
    std::ifstream file(file_path);
    return file.good() ? true : false;
}

bool numeric(const std::string &input) {
    try {
        if (input.empty()) {
            return false;
        }
        if (input == "0") {
            return true;
        }

        // detect negative value or positive
        if (input[0] == '-') {
            if (input.size() == 1) {
                return false;
            }
            if (input.size() == 2 && input[1] == '0') {
                return true; // handle "-0"
            }
            if (input[1] == '0') {
                return false; // leading zero after '-'
            }
            if (!std::all_of(input.begin() + 1, input.end(), ::isdigit)) {
                return false;
            }
        } else {
            if (input[0] == '0' && input.size() > 1) {
                return false; // leading zero
            }
            if (!std::all_of(input.begin(), input.end(), ::isdigit)) {
                return false;
            }
        }

        std::stoll(input);
    } catch (const std::exception &e) {
        std::printf("Exception: %s\n", e.what());
        return false;
    } catch (...) {
        std::printf("Error: unexpected behaviour from %s; %i\n", __FILE__,
                    __LINE__);
        return false;
    }

    return true;
}

bool numeric_unsigned(const std::string &input) {
    try {
        if (input.empty() || input[0] == '-') {
            return false;
        }
        if (input == "0") {
            return true;
        }
        if (input[0] == '0' && input.size() > 1) {
            return false; // leading zero
        }
        if (!std::all_of(input.begin(), input.end(), ::isdigit)) {
            return false;
        }

        std::stoull(input);
    } catch (const std::exception &e) {
        std::printf("Exception: %s\n", e.what());
        return false;
    } catch (...) {
        std::printf("Error: unexpected behaviour from %s; %i\n", __FILE__,
                    __LINE__);
        return false;
    }

    return true;
}

bool numeric_decimal(const std::string &input) {
    try {
        if (input.empty()) {
            return false;
        }

        size_t dot_pos = input.find('.');
        if (dot_pos == std::string::npos || dot_pos == input.size() - 1) {
            return false; // wrong decimal format: no dot, dot at start nor dot
                          // at the end
        }

        std::string integer_part = input.substr(0, dot_pos),
                    fractional_part = input.substr(dot_pos + 1);

        // validate integer part
        if (integer_part == "0" || integer_part == "-0") {
            // ok for "0" or "-0"
        } else {
            if (integer_part[0] == '-') {
                if (integer_part.size() == 1 || integer_part[1] == '0')
                    return false;
                // ensure no leading zeros after '-' and all characters are
                // digits
                if (!std::all_of(integer_part.begin() + 1, integer_part.end(),
                                 ::isdigit))
                    return false;
            } else {
                if (integer_part[0] == '0' && integer_part.size() > 1)
                    return false; // leading zero
                if (!std::all_of(integer_part.begin(), integer_part.end(),
                                 ::isdigit))
                    return false;
            }
        }

        // validate fractional part
        if (!std::all_of(fractional_part.begin(), fractional_part.end(),
                         ::isdigit)) {
            return false;
        }

        std::stod(input);
    } catch (const std::exception &e) {
        std::printf("Exception: %s\n", e.what());
        return false;
    } catch (...) {
        std::printf("Error: unexpected behaviour from %s; %i\n", __FILE__,
                    __LINE__);
        return false;
    }

    return true;
}

} // namespace is
} // namespace utils
} // namespace phh
