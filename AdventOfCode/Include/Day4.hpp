#pragma once

#include "AdventOfCodeDayChallenges.hpp"

class Day4 : public AdventOfCodeDayChallenges
{
public:
    Day4() : AdventOfCodeDayChallenges(4) {}

private:
    virtual void ParseInput(std::string_view input) override;

    void ProcessChallengeOne() override;
    void ProcessChallengeTwo() override;

    struct CleaningSection {
        unsigned int mStart = 0;
        unsigned int mEnd = 0;

        inline bool Contains(CleaningSection& other) const
        {
            return other.mStart >= mStart && other.mEnd <= mEnd;
        }
        inline bool PartiallyContains(CleaningSection& other)
        {
            return other.mStart >= mStart && other.mStart <= mEnd
                || other.mEnd >= mStart && other.mEnd <= mEnd;
        }
    };

    std::vector<CleaningSection> mCleaningSections;
};
