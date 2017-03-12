#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("matrix init", "[init]") {
	Matrix matrix;
	REQUIRE(matrix.str() == 0);
	REQUIRE(matrix.col() == 0);
}
