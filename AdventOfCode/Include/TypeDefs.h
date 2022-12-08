#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <cstdint>
#include <functional>

using StrViewVec = std::vector<std::string_view>;
using CompareFunc = std::function<bool(unsigned long, unsigned long)>;
