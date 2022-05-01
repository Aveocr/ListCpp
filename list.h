#pragma once
#pragma warning(disable : 4996) 
#include "sportsman.h"

class MyList
{
public:
	MyList();
	~MyList();

	// изменение размера списка 

	// добавление в конец
	void push_back(Sportsman* data);
	// добавление в начало
	void push_top(Sportsman* data);
	// удаление последнего элемента
	void pop_back();
	// удалеине первого элемента 
	void pop_front();
	// удаление всех элементов из списка, очистка
	void remove();
	// удаление по индексу
	void pop_index(int index);

	// вывод информации на экран

	// вывод всей информации
	void print_all();
	// Поиск по баллам (перебором)
	void print_point(int number);
	// Поиск по фамилии (перебором)
	void print_surname(char surname[]);
	// Вывод сумму баллов и сколько человек имеет данное количество баллов
	void print_count_point();

	// поление размера списка
	int get_size();

	// работа с файлами 

	// чтения из файла(бинарный)
	bool readFromFile();
	// чтение из файла(текстовый)
	bool readFromTextFile();
	// загрузка в файл 
	bool load_to_file();


	// Сортировка по полям 

	// сортировка по фамилии
	void sortBySurname();
	// Сортировка по сумме попыток
	void sortBySum();


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

