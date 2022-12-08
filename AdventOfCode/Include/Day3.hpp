#pragma once

#include "AdventOfCodeDayChallenges.hpp"

class Day3 : public AdventOfCodeDayChallenges
{
public:
    Day3() : AdventOfCodeDayChallenges(3) {}

private:
    virtual void ParseInput(std::string_view input) override;
    void ProcessChallengeOne() override;
    void ProcessChallengeTwo()override;

    bool SplitPouches(const std::string_view& rucksack, StrViewVec& output) const;
    unsigned int CharToScore(char& c);

    StrViewVec mRucksacks;
};
