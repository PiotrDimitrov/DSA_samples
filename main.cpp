#include <iostream>
#include "header.h"
#include <list>
int main() {
myListTwo<int> lst;
    lst.push_back(5);
    lst.push_back(8);
    lst.push_back(1);
    lst.push_back(3);
    lst.push_back(11);
    lst.insert(19, 4);
    lst.push_front(2);

    lst.print();
    //lst.show();

    for (int i = 0; i < 2; i++) {lst.pop_back();}
    lst.erase(1);

    lst.print();
    std::cout << lst[1] << ' ' << lst[3] << std::endl;
    lst[0] = 11;
    lst.print();
}
