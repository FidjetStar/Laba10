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
        cout << "0. Выход" << endl;
        cout << "Выберите: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "\n=== Задание ListWork13 ===" << endl;
            int choice1;
            do {
                cout << "\n=== Выберите Способ заполнения ===" << endl;
                cout << "1. С клавиатуры" << endl;
                cout << "2. Рандомно" << endl;
                cout << "3. С файла" << endl;
                cout << "0. Назад" << endl;
                cout << "Выберите: ";
                cin >> choice1;
                switch (choice1) {
                case 1: {
                    inputfromkeyboard();
                    break;
                }
                case 2:
                    cout << "Рандомное заполнение (будет реализовано)" << endl;
                    break;
                case 3:
                    cout << "Заполнение из файла (будет реализовано)" << endl;
                    break;
                case 0:
                    cout << "Возврат в главное меню" << endl;
                    break;
                default:
                    cout << "Введены неверные данные" << endl;
                }
            } 
            while (choice1 != 0);

            break; 
        }
        case 0:
            cout << "Программа завершена" << endl;
            break;
        default:
            cout << "Введены неверные данные" << endl;
        }
    } 
    while (choice != 0);
    return 0;
}

