#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string HTMLEncode(string& str);
string Replace(string& Encode, const string& Symbol, const string& Code);
