#ifndef DSA_SAMPLES_INTERFACES_H
#define DSA_SAMPLES_INTERFACES_H

template <typename T>
class iterator {
private:
public:
    T* iterPtr;
    virtual T& operator ++ () = 0;
    virtual T& operator ++ (int) = 0;
    virtual T& operator -- () = 0;
    virtual T& operator -- (int) = 0;
    virtual T* advance() = 0;
    virtual T* retreat() = 0;
    virtual iterator& operator = (iterator& it);
};

template <typename T>
class container {
public:
    int size();
    void push_back();
    void pop_back();
    const T* begin();
    const T* end();
    void clear();
    T& operator [] (int index);
    container& operator = (const container& other);
private:
    int sz;
};

#endif //DSA_SAMPLES_INTERFACES_H
