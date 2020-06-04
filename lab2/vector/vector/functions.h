#pragma once
#include <vector>

std::vector<double> ReadVector(std::istream& input);
void MultiplyingOnMinElement(std::vector<double>& numbers);
void PrintVector(std::ostream& output, const std::vector<double>& numbers);