#include "Day4.hpp"

#include "UtilFuncs.hpp"

void Day4::ParseInput(std::string_view input)
{
    auto pairs = SplitStringToVector(input, "\n");
    for (const auto& pair : pairs)
    {
        auto pairSections = SplitStringToVector(pair, ",");

        for (const auto& section : pairSections)
        {
            auto startEnd = SplitStringToVector(section, "-");
            mCleaningSections.emplace_back(ToULong(startEnd[0]), ToULong(startEnd[1]));
        }
    }
}

void Day4::ProcessChallengeOne()
{
    int sum = 0;
    for (size_t i = 0; i < mCleaningSections.size(); i += 2)
    {
        sum += mCleaningSections[i].Contains(mCleaningSections[i + 1]) || mCleaningSections[i+1].Contains(mCleaningSections[i]);
    }
    mResults[0] = std::to_string(sum);
}

void Day4::ProcessChallengeTwo()
{
    int sum = 0;
    for (size_t i = 0; i < mCleaningSections.size(); i += 2)
    {
        sum += mCleaningSections[i].PartiallyContains(mCleaningSections[i + 1]) || mCleaningSections[i + 1].PartiallyContains(mCleaningSections[i]);
    }
    mResults[1] = std::to_string(sum);
}
