#include "sportsman.h"

using namespace std;

bool Sportsman::writeToFile(std::ofstream* outFile) {
	// File not open
	if (!outFile) {
		return false;
	}
	outFile->write((char*)this, sizeof(Sportsman));

	if (outFile->good()) {
		return true;
	}
	return false;
}

// It's reading 
bool Sportsman::readToFile(std::ifstream* inFile) {
	if (!inFile) {
		return false;
	}
	if (inFile->peek() == EOF) {
		return false;
	}
	inFile->read((char*)this, sizeof(Sportsman));
	if (inFile->good()) {
		return true;
	}
	return false;
}

int Sportsman::sumAttemption()
{
	return attemtionOne + attemptionThree + attemptionTwo;
}
