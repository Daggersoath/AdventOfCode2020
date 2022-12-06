#include "Day1.hpp"

#include "UtilFuncs.hpp"

#include <algorithm>
#include <numeric>

void Day1::ParseInput(std::string_view input)
{
    for (const auto& pack : SplitStringToVector(input, "\n\n"))
    {
        mBackpacks.emplace_back();
        auto& backpack = mBackpacks.back();
        for (const auto& item : SplitStringToVector(pack, "\n"))
        {
            backpack.push_back(item);
        }
    }
}

unsigned long Day1::GetTotalFromLargestBackpacks(int count)
{
    std::vector<unsigned long> backpackTotals;
    for (const auto& backpack : mBackpacks)
    {
        unsigned long total = 0;
        for (const auto& item : backpack)
        {
            total += ToULong(item);
        }
        backpackTotals.push_back(total);
    }

    std::sort(backpackTotals.begin(), backpackTotals.end());

    return std::accumulate(backpackTotals.end() - count, backpackTotals.end(), 0);
}

void Day1::ProcessChallengeOne()
{
    mResults[0] = std::to_string(GetTotalFromLargestBackpacks(1));
}

void Day1::ProcessChallengeTwo()
{
    mResults[1] = std::to_string(GetTotalFromLargestBackpacks(3));
}
