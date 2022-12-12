#pragma once

#include "TypeDefs.h"

class AdventOfCodeDayChallenges
{
public:
    AdventOfCodeDayChallenges(int day);
    virtual ~AdventOfCodeDayChallenges() = default;

    void Run(std::string_view filePath);
    void Verify(std::string_view expectedResults[]);

private:
    virtual void ParseInput(std::string_view input) = 0;
    virtual void ProcessChallengeOne() = 0;
    virtual void ProcessChallengeTwo() = 0;

protected:
    static constexpr uint32_t RESULT_COUNT = 2;
    std::string mResults[RESULT_COUNT];
    const uint64_t mDay = ~0ull;
};

#define DAY_START(day) class Day##day : public AdventOfCodeDayChallenges { \
public:\
    Day##day() : AdventOfCodeDayChallenges(day) {}\
private:\
    virtual void ParseInput(std::string_view input) override;\
    virtual void ProcessChallengeOne() override;\
    virtual void ProcessChallengeTwo() override;