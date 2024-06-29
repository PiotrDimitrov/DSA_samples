#ifndef DSA_SAMPLES_MYSTACK_H
#define DSA_SAMPLES_MYSTACK_H

template <typename T>
class myStack {
    class Node {
        Node();
        Node(T value);
        Node* next;
        Node* prev;
        T data;
        friend class myStack;
    };
public:
    myStack();
    ~myStack();
    void pop();
    void push(const T& value);
    int size();
    void clear();
    myStack<T>& operator = (const myStack<T>& other);
    T& top();
private:
    Node* head;
    Node* tail;
    int sz;
};

template<typename T>
T &myStack<T>::top() {
    return tail->data;
}

template<typename T>
myStack<T>::Node::Node() {
    next = nullptr;
    prev = nullptr;
}

template<typename T>
myStack<T>::Node::Node(T value) {
    next = nullptr;
    prev = nullptr;
    data = value;
}

template<typename T>
myStack<T>::myStack() {
    sz = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
myStack<T>::~myStack() {
    Node* temp = tail;
    while (tail != nullptr) {
        temp = tail;
        tail = tail->prev;
        delete temp;
    }
}

template<typename T> //TO DO
myStack<T> &myStack<T>::operator=(const myStack<T> &other) {
    this->clear();
    Node* temp = other.head;
    Node* here = head;
    while (temp != nullptr) {
        Node* newNode = temp;
        here = newNode;
        here = here->next;
        temp = temp->next;
    }
    return *this;
}

template<typename T>
void myStack<T>::pop() {
    Node* temp = tail;
    tail = tail->prev;
    delete temp;
    sz--;
}

template<typename T>
void myStack<T>::push(const T &value) {
    Node* newNode = new Node(value);
    if (sz == 0) {
        head = newNode;
        tail = newNode;
    } else {
        Node* temp = tail;
        newNode->prev = temp;
        temp->next = newNode;
        tail = newNode;
    }
    sz++;
}

template<typename T>
int myStack<T>::size() {
    return sz;
}

template<typename T>
void myStack<T>::clear() {
    Node* temp = tail;
    while (tail != nullptr) {
        temp = tail;
        tail = tail->prev;
        delete temp;
    }
    sz = 0;
}


#endif //DSA_SAMPLES_MYSTACK_H
