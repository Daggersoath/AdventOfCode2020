#pragma once

#include "TypeDefs.h"

class Directory {
public:
	Directory(std::shared_ptr<Directory> parent) : mParent(parent) {};

	void Parse(std::shared_ptr<Directory> self, StrViewVec lsOutput);

	std::uint64_t GetSize();
	std::uint64_t GetSize() const { return mSize; }
	std::shared_ptr<Directory> GetDir(std::string_view name);

	template<typename ValidationFunc, typename Callback>
	void Find(ValidationFunc func, Callback cb)
	{
		if (func(*this))
			cb(*this);
		for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
			it->second->Find(func, cb);
	}

private:

	std::unordered_map<std::string_view, std::shared_ptr<Directory>> mChildren;
	std::vector<std::pair<std::uint64_t, std::string_view>> mFiles;
	std::shared_ptr<Directory> mParent;
	std::uint64_t mSize = 0;
};
