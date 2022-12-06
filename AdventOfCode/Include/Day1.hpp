#pragma once

#include "AdventOfCodeDayChallenges.hpp"

#include <vector>

class Day1 : public AdventOfCodeDayChallenges
{
public:
    Day1() : AdventOfCodeDayChallenges(1) {}

private:
    virtual void ParseInput(std::string_view input) override;

    unsigned long GetTotalFromLargestBackpacks(int count);

    void ProcessChallengeOne() override;
    void ProcessChallengeTwo() override;

    std::vector<std::vector<std::string_view>> mBackpacks;
};
