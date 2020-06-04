#pragma once
#include <iostream>
#include <set>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;

bool OpenFiles(int& argc, char* argv[], set<string>& students);

void ReadFiles(istream& input, set<string>& students);

void WriteStudents(const set<string>& students);