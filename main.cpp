#include <iostream>
#include "header.h"
#include <list>
int main() {
myPrQueue<int> pq;
    pq.push(4);
    std::cout << "push norm\n";
    pq.push(2);
    std::cout << "push norm 1\n";
    pq.push(5);
    std::cout << "push norm 1\n";
    pq.push(11);
    std::cout << "push norm 1\n";
    pq.push(7);
    std::cout << "push norm 1\n";
    pq.push(1);
    std::cout << "push norm 1\n";
    pq.push(8);
    std::cout << "push norm all\n";

    int s = pq.size();
    for (int i = 0; i < s-1; i++){
        std::cout << pq.pop() << ' ';
    }
    std::cout << std::endl;
    std::cout << pq.size() << std::endl;
    std::cout << pq.pop() << std::endl;
    std::cout << "sad";
    return 0;
}
