#pragma once
#include <map>

template<typename K, typename V>
class interval_map {
	V m_valBegin;
	std::map<K,V> m_map;
public:
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {

		using Map = std::map<K, V>;
		using Pair = std::pair<K, V>;

		// Get elements within the assigned interval
		
		//NEED TO CONSTIDER EXTENDING ASSIGNMENT RANGE TO INCLUDE RANGES WITH THE SAME VALUE AND THE ONE BEING ASIGNED
		auto itStart = std::find_if(m_map.begin(), m_map.end(), [&](const Pair& p) {return keyBegin < p.first; });
		auto itEnd = std::find_if(m_map.begin(), m_map.end(), [&](const Pair& p) {return keyEnd < p.first; });


		// introducing some higher level concepts:
		bool nonEmpty = std::distance(m_map.begin(),m_map.end())>0;
		bool nonEmptyBeforeRange = std::distance(m_map.begin(),itStart)>0;
		bool nonEmptyAssignmentRange = std::distance(itStart,itEnd)>0;
		bool nonEmptyAfterRange = std::distance(itEnd, m_map.end())>0;

		// need to know what the value should be for after the key range
		V valueImmediatelyAfterAssignmentRange = operator[](keyEnd);

		// we need to erase all elements in the assignment range
		for (auto it = itStart; it != itEnd && it != m_map.end();) { it = m_map.erase(it); }
		m_map.insert_or_assign(keyBegin, val);
		m_map.insert_or_assign(keyEnd,valueImmediatelyAfterAssignmentRange);
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