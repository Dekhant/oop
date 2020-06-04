#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../catch/catch.hpp"
#include "../vector/functions.h"
#include <vector>

using namespace std;

TEST_CASE("Test for reading")
{
	istringstream input("1.11 2.22 3.33 4.44 5.55");
	vector<double> vec;
	vec = ReadVector(input);
	vector<double> result{ 1.11, 2.22, 3.33, 4.44, 5.55 };
	CHECK(result == vec);
	vec.clear();
}

TEST_CASE("Test for multiplying")
{
	const double min = 3;
	vector<double> input, result;
	input = { 3, 4, 5, 6 };
	result = { (3 * min), (4 * min), (5 * min), (6 * min) };
	MultiplyingOnMinElement(input);
	CHECK(input == result);
}

TEST_CASE("Test for output")
{
	ostringstream output;
	vector<double> input{ 1.11, 6.66, 8.88, 10.1 };
	PrintVector(output, input);
	REQUIRE(output.str() == "1.11 6.66 8.88 10.1 ");
}