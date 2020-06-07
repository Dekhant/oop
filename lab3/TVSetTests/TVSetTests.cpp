#define CATCH_CONFIG_MAIN
#include "../catch/catch.hpp"
#include "../TVSet/CTVSet.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

CTVSet* Tv = new CTVSet();


TEST_CASE("Turn on")
{
	CHECK(Tv->TurnOn() == true);
	CHECK(Tv->GetChannel() == 1);
}

TEST_CASE("Trying turn on already turned on tv")
{
	Tv->TurnOn();
	CHECK(Tv->TurnOn() == false);
	CHECK(Tv->GetChannel() == 1);
}

TEST_CASE("Turn off")
{
	Tv->TurnOn();
	CHECK(Tv->TurnOff());
	CHECK(Tv->GetChannel() == 0);
}

TEST_CASE("Trying turn off already turned off tv")
{
	Tv->TurnOn();
	Tv->TurnOff();
	CHECK(Tv->TurnOff() == false);
	CHECK(Tv->GetChannel() == 0);
}

TEST_CASE("Select channel")
{
	Tv->TurnOn();
	CHECK(Tv->SelectChannel(20));
	CHECK(Tv->GetChannel() == 20);
}

TEST_CASE("Select wrong channel")
{
	Tv->TurnOn();
	CHECK(Tv->SelectChannel(100) == false);
}

TEST_CASE("Select prev channel")
{
	Tv->TurnOn();
	Tv->SelectChannel(20);
	Tv->SelectChannel(40);
	CHECK(Tv->SelectPreviousChannel());
	CHECK(Tv->GetChannel() == 20);
}