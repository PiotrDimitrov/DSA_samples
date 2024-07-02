#ifndef DSA_SAMPLES_MYDEQUE_H
#define DSA_SAMPLES_MYDEQUE_H

template <typename T>
class myDeque {
    class segment {
        int size;
        T* array;
        segment* next;
        segment* prev;
        segment(int s);
        ~segment();
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
private:
    int sz;
    int sg;
    int coef;
    segment* begin;
    segment* end;
    void addSegment();

};

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
    begin = newSeg;
    end = newSeg;
}

template<typename T>
myDeque<T>::myDeque() {
    sz = 0;
    sg = 16;
    coef = 1;
    auto newSeg = new segment(coef*sg);
    begin = newSeg;
    end = newSeg;
}

template<typename T>
myDeque<T>::segment::segment(int s) {
    prev = nullptr;
    next = nullptr;
    array = new T[s];
    size = s;
}

template<typename T>
myDeque<T>::segment::~segment() {
        delete array;
}



#endif //DSA_SAMPLES_MYDEQUE_H
