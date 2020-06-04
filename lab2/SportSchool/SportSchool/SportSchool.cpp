#include <iostream>
#include <set>
#include <fstream>
#include <iterator>
#include <string>
#include "Functions.h"

using namespace std;


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	set<string> students;

	if (!OpenFiles(argc, argv, students))
		return 1;
	WriteStudents(students);
}
