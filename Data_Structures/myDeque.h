#ifndef DSA_SAMPLES_MYDEQUE_H
#define DSA_SAMPLES_MYDEQUE_H

template <typename T>
class myDeque {
    class segment {
        int size;
        T* array;
        segment* next;
        segment* prev;
        segment();
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
private:
    int sz;
    int sg;

};

#endif //DSA_SAMPLES_MYDEQUE_H
