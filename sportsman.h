#pragma once

#include <fstream>

class Sportsman
{
public:
	char surname[50];
	int number;
	int attemtionOne, attemptionTwo, attemptionThree;

	bool writeToFile(std::ofstream* outFile);
	bool readToFile(std::ifstream* inFile);
	int sumAttemption();
};