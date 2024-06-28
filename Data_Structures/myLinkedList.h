#ifndef DSA_SAMPLES_MYLINKEDLIST_H
#define DSA_SAMPLES_MYLINKEDLIST_H
#include <iostream>
#include "interfaces.h"

template <typename T> class myList : public container<T>{
public:
    myList();
    myList(T value);
    ~myList();
    void push_back(const T& value);
    void pop_back();
    void push_front(const T& value);
    void pop_front();
    void insert(const T& value, int index);
    void erase(int index);
    int size();
    void clear();
    T& operator [] (int index);
    myList& operator = (const myList& other);
    void print();
private:
    int sz;
    class Node {
        T data;
        Node* next;
        Node();
        Node(T value);
        friend class myList;
    };
    Node* head;
};

template<typename T>
void myList<T>::print() {
    Node* temp = head;
    while (temp != nullptr){
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<typename T>
myList<T>::Node::Node(T value) {
next = nullptr;
data = value;
}

template<typename T>
myList<T>::Node::Node() {
next = nullptr;
}

template<typename T>
void myList<T>::clear() {
    Node* temp = head;
    while (temp != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }
    sz = 0;
}


template<typename T>
myList<T>::myList() {
    sz = 0;
    head = nullptr;
}

template<typename T>
myList<T>::myList(T value) {
    sz = 1;
    head = new Node;
    head->data = value;
    head->next = nullptr;
}

template<typename T>
myList<T>::~myList() {
    Node* temp = head;
    while (temp != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

template<typename T>
void myList<T>::push_back(const T &value) {
    Node* newNode = new Node(value);
    if (sz == 0){
        head = newNode;
    } else {
        int c = sz - 1;
        Node* temp = head;
        while (c--) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    sz++;
}

template<typename T>
void myList<T>::pop_back() {
    if (sz <= 0) { return;}
    if (sz == 1) {delete head; head = nullptr; sz = 0; return;}
    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    sz--;
}

template<typename T>
void myList<T>::pop_front() {
    if (sz <= 0) { return;}
    Node* temp = head;
    head = head->next;
    delete temp;
    sz--;
}

template<typename T>
void myList<T>::push_front(const T &value) {
    Node* temp = head;
    Node* newNode = new Node(value);
    newNode->next = temp;
    head = newNode;
    sz++;
}

template<typename T>
void myList<T>::insert(const T &value, int index) {
    if (index <= 0) {push_front(value); return;}
    if (index >= sz-1) {push_back(value); return;}
    Node* newNode = new Node(value);
    Node* temp = head;
    Node* prev;
    while (index--){
        prev = temp;
        temp = temp->next;
    }
    newNode->next = temp;
    prev->next = newNode;
    sz++;
}

template<typename T>
void myList<T>::erase(int index) {
    if (index <= 0) {pop_front(); return;}
    if (index >= sz-1) {pop_back(); return;}
    Node* temp = head;
    Node* prev; Node* nextN;
    while (index--) {
        prev = temp;
        temp = temp->next;
    }
    nextN = temp->next;
    prev->next = nextN;
    delete temp;
    sz--;
}

template<typename T>
myList<T> &myList<T>::operator=(const myList &other) {
    Node* thisNode = head;
    Node* otherNode = other.head;
    while (thisNode != nullptr) {
        thisNode->data = otherNode->data;
        if (thisNode->next == nullptr){
            thisNode->next = new Node;
        }
        otherNode = otherNode->next;
        thisNode = thisNode->next;
    }
}

template<typename T>
T &myList<T>::operator[](int index) {
    if (index < 0) {index = 0;}
    if (index > sz-1) {index = sz - 1;}
    Node* temp = head;
    while (index--){
        temp = temp->next;
    }
    return temp->data;
}

template<typename T>
int myList<T>::size() {
    return sz;
}

#endif //DSA_SAMPLES_MYLINKEDLIST_H
