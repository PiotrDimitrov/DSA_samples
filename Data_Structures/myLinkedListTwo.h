#ifndef DSA_SAMPLES_MYLINKEDLISTTWO_H
#define DSA_SAMPLES_MYLINKEDLISTTWO_H

#include <iostream>
#include "interfaces.h"

template <typename T>
class myListTwo{
public:
    myListTwo();
    myListTwo(T value);
    ~myListTwo();
    void push_back(const T& value);
    void pop_back();
    void push_front(const T& value);
    void pop_front();
    void insert(const T& value, int index);
    void erase(int index);
    int size();
    void clear();
    T& operator [] (int index);
    myListTwo& operator = (const myListTwo& other);
    void print();
    void show();
private:
    int sz;
    class Node {
        T data;
        Node* next;
        Node* prev;
        Node();
        Node(T value);
        friend class myListTwo;
    };
    Node* head;
    Node* tail;
};

template<typename T>
myListTwo<T> &myListTwo<T>::operator=(const myListTwo &other) {
    this->clear;
    Node* step = other.head;
    while (step != nullptr){
        this->push_back(step->data);
        step = step->next;
    }
    return *this;
}


template<typename T>
myListTwo<T>::myListTwo() {
    head = nullptr;
    tail = nullptr;
    sz = 0;
}

template<typename T>
myListTwo<T>::myListTwo(T value) {
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    sz = 1;
}

template<typename T>
myListTwo<T>::~myListTwo() {
    Node* temp = head;
    while (temp != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

template<typename T>
void myListTwo<T>::push_back(const T &value) {
    Node* newNode = new Node(value);
    if (sz == 0) {
        head = newNode;
        tail = newNode;
        sz++;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = tail->next;
    sz++;
}

template<typename T>
void myListTwo<T>::pop_back() {
    if (sz <= 0) { return;}
    if (sz == 1) {
        Node* temp = tail;
        head = nullptr; tail = nullptr;
        delete temp;
        sz = 0;
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    delete temp;
    tail->next = nullptr;
    sz--;
}

template<typename T>
void myListTwo<T>::push_front(const T &value) {
    Node* temp = head;
    Node* newNode = new Node(value);
    temp->prev = newNode;
    newNode->next = temp;
    head = newNode;
    sz++;
}

template<typename T>
void myListTwo<T>::pop_front() {
    if (sz <= 0) { return;}
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    sz--;
}

template<typename T>
void myListTwo<T>::insert(const T &value, int index) {
    if (index <= 0) { push_front(value); return;}
    if (index >= sz) { push_back(value); return;}
    Node* ntemp;
    if (index > sz / 2) {
        int c = sz - 1;
        ntemp = tail;
        while (c != index){
            ntemp = ntemp->prev;
            c--;
        }

    } else {
        int c = 0;
        ntemp = head;
        while (c != index){
            ntemp = ntemp->next;
            c++;
        }
    }
    Node* ptemp = ntemp->prev;
    Node* newNode = new Node(value);
    newNode->next = ntemp;
    newNode->prev = ntemp->prev;
    ptemp->next = newNode;
    ntemp->prev = newNode;
    sz++;
}

template<typename T>
void myListTwo<T>::erase(int index) {
    if (index <= 0) { pop_front(); return;}
    if (index >= sz) { pop_back(); return;}
    Node* ptemp; Node* temp; Node* ntemp;
    if (index > sz / 2) {
        int c = sz - 1;
        temp = tail;
        while (c != index){
            temp = temp->prev;
            c--;
        }
    } else {
        int c = 0;
        temp = head;
        while (c != index){
            temp = temp->next;
            c++;
        }
    }
    ntemp = temp->next;
    ptemp = temp->prev;
    ptemp->next = ntemp;
    ntemp->prev = ptemp;
    delete temp;
    sz--;
}

template<typename T>
int myListTwo<T>::size() {
    return sz;
}

template<typename T>
void myListTwo<T>::clear() {
    sz = 0;
    Node* temp = head;
    while (temp != nullptr){
        head = head->next;
        delete temp;
        temp = head;
    }
}

template<typename T>
T &myListTwo<T>::operator[](int index) {
    if (index < 0) {index = 0;}
    if (index > sz-1) {index = sz - 1;}
    Node* temp;
    if (index < sz/2){
        temp = head;
        while (index--){
            temp = temp->next;
        }
    } else {
        temp = tail;
        int c = sz - 1 - index;
        while (c--){
            temp = temp->prev;
        }
    }
    return temp->data;
}

template<typename T>
void myListTwo<T>::print() {
    Node* temp = head;
    while (temp != nullptr){
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<typename T>
void myListTwo<T>::show() {
    Node* temp = tail;
    while (temp != nullptr) {
        std::cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    std::cout << std::endl;
}

template<typename T>
myListTwo<T>::Node::Node() {
    next = nullptr;
    prev = nullptr;
}


template<typename T>
myListTwo<T>::Node::Node(T value) {
    data = value;
    next = nullptr;
    prev = nullptr;
}




#endif //DSA_SAMPLES_MYLINKEDLISTTWO_H
