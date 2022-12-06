#include "AdventOfCodeDayChallenges.hpp"

#include <iostream>
#include <fstream>
#include <string>

AdventOfCodeDayChallenges::AdventOfCodeDayChallenges(int day)
    : mDay(day)
{
}

void AdventOfCodeDayChallenges::Run(std::string_view filePath)
{
    std::string input;
    std::getline(std::ifstream(filePath.data()), input, '\0');

    ParseInput(input);
    ProcessChallengeOne();
    ProcessChallengeTwo();
}

void AdventOfCodeDayChallenges::Verify(std::string_view expectedResults[])
{
    for (size_t i = 0; i < RESULT_COUNT; ++i)
    {
        std::cout << "Day " << mDay << " Challenge " << i << ": " << expectedResults[i] << " == " << mResults[i]
            << " - " << (expectedResults[i] == mResults[i] ? "SUCCESS" : "FAIL") << std::endl;
    }
}