#pragma once

#include "AdventOfCodeDayChallenges.hpp"
#include <vector>

class Day3 : public AdventOfCodeDayChallenges
{
public:
    Day3() : AdventOfCodeDayChallenges(3) {}

private:
    virtual void ParseInput(std::string_view input) override;
    void ProcessChallengeOne() override;
    void ProcessChallengeTwo()override;

    bool SplitPouches(const std::string_view& rucksack, std::vector<std::string_view>& output) const;
    unsigned int CharToScore(char& c);

    std::vector<std::string_view> mRucksacks;
};
