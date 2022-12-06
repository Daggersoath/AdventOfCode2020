#include "Day5.hpp"

#include "UtilFuncs.hpp"

void Day5::ParseInput(std::string_view input)
{
    // Input format is stacks and moves seperated by two new lines
    auto mixedInput = SplitStringToVector(input, "\n\n");
    ParseStacks(mixedInput[0]);
    ParseMoves(mixedInput[1]);
}

void Day5::ParseStacks(std::string_view input)
{
    // Each row of stacks is seperated by a newline
    // The last line is just the numbers which are in order so can be skipped
    auto rows = SplitStringToVector(input, "\n");
    rows.pop_back();

    // The number of characters is the amount of columns * 4 - 1
    // From this we extrapolate the number of columns must equal (chars + 1) / 4
    mStacks.resize((rows[0].length() + 1) / 4);
    for (const auto& row : rows)
        for (int i = 0; i < row.length(); i += 4)
            if (char box = row[i + 1]; box != ' ')
                mStacks[i / 4].insert(0, 1, box);
}

void Day5::ParseMoves(std::string_view input)
{
    // Each line is 1 move "move x from y to z"
    for (const auto& move : SplitStringToVector(input, "\n"))
    {
        auto components = SplitStringToVector(move, " ");
        mMoves.emplace_back(ToULong(components[1]), ToULong(components[3]) - 1, ToULong(components[5]) - 1);
    }
}

void Day5::DoMove(std::vector<std::string>& stacks, const Move& move, bool reverseOrder) const
{
    auto& src = stacks[move.Source];
    auto& dst = stacks[move.Dest];

    dst.insert(dst.end(), std::make_move_iterator(src.end() - move.Count), std::make_move_iterator(src.end()));
    src.erase(src.end() - move.Count, src.end());
    if (reverseOrder)
        std::reverse(dst.end() - move.Count, dst.end());
}

void Day5::ProcessChallengeOne()
{
    auto workingStacks = mStacks;
    for (const auto& move : mMoves)
        DoMove(workingStacks, move, true);

    mResults[0] = "";
    for (const auto& stack : workingStacks)
    {
        mResults[0] += stack.back();
    }
}

void Day5::ProcessChallengeTwo()
{
    auto workingStacks = mStacks;
    for (const auto& move : mMoves)
        DoMove(workingStacks, move, false);

    mResults[1] = "";
    for (const auto& stack : workingStacks)
    {
        mResults[1] += stack.back();
    }
}
