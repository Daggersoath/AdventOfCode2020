#include "Days/Day3.hpp"

#include <stdexcept>

#include "StrUtils.h"

void Day3::ParseInput(std::string_view input)
{
    mRucksacks = String::Split(input, "\n");
}

void Day3::ProcessChallengeOne()
{
    std::uint64_t sum = 0;

    for (const auto& rucksack : mRucksacks)
    {
        if (StrViewVec pouches; SplitPouches(rucksack, pouches))
        {
            auto commonItem = String::FindCommonChar(pouches);
            sum += CharToScore(commonItem);
        }
    }
    mResults[0] = std::to_string(sum);
}

void Day3::ProcessChallengeTwo()
{
    std::uint64_t sum = 0;
    for (size_t i = 0; i < mRucksacks.size(); i += 3)
    {
        auto commonItem = String::FindCommonChar({ mRucksacks.begin() + i, mRucksacks.begin() + i + 3 });
        sum += CharToScore(commonItem);
    }
    mResults[1] = std::to_string(sum);
}

bool Day3::SplitPouches(const std::string_view& rucksack, StrViewVec& output) const
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
    return (Char::ToUpper(c) - 'A') + (Char::IsUpper(c) * 26) + 1;
}
