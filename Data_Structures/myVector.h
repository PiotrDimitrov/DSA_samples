#ifndef DSA_SAMPLES_MYVECTOR_H
#define DSA_SAMPLES_MYVECTOR_H
#include <iostream>
#include "interfaces.h"
#include <cstring>

template <typename T>
class myVector{
    public:
        myVector();
        myVector(int n);
        myVector(int n, T value);
        ~myVector();
        T& operator [] (int index);
        myVector& operator = (myVector& other);
        void push_back(T obj);
        void pop_back();
        int size();
        int capacity();
        void reserve(int n);
        T* begin();
        T* end();
    private:
        int sz;
        int cap;
        T* array;
        class vecIter : public iterator<T>{
            T* advance () override;
            T* retreat () override;

        };
};

template <typename T>
T* myVector<T>::vecIter::advance()  {
    return this->iterPtr + 1;
}

template <typename T>
T* myVector<T>::vecIter::retreat() {
    return this->iterPtr - 1;
}

template<typename T>
myVector<T> &myVector<T>::operator=(myVector &other) {
    this->sz = other.sz;
    this->cap = other.cap;
    std::memcpy(this->array, other.array, sz);
}

template<typename T>
T *myVector<T>::end() {
    return array+sz;
}

template<typename T>
T *myVector<T>::begin() {
    return array;
}

template<typename T>
myVector<T>::myVector() {
    sz  = 0;
    cap = 1;
    array = new T[1];
}

template<typename T>
myVector<T>::myVector(int n) {
    sz = 0;
    cap = n;
    array = new T[cap];
}

template<typename T>
myVector<T>::myVector(int n, T value) {
    sz = n;
    cap = n;
    array = new T[cap];
    for (int i = 0; i < sz; i++) {array[i] = value;}
}

template<typename T>
myVector<T>::~myVector() {
    delete [] array;
}

template<typename T>
T &myVector<T>::operator[](int index) {
    return array[index];
}

template<typename T>
void myVector<T>::push_back(T obj) {
    if (sz >= cap) {
        if (cap == 0) {cap = 1;}
        T* temp = new T[2*cap];
        for (int i = 0; i < sz; i++){
            temp[i] = array[i];
        }
        delete [] array;
        array = temp;
        cap = 2 * cap;
    }
    array[sz] = obj;
    sz++;
}

template<typename T>
void myVector<T>::pop_back() {
    if (sz <= 0) { return;}
    sz--;
}

template<typename T>
int myVector<T>::size() {
    return sz;
}

template<typename T>
int myVector<T>::capacity() {
    return cap;
}

template<typename T>
void myVector<T>::reserve(int n) {
    if (n < sz) {
        T* temp = new T[sz];
        for (int i = 0; i < sz; i++){
            temp[i] = array[i];
        }
        delete [] array;
        array = temp;
        sz = n;
    }
    cap = n;
}

//template<typename T>
//T &myVector<T>::iterator::operator=(T *t) {
//    ptr = t;
//    return ptr;
//}
//
//template<typename T>
//void myVector<T>::iterator::increment() {
//    ptr += 1;
//}
//
//template<typename T>
//void myVector<T>::iterator::decrement() {
//    ptr -= 1;
//}

#endif //DSA_SAMPLES_MYVECTOR_H
