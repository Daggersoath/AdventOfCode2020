#include "Days/Day7.hpp"

#include "StrUtils.h"
#include "VecUtils.hpp"

#include <unordered_map>
#include <numeric>
#include <functional>

#include "Directory.h"

Day7::Day7()
	: AdventOfCodeDayChallenges(7), mRootDir(std::make_shared<Directory>(nullptr)) {}

void Day7::ParseInput(std::string_view input)
{
	// Lines with commands start with "$ ", output does not
    auto cmds = String::Split(input, "$ ");

	std::shared_ptr<Directory> activeDir = mRootDir;
	for (const auto& cmd : cmds)
		ProcessCommand(cmd, activeDir);
}

void Day7::ProcessCommand(std::string_view cmd, std::shared_ptr<class Directory>& activeDir)
{
	// first line is command, all lines after are the output
	auto output = std::move(String::Split(cmd, "\n"));
	// commands are written as "cmd arg1 arg2", so pop front to cmd, rest is args
	auto args = String::Split(Vector::PopFront(output), " ");
	auto name = Vector::PopFront(args);

	if (name == "ls")
		activeDir->Parse(activeDir, output);
	else // it is a cd command as there are only ls and cd commands
		activeDir = args[0] == "/" ? mRootDir : activeDir->GetDir(args[0]);
}

void Day7::ProcessChallengeOne()
{
	// Make sure that size has been calculated
	mRootDir->GetSize();

	constexpr auto max_size = 100000ul;
	std::uint64_t totalSize = 0;
	mRootDir->Find(
		[](const Directory& d) {return d.GetSize() <= max_size; },
		[&totalSize](const Directory& d) { totalSize += d.GetSize(); });

	mResults[0] = std::to_string(totalSize);
}

void Day7::ProcessChallengeTwo()
{
	constexpr auto total_disk = 70000000ul;
	constexpr auto total_needed_size = 30000000ul;
	const auto currentAvail = total_disk - mRootDir->GetSize();
	const auto neededSize = total_needed_size - currentAvail;

	std::uint64_t minSize = mRootDir->GetSize();
	mRootDir->Find(
		[neededSize, &minSize](const Directory& d) {
			return d.GetSize() >= neededSize
				&& d.GetSize() < minSize;
		},
		[&minSize](const Directory& d) {minSize = d.GetSize(); });

	mResults[1] = std::to_string(minSize);
}