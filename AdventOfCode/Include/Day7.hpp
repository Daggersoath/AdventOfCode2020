#pragma once

#include "TypeDefs.h"

#include "AdventOfCodeDayChallenges.hpp"

class Day7 : public AdventOfCodeDayChallenges {
public:
    Day7();

private:

    virtual void ParseInput(std::string_view input) override;
    void ProcessCommand(std::string_view cmd, std::shared_ptr<class Directory>& activeDir);

    virtual void ProcessChallengeOne() override;
    virtual void ProcessChallengeTwo() override;

    std::shared_ptr<class Directory> mRootDir;
};