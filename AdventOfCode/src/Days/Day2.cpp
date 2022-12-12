#include "Days/Day2.hpp"

#include "StrUtils.h"

#include <array>
#include <string>

void Day2::ParseInput(std::string_view input)
{
	for (const auto& play : String::Split(input, "\n"))
	{
		mOpponentPlay.push_back(play[0] - 'A');
		mMyPlay.push_back(play[2] - 'X');
	}
}

int Day2::GetRoundResult(unsigned char oponentCode, unsigned char yourCode)
{
	char rr = oponentCode - yourCode;

	return mPointsForPlay[yourCode] + ((rr == 0) ? mPointsForResult[1]
		: (rr == -1 || rr == 2) ? mPointsForResult[2]
		: mPointsForResult[0]);
}

void Day2::ProcessChallengeOne()
{
	int total = 0;
	for (size_t i = 0; i < mOpponentPlay.size(); ++i)
		total += GetRoundResult(mOpponentPlay[i], mMyPlay[i]);
	mResults[0] = std::to_string(total);
}

void Day2::ProcessChallengeTwo()
{
	std::array<std::array<unsigned char, 3>, 3> cheatSheet = {
		3, 1, 2,
		1, 2, 3,
		2, 3, 1 };

	int total = 0;
	for (size_t i = 0; i < mOpponentPlay.size(); ++i)
	{
		total += cheatSheet[mOpponentPlay[i]][mMyPlay[i]] + mPointsForResult[mMyPlay[i]];
	}
	mResults[1] = std::to_string(total);
}
