#define CATCH_CONFIG_MAIN
#include "../catch/catch.hpp"
#include "../SportSchool/Functions.h"
#include <sstream>
#include <iostream>
#include <set>
#include <string>


TEST_CASE("Empty input")
{
	set<string> students;
	istringstream input("");
	ReadFiles(input, students);
	CHECK(students.size() == 0);
}

TEST_CASE("Normal work")
{
	set<string> students;
	istringstream input("Pushin\nGogol\nTolstoi");
	ReadFiles(input, students);
	CHECK(students.size() == 3);
}

TEST_CASE("Duplicates")
{
	set<string> students;
	istringstream input("Pushkin\nPushkin\nPushkin");
	ReadFiles(input, students);
	CHECK(students.size() == 1);
}