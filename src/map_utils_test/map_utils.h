
#pragma once
#include <map>

namespace utils
{
	using Map = std::map<int, char>;
	using Pair = std::pair<int, char>;

	bool containsLowerKey(const Map& m_map, const int& kStart);

	bool containsHigherKey(Map& m_map, const int& kStart);
}