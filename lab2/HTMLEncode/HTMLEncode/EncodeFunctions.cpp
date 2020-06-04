#include "functions.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Dictionary
{
	string symbol;
	string code;

};

const vector<Dictionary> HTML_Codes = { {"&", "&amp;"}, {"\"", "&quot;"}, {"'", "&apos;"}, {"<", "&lt;"}, {">", "&gt;"}};

string Replace(string& Encode, const string& Symbol, const string& Code)
{
	string Result = "";
	if (Encode.empty())
	{
		return Result;
	}
	size_t Position = 0, CodePosition = 0;
	while (CodePosition != string::npos)
	{
		CodePosition = Encode.find(Symbol, Position);
		if (CodePosition == string::npos)
		{
			Result.append(Encode, Position, Encode.size());
			break;
		}
		else
		{
			Result.append(Encode, Position, CodePosition - Position);
			Position = CodePosition + 1;
			Result.append(Code);
		}
	}
	return Result;
}

string HTMLEncode(string& str)
{
	string Encode = str;
	for (auto replacements : HTML_Codes)
	{
		Encode = Replace(Encode, replacements.symbol, replacements.code);
	}
	return Encode;
}