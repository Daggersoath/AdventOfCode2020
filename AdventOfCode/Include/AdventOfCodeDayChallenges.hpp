#pragma once

#include "TypeDefs.h"

class AdventOfCodeDayChallenges
{
public:
    AdventOfCodeDayChallenges(int day);
    virtual ~AdventOfCodeDayChallenges() = default;

    void Run(std::string_view filePath);
    void Verify(std::string_view expectedResults[]);

protected:
    static constexpr uint32_t RESULT_COUNT = 2;
    std::string mResults[RESULT_COUNT];
    const int mDay = -1;

private:
    virtual void ParseInput(std::string_view input) = 0;
    virtual void ProcessChallengeOne() = 0;
    virtual void ProcessChallengeTwo() = 0;
};