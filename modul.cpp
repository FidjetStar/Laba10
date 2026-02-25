#include "h.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>
void inputfromkeyboard() {
    using namespace std;
    cout << "Ввод с клавиатуры" << endl;
    LinkedList list;
    int n;
    cout << "Сколько чисел добавить? ";
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int val;
        cout << "Введите число " << i+1 << ": ";
        cin >> val;
        list.pushBack(val);
    }
    cout << "Ваш список: ";
    list.print();
}
