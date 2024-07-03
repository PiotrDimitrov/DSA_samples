#include <iostream>
#include "header.h"

int main() {
    myDeque<int> dq(4);
    std::cout << 'a';
    for (int i = 1; i < 50; i+=2){
        dq.push_back(i);
        std::cout << '-';
    }
    dq.print();
}
