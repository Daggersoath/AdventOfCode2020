#include "Days/Day6.hpp"

#include "StrUtils.h"

void Day6::ParseInput(std::string_view input)
{
    // No processing needed
    mInput = input;
}

void Day6::ProcessChallengeOne()
{
    mResults[0] = std::to_string(String::FirstUniqueSequenceLocation(mInput, 4) + 1);
}

void Day6::ProcessChallengeTwo()
{
    mResults[1] = std::to_string(String::FirstUniqueSequenceLocation(mInput, 14) + 1);
}
