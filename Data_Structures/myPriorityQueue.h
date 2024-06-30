#ifndef DSA_SAMPLES_MYPRIORITYQUEUE_H
#define DSA_SAMPLES_MYPRIORITYQUEUE_H

template <typename T>
class myPrQueue {
    class Node {
        T data;
        Node* next;
        Node* prev;
        Node();
        Node(T value);
        friend class myPrQueue;
    };
public:
    myPrQueue();
    ~myPrQueue();
//    bool (*compare)(T, T) = nullptr;
//    bool defaultCompare(T a, T b);
//    void setCompare(bool (*f)(T, T));
    void push(const T& value);
    void push(const T& value, bool (*comparePredicate)(T, T));
    T pop();
    T& top();
    T& bot();
    int size();
    void clear();
    myPrQueue<T>& operator = (const myPrQueue<T>& other);
private:
    Node* head;
    Node* tail;
    int sz;
    T last;
    myPrQueue<T>& copy(const myPrQueue<T>& other);
};

//template<typename T>
//bool myPrQueue<T>::defaultCompare(T a, T b) {
//    return a > b;
//}

//template<typename T>
//void myPrQueue<T>::setCompare(bool (*f)(T, T)) {
//    compare = f;
//}

template<typename T>
myPrQueue<T>::Node::Node() {
    next = nullptr;
    prev = nullptr;
}

template<typename T>
myPrQueue<T>::Node::Node(T value) {
    next = nullptr;
    prev = nullptr;
    data = value;
}

template<typename T>
myPrQueue<T>::myPrQueue() {
    head = nullptr;
    tail = nullptr;
    sz = 0;
}

template<typename T>
myPrQueue<T>::~myPrQueue() {
    clear();
}

template<typename T>
void myPrQueue<T>::push(const T &value) {
    Node* newNode = new Node(value);
    if (sz == 0) {
        head = newNode;
        tail = newNode;
        sz = 1;
        return;
    }
    Node* temp = tail;
    if (value <= tail->data){
        newNode->prev = tail;
        tail->next = newNode;
        tail = tail->next;
        sz++; return;
    }
    while (value > temp->data && temp->prev != nullptr){
        temp = temp->prev;
    }
    if (temp->prev == nullptr && value > temp->data){
        newNode->next = head;
        head->prev = newNode;
        head = head->prev;
        sz++; return;
    }
    Node* saveNext = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = saveNext;
    sz++;
}

template<typename T>
void myPrQueue<T>::push(const T &value, bool (*comparePredicate)(T, T)) {

}

template<typename T>
T myPrQueue<T>::pop() {
    if (sz == 0) {return last;}
//    if (sz == 1) {
//        T t = head->data;
//        delete head;
//        head = nullptr;
//        tail = nullptr;
//        sz--; return t;
//    }
    Node* temp = head;
    T t = temp->data;
    if (head->next != nullptr){
        head = head->next;
    }
    delete temp;
    head->prev = nullptr;
    sz--;
    return t;
}

template<typename T>
T &myPrQueue<T>::top() {
    return head->data;
}

template<typename T>
T &myPrQueue<T>::bot() {
    return tail->data;
}

template<typename T>
int myPrQueue<T>::size() {
    return sz;
}

template<typename T>
void myPrQueue<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    sz = 0;
}

template<typename T>
myPrQueue<T> &myPrQueue<T>::copy(const myPrQueue<T> &other) {

}

template<typename T>
myPrQueue<T> &myPrQueue<T>::operator=(const myPrQueue<T> &other) {

}

#endif //DSA_SAMPLES_MYPRIORITYQUEUE_H
