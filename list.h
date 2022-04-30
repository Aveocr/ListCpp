#pragma once
#pragma warning(disable : 4996) 
#include "sportsman.h"

class MyList
{
public:
	MyList();
	~MyList();

	void push_back(Sportsman* data);
	void push_top(Sportsman* data);
	void pop_back();
	void pop_front();
	void remove();
	void pop_index(int index);

	void print_all();
	void print_point(int number);
	void print_surname(char surname[]);
	void print_count_point();

	int get_size();
	bool readFromFile();
	bool readFromTextFile();
	bool load_to_file();

private:

	struct Node {
		Sportsman data;
		Node* pNext;
		//конструктор с одним параметром
		Node(Sportsman* tempData) {
			//копируем данные полей из tempData в data
			strcpy(data.surname, tempData->surname);
			data.number = tempData->number;
			data.attemtionOne = tempData->attemtionOne;
			data.attemptionTwo = tempData->attemptionTwo;
			data.attemptionThree = tempData->attemptionThree;
			pNext = nullptr;
		}
	};

	int size;
	Node* head;
};

