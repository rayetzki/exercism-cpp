#include "atbash_cipher.h"
#include <string>
#include <cctype>

constexpr char transform_char(unsigned char ch) {
    if (std::isalpha(ch)) {
        char lower = static_cast<char>(std::tolower(ch));
        return static_cast<char>('z' - (lower - 'a'));
    }
    if (std::isdigit(ch)) {
        return static_cast<char>(ch);
    }
    return '\0';
}

namespace atbash_cipher {    
    std::string encode(std::string str) {
        std::string encoded{};
        encoded.reserve(str.size() + str.size() / 5);
        
        int group_count = 0;
    
        for (unsigned char ch : str) {
            char mapped = transform_char(ch);
    
            if (mapped == '\0') continue;

            if (group_count == 5) {
                encoded += ' ';
                group_count = 0;
            }

            encoded += mapped;
            group_count++;
        }
    
        return encoded;
    }
    
    std::string decode(std::string str) {
        std::string decoded{};
        decoded.reserve(str.size());
    
        for (unsigned char ch : str) {
            char mapped = transform_char(ch);
    
            if (mapped != '\0') {
                decoded += mapped;
            }
        }
    
        return decoded;
    }
}  // namespace atbash_cipher
