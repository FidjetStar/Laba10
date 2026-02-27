#include "h.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

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

void Listwork60(const LinkedList& list, int m) {
    if (list.head == nullptr) {                     
        LinkedList newlist;                         
        newlist.pushBack(m);                        
        std::cout << "Исходный список пуст. Создан новый список с элементом " << m << std::endl;               // FIX
        newlist.print();                            
        return;                                     
    }

    Node* current = list.head;
    Node* lastcurrent = list.head;

    while (current->next != nullptr) {              
        if (current->value > current->next->value) {
            std::cout << "Список не упорядочен по возрастанию. "
                      << "Задание не может быть выполнено." << std::endl;
            return;
        }
        current = current->next;                   
    }

    std::cout << "Список упорядочен по возрастанию." << std::endl;

    LinkedList newlist = list; 

    Node* newcurrent = newlist.head;
    Node* prev = nullptr;                     

    while (newcurrent != nullptr && newcurrent->value < m) { 
        prev = newcurrent;                          
        newcurrent = newcurrent->next;              
    }

    Node* newNode = new Node(m);

    if (prev == nullptr) {                          
        newNode->next = newlist.head;               
        newlist.head = newNode;                    
        if (newlist.tail == nullptr)                
            newlist.tail = newNode;                 
    }
    else {
        newNode->next = newcurrent;                
        prev->next = newNode;                       

        if (newcurrent == nullptr)                 
            newlist.tail = newNode;                 
    }

    std::cout << "Значение " << m << " вставлено в список." << std::endl;
    std::cout << "Новый список: ";
    newlist.print();
    std::cout << newlist.head << " адрес головы нового списка" << std::endl; // вывод адреса головы нового списка
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


void inputfromFile(LinkedList& list, const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла\n";
        return;
    }
    int val;
    while (file >> val) {
        list.pushBack(val);
    }
    file.close();
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
                Node* node = list.find(val); // запишет указатель на найденный узел или nullptr
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
