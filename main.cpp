#include <iostream>
#include "header.h"
#include <list>
int main() {
    myList<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(13);
    lst.push_back(1);
    lst.push_back(8);
    for (int i = 0; i < lst.size(); i++){
        std::cout << lst[i] << ' ';
    }
    std::cout << std::endl;

}
