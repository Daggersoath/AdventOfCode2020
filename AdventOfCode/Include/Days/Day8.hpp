#pragma once

#include "AdventOfCodeDayChallenges.hpp"

#include <optional>

DAY_START(8)

bool IsTreeBlocking(size_t x, size_t y, std::uint8_t val);
void FindBlockingTrees(size_t x, size_t y, std::optional<size_t>* blockingDistances);
size_t CalculateViewScore(size_t x, size_t y);

std::vector<std::vector<std::uint8_t>> mTreeHeights;

};