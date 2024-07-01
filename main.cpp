#include <iostream>
#include "header.h"

bool test(int a, int b){
    if (a % 2 == 0 && b % 2 != 0) {return true;}
    if (b % 2 == 0 && a % 2 != 0) {return false;}
    return a > b;
}

int main() {
myPrQueue<int> pq;
    pq.push(4, nullptr);

    pq.push(2, nullptr);

    pq.push(5, nullptr);

    pq.push(11, nullptr);

    pq.push(7, nullptr);

    pq.push(1, nullptr);

    pq.push(8, nullptr);


    int s = pq.size();
    for (int i = 0; i < s; i++){
        std::cout << pq.pop() << ' ';
    }
    std::cout << std::endl;
    std::cout << pq.size() << std::endl;
    std::cout << "sad";
    return 0;
}
