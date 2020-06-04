#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "functions.h"

using namespace std;

vector<double> ReadVector(istream& input)
{
	vector<double> numbers;
	double store;
	while (input >> store)
	{
		numbers.push_back(store);
	}
	return numbers;
}

void MultiplyingOnMinElement(vector<double>& numbers)
{
	const double min = *min_element(numbers.begin(), numbers.end());
	for (size_t i = 0; i < numbers.size(); i++)
	{
		numbers[i] *= min;
	}
}

void PrintVector(ostream& output, const vector<double>& numbers)
{
	for (size_t i = 0; i < numbers.size(); i++)
	{
		output << setprecision(3) << numbers[i] << " ";
	}
}