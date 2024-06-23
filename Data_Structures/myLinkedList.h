#ifndef DSA_SAMPLES_MYLINKEDLIST_H
#define DSA_SAMPLES_MYLINKEDLIST_H

template <typename T> class myList {
public:
    myList();
    myList(T value);
    ~myList();
    void push_back(const T& value);
    void pop_back();
    void push_front(const T& value);
    void pop_front();
    void insert(const T& value, int index);
    void erase(int index);
    int size();
    void clear();
    T& operator [] (int index);
    myList& operator = (const myList& other);
private:
    int sz;
    class Node {
        T data;
        Node* next;
        friend class myList;
    };
    Node* head;
};

template<typename T>
void myList<T>::clear() {
    Node* temp = head;
    while (temp != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }
}


template<typename T>
myList<T>::myList() {
    sz = 1;
    head = nullptr;
}

template<typename T>
myList<T>::myList(T value) {
    sz = 1;
    head = new Node;
    head->data = value;
    head->next = nullptr;
}

template<typename T>
myList<T>::~myList() {
    Node* temp = head;
    while (temp != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

template<typename T>
void myList<T>::push_back(const T &value) {
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Node;
    (temp->next)->next = nullptr;
    temp->data = value;
    sz++;

//    Node* temp = head;
//    int c = sz - 1;
//    while (c--) {
//        temp = temp->next;
//    }
//    temp->next = new Node;
//    (temp->next)->next = nullptr;
//    temp->data = value;
//    sz++;
}

template<typename T>
void myList<T>::pop_back() {
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    sz--;
}

template<typename T>
void myList<T>::pop_front() {
    Node* temp = head;
    head = head->next;
    delete temp;
    sz--;
}

template<typename T>
void myList<T>::push_front(const T &value) {
    Node* temp = head;
    head = nullptr;
    head = new Node;
    head->data = value;
    head->next = temp;
    sz++;
}

template<typename T>
void myList<T>::insert(const T &value, int index) {
    if (index == 0) {push_front(value); return;}
    if (index >= sz-1) {push_back(value); return;}
    int c = 0;
    Node* temp = head;
    while (c != index-1){
        temp = temp->next;
        c++;
    }
    Node* nextadr = temp->next;
    temp->next = nullptr;
    temp->next = new Node;
    temp->next->next = nextadr;
    temp->next->data = value;
    sz++;
}

template<typename T>
void myList<T>::erase(int index) {
    if (index == 0) {pop_front(); return;}
    if (index >= sz-1) {pop_back(); return;}
    int c = 0;
    Node* temp = head;
    while (c != index-1) {
        temp = temp->next;
        c++;
    }
    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
    sz--;
}

template<typename T>
myList<T> &myList<T>::operator=(const myList &other) {
    Node* thisNode = head;
    Node* otherNode = other.head;
    while (thisNode != nullptr) {
        thisNode->data = otherNode->data;
        if (thisNode->next == nullptr){
            thisNode->next = new Node;
        }
        otherNode = otherNode->next;
        thisNode = thisNode->next;
    }
}

template<typename T>
T &myList<T>::operator[](int index) {
    int c = 0;
    if (index < 0) {index = 0;}
    Node* temp = head;
    while (index > c && temp != nullptr){
        temp = temp->next;
        c++;
    }
    return (temp->data);
}

template<typename T>
int myList<T>::size() {
    return sz;
}

#endif //DSA_SAMPLES_MYLINKEDLIST_H
