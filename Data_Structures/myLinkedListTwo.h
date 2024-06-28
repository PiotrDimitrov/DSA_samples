#ifndef DSA_SAMPLES_MYLINKEDLISTTWO_H
#define DSA_SAMPLES_MYLINKEDLISTTWO_H

#include <iostream>
#include "interfaces.h"

template <typename T>
class myListTwo : public container<T> {
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
        friend class myList;
    };
    Node* head;
    Node* tail;
};

template<typename T>
myListTwo<T>::myListTwo() {

}

template<typename T>
myListTwo<T>::myListTwo(T value) {

}

template<typename T>
myListTwo<T>::~myListTwo() {

}

template<typename T>
void myListTwo<T>::push_back(const T &value) {

}

template<typename T>
void myListTwo<T>::pop_back() {

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

}

template<typename T>
myListTwo<T>::Node::Node() {

}


template<typename T>
myListTwo<T>::Node::Node(T value) {

}



//template<typename T>
//myListTwo<T>::myList() {
//    sz = 0;
//    head = nullptr;
//}
//
//template<typename T>
//myListTwo<T>::myList(T value) {
//    sz = 1;
//    head = new Node;
//    head->data = value;
//    head->next = nullptr;
//}
//
//template<typename T>
//myListTwo<T>::~myList() {
//    Node* temp = head;
//    while (temp != nullptr) {
//        head = head->next;
//        delete temp;
//        temp = head;
//    }
//}

#endif //DSA_SAMPLES_MYLINKEDLISTTWO_H
