#include <iostream>
#include "header.h"

int main() {
    myDeque<int> dq(4);
    for (int i = 1; i < 50; i+=2){
        dq.push_back(3*i);
    }
//    std::cout << dq[20] << std::endl;
//    dq[0] = 4;
//    dq[9] = 100;
    std::cout << dq.size() << std::endl;
    dq.print();

    for (int i = 0; i < 25; i++){
        dq.pop_back();
        dq.print();
    }

}
