
#include "catch.hpp"
#include "interval_map/interval_map.h"


TEST_CASE("Empty Interval Map", "[interval_map]") {

	char valBegin = 'A';

	interval_map<int, char> emptyMap(valBegin);

	SECTION("querying and empty interval map returns the initialisation value") {

		try
		{
			char V = emptyMap[71675];
			REQUIRE(V=='A');
		}
		catch (...)
		{
			REQUIRE(false);
		}
	}

}