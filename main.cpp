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
        cout << "0. Выход" << endl;
        cout << "Выберите: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "\n=== Задание ListWork13 ===" << endl;
            LinkedList list;
            int choice1;
            do {
                cout << "\n=== Выберите Способ заполнения ===" << endl;
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
                    cout << "Заполнение из файла (будет реализовано)\n";
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
                cout << "\n=== Выберите Способ заполнения ===" << endl;
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
                    cout << "Заполнение из файла (будет реализовано)\n";
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
        case 0:
            cout << "Программа завершена\n";
            break;
        default:
            cout << "Неверный ввод\n";
        }
    } 
    while (choice != 0);
    return 0;
}

