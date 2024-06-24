#include <iostream>
#include "header.h"
#include <list>
int main() {
myList<int> lst;
    lst.push_back(5);
    lst.push_back(8);
    lst.push_back(1);
    lst.push_back(3);
    lst.push_back(11);
    lst.insert(14, 4);
    lst.print();
    lst[1] = 0;
//    lst.erase(2);
//    lst.erase(0);
    lst.print();
}
