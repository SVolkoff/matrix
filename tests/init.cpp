#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("matrix init", "[init]") {
	Matrix matrix;
	REQUIRE(matrix.lines_() == 0);
	REQUIRE(matrix.columns_() == 0);
}
SCENARIO("matrix with params", "[init]")
{
	Matrix matrix(3,3);
	REQUIRE(matrix.lines_() == 3);
	REQUIRE(matrix.columns_() == 3);
}
SCENARIO("copy", "[init]")
{
	Matrix matrix(3,3);
	Matrix copy(matrix);
	REQUIRE(copy.lines_() == 3);
	REQUIRE(copy.columns_() == 3);
}
SCENARIO("+", "[init]")
{
	Matrix matr1(3, 3);
	Matrix matr2(3, 3);
	Matrix matr12(3, 3);
	std::ifstream ("matr1.txt") >> matr1;
	std::ifstream ("matr2.txt") >> matr2;
	std::ifstream ("matr1+2.txt") >> matr12;
	REQUIRE((matr1 + matr2) == matr12);
}

SCENARIO("*", "[init]")
{
	Matrix matr1(3, 3);
	Matrix matr2(3, 3);
	Matrix matr12(3, 3);
	std::ifstream ("matr1.txt") >> matr1;
	std::ifstream ("matr2.txt") >> matr2;
	std::ifstream ("matr12.txt") >> matr12;
	REQUIRE((matr1 * matr2) == matr12);
}
				


SCENARIO("==", "[init]")
{
	Matrix matr1(3, 3);
	Matrix matr2(3, 3);
	bool f;
	std::ifstream("matr1.txt") >> matr1;
	std::ifstream("matr1.txt") >> matr2;
	if (matr1 == matr2)
		f = true;
	REQUIRE(f == true);
}

SCENARIO("=", "[init]")
{
	Matrix matr1(3, 3);
	Matrix matr2;
	std::ifstream("matr1.txt") >> matr1;
	matr2 = matr1;
	REQUIRE(matr1 == matr2);
}
SCENARIO("scan") {
	Matrix m1(3, 3);
	Matrix m2(3, 3);
	std::ifstream("matr1.txt") >> m1;
	m2.scan("matr1.txt");
	REQUIRE(m1 == m2);
}
