#include "Days/Day8.hpp"

#include "StrUtils.h"
#include "VecUtils.hpp"

#include <iostream>
#include <cmath>

void Day8::ParseInput(std::string_view input)
{
    mResults[0] = input;

    auto lines = String::Split(input, "\n");
    mTreeHeights.resize(lines.size());

    for (size_t i = 0; i < lines.size(); ++i)
    {
        Vector::Transform(lines[i], mTreeHeights[i], [](const char& c) { return static_cast<unsigned char>((c - '0')); });
        mTreeHeights[i].resize(lines[i].length());
    }
}

void Day8::ProcessChallengeOne()
{
    const size_t edgeTrees = mTreeHeights.size() * 2 + mTreeHeights.front().size() * 2 - 4;
    size_t count = edgeTrees;
    for (size_t y = 1; y < mTreeHeights.size() - 1; ++y)
    {
        for (size_t x = 1; x < mTreeHeights[y].size() - 1; ++x)
        {
            std::optional<size_t> distances[4];
            FindBlockingTrees(x, y, distances);
            for (size_t i = 0; i < 4; ++i)
            {
                if (!distances[i].has_value())
                {
                    ++count;
                    break;
                }
            }
        }
    }
    mResults[0] = std::to_string(count);
}

void Day8::ProcessChallengeTwo()
{
    size_t max = 0;
    for (size_t y = 1; y < mTreeHeights.size() - 1; ++y)
        for (size_t x = 1; x < mTreeHeights[y].size() - 1; ++x)
            max = std::max(max, CalculateViewScore(x, y));

    mResults[1] = std::to_string(max);
}

size_t Day8::CalculateViewScore(size_t x, size_t y)
{
    std::optional<size_t> distances[4]; // left, right, up, down;
    FindBlockingTrees(x, y, distances);
    return distances[0].value_or(x)
        * distances[1].value_or(mTreeHeights[y].size() - x - 1)
        * distances[2].value_or(y)
        * distances[3].value_or(mTreeHeights.size() - y - 1);
}

bool Day8::IsTreeBlocking(size_t x, size_t y, std::uint8_t val)
{
    if (x < 0 || y < 0 || y >= mTreeHeights.size() || x >= mTreeHeights[y].size())
        return false;
    return mTreeHeights[y][x] >= val;
}

void Day8::FindBlockingTrees(size_t x, size_t y, std::optional<size_t>* blockingDistances)
{
    uint8_t& val = mTreeHeights[y][x];
    size_t max = std::max(std::max(x, mTreeHeights[y].size()), std::max(y, mTreeHeights.size() - y));
    for (size_t i = 1; i < max; ++i)
    {
        if (!blockingDistances[0].has_value() && IsTreeBlocking(x - i, y, val))
            blockingDistances[0] = i;
        if (!blockingDistances[1].has_value() && IsTreeBlocking(x + i, y, val))
            blockingDistances[1] = i;
        if (!blockingDistances[2].has_value() && IsTreeBlocking(x, y - i, val))
            blockingDistances[2] = i;
        if (!blockingDistances[3].has_value() && IsTreeBlocking(x, y + i, val))
            blockingDistances[3] = i;
    }
}