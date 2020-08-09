#include "map_utils.h"
#include <algorithm>

namespace utils
{
	bool containsLowerKey(const Map& m_map, const int& kStart)
	{
		auto& it = std::find_if(m_map.begin(), m_map.end(), [&](const Pair& p) {return kStart < p.first; });
		return it != m_map.end();
	}

	bool containsHigherKey(Map& m_map, const int& kStart)
	{
		auto& it = std::find_if(m_map.begin(), m_map.end(), [&](const Pair& p) {return kStart < p.first; });
		if (std::distance(it, m_map.end()) > 1u) return true;
	}
}