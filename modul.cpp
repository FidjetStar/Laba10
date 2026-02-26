#include "h.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


void printMultiplesOfThree(const LinkedList& list) {
    Node* current = list.head;
    std::cout << "Элементы, кратные 3: ";
    while (current) {
        if (current->value % 3 == 0)
            std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
    std::cout << "Задание завершено" << std::endl;

}

void Listwork22(const LinkedList& list, int m) {
    Node* current = list.head;
    int length = 0;
    while (current != nullptr) {
        length++;
        current = current->next;
    }

    if (length < 2) {
        std::cout << "Список содержит меньше 2 элементов. Вставка невозможна." << std::endl;
        return;
    }
    current = list.head;  // сбрасываем current на начало
    Node* q;
    int k = 1;
    while (current != nullptr) {
        if (k % 2 == 0) {
            q = current->next;                    
            Node* newNode = new Node(m);           
            newNode->next = q;                      
            current->next = newNode;                 
            current = q;
        } 
        else {
            current = current->next;
        }
        k++;
    }
    std::cout << "Задание завершено. Значение " << m << " вставлено после каждого второго элемента." << std::endl;
}

void inputfromRandom(LinkedList& list) {
    srand(time(nullptr));
    std::cout << "Сколько чисел добавить? ";
    int n; 
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int val = rand() % 100 + 1;
        list.pushBack(val);
    }
}




void inputfromkeyboard(LinkedList& list) {
    std::cout << "Сколько чисел добавить? ";
    int n; 
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        std::cout << "Введите число " << i+1 << ": ";
        std::cin >> val;
        list.pushBack(val);
    }
}

void AddDelFind(LinkedList& list) {
    int choice;
    do {
        std::cout << "Меню";
        std::cout << "\n1 - Добавить\n2 - Удалить\n3 - Найти\n4 - Показать\n0 - Выход\nВыбор: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                int val; 
                std::cout << "Введите значение: "; 
                std::cin >> val;
                list.pushBack(val);
                break;
            }
            case 2: {
                int val; 
                std::cout << "Введите значение для удаления: "; 
                std::cin >> val;
                if (list.remove(val)) std::cout << "Удалено\n";
                else std::cout << "Не найдено\n";
                break;
            }
            case 3: {
                int val; 
                std::cout << "Введите значение для поиска: "; 
                std::cin >> val;
                Node* node = list.find(val);
                if (node) std::cout << "Элемент найден(первое вхождение): " << node << "\n";
                else std::cout << "Не найдено\n";
                break;
            }
            case 4: list.print(); break;
            case 0: break;
            default: std::cout << "Неверный выбор\n";
        }
    } 
    while (choice != 0);
}
