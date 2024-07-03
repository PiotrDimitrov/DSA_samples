#ifndef DSA_SAMPLES_MYDEQUE_H
#define DSA_SAMPLES_MYDEQUE_H
#include <iostream>

template <typename T>
class myDeque {
    class segment {
        bool isFull;
        int szg;
        T* array;
        segment* next;
        segment* prev;
        segment(int s);
        ~segment();
        friend class myDeque;
    };
public:
    myDeque();
    myDeque(int n);
    ~myDeque();
    void push_back(const T& value);
    void pop_back();
    int size();
    T& operator [] (int index);
    myDeque<T>& operator = (const myDeque<T> other);
    void clear();
    void print();
private:
    int sz;
    int sg;
    int coef;
    int cap;
    segment* begin;
    segment* end;
    void addSegment();
};

template<typename T>
void myDeque<T>::pop_back() {
    if (sz == 0) { throw std::out_of_range("empty"); }
    sz--;
}

template<typename T>
void myDeque<T>::print() {
    segment* current = begin;
    while (current != nullptr) {
        for (int i = 0; i < current->szg; i++){
            std::cout << current->array[i] << ' ';
        }
        current = current->next;
    }
}

template<typename T>
void myDeque<T>::push_back(const T &value) {
    segment* current = begin;
    int index = sz;
    while (current->next != nullptr) {
        index -= current->szg;
    }
    if (current->isFull){
        addSegment();
        current = current->next;
    }
    current->array[index];
    if (index == current->szg - 1) {current->isFull = true;}
}

template<typename T>
T &myDeque<T>::operator[](int index) {
    if (index >= sz) {index = sz-1;}
    if (index < 0) {index = 0;}
    if (index < sg) {
        return begin->array[index];
    } else {
        segment* current = begin;
        int counter = sg - 1;
        int tempInd = index;
        while (counter < index) {
            tempInd -= current->szg;
            current = current->next;
            counter += current->szg;
        }
        return current->array[tempInd];
    }
}

template<typename T>
void myDeque<T>::clear() {
    while(begin != nullptr){
        segment* temp = begin;
        begin = begin->next;
        delete temp;
    }
    sz = 0;
    coef = 1;
    begin = nullptr; end = nullptr;
}

template<typename T>
void myDeque<T>::addSegment() {
    if (end->next != nullptr){
        while (end->next != nullptr){
            end = end->next;
        }
    }
    coef++;
    auto newSeg = new segment(coef*sg);
    cap += coef*sg;
    segment* temp = end;
    temp->next = newSeg;
    newSeg->prev = temp;
    end = newSeg;
}

template<typename T>
myDeque<T>::~myDeque() {
    clear();
}

template<typename T>
myDeque<T>::myDeque(int n) {
    sz = 0;
    sg = n;
    coef = 1;
    auto newSeg = new segment(coef*sg);
    cap = coef*sg;
    begin = newSeg;
    end = newSeg;
}

template<typename T>
myDeque<T>::myDeque() {
    sz = 0;
    sg = 16;
    coef = 1;
    auto newSeg = new segment(coef*sg);
    cap = coef*sg;
    begin = newSeg;
    end = newSeg;
}

template<typename T>
myDeque<T>::segment::segment(int s) {
    prev = nullptr;
    next = nullptr;
    array = new T[s];
    szg = s;
    isFull = false;
}

template<typename T>
myDeque<T>::segment::~segment() {
        delete [] array;
}



#endif //DSA_SAMPLES_MYDEQUE_H
