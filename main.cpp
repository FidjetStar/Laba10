#include <iostream>
#include "h.h"
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>
#ifdef _WIN64
#include <windows.h>
#endif

int main() {
    using namespace std;
    #ifdef _WIN64
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    #endif
    int choice;
    do {
        cout << "\n=== Выберите Задание ===" << endl;
        cout << "1. ListWork13 " << endl;
        cout << "2. ListWork22" << endl;
        cout << "3. ListWork60" << endl;
        cout << "4. Dynamic4" << endl;
        cout << "5. Dynamic26" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "\n=== Задание ListWork13 ===" << endl;
            LinkedList list;
            int choice1;
            do {
                cout << "\n=== Выберите Способ заполнения  списка===" << endl;
                cout << "1. С клавиатуры" << endl;
                cout << "2. Рандомно" << endl;
                cout << "3. С файла" << endl;
                cout << "4. Действия со списком" << endl;
                cout << "5. Решение задания" << endl;
                cout << "0. Назад" << endl;
                cout << "Выберите: ";
                cin >> choice1;
                switch (choice1) {
                case 1:
                    inputfromkeyboard(list);
                    break;
                case 2:
                    inputfromRandom(list);
                    break;
                case 3:
                    char filename[100];
                    cout << "Введите имя файла из которого хотите считать данные: ";
                    cin >> filename;
                    inputfromFile(list, filename);
                    break;
                case 4:
                    AddDelFind(list);
                    break;
                case 5:
                    printMultiplesOfThree(list);
                    break;
                case 0:
                    cout << "Возврат\n";
                    break;
                default:
                    cout << "Неверный ввод\n";
                }
            } 
            while (choice1 != 0);
            break;
        }
        case 2: {
            cout << "\n=== Задание ListWork22 ===" << endl;
            LinkedList list1;
            int choice1;
            do {
                cout << "\n=== Выберите Способ заполнения списка ===" << endl;
                cout << "1. С клавиатуры" << endl;
                cout << "2. Рандомно" << endl;
                cout << "3. С файла" << endl;
                cout << "4. Действия со списком" << endl;
                cout << "5. Решение задания" << endl;
                cout << "0. Назад" << endl;
                cout << "Выберите: ";
                cin >> choice1;
                switch (choice1) {
                case 1:
                    inputfromkeyboard(list1);
                    break;
                case 2:
                    inputfromRandom(list1);
                    break;
                case 3:
                    char filename[100];
                    cout << "Введите имя файла из которого хотите считать данные: ";
                    cin >> filename;
                    inputfromFile(list1, filename);
                    break;
                case 4:
                    AddDelFind(list1);
                    break;
                case 5: {
                    int m;
                    cout << "Введите значение которое хотите вставить после каждого второго элемента списка" << endl;
                    cin >> m;
                    Listwork22(list1, m);
                    break; 
                }
                case 0:
                    cout << "Возврат\n";
                    break;
                default:
                    cout << "Неверный ввод\n";
                }
            } 
            while (choice1 != 0);
            break;
        }
        case 3: {
            cout << "\n=== Задание ListWork60 ===" << endl;
            LinkedList list2;
            int choice2;
            do {
                cout << "\n=== Выберите Способ заполнения списка ===" << endl;
                cout << "1. С клавиатуры" << endl;
                cout << "2. Рандомно" << endl;
                cout << "3. С файла" << endl;
                cout << "4. Действия со списком" << endl;
                cout << "5. Решение задания" << endl;
                cout << "0. Назад" << endl;
                cout << "Выберите: ";
                cin >> choice2;
                switch (choice2) {
                case 1:
                    inputfromkeyboard(list2);
                    break;
                case 2:
                    inputfromRandom(list2);
                    break;
                case 3:
                    char filename[100];
                    cout << "Введите имя файла из которого хотите считать данные: ";
                    cin >> filename;
                    inputfromFile(list2, filename);
                    break;
                case 4:
                    AddDelFind(list2);
                    break;
                case 5: {
                    int m;
                    cout << "Введите значение которое хотите вставить в список: " << endl;
                    cin >> m;
                    Listwork60(list2, m);
                    break; 
                }
                case 0:
                    cout << "Возврат\n";
                    break;
                default:
                    cout << "Неверный ввод\n";
                }
            } 
            while (choice2 != 0);
            break;
        }
        case 4: {
            cout << "\n=== Задание Dynamic4 ===" << endl;
            LinkedListStack stack;
            int choice2;
            do {
                cout << "\n=== Выберите Способ заполнения стека ===" << endl;
                cout << "1. С клавиатуры" << endl;
                cout << "2. Рандомно" << endl;
                cout << "3. С файла" << endl;
                cout << "4. Действия со стеком" << endl;
                cout << "5. Решение задания" << endl;
                cout << "0. Назад" << endl;
                cout << "Выберите: ";
                cin >> choice2;
                switch (choice2) {
                case 1:
                    inputfromkeyboardstack(stack);
                    break;
                case 2:
                    inputfromRandomStack(stack);
                    break;
                case 3:
                    char filename[100];
                    cout << "Введите имя файла из которого хотите считать данные: ";
                    cin >> filename;
                    inputfromFileStack(stack, filename);
                    break;
                case 4:
                    AddDelShowStack(stack);
                    break;
                case 5: {
                    Dynamic4(stack);
                    break; 
                }
                case 0:
                    cout << "Возврат\n";
                    break;
                default:
                    cout << "Неверный ввод\n";
                }
            } 
            while (choice2 != 0);
            break;
        }
        case 5: {
            cout << "\n=== Задание Queue ===" << endl;
            Queue queue;
            int choice2;
            do {
                cout << "\n=== Выберите Способ заполнения очереди ===" << endl;
                cout << "1. С клавиатуры" << endl;
                cout << "2. Рандомно" << endl;
                cout << "3. С файла" << endl;
                cout << "4. Действия со стеком" << endl;
                cout << "5. Решение задания" << endl;
                cout << "0. Назад" << endl;
                cout << "Выберите: ";
                cin >> choice2;
                switch (choice2) {
                case 1:
                    inputfromkeyboardqueue(queue);
                    break;
                case 2:
                    inputfromRandomQueue(queue);
                    break;
                case 3:
                    char filename[100];
                    cout << "Введите имя файла из которого хотите считать данные: ";
                    cin >> filename;
                    inputfromFileQueue(queue, filename);
                    break;
                case 4:
                    AddDelShowQueue(queue);
                    break;
                case 5: {
                    break; 
                }
                case 0:
                    cout << "Возврат\n";
                    break;
                default:
                    cout << "Неверный ввод\n";
                }
            } 
            while (choice2 != 0);
            break;
        }
    } 
    }
    while (choice != 0);
    return 0;
}
