#include "reverse_string.h"
#include <algorithm>
#include <string>
#include <iterator>

namespace reverse_string {
    std::string reverse_string(std::string str) {
        std::string reversed;
        reversed.reserve(str.size());
        std::copy(str.rbegin(), str.rend(), std::back_inserter(reversed));
        return reversed;
    }
}  // namespace reverse_string
