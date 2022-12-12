#pragma once

#include "AdventOfCodeDayChallenges.hpp"

class Day1 : public AdventOfCodeDayChallenges
{
public:
    Day1() : AdventOfCodeDayChallenges(1) {}

private:
    virtual void ParseInput(std::string_view input) override;

    uint64_t GetTotalFromLargestBackpacks(int count);

    void ProcessChallengeOne() override;
    void ProcessChallengeTwo() override;

    std::vector<StrViewVec> mBackpacks;
};
