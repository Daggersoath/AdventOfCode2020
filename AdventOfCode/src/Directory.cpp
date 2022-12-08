#include "Directory.h"

#include "StrUtils.h"

#include <stdexcept>

void Directory::Parse(std::shared_ptr<Directory> self, StrViewVec lsOutput)
{
	for (const auto& entry : lsOutput)
	{
		auto entryComponents = String::Split(entry, " ");
		if (entryComponents[0] != "dir")
			mFiles.push_back({ String::ToUint64(entryComponents[0]), entryComponents[1] });
		else if (mChildren.find(entryComponents[1]) == mChildren.end())
			mChildren[entryComponents[1]] = std::make_shared<Directory>(self);
	}
}

std::shared_ptr<Directory> Directory::GetDir(std::string_view name)
{
	if (name == "..")
		return mParent;
	if (auto it = mChildren.find(name); it != mChildren.end())
		return it->second;
	throw std::runtime_error("No such directory!");
}

std::uint64_t Directory::GetSize()
{
	mSize = 0;
	for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
	{
		mSize += it->second->GetSize();
	}
	for (const auto& file : mFiles)
		mSize += file.first;
	return mSize;
}