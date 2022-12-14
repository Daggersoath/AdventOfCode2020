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
    std::cout << "Day " << mDay << " - ";
    for (size_t i = 0; i < RESULT_COUNT; ++i)
    {
        if (expectedResults[i].empty())
            continue;
        if (expectedResults[i] != mResults[i])
        {
            std::cout << "FAILED Challenge " << i + 1 << ", Expected "
                << expectedResults[i] << " but got " << mResults[i] << std::endl;
            return;
        }
    }
    std::cout << "SUCCESS!" << std::endl;
}