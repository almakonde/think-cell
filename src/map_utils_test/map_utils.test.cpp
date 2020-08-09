
#include "catch.hpp"
#include "map_utils.h"




TEST_CASE("Test containsLowerKey", "[map utils]") {

	std::map<int, char> m;

	SECTION("test empty map") {

		REQUIRE(!utils::containsLowerKey(m, 71675));
	}

	SECTION("try with some values") {

		m.insert(std::make_pair(1, 'A'));
		m.insert(std::make_pair(2, 'B'));
		m.insert(std::make_pair(4, 'D'));
		m.insert(std::make_pair(5, 'E'));

		REQUIRE(utils::containsLowerKey(m, 3));
	}
}

TEST_CASE("Test containsHigherKey", "[map utils]") {

	std::map<int, char> m;

	SECTION("test empty map") {

		REQUIRE(!utils::containsHigherKey(m, 71675));
	}

	SECTION("try with some values") {

		m.insert(std::make_pair(1, 'A'));
		m.insert(std::make_pair(2, 'B'));
		m.insert(std::make_pair(4, 'D'));
		m.insert(std::make_pair(5, 'E'));

		REQUIRE(utils::containsHigherKey(m, 3));
	}
}