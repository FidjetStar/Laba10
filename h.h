#pragma once
#include <iostream>
#include <vector>
#include <string>

class Node {
public: 
    int value;
    Node* next;
    Node(const int& val) : value(val), next(nullptr) {}
};


class LinkedList {
public: 
    Node* head;
    Node* tail;
    LinkedList(): head(nullptr), tail(nullptr) {} // конструктор по умолчанию 
    bool isEmpty() const {
        return head == nullptr;
    }
    ~LinkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    }
    void pushBack(const int& val) {
        Node* NewNode = new Node(val);
        if(isEmpty()) {
            head = NewNode;
            tail = NewNode;
        }
        else {
            tail->next = NewNode;
            tail = NewNode;
        }
    }
    void print() const {
        using namespace std;
        if(isEmpty()) {
            return;
        }
        Node* current = head;
        while(current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << std::endl;
    }
};




void inputfromkeyboard();
