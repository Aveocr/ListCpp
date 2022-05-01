#define _CRT_SECURE_NO_WARNINGS 1

#include "sportsman.h"

using namespace std;

// swap 
void Sportsman::swap(Sportsman data)
{
	Sportsman temp; 
	// меняем фамилию
	strcpy(temp.surname, data.surname);
	strcpy(data.surname, surname);
	strcpy(surname, temp.surname);

	// меняем порядковый номер спортсмена
	temp.number = data.number; 
	data.number = number; 
	number = temp.number; 

	// меняем попытки спортсмена

	temp.attemtionOne = data.attemtionOne;
	data.attemtionOne = attemtionOne;
	attemtionOne = temp.attemtionOne;

	temp.attemptionTwo = data.attemptionTwo;
	data.attemptionTwo = attemptionTwo;
	attemptionTwo = temp.attemptionTwo;

	temp.attemptionThree = data.attemptionThree;
	data.attemptionThree = attemptionThree;
	attemptionThree = temp.attemptionThree;
}

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
