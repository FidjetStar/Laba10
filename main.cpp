#pragma once
#include <iostream>

class LinkedList;
class LinkedListStack;
class Queue;

void printMultiplesOfThree(const LinkedList& list);
void Listwork22(const LinkedList& list, int m );
void Listwork60(const LinkedList& list, int m);

class Node {
private:
    int value;
    Node* next;
public:
    Node(int val) : value(val), next(nullptr) {}
    int getValue() const { return value; }
    friend class LinkedList;
    friend void printMultiplesOfThree(const LinkedList& list);
    friend void Listwork22(const LinkedList& list, int m);
    friend void Listwork60(const LinkedList& list, int m);
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr) {
        Node* current = other.head;
        while (current) {
            pushBack(current->value);
            current = current->next;
        }
    }
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    bool isEmpty() const { return head == nullptr; }

    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() const {
        Node* current = head;
        if (!current) {
            std::cout << "Пустой\n";
            return;
        }
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    Node* find(int val) const {
        Node* current = head;
        while (current && current->value != val)
            current = current->next;
        return current;
    }

    bool remove(int val) {
        if (isEmpty()) return false;
        Node* current = head;
        Node* prev = nullptr;
        while (current) {
            if (current->value == val) {
                if (!prev) {
                    head = current->next;
                    if (!head) tail = nullptr;
                } 
                else {
                    prev->next = current->next;
                    if (current == tail) tail = prev;
                }
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }
    friend void printMultiplesOfThree(const LinkedList& list);
    friend void Listwork22(const LinkedList& list, int m);
    friend void Listwork60(const LinkedList& list, int m);
};


void inputfromkeyboard(LinkedList& list);
void AddDelFind(LinkedList& list);
void inputfromRandom(LinkedList& list);
void inputfromFile(LinkedList& list, const char* filename);





//===== СТЭК ======



class Node1 {
private:
    int value;
    Node1* next;
public:
    friend class LinkedListStack;
    Node1(int val) : value(val), next(nullptr) {}
    int getValue() const { return value; }
    friend void Dynamic4(LinkedListStack& stack);

};



class LinkedListStack {
private:
    Node1* head;
    
public:
    LinkedListStack() : head(nullptr) {}
    LinkedListStack(const LinkedListStack& other) : head(nullptr) {
    LinkedListStack temp;                 
    Node1* current = other.head;
    while (current) {
        temp.push(current->getValue());
        current = current->next;
    }
    current = temp.head; 
    while (current) {
        push(current->getValue());
        current = current->next;
    }
    }
    ~LinkedListStack() {
        Node1* current = head;
        while (current) {
            Node1* temp = current;
            current = current->next;
            delete temp;
        }
    }
    bool isEmpty() const { return head == nullptr; }
    void push(int val) {
        if (isEmpty()) {
            head = new Node1(val);
        } 
        else {
            Node1* newNode = new Node1(val);
            newNode->next = head;
            head = newNode;
        }
    }

    void print() const {
    Node1* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
    }

    void pop() {
    if (isEmpty()) {
        std::cout << "Стек пуст. Удаление невозможно." << std::endl;
        return;
    }
    Node1* temp = head;   
    head = head->next;     
    delete temp;            
    }
    /*Node1* find(int val) const {
        Node1* current = head;
        while (current && current->value != val)
            current = current->next;
        return current;
    }*/
   friend void Dynamic4(LinkedListStack& stack);
};



void inputfromkeyboardstack(LinkedListStack& stack);
void inputfromFileStack(LinkedListStack& stack, const char* filename);
void inputfromRandomStack(LinkedListStack& stack);
void AddDelShowStack(LinkedListStack& list);




// ===== Очередь =====





class Tnode {
private:
    int value;
    Tnode* next;
public:
    Tnode(int val) : value(val), next(nullptr) {}
    int getValue() const { return value; }
    friend class Queue;

};

class Queue {
private:
    Tnode* head;
    Tnode* tail;
public:
    Queue() : head(nullptr), tail(nullptr) {}
    Queue(const Queue& other) : head(nullptr), tail(nullptr) {
        Tnode* current = other.head;
        while (current) {
            pushBackQueue(current->getValue());
            current = current->next;
        }
    }
    ~Queue() {
        Tnode* current = head;
        while (current) {
            Tnode* temp = current;
            current = current->next;
            delete temp;
        }
    }

    bool isEmpty() const { return head == nullptr; }

    void pushBackQueue(int val) {
        Tnode* newNode = new Tnode(val);
        if (isEmpty()) {
            head = tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = nullptr;
        }
    }

    void print() const {
        Tnode* current = head;
        if (!current) {
            std::cout << "Пустой\n";
            return;
        }
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void popQueue() {
    if (isEmpty()) {
        std::cout << "Очередь пуста. Удаление невозможно." << std::endl;
        return;
    }
    Tnode* temp = head;   
    head = head->next;     
    delete temp;            
    }

    Tnode* find(int val) const {
        Tnode* current = head;
        while (current && current->value != val)
            current = current->next;
        return current;
    }
    
};

void AddDelShowQueue(Queue& queue);
void inputfromRandomQueue(Queue& queue);
void inputfromFileQueue(Queue& queue, const char* filename);
void inputfromkeyboardqueue(Queue& queue);

