#include <iostream>
#include "functions.h"
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<double> numbers;
	numbers = ReadVector(cin);
	try
	{
		MultiplyingOnMinElement(numbers);
		if (numbers.empty())
		{
			cout << "Vector is empty";
		}
		else
		{
			sort(numbers.begin(), numbers.end());
			PrintVector(cout, numbers);
			return 0;
		}
	}
	catch(const exception& e)
	{
		cout << e.what();
		return 1;
	}
}

