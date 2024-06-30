#ifndef DSA_SAMPLES_MYQUEUE_H
#define DSA_SAMPLES_MYQUEUE_H

template <typename T>
class myQueue {
    class Node {
        T data;
        Node* next;
        Node* prev;
        Node();
        Node(T value);
        friend class myQueue;
    };
public:
    myQueue();
    ~myQueue();
    void push(const T& value);
    T pop();
    T& top();
    T& bot();
    int size();
    void clear();
    myQueue<T>& operator = (const myQueue<T>& other);
private:
    Node* head;
    Node* tail;
    int sz;
    T last;
    myQueue<T>& copy(const myQueue<T>& other);
};

template<typename T>
myQueue<T>::Node::Node() {
    next = nullptr;
    prev = nullptr;
}

template<typename T>
myQueue<T>::Node::Node(T value) {
    next = nullptr;
    prev = nullptr;
    data = value;
}

template<typename T>
myQueue<T>::myQueue() {
    head = nullptr;
    tail = nullptr;
    sz = 0;
}

template<typename T>
myQueue<T>::~myQueue() {
    clear();
}

template<typename T>
void myQueue<T>::push(const T &value) {
    Node* newNode = new Node(value);
    if (sz == 0) {
        head = newNode;
        tail = newNode;
        sz = 1;
        return;
    }
    Node* temp = tail;
    temp->next = newNode;
    newNode->prev = temp;
    tail = newNode;
    sz++;
}

template<typename T>
T myQueue<T>::pop() {
    if (sz == 0) {return last;}
    Node* temp = head;
    T t = temp->data;
    head = head->next;
    delete temp;
    head->prev = nullptr;
    sz--;
    return t;
}

template<typename T>
T &myQueue<T>::top() {
    return head->data;
}

template<typename T>
T &myQueue<T>::bot() {
    return tail->data;
}


template<typename T>
int myQueue<T>::size() {
    return sz;
}

template<typename T>
void myQueue<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    sz = 0;
}

template<typename T>
myQueue<T> &myQueue<T>::copy(const myQueue<T> &other) {
    if (other.sz == 0) {
        sz = 0;
        tail = nullptr;
        head = nullptr;
        return;
    }
    Node* currentOther = other.head;
    while (currentOther != nullptr) {
        push(currentOther->data);
        currentOther = currentOther->next;
    }
    sz = other.sz;
    last = other.last;
}

template<typename T>
myQueue<T> &myQueue<T>::operator=(const myQueue<T> &other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

#endif //DSA_SAMPLES_MYQUEUE_H
