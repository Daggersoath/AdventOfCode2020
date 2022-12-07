#pragma once

#include <vector>
#include <string>

inline bool IsUpper(char c) { return !(c & 32); }
inline char ToUpper(char c) { return (c & 95); }

unsigned long ToULong(std::string_view str);

std::vector<std::string_view> SplitStringToVector(std::string_view input, const char* del);

char FindCommonChar(std::vector<std::string_view> strVec);
bool IsSequenceUnique(std::string_view sequence);
size_t FirstUniqueSequenceLocation(std::string_view str, size_t seqLen);