#include "Day3.hpp"

#include <stdexcept>

#include "UtilFuncs.hpp"

void Day3::ParseInput(std::string_view input)
{
    mRucksacks = SplitStringToVector(input, "\n");
}

void Day3::ProcessChallengeOne()
{
    unsigned long long sum = 0;

    for (const auto& rucksack : mRucksacks)
    {
        if (std::vector<std::string_view> pouches; SplitPouches(rucksack, pouches))
        {
            auto commonItem = FindCommonChar(pouches);
            sum += CharToScore(commonItem);
        }
    }
    mResults[0] = std::to_string(sum);
}

void Day3::ProcessChallengeTwo()
{
    unsigned long long sum = 0;
    for (size_t i = 0; i < mRucksacks.size(); i += 3)
    {
        auto commonItem = FindCommonChar({ mRucksacks.begin() + i, mRucksacks.begin() + i + 3 });
        sum += CharToScore(commonItem);
    }
    mResults[1] = std::to_string(sum);
}

bool Day3::SplitPouches(const std::string_view& rucksack, std::vector<std::string_view>& output) const
{
    if (rucksack.size() & 1)
        return false;

    size_t pouchSize = rucksack.size() / 2;
    output.push_back(rucksack.substr(0, pouchSize));
    output.push_back(rucksack.substr(pouchSize));

    return true;
}

unsigned int Day3::CharToScore(char& c)
{
    return (ToUpper(c) - 'A') + (IsUpper(c) * 26) + 1;
}
