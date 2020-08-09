
#include "catch.hpp"
#include "interval_map/interval_map.h"
#include "interval_map/key.h"
#include "interval_map/value.h"
#include "interval_map/key.h"


TEST_CASE("Empty Interval Map", "[interval_map]") {

	Value<char> valBegin = 'A';

	interval_map<Key<int>, Value<char>> emptyMap(valBegin);

	SECTION("querying and empty interval map returns the initialisation value") {

		try
		{
			Value<char> V = emptyMap[Key<int>(71675)];
			REQUIRE(V==Value('A'));
		}
		catch (...)
		{
			REQUIRE(false);
		}
	}
}

TEST_CASE("Interval Map Basic Functionality", "[interval_map]") {

	interval_map<Key<int>, Value<char>> m(Value<char>('B'));
	m.assign(Key<int>(0), Key<int>(2), Value('C'));
	m.assign(Key<int>(2), Key<int>(4), Value('D'));
	m.assign(Key<int>(4), Key<int>(6), Value('E'));

	/*
	SECTION("Each key-value-pair (k,v) in interval_map<K,V>::m_map means that the value v is associated with all keys from k (including) to the next key (excluding) in m_map") {

		try
		{
			REQUIRE(m[0] == 'C');
			REQUIRE(m[1] == 'C');
			REQUIRE(m[2] == 'D');
			REQUIRE(m[3] == 'D');
			REQUIRE(m[4] == 'E');
			REQUIRE(m[5] == 'E');

			REQUIRE(m[7] == 'E');
		}
		catch (...)
		{
			REQUIRE(false);
		}
	}

	SECTION("The member interval_map<K,V>::m_valBegin holds the value that is associated with all keys less than the first key in m_map.") {

		try
		{
			REQUIRE(m[-1] == 'B');
		}
		catch (...)
		{
			REQUIRE(false);
		}
	}

	SECTION("The first entry in m_map must not contain the same value as m_valBegin") {

		try
		{
			size_t startSize = m.internalMapSize();
			
            // add values which are less than the initialisation value
			// these should be ignored and not added to the map
			// (Note: this is infered from the question)
			m.assign(-2, -1, 'A');

			REQUIRE(m.internalMapSize() == startSize);
		}
		catch (...)
		{
			REQUIRE(false);
		}
	}

	*/	
}