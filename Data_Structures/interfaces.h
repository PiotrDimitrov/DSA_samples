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
    virtual int size() = 0;
    virtual void push_back() = 0;
    virtual void pop_back() = 0;
    virtual const T* begin() = 0;
    virtual const T* end() = 0;
    virtual void clear() = 0;
    virtual T& operator [] (int index) = 0;
    virtual container& operator = (const container& other) = 0;
private:
    int sz;
};

#endif //DSA_SAMPLES_INTERFACES_H
