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
    int capacity();
private:
    int sz;
    int sg;
    int coef;
    int _capacity;
    int lastIndex;
    segment* begin;
    segment* end;
    void addSegment();
    void removeEnd();
};

template<typename T>
int myDeque<T>::size() {
    return sz;
}

template<typename T>
void myDeque<T>::removeEnd() {
    segment* temp = end;
    end = end->prev;
    end->next = nullptr;
    delete temp;
}

template<typename T>
int myDeque<T>::capacity() {
    return _capacity;
}

template<typename T>
void myDeque<T>::pop_back() {
    if (sz == 0) { throw std::out_of_range("empty"); }
    if (lastIndex == 0) {
        removeEnd();
        lastIndex = end->szg;
        pop_back();
    } else {
        end->isFull = false;
        lastIndex--;
        sz--;
    }
}

template<typename T>
void myDeque<T>::print() {
    segment* current = begin;
    while (current != end) {
        for (int i = 0; i < current->szg; i++){
            std::cout << current->array[i] << ' ';
        }
        current = current->next;
    }
    for (int i = 0; i < lastIndex; i++){
        std::cout << current->array[i] << ' ';
    }
    std::cout << std::endl;
}

template<typename T>
void myDeque<T>::push_back(const T &value) {
    if (end->isFull || end == nullptr){
        addSegment();
        lastIndex = 0;
    }
    end->array[lastIndex] = value;
    sz++;
    lastIndex++;
    if (end->szg == lastIndex) {end->isFull = true;}
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
    _capacity += coef*sg;
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
    _capacity = coef*sg;
    begin = newSeg;
    end = newSeg;
    lastIndex = 0;
}

template<typename T>
myDeque<T>::myDeque() {
    sz = 0;
    sg = 16;
    coef = 1;
    auto newSeg = new segment(coef*sg);
    _capacity = coef*sg;
    begin = newSeg;
    end = newSeg;
    lastIndex = 0;
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
