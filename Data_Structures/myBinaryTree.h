#ifndef DSA_SAMPLES_MYBINARYTREE_H
#define DSA_SAMPLES_MYBINARYTREE_H
#include <iostream>
template <typename T>
class myBinTree {
    class Node {
        bool isEmpty;
        T data;
        Node* left;
        Node* right;
        Node* prev;
        Node() : left(nullptr), right(nullptr), prev(nullptr), isEmpty(true) {};
        Node(T value) : left(nullptr), right(nullptr), prev(nullptr), isEmpty(false), data(value) {};
        friend class myBinTree;
    };
public:
    myBinTree();
    ~myBinTree();
    void push(const T& value);
    void clear();
    void print();
    bool findIn(T value);
private:
    int sz;
    Node* begin;
    void clearTree(Node* n);
    void printNode(Node* n);
};

template<typename T>
bool myBinTree<T>::findIn(T value) {
    Node* current = begin;
    while (current != nullptr) {
        if (value == current->data) {return true;}
        if (value < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return false;
}

template<typename T>
void myBinTree<T>::printNode(myBinTree::Node *n) {
    if (n == nullptr) { return;}
    if (n->left != nullptr){
        printNode(n->left);
    }
    std::cout << n->data << ' ';
    if (n->right != nullptr){
        printNode(n->right);
    }
}

template<typename T>
void myBinTree<T>::print() {
    printNode(begin);
    std::cout << std::endl;
}

template<typename T>
void myBinTree<T>::clearTree(Node* n) {
    if (n == nullptr) { return;}
    if (n->left == nullptr && n->right == nullptr){
        delete n;
        return;
    }
    if (n->left != nullptr){
        clearTree(n->left);
    }
    if (n->right != nullptr){
        clearTree(n->right);
    }
}

template<typename T>
void myBinTree<T>::clear() {
    clearTree(begin);
    begin = nullptr;
    sz = 0;
}

template<typename T>
myBinTree<T>::myBinTree() {
    begin = nullptr;
    sz = 0;
}

template<typename T>
myBinTree<T>::~myBinTree() {
    clear();
}

template<typename T>
void myBinTree<T>::push(const T &value) {
//    Node* newNode = new Node(value);
//    if (sz == 0) {
//        begin = newNode;
//        sz = 1;
//        return;
//    }
//    bool flag;
//    Node* current = begin;
//    while (current != nullptr) {
//        if (value == current->data) {delete newNode; return;}
//        if (value < current->data){
//            flag = false;
//            if (current->left == nullptr){
//                break;
//            }
//            current = current->left;
//        } else {
//            flag = true;
//            if (current->right == nullptr){
//                break;
//            }
//            current = current->right;
//        }
//    }
//    newNode->prev = current;
//    if (flag) {
//        current->right = newNode;
//    } else {
//        current->left = newNode;
//    }
//    sz++;
    Node* newNode = new Node(value);
    if (sz == 0) {
        begin = newNode;
        sz = 1;
        return;
    }
    Node* current = begin;
    while (true) {
        if (value == current->data) {
            delete newNode; // Avoid memory leak
            return;
        }
        if (value < current->data) {
            if (current->left == nullptr) {
                current->left = newNode;
                newNode->prev = current;
                break;
            }
            current = current->left;
        } else {
            if (current->right == nullptr) {
                current->right = newNode;
                newNode->prev = current;
                break;
            }
            current = current->right;
        }
    }
    sz++;
}

#endif //DSA_SAMPLES_MYBINARYTREE_H
