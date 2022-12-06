#pragma once

#include "AdventOfCodeDayChallenges.hpp"

#include <vector>

class Day2 : public AdventOfCodeDayChallenges
{
public:
    Day2() : AdventOfCodeDayChallenges(2) {}

private:
    virtual void ParseInput(std::string_view input) override;
    void ProcessChallengeOne() override;
    void ProcessChallengeTwo()override;

    int GetRoundResult(unsigned char oponentCode, unsigned char yourCode);

    static constexpr int mPointsForResult[] = {0, 3, 6};
    static constexpr char mPointsForPlay[] = { 1, 2, 3 };

    std::vector<unsigned char> mOpponentPlay;
    std::vector<unsigned char> mMyPlay;
};
