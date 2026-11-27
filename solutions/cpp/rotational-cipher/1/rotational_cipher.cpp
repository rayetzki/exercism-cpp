#include "rotational_cipher.h"
#include <cctype>

constexpr char transform_char(const unsigned char ch, int shift) {    
    int normalized_shift = ((shift % 26) + 26) % 26;

    if (std::isupper(ch)) {
        return ((static_cast<int>(ch) - 65 + normalized_shift) % 26) + 65;
    }

    if (std::islower(ch)) {
         return ((static_cast<int>(ch) - 97 + normalized_shift) % 26) + 97;
    }

    return ch;
}

namespace rotational_cipher {
    std::string rotate(std::string str, int shift) {
        std::string rotated{};
    
        for (const unsigned char ch : str) {
            rotated += transform_char(ch, shift);
        }

        return rotated;
    };
}  // namespace rotational_cipher
