#pragma once

#include <fstream>

class Student
{
public:
	char surname[50];
	char name[30];
	int age;

	bool writeToFile(std::ofstream *outFile);
	bool readToFile(std::ifstream* inFile);
};
