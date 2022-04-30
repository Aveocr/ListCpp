// studyLabaList4.cpp :
// Author: aveocr


#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

#include "sportsman.h"
#include "list.h"

#define PATH "C:\\Temp\\sportsman.dat"
#define PATH_TXT "C:\\Temp\\Sportsman.txt"

using namespace std;

void readListFromFile(MyList* list);
void addStudToList(MyList* list);
void loadListToFile(MyList* list);
void readListFromTextFile(MyList* list);


int main()
{
    setlocale(0, "");
    bool flag = true;
    int select; 
    MyList list;

    cout.setf(ios::left);
    while (flag) {
        system("cls");

        cout << " Меню" << endl;
        cout << "________________________________\n";
        cout << "1: Чтение из файла" << endl;
        cout << "2: Печать списка" << endl;
        cout << "3: Добавление спортсмена" << endl;
        cout << "4: Сохранение в файл" << endl;
        cout << "5: Поиск по фамилии" << endl;
        cout << "6: Поиск по баллам" << endl;
        cout << "7: Удаление последнего элемента" << endl;
        cout << "8: Удаление первого элемента" << endl;
        cout << "9: Удаление выбранного элемента" << endl;
        cout << "10: Считать из текстового файла" << endl;
        cout << "11: Очистить список" << endl;
        cout << "12: Сортировка" << endl;
        cout << "13: Поиск по числовому полю" << endl;
        cout << "14: Поиск по текстовому полю" << endl;
        cout << "15: Вывести размер списка" << endl;
        cout << "16: Выход" << endl;
        cout << "________________________________\n" << endl;
        cout << "Выберите операцию (1-16): ";

        cin >> select;
        switch (select)
        {
            case 1: readListFromFile(&list); system("PAUSE"); 
                break;

            case 2: list.print_all(); system("PAUSE"); 
                break;

            case 3: addStudToList(&list);
                break;
            case 4: loadListToFile(&list); 
                break;

            case 5: 
                char surname[50];
                cout << "Введите фамилию человека, которого хотите найти в списке: ";
                cin >> surname;
                list.print_surname(surname);
                system("pause");
                break;

            case 6:
                int age;
                cout << "Введите сумму баллов спортсменов, которых вы хотите найти в списке: ";
                cin >> age; 
                list.print_point(age);

                cout << "Дополнительная информация: ";
                list.print_count_point();
                system("pause");
                break;

            case 7: list.pop_back(); 
                break;

            case 8: list.pop_front(); 
                break; 

            case 9:
                list.print_all();
                int number;
                cout << "Введите номер, которые вы хотите удалить: ";
                cin >> number; 
                list.pop_index(number);
                break; 

            case 10: 
                system("cls");
                readListFromTextFile(&list);
                list.print_all();
                system("pause");
                break;

            case 11: 
                list.remove();
                break;

            case 12: cout << "Метод еще не создан" << endl; 
                break;

            case 13: cout << "Метод еще не создан" << endl;
                system("pause");
                break;

            case 14: cout << "Метод еще не создан" << endl;
                system("pause");
                break;

            case 15: 
                cout << list.get_size() << endl;
                system("pause");
                break;
            case 16: flag = false;
                list.remove();
                break;;

            default: cout << "Выберите число от 1 до 16\n";
        }
    }
    system("PAUSE");
    return 0;
}

void readListFromFile(MyList* list)
{
    if (list == nullptr) {
        cout << "We haven't a point of list" << endl;
    }
    else {
        ifstream inFile(PATH, ios::binary | ios::in);
        //cout << "Input name file with data: "
        if (!list->readFromFile()) {
            cout << "Wrong name file";
         }
        else {
            cout << "Successful read" << endl;
        }
    }
}

// Добавление студента в список
void addStudToList(MyList* list)
{
    if (list == nullptr) {
        cout << "We haven't a point of list";
    }
    else {
        Sportsman stud;
        system("cls");
        cin.ignore();

        cout << "Surname: "; cin.getline(stud.surname, 50);
        cout << "Number: "; cin >> stud.number;
        cout << "Attemtion one: "; cin >> stud.attemtionOne;
        cout << "Attemtion two: "; cin >> stud.attemptionTwo;
        cout << "Attemtion three: "; cin >> stud.attemptionThree;
        list->push_top(&stud);
    }
}

// Сохранение списка в файл
void loadListToFile(MyList* list)
{
    if (list == nullptr) {
        cout << "We haven't a point of list";
    }
    else {
        system("cls");
        if (list->load_to_file()) {
            cout << "Successful" << endl; 
        }
        else {
            cout << "Error load " << endl;
        }
    }
}

// чтения информации из текстового файла в список
void readListFromTextFile(MyList* list)
{
    ifstream textStudent(PATH_TXT);
    if (!textStudent) {
        cout << "Файла по пути " << PATH_TXT << " не существует! " << endl;
    }
    else if (textStudent.peek() == EOF) {
        cout << "Файл " << PATH_TXT << " пустой" << endl;
    }
    else {
        if (list->readFromTextFile()) {
            cout << "Successful" << endl;
        }
        else {
            cout << "Error load" << endl;
        }
    }
}


