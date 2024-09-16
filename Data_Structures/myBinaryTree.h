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
    myBinTree(const myBinTree<T>& other);
    ~myBinTree();
    void push(const T& value);
    void clear();
    void print() const;
    bool findIn(T value) const;
    bool isFull() const;
    myBinTree<T> balance();
    void description() const;
    myBinTree<T>& operator = (const myBinTree<T>& other);
private:
    bool checkFullNode(Node* n) const;
    int sz;
    Node* begin;
    myBinTree<T> blncSubtree(Node* n);
    void insertionCntnr(const std::vector<Node*> &v, std::vector<Node*> &cntnr);
    void blncPushCntnr(Node* n, std::vector <Node*> &v);
    void dscrptNode(Node* n);
    void clearTree(Node* n);
    void printNode(Node* n);
    Node* copyNode(Node* other);

};

template<typename T>
bool myBinTree<T>::checkFullNode(myBinTree::Node *n) const{
    if ((n->left == nullptr && n->right != nullptr) || (n->right == nullptr && n->left != nullptr)) {
        return false;
    }
    if (n->left != nullptr && !checkFullNode(n->left)) {
        return false;
    }
    if (n->right != nullptr && !checkFullNode(n->right)) {
        return false;
    }
    return true;
}

template<typename T>
bool myBinTree<T>::isFull() const {
    return checkFullNode(begin);
}

template<typename T>
myBinTree<T>::myBinTree(const myBinTree<T> &other) : sz(0), begin(nullptr) {
    if (other.begin != nullptr) {
        begin = copyNode(other.begin);
        sz = other.sz;
    }
}

template<typename T>
typename myBinTree<T>::Node* myBinTree<T>::copyNode(myBinTree::Node* other) {
    if (other == nullptr){
        return nullptr;
    }
    Node* newNode = new Node(other->data);
    newNode->left = copyNode(other->left);
    newNode->right = copyNode(other->right);
    if (newNode->left != nullptr) {
        newNode->left->prev = newNode;
    }
    if (newNode->right != nullptr) {
        newNode->right->prev = newNode;
    }
    return newNode;
}


template<typename T>
myBinTree<T> &myBinTree<T>::operator = (const myBinTree<T> &other) {
    if (this == &other) {
        return *this;
    }

    clear();

    if (other.begin != nullptr) {
        begin = copyNode(other.begin);
        sz = other.sz;
    }
    return *this;
}

template<typename T>
void myBinTree<T>::insertionCntnr(const std::vector<Node *> &v, std::vector<Node *> &cntnr) {
    cntnr.push_back(v[v.size() / 2]);
    if (v.size() > 1) {
        insertionCntnr(std::vector<Node*>(v.begin(), v.begin() + v.size() / 2), cntnr);
    }
    if (v.size() > 2) {
        insertionCntnr(std::vector<Node*>(v.begin() + v.size() / 2 + 1, v.end()), cntnr);
    }
}

template<typename T>
myBinTree<T> myBinTree<T>::blncSubtree(myBinTree::Node *n) {
    myBinTree<T> newTree;
    std::vector<Node*> tempContainer;
    blncPushCntnr(n, tempContainer);
    std::vector<Node*> insertionList;
    insertionCntnr(tempContainer, insertionList);
    for (int i = 0; i < sz; i++){
        newTree.push(insertionList[i]->data);
    }
    return newTree;
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
void myBinTree<T>::description() const {
    dscrptNode(begin);
    std::cout << std::endl;
}


template<typename T>
bool myBinTree<T>::findIn(T value) const {
    if (begin == nullptr) {return false;}
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
void myBinTree<T>::print() const {
    printNode(begin);
    std::cout << std::endl;
}

template<typename T>
void myBinTree<T>::clearTree(Node* n) {
    if (n == nullptr) { return;}
    if (n->left != nullptr){
        clearTree(n->left);
    }
    if (n->right != nullptr){
        clearTree(n->right);
    }
    delete n;
    sz--;
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
    if (sz == 0) {
        begin = new Node(value);
        sz = 1;
        return;
    }
    Node* current = begin;
    while (true) {
        if (value == current->data) {
            return;
        }
        if (value < current->data) {
            if (current->left == nullptr) {
                current->left = new Node(value);
                current->left->prev = current;
                break;
            }
            current = current->left;
        } else {
            if (current->right == nullptr) {
                current->right = new Node(value);
                current->right->prev = current;
                break;
            }
            current = current->right;
        }
    }
    sz++;
}


template <typename T>
myBinTree<T> myBinTree<T>::balance() {
    return blncSubtree(begin);
}


template<typename T>
void myBinTree<T>::blncPushCntnr(myBinTree::Node* n, std::vector <Node*> &v) {
    if (n == nullptr) { return;}
    if (n->left != nullptr){
        blncPushCntnr(n->left, v);
    }
    v.push_back(n);
    if (n->right != nullptr){
        blncPushCntnr(n->right, v);
    }
}

#endif //DSA_SAMPLES_MYBINARYTREE_H
