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
    newNode->next = nullptr;
    tail->next = newNode;
    tail = tail->next;
    sz++;
}

template<typename T>
void myListTwo<T>::pop_back() {
    Node* temp = tail;
    tail = tail->prev;
    delete temp;
    tail->next = nullptr;
    sz--;
}

template<typename T>
void myListTwo<T>::push_front(const T &value) {

}

template<typename T>
void myListTwo<T>::pop_front() {

}

template<typename T>
void myListTwo<T>::insert(const T &value, int index) {

}

template<typename T>
void myListTwo<T>::erase(int index) {

}

template<typename T>
int myListTwo<T>::size() {
    return 0;
}

template<typename T>
void myListTwo<T>::clear() {

}

template<typename T>
T &myListTwo<T>::operator[](int index) {

}

template<typename T>
void myListTwo<T>::print() {
    Node* temp = head;
    while (temp != nullptr){
        std::cout << temp->data << " -> ";
        temp = temp->next;
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
