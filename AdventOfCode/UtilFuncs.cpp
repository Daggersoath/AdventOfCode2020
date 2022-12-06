#include "UtilFuncs.hpp"

#include <charconv>

unsigned long ToULong(std::string_view str)
{
    int out;
    const std::from_chars_result result = std::from_chars(str.data(), str.data() + str.size(), out);
    if (result.ec == std::errc::invalid_argument || result.ec == std::errc::result_out_of_range)
    {
        return ~0ul;
    }
    return out;
}

std::vector<std::string_view> SplitStringToVector(std::string_view input, const char* del)
{
    std::vector<std::string_view> output;
    size_t offset = 0;
    size_t delSize = strlen(del);

    while (offset < input.size())
    {
        if (size_t pos = input.find(del, offset); pos != -1)
        {
            output.push_back(input.substr(offset, pos - offset));
            offset = pos + delSize;
            continue;
        }
        output.push_back(input.substr(offset));
        break;
    }

    return output;
}

char FindCommonChar(std::vector<std::string_view> strVec)
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
