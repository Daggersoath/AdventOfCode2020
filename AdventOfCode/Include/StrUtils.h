#pragma once

#include <string_view>
#include <vector>

namespace Char {
    inline bool IsUpper(char c) { return !(c & 32); }
    inline char ToUpper(char c) { return (c & 95); }
}

namespace String {
    using view = std::string_view;

    std::uint64_t ToUint64(std::string_view str);

    std::vector<view> Split(view input, view del);

    char FindCommonChar(std::vector<view> strVec);

    bool IsSequenceUnique(view sequence);
    size_t FirstUniqueSequenceLocation(view str, size_t seqLen);
}