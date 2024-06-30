#ifndef DSA_SAMPLES_MYSTACK_H
#define DSA_SAMPLES_MYSTACK_H

template <typename T>
class myStack {
    class Node {
        Node();
        Node(T value);
        Node* prev;
        Node* next;
        T data;
        friend class myStack;
    };
public:
    myStack();
    ~myStack();
    T pop();
    void push(const T& value);
    int size();
    void clear();
    myStack<T>& operator = (const myStack<T> &other);
    T& top();
private:
    T last;
    Node* tail;
    int sz;
    void copyFrom(const myStack<T>& other);
};

template <typename T>
void myStack<T>::copyFrom(const myStack<T>& other) {
    if (other.tail == nullptr) {
        tail = nullptr;
        sz = 0;
        return;
    }

    Node* currentOther = other.tail;
    Node* previousNewNode = nullptr;

    while (currentOther != nullptr) {
        Node* newNode = new Node(currentOther->data);
        if (previousNewNode != nullptr){
            previousNewNode->prev = newNode;
            newNode->next = previousNewNode;
        }
        previousNewNode = newNode;

        if (currentOther == other.tail) {
            tail = newNode;
        }

        currentOther = currentOther->prev;
    }

    sz = other.sz;
    last = other.last;
}

template<typename T>
T &myStack<T>::top() {
    if (sz == 0) {return last;}
    return tail->data;
}

template<typename T>
myStack<T>::Node::Node() {
    prev = nullptr;
    next = nullptr;
}

template<typename T>
myStack<T>::Node::Node(T value) {
    prev = nullptr;
    next = nullptr;
    data = value;
}


template<typename T>
myStack<T>::myStack() {
    sz = 0;
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

template <typename T>
myStack<T>& myStack<T>::operator=(const myStack<T>& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
T myStack<T>::pop() {
    if (sz == 0) {return last;}
    Node* temp = tail;
    tail = tail->prev;
    T t = temp->data;
    delete temp;
    sz--;
    return t;
}

template<typename T>
void myStack<T>::push(const T &value) {
    Node* newNode = new Node(value);
    newNode->prev = tail;
    tail = newNode;
    sz++;
    if (tail->prev != nullptr){
        Node* temp = tail->prev;
        temp->next = tail;
    }
}

template<typename T>
int myStack<T>::size() {
    return sz;
}

template<typename T>
void myStack<T>::clear() {
    if (sz == 0) { return;}
    Node* temp = tail;
    while (tail != nullptr) {
        temp = tail;
        tail = tail->prev;
        delete temp;
    }
    sz = 0;
}


#endif //DSA_SAMPLES_MYSTACK_H
