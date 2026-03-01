#include "h.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

void printMultiplesOfThree(const LinkedList& list) {
    Node* current = list.head;
    bool found = false;
    std::cout << "Элементы, кратные 3: ";
    while (current) {
        if (current->value % 3 == 0) {
            std::cout << current->value << " ";
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "нету элементов кратных трем";
    }
    std::cout << std::endl;
    std::cout << "Задание завершено" << std::endl;
}


void inputfromkeyboardstack(LinkedListStack& stack) {
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Количество должно быть положительным.\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        int val;
        std::cout << "Введите значение элемента " << i + 1 << ": ";
        std::cin >> val;
        stack.push(val);
    }
    std::cout << "данные записаны в стек" << std::endl;
}

void inputfromFileStack(LinkedListStack& stack, const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла\n";
        return;
    }
    int val;
    while (file >> val) {
        stack.push(val);
    }
    file.close();
    std::cout << "Данные успешно считаны из файла\n";
}

void inputfromRandomStack(LinkedListStack& stack) {
    srand(time(nullptr));
    std::cout << "Сколько чисел добавить? ";
    int n; 
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Количество должно быть положительным.\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        int val = rand() % 100 + 1;
        stack.push(val);
    }
    std::cout << "Случайные числа добавлены в стек\n";
}




void Listwork60(const LinkedList& list, int m) {
    if (list.head == nullptr) {                     
        LinkedList newlist;                         
        newlist.pushBack(m);                        
        std::cout << "Исходный список пуст. Создан новый список с элементом " << m << std::endl;              
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
    std::cout << "Данные успешно считаны из файла\n";
}



void inputfromRandom(LinkedList& list) {
    srand(time(nullptr));
    std::cout << "Сколько чисел добавить? ";
    int n; 
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Количество должно быть положительным.\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        int val = rand() % 100 + 1;
        list.pushBack(val);
    }
    std::cout << "Случайные числа добавлены в список\n";
}




void inputfromkeyboard(LinkedList& list) {
    std::cout << "Сколько чисел добавить? ";
    int n; 
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Количество должно быть положительным.\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        int val;
        std::cout << "Введите число " << i+1 << ": ";
        std::cin >> val;
        list.pushBack(val);
    }
    std::cout << "данные записаны в список" << std::endl;
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




void AddDelShowStack(LinkedListStack& stack) {
    int choice;
    do {
        std::cout << "Меню";
        std::cout << "\n1 - Добавить в голову \n2 - Удалить верхний элемент\n3- Показать\n0 - Выход\nВыбор: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                int val; 
                std::cout << "Введите значение: "; 
                std::cin >> val;
                stack.push(val);
                break;
            }
            case 2: {
                stack.pop();
                std::cout << "Удален верхний элемент\n";
            }
            case 3: {
                stack.print();
                break;
            }
            case 0: break;
            default: std::cout << "Неверный выбор\n";
        }
    } 
    while (choice != 0);
}




void Dynamic4(LinkedListStack& stack) {
    int n;
    std::cout << "Введите количество элементов для стека: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Количество должно быть положительным.\n";
        return;
    }
    std::vector<int> nn;
    nn.reserve(n);
    for (int i = 0; i < n; i++) {
        int val;
        std::cout << "Введите значение элемента " << i + 1 << ": ";
        std::cin >> val;
        nn.push_back(val);
    }
    for (int i = 0; i < n; i++) {
        stack.push(nn[i]);
    }
    stack.print();
    std::cout << stack.head << " указатель на вершину" << std::endl;

}

void AddDelShowQueue(Queue& queue) {
    int choice;
    do {
        std::cout << "Меню";
        std::cout << "\n1 - Добавить в конец\n2 - Удалить\n3- Показать\n4 - Найти\n0 - Выход\nВыбор: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                int val; 
                std::cout << "Введите значение: "; 
                std::cin >> val;
                queue.pushBackQueue(val);
                break;
            }
            case 2: {
                queue.popQueue();
                std::cout << "Удален первый элемент\n";
            }
            case 3: {
                queue.print();
                break;
            }
            case 4: {
                int val;
                std::cout << "Введите значение для поиска: ";
                std::cin >> val;
                Tnode* node = queue.find(val);
                if (node) std::cout << "Элемент найден: " << node << "\n";
                else std::cout << "Не найдено\n";
                break;
            }
            case 0: break;
            default: std::cout << "Неверный выбор\n";

        }
    } 
    while (choice != 0);
}




void inputfromkeyboardqueue(Queue& queue) {
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Количество должно быть положительным.\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        int val;
        std::cout << "Введите значение элемента " << i + 1 << ": ";
        std::cin >> val;
        queue.pushBackQueue(val);
    }
    std::cout << "данные записаны в очередь" << std::endl;

}



void inputfromFileQueue(Queue& queue, const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла\n";
        return;
    }
    int val;
    while (file >> val) {
        queue.pushBackQueue(val);
    }
    file.close();
    std::cout << "Данные успешно считаны из файла\n";
}

void inputfromRandomQueue(Queue& queue) {
    srand(time(nullptr));
    std::cout << "Сколько чисел добавить? ";
    int n; 
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Количество должно быть положительным.\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        int val = rand() % 100 + 1;
        queue.pushBackQueue(val);
    }
    std::cout << "Случайные числа добавлены в список\n";
}

    // ===== Демонстрация работы AddDelShowQueue, AddDelShowStack, AddDelFind =====
    void showExamples() {
        std::cout << "\n=== Демонстрация AddDelFind (список) ===" << std::endl;
        LinkedList list;
        list.pushBack(10);
        list.pushBack(20);
        list.pushBack(30);
        std::cout << "Исходный список: ";
        list.print();
        std::cout << "Добавим 40" << std::endl;
        list.pushBack(40);
        list.print();
        std::cout << "Удалим 20" << std::endl;
        list.remove(20);
        list.print();
        std::cout << "Найдем 30..." << std::endl;
        Node* found = list.find(30);
        if (found) std::cout << "Найдено: " << found->getValue() << std::endl;
        else std::cout << "Не найдено" << std::endl;

        std::cout << "\n=== Демонстрация AddDelShowStack (стек) ===" << std::endl;
        LinkedListStack stack;
        stack.push(5);
        stack.push(15);
        stack.push(25);
        std::cout << "Исходный стек: ";
        stack.print();
        std::cout << "Добавим 35" << std::endl;
        stack.push(35);
        stack.print();
        std::cout << "Удалим верхний элемент" << std::endl;
        stack.pop();
        stack.print();

        std::cout << "\n=== Демонстрация AddDelShowQueue (очередь) ===" << std::endl;
        Queue queue;
        queue.pushBackQueue(100);
        queue.pushBackQueue(200);
        queue.pushBackQueue(300);
        std::cout << "Исходная очередь: ";
        queue.print();
        std::cout << "Добавим 400" << std::endl;
        queue.pushBackQueue(400);
        queue.print();
        std::cout << "Удалим первый элемент" << std::endl;
        queue.popQueue();
        queue.print();
    }

