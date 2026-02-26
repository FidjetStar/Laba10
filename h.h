#pragma once
#include <iostream>

class LinkedList;
void printMultiplesOfThree(const LinkedList& list);
void Listwork22(const LinkedList& list, int m );

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
};


void inputfromkeyboard(LinkedList& list);
void AddDelFind(LinkedList& list);
void inputfromRandom(LinkedList& list);
