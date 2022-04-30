#include "student.h"

using namespace std;

bool Student::writeToFile(std::ofstream* outFile) {
	// File not open
	if(!outFile){
		return false;
	}
	outFile->write((char*)this, sizeof(Student));

	if (outFile->good()) {
		return true;
	}
	return false;
}

// It's reading 
bool Student::readToFile(std::ifstream* inFile) {
	if (!inFile) {
		return false;
	}
	if (inFile->peek() == EOF) {
		return false;
	}
	inFile->read((char*)this, sizeof(Student));
	if (inFile->good()) {
		return true;
	}
	return false;
}