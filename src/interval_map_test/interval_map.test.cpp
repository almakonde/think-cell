
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
			REQUIRE(V == Value('A'));
		}
		catch (...)
		{
			REQUIRE(false);
		}
	}
}

TEST_CASE("Interval Map Typical Functionality: Insertions above the lowest Key in the map", "[interval_map]") {

	interval_map<Key<int>, Value<char>> m(Value<char>('A'));
	m.assign(Key<int>(0), Key<int>(2), Value('B'));
	m.assign(Key<int>(2), Key<int>(4), Value('C'));
	m.assign(Key<int>(4), Key<int>(6), Value('D'));

	SECTION("Each key-value-pair (k,v) in interval_map<K,V>::m_map means that the value v is associated with all keys from k (including) to the next key (excluding) in m_map") {

		try
		{
			REQUIRE(m[0] == Value('B'));
			REQUIRE(m[1] == Value('B'));
			REQUIRE(m[2] == Value('C'));
			REQUIRE(m[3] == Value('C'));
			REQUIRE(m[4] == Value('D'));
			REQUIRE(m[5] == Value('D'));

			REQUIRE(m[7] == Value('D'));
		}
		catch (...)
		{
			REQUIRE(false);
		}
	}

	SECTION("The member interval_map<K,V>::m_valBegin holds the value that is associated with all keys less than the first key in m_map.") {

		try
		{
			REQUIRE(m[-1] == Value('A'));
		}
		catch (...)
		{
			REQUIRE(false);
		}
	}

	SECTION("insertions should persist any previous results") {

		/*  Before
			------
			Key:    . . . 0 . . 3 . . 6 . . . . .
			Value:  B B B C C C D D D E E E E E E
		*/

		//  assign(4, 5, X)

		/*  After
			------
			Key:    . . . 0 . . 3 4 . 6 . . . . .
			Value:  B B B C C C D X D E E E E E E
		*/

		try
		{
			try
			{
				REQUIRE(m[3] == Value('D'));
				REQUIRE(m[4] == Value('X'));
				REQUIRE(m[5] == Value('D'));
				REQUIRE(m[6] == Value('E'));
			}
			catch (...)
			{
				REQUIRE(false);
			}
		}
		catch (...)
		{
			REQUIRE(false);
		}
	}

	SECTION("Inserts can overwrite existing values where applicable") {

		/*  Before
			------
			Key:    . . . 0 . . 3 . . 6 . . . . .
			Value:  B B B C C C D D D E E E E E E
		*/

		//  assign(2, 9, X)

		/*  After
			------
			Key:    . . . 0 . 2 . . . . . . 9  .
			Value:  B B B C C X X X X X X X E E E
		*/

		try
		{
			try
			{
				REQUIRE(m[1] == Value('C'));
				REQUIRE(m[2] == Value('X'));
				REQUIRE(m[5] == Value('X'));
				REQUIRE(m[8] == Value('X'));
				REQUIRE(m[9] == Value('E'));
			}
			catch (...)
			{
				REQUIRE(false);
			}
		}
		catch (...)
		{
			REQUIRE(false);
		}
	}
}

TEST_CASE("Interval Map Subtle Functionality: Insertions below the lowest Key in the map & more...", "[interval_map]") {

	interval_map<Key<int>, Value<char>> m(Value<char>('B'));
	m.assign(Key<int>(0), Key<int>(3), Value('C'));
	m.assign(Key<int>(3), Key<int>(6), Value('D'));
	m.assign(Key<int>(6), Key<int>(9), Value('E'));

	SECTION("Unnesesary insertions to m_map should be ignored i.e. simply return if the map already produces the correct answer") {
	
		/*  Before
			------
			Key:    . . . 0 . . 3 . . 6 . . . . .
			Value:  B B B C C C D D D E E E E E E
		*/

		//  assign(4, 5, D)

		/*  After
			------
			Key:    . . . 0 . . 3 . . 6 . . . . .
			Value:  B B B C C C D D D E E E E E E
		*/

		try
		{
			size_t startSize = m.internalMapSize();

			m.assign(Key<int>(4), Key<int>(5), Value('D'));

			REQUIRE(m.internalMapSize() == startSize);
		}
		catch (...)
		{
			REQUIRE(false);
		}
	}

	SECTION("insertions before the beginning of m_map should persist any previous results") {

		/*  Before
			------
			Key:    . . . . . . . 0 . . 3 . . 6 . . . . .
			Value:  B B B B B B B C C C D D D E E E E E E
		*/

		//  assign(-4, -2, X)

		/*  After
			------
			Key:    . . .-4 .-2 . 0 . . 3 . . 6 . . . . .
			Value:  B B B X X X B C C C D D D E E E E E E
		*/

		try
		{
			try
			{
				REQUIRE(m[-5] == Value('B'));
				REQUIRE(m[-4] == Value('X'));
				REQUIRE(m[-3] == Value('X'));
				REQUIRE(m[-2] == Value('X'));
				REQUIRE(m[-1] == Value('B'));
				REQUIRE(m[ 0] == Value('C'));
			}
			catch (...)
			{
				REQUIRE(false);
			}
		}
		catch (...)
		{
			REQUIRE(false);
		}
	}
}