#include "Day6.hpp"

#include "UtilFuncs.hpp"

void Day6::ParseInput(std::string_view input)
{
    // No processing needed
    mInput = input;
}

void Day6::ProcessChallengeOne()
{

    size_t i = 3;
    for (; i < mInput.length(); ++i)
        if (IsSequenceUnique(mInput.substr(i-3, 4)))
            break;

    mResults[0] = std::to_string(FirstUniqueSequenceLocation(mInput, 4) + 1);
}

void Day6::ProcessChallengeTwo()
{
    mResults[1] = std::to_string(FirstUniqueSequenceLocation(mInput, 14) + 1);
}
