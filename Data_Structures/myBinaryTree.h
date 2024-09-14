#ifndef DSA_SAMPLES_MYBINARYTREE_H
#define DSA_SAMPLES_MYBINARYTREE_H
#include <iostream>
#include <vector>
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
    void balance(Node* n);
    void description();
private:
    int sz;
    Node* begin;
    void voidBlncSubtree(Node* n);
    void blncPushCntnr(Node* n, std::vector <Node*> &v);
    std::vector<Node*> firstHalf(const std::vector <Node*> &v);
    std::vector<Node*> secondHalf(const std::vector <Node*> &v);
    void dscrptNode(Node* n);
    void clearTree(Node* n);
    void printNode(Node* n);

};

template<typename T>
std::vector<typename myBinTree<T>::Node*> myBinTree<T>::secondHalf(const std::vector<Node *> &v) {
    int end = v.size() / 2;
    std::vector<Node*> result;
    for (int i = 0; i < end; i++){
        result.push_back(v[i]);
    }
    return result;
}

template<typename T>
std::vector<typename myBinTree<T>::Node*> myBinTree<T>::firstHalf(const std::vector<Node *> &v) {
    int begin = v.size() / 2 + 1;
    std::vector<Node*> result;
    for (int i = begin; i < v.size(); i++){
        result.push_back(v[i]);
    }
    return result;
}

template<typename T>
void myBinTree<T>::voidBlncSubtree(myBinTree::Node *n) {
    std::vector<Node*> tempContainer;
    blncPushCntnr(n, tempContainer);
    for (int i = 0; i < sz; i++){
        std::cout << tempContainer[i] << " - ";
    }
    delete [] tempContainer;
}

template<typename T>
void myBinTree<T>::dscrptNode(myBinTree::Node *n) {
    if (n == nullptr) { return;}
    if (n->left != nullptr && n->right != nullptr){
        std::cout << n->data << " => ( l: " << n->left->data << " , r: " << n->right->data << " )" << std::endl;
    }
    if (n->left != nullptr && n->right == nullptr){
        std::cout << "    " << n->data << " => ( l: " << n->left->data << " , r: null )" << std::endl;
    }
    if (n->left == nullptr && n->right != nullptr){
        std::cout << "    "  << n->data << " => ( l: null , r: " << n->right->data << " )" << std::endl;
    }
    if (n->left == nullptr && n->right == nullptr) {
        std::cout << "        "  << n->data << " => ( l: null , r: null )" << std::endl;
    }
    if (n->left != nullptr){
        dscrptNode(n->left);
    }
    if (n->right != nullptr){
        dscrptNode(n->right);
    }
}

template<typename T>
void myBinTree<T>::description() {
    dscrptNode(begin);
    std::cout << std::endl;
}


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
    Node* newNode = new Node(value);
    if (sz == 0) {
        begin = newNode;
        sz = 1;
        return;
    }
    Node* current = begin;
    while (true) {
        if (value == current->data) {
            delete newNode;
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

template <typename T>
void myBinTree<T>::balance(Node* n) {
    std::vector<Node*> tempContainer;
    blncPushCntnr(n, tempContainer);
    for (int i = 0; i < sz; i++){
        std::cout << tempContainer[i] << " - ";
    }
    delete [] tempContainer;
}


template<typename T>
void myBinTree<T>::blncPushCntnr(myBinTree::Node *n, std::vector <Node*> &v) {
    if (n == nullptr) { return;}
    if (n->left != nullptr){
        blncPushCntnr(n->left, v);
    }
    v.push_back(n->data);
    if (n->right != nullptr){
        blncPushCntnr(n->right, v);
    }
}

#endif //DSA_SAMPLES_MYBINARYTREE_H
