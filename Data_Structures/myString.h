#ifndef DSA_SAMPLES_MYSTRING_H
#define DSA_SAMPLES_MYSTRING_H

#include <cstring>
#include <iostream>

class myString {
public:
    myString();
    myString(const char* s);
    myString(const myString& other);
    ~myString();
    myString& operator=(const myString& other);
    myString& operator+=(const myString& other);
    myString operator+(const myString& other) const;
    char& operator[](int index);
    const char& operator[](int index) const;
    int size() const;
    const char* c_str() const;

    friend std::ostream& operator<<(std::ostream& os, const myString& str);

private:
    char* str;
    int sz;
    int fixSize();
    void copyStr(const char* source);
};

int myString::fixSize() {
    int res = 0;
    int i = 0;
    while(str[i] != '\0'){
        res++;
        i++;
    }
    sz = res;
    return res;
}

myString::myString() {
    str = new char[1];
    str[0] = '\0';
    sz = 0;
}

myString::myString(const char* s) {
    copyStr(s);
}

myString::myString(const myString& other) {
    copyStr(other.str);
}

myString::~myString() {
    delete [] str;
}

myString& myString::operator=(const myString& other) {
    if (this != &other) {
        delete [] str;
        copyStr(other.str);
    }
    return *this;
}

myString& myString::operator+=(const myString& other) {
    char* temp = new char[sz + other.sz + 1];
    std::strcpy(temp, str);
    std::strcat(temp, other.str);
    delete [] str;
    str = temp;
    sz += other.sz;
    return *this;
}

myString myString::operator+(const myString& other) const {
    myString result;
    result.sz = sz + other.sz;
    result.str = new char[result.sz + 1];
    std::strcpy(result.str, str);
    std::strcat(result.str, other.str);
    return result;
}

char& myString::operator[](int index) {
    if (index >= 0 && index < sz) {
        return str[index];
    }
    throw std::out_of_range("Index out of range");
}

const char& myString::operator[](int index) const {
    if (index >= 0 && index < sz) {
        return str[index];
    }
    throw std::out_of_range("Index out of range");
}

int myString::size() const {
    return sz;
}

const char* myString::c_str() const {
    return str;
}

std::ostream& operator<<(std::ostream& os, const myString& str) {
    os << str.c_str();
    return os;
}

void myString::copyStr(const char* source) {
    sz = std::strlen(source);
    str = new char[sz + 1];
    std::strcpy(str, source);
}

#endif //DSA_SAMPLES_MYSTRING_H
