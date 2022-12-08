#include "StrUtils.h"

#include <charconv>

using namespace String;

std::uint64_t String::ToUint64(view str)
{
    int out;
    const std::from_chars_result result = std::from_chars(str.data(), str.data() + str.size(), out);
    if (result.ec == std::errc::invalid_argument || result.ec == std::errc::result_out_of_range)
    {
        return ~0ul;
    }
    return out;
}

std::vector<view> String::Split(view input, view del)
{
    std::vector<view> output;
    size_t offset = 0;

    while (offset < input.size())
    {
        if (size_t pos = input.find(del, offset); pos != -1)
        {
            if (auto substr = input.substr(offset, pos - offset); !substr.empty())
                output.push_back(substr);
            offset = pos + del.length();
            continue;
        }
        output.push_back(input.substr(offset));
        break;
    }

    return output;
}

char String::FindCommonChar(std::vector<view> strVec)
{
    if (strVec.empty())
        return 0;

    std::string commonChars(strVec[0]);
    for (size_t i = 1; i < strVec.size(); ++i)
        for (size_t j = 0; j < commonChars.size(); ++j)
            if (strVec[i].find(commonChars[j]) == -1)
                commonChars.erase(commonChars.begin() + j--);

    return commonChars.empty() ? 0 : commonChars[0];
}

bool String::IsSequenceUnique(view sequence)
{
    const size_t seqLen = sequence.length();
    for (size_t i = 0; i < seqLen; ++i)
        for (size_t j = i + 1; j < seqLen; ++j)
            if (sequence[i] == sequence[j])
                return false;

    return true;
}

size_t String::FirstUniqueSequenceLocation(view str, size_t seqLen)
{
    const size_t start = seqLen - 1;
    size_t index = start;
    for (; index < str.length(); ++index)
        if (String::IsSequenceUnique(str.substr(index - start, seqLen)))
            break;

    return index;
}
