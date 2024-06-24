#ifndef DSA_SAMPLES_INTERFACES_H
#define DSA_SAMPLES_INTERFACES_H

class container {
public:
    virtual int size() = 0;
    virtual void push_back() = 0;
    virtual void pop_back() = 0;
};

#endif //DSA_SAMPLES_INTERFACES_H
