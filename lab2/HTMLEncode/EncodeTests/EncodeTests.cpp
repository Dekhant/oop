#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../catch/catch.hpp"
#include "../HTMLEncode/functions.h"
#include <vector>

TEST_CASE("Empty Input")
{
	string str = "", Encoded = "";
	CHECK(HTMLEncode(str) == Encoded);
}

TEST_CASE("Nothing to change")
{
	string str = "cat says meow", Encoded = "cat says meow";
	CHECK(HTMLEncode(str) == Encoded);
}

TEST_CASE("Normal Work")
{
	std::string str = "Cat <says> \"Meow\". M&M's";
	std::string Encoded = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";

	CHECK(HTMLEncode(str) == Encoded);

	Encoded = "&amp&amp;;&lt;&amp&gt;";
	str = "&&;<&>";

	CHECK(HTMLEncode(str) == Encoded);
}