#pragma once
#include <map>

namespace
{

}

template<typename K, typename V>
class interval_map {
	V m_valBegin;
	std::map<K,V> m_map;
public:
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {

	}

	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}

	size_t internalMapSize()
	{
		return m_map.size();
	}
};