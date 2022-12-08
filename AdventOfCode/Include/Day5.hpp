#pragma once

#include "AdventOfCodeDayChallenges.hpp"

#include <string>

class Day5 : public AdventOfCodeDayChallenges {
public:
    Day5() : AdventOfCodeDayChallenges(5) {}

private:
    struct Move {
        const std::uint64_t Count;
        const std::uint64_t Source;
        const std::uint64_t Dest;
    };

    virtual void ParseInput(std::string_view input) override;
    void ParseStacks(std::string_view input);
    void ParseMoves(std::string_view input);

    void DoMove(std::vector<std::string>& stacks, const Move& move, bool reverseOrder) const;

    virtual void ProcessChallengeOne() override;
    virtual void ProcessChallengeTwo() override;

    std::vector<std::string> mStacks;
    std::vector<Move> mMoves;
};

