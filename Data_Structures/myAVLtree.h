#ifndef DSA_SAMPLES_MYAVLTREE_H
#define DSA_SAMPLES_MYAVLTREE_H
#include <iostream>
#include <vector>
template <typename T>
class myAVLtree {
    class Node {
        Node* right;
        Node* left;
        Node* prev;
        T data;
        Node() : left(nullptr), right(nullptr), prev(nullptr) {};
        Node(T value) : left(nullptr), right(nullptr), prev(nullptr),  data(value) {};
        friend class myAVLtree;
    };
};

#endif //DSA_SAMPLES_MYAVLTREE_H
