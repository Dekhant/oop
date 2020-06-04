#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		string EncodedStr = HTMLEncode(str);
		cout << EncodedStr << endl;
	}
}
