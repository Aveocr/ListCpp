#include <iostream>
#include <iomanip>
#include <fstream>
#include "list.h"

#define PATH "C:\\Temp\\sportsman.dat"
#define PATH_TXT "C:\\Temp\\Sportsman.txt"

using namespace std;


MyList::MyList()
{
	head = nullptr;
	size = 0;
}

MyList::~MyList()
{
	remove();
}

// ������� � ������� 
void MyList::push_top(Sportsman* data)
{
	Node* temp = new Node(data);
	temp->pNext = head; 
	head = temp;
	size++;
}


// ������� � �����
void MyList::push_back(Sportsman* data) 
{

	if (head == nullptr) {
		head = new Node(data);
	}
	else {
		Node* current = head; 
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	size++;
}

// ����� ������ 
void MyList::print_all() {
	Node* current = head;

	cout << setw(20) << "Surname" << setw(20) << "Number" << setw(10) << "Sum result" << endl;
	int count = 0;
	while (count < size) {
		cout << setw(20) << current->data.surname; // �������
		cout << setw(20) << current->data.number; // ���
		cout << setw(10) << current->data.sumAttemption() << endl;
		current = current->pNext;
		count++;
	}
	cout << "__________________________________________" << endl << endl;
}

// ������ ����� �� ������
void MyList::print_point(int point)
{
	Node* current = head;
	cout << "Sorted by point: " << point << endl;
	int count = 0;
	cout << setw(20) << "Surname" << setw(20) << "Name" << setw(10) << "Sum" << endl;
	while (current != nullptr) {
		
		if (current->data.sumAttemption() == point) {
			count++;
			cout << setw(20) <<  current->data.surname << setw(20) << current->data.number<< setw(10) << current->data.sumAttemption() << endl;
		}
		current = current->pNext;
	}
	cout << "����� � ������ ������� " << count << endl;
	cout << "__________________________________________" << endl << endl;
}


// ������ ����� �� �������
void MyList::print_surname(char surname[])
{
	Node* current = head;
	cout << "Sorted by surname: " << surname << endl;
	cout << setw(20) << "Surname" << setw(20) << "Number" << setw(10) << "Point" << endl;
	while (current!=nullptr) {

		if (!strcmp(current->data.surname, surname)) {
			cout << setw(20) << current->data.surname << setw(20) << current->data.number << setw(10) << current->data.sumAttemption() << endl;
		}
		current = current->pNext;
	}
	cout << "__________________________________________" << endl << endl;
}

// ����� ����� �� ����
void MyList::print_count_point()
{
	Node* current; 
	int count;
	cout << "���������� ����� � ������������� �������\n ����������, ���� �� � ���� ����� ������ ���, �� ��� �� ����� ���������" << endl << endl;
	cout << setw(20) << "Points" << setw(10) << "Quantity" << endl;
	for (int i = 0; i <= 30; i++) {
		current = head;
		count = 0;
		while (current != nullptr) {
			if (i == current->data.sumAttemption()) {
				count++;
			}
			current = current->pNext; 
		}
		if (count != 0) {
			cout << setw(20) << i << setw(10) << count << endl;
		}
	}
	
}

// ��������� ������� ������
int MyList::get_size()
{
	return size;
}

// ������ �� ��������� ����� 
bool MyList::readFromFile()
{
	if (PATH == nullptr) {
		return false;
	}
	ifstream inFile;
	inFile.open(PATH, ios::binary | ios::in);

	if (!inFile) {
		return false;
	}

	remove();

	Sportsman temp;
	bool ok = false; 
	while (!inFile.eof()) {
		if (inFile.peek() != EOF) {
			ok = temp.readToFile(&inFile);
			if (!ok) {
				inFile.close();
				return false;
			}
			push_back(&temp);
		}
	}
	inFile.close(); // close file
	return true;
}

// ������ �� �������� �����
bool MyList::readFromTextFile()
{
	
	ifstream textFile(PATH_TXT);
	char word[50];
	int number; // ���������� ��� ������ �������� ������ � �����
	int num = 1; // ���������� ����� ����������
	Sportsman temp; 
	while (!textFile.eof()) {
		if (textFile.peek() != EOF) {
			textFile >> word;
			strcpy(temp.surname, word);
			temp.number = num;
			num++;
			textFile >> number;
			temp.attemtionOne = number;
			textFile >> number;
			temp.attemptionTwo = number;
			textFile >> number;
			temp.attemptionThree = number;
			push_back(&temp);
		}
	}
	textFile.close();
	return true;
}

// �������� � �������� ����
bool MyList::load_to_file()
{
	if (PATH == nullptr) {
		return false;
	}

	ofstream outFile(PATH, ios::binary | ios::out);

	if (!outFile) {
		return false;
	}

	Node* current = head;
	while (current != nullptr) {
		current->data.writeToFile(&outFile);
		current = current->pNext;
		if (!outFile.good()) {
			outFile.close();
			return false;
		}
	}
	outFile.close();
	return true;
}

// ���������� �� �������
void MyList::sortBySurname()
{
	Node* current;
	Node* next; 
	Sportsman temp; 

	for (int i = 0; i < size; i++) {
		current = head; // j 
		next = current->pNext; // j+1

		for (int j = 0; j < size - 1; j++) {
			// ���� ������� �� current->data.surname ������, ��� next->data.surname, �� �������� ���� ����������
			if (strcmp(current->data.surname, next->data.surname) > 0) {


				// �� �������, �������� ��� ���� 
				/*temp.swap(next->data);
				next->data.swap(current->data);
				current->data.swap(temp);*/
				
				// ����� ���������, ���� ���� �������� ����� �������� � swap, ��� ������� ����, �� �� ������-�� �������� �� ��� ��� ����
				strcpy(temp.surname, current->data.surname);
				// ������ ������� �������
				strcpy(current->data.surname, next->data.surname);
				strcpy(next->data.surname, temp.surname);
				// ������ ����� ���������� 
				temp.number = current->data.number;
				current->data.number = next->data.number; 
				next->data.number = temp.number; 
				// ������ ����� �� �������
				temp.attemtionOne = current->data.attemtionOne;
				current->data.attemtionOne = next->data.attemtionOne;
				next->data.attemtionOne = temp.attemtionOne;

				temp.attemptionTwo = current->data.attemptionTwo;
				current->data.attemptionTwo = next->data.attemptionTwo;
				next->data.attemptionTwo = temp.attemptionTwo;

				temp.attemptionThree = current->data.attemptionThree;
				current->data.attemptionThree = next->data.attemptionThree;
				next->data.attemptionThree = temp.attemptionThree;
			}
			current = current->pNext;
			next = current->pNext;
		}
		
	}
}

// ���������� �� �����
void MyList::sortBySum()
{
	Node* current; 
	Node* next; 
	Sportsman temp;
	for (int i = 0; i < size; i++) {
		current = head;  // j
		next = current->pNext; // j + 1
		for (int j = 0; j < size - 1; j++) {
			if (current->data.sumAttemption() > next->data.sumAttemption()) {
				// ����� ���������, ���� ���� �������� ����� �������� � swap, ��� ������� ����, �� �� ������-�� �������� �� ��� ��� ����
				strcpy(temp.surname, current->data.surname);
				// ������ ������� �������
				strcpy(current->data.surname, next->data.surname);
				strcpy(next->data.surname, temp.surname);
				// ������ ����� ���������� 
				temp.number = current->data.number;
				current->data.number = next->data.number;
				next->data.number = temp.number;
				// ������ ����� �� �������
				temp.attemtionOne = current->data.attemtionOne;
				current->data.attemtionOne = next->data.attemtionOne;
				next->data.attemtionOne = temp.attemtionOne;

				temp.attemptionTwo = current->data.attemptionTwo;
				current->data.attemptionTwo = next->data.attemptionTwo;
				next->data.attemptionTwo = temp.attemptionTwo;

				temp.attemptionThree = current->data.attemptionThree;
				current->data.attemptionThree = next->data.attemptionThree;
				next->data.attemptionThree = temp.attemptionThree;
			}
			current = current->pNext;
			next = next->pNext;
		}
	}
}

// �������� ������
void MyList::remove() {
	while (head != nullptr) {
		Node* current = head->pNext;
		delete head;
		head = current;
		size--;
	}
	head = nullptr;
}

// �������� ���������� �������� 
void MyList::pop_back()
{
	pop_index(size - 1);
}

// �������� ������� ��������
void MyList::pop_front()
{
	if (this->head == nullptr) {
		cout << "������! ������ ������!" << endl;
		system("pause");
	}
	else {
		Node* temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
}
// ���������� � ���� 

void MyList::pop_index(int index)
{
	if (index == 0) {
		pop_front();
	}
	else if (index < size || index >= size) {
		cout << "������ ������ �� ���������. ������ ������ � ������ �� ����������" << endl;
		system("pause");
	}
	else
	{
		int count = 0;
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		Node* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}
