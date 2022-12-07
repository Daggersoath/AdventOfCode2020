#pragma once

#include "AdventOfCodeDayChallenges.hpp"

class Day6 : public AdventOfCodeDayChallenges {
public:
    Day6() : AdventOfCodeDayChallenges(6) {}

private:

    virtual void ParseInput(std::string_view input) override;

    virtual void ProcessChallengeOne() override;
    virtual void ProcessChallengeTwo() override;

    std::string_view mInput;
};

