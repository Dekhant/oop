#include <iostream>
#include <set>
#include <fstream>
#include <iterator>
#include <string>
#include "Functions.h"

using namespace std;

bool OpenFiles(int& argc, char* argv[], set<string>& students)
{
	if (argc < 1)
	{
		cout << "No arguments. Usage SportSchool.exe <FirstSection.txt> <SecondSection.txt> ..." << endl;
		return false;
	}
	else
	{
		string student;
		for (int i = 1; i < argc; i++)
		{
			ifstream input(argv[i]);
			ReadFiles(input, students);
			input.close();
		}
		return true;
	}
}

void ReadFiles(istream& input, set<string>& students)
{
	string student;
	while (input >> student)
	{
		students.insert(student);
	}
}

void WriteStudents(const set<string>& students)
{
	ofstream output("output.txt");
	for (string i : students)
	{
		output << i << endl;
	}
}