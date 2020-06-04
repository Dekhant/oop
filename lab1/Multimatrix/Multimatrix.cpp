#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <functional>
#include <iomanip>

using namespace std;

const unsigned int Size = 3;

typedef double SquareMatrix[Size][Size];

bool ReadMatrixFromFile(const string& FileName, SquareMatrix& matrix)
{
	int counter = 0;
	size_t i = 0, j = 0;
	bool done = false;
	ifstream input(FileName);
	if (!(input.is_open()))
	{
		cout << "File not opend";
		return false;
	}
	double num;
	while (input >> num)
	{
		counter++;
		if (counter > 9)
		{
			cout << "wrong matrix";
			return false;
		}
		if (j == 3)
		{
			j = 0;
			i++;
		}
		if (i == 3)
		{
			done = true;
		}
		if(!done)
		{
			matrix[i][j] = num;
		}
		j++;
	}
	return true;
}

bool MultiMatrix(const SquareMatrix& matrix1, const SquareMatrix& matrix2, SquareMatrix& resultMatrix)
{
	double sum = 0;
	for (size_t i = 0; i < Size; i++)
	{
		for (size_t j = 0; j < Size; j++)
		{
			for (size_t k = 0; k < Size; k++)
			{
				sum += matrix1[i][k] * matrix2[k][j];
			}
			resultMatrix[i][j] = sum;
			sum = 0;
		}
	}
	return true;
}


void PrintSquareMatrix(SquareMatrix mat) 
{
	for (unsigned int i = 0; i < Size; ++i)
	{
		for (unsigned int j = 0; j < Size; ++j) 
		{
			cout << fixed << setprecision(3) << mat[i][j] << " ";
		}
		cout << endl;
	}
}

bool Combining(const int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid argument count\n"<< "Usage: Multimatrix.exe <matrix1.txt> <matrix2.txt>";
		return false;
	}
	SquareMatrix matrix1, matrix2, resultMatrix;
	if (!ReadMatrixFromFile(argv[1], matrix1))
	{
		return false;
	}
	if (!ReadMatrixFromFile(argv[2], matrix2))
	{
		return false;
	}
	if (!MultiMatrix(matrix1, matrix2, resultMatrix))
	{
		return false;
	}
	PrintSquareMatrix(resultMatrix);
	return true;
}

int main(int argc, char* argv[])
{
	if (!Combining(argc, argv))
	{
		return 1;
	}
	return 0;
}