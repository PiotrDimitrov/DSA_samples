#include <iostream>
#include "header.h"

bool test(int a, int b){
    if (a % 2 == 0 && b % 2 != 0) {return true;}
    if (b % 2 == 0 && a % 2 != 0) {return false;}
    return a > b;
}

int main() {
    myQueue<int> q;
    q.push(7); q.push(11); q.push(2);
    q.push(8); q.push(9); q.push(1);
    q.push(4); q.push(16);
    int s = q.size();
    myQueue<int> nq;
    nq = q;
    nq.push(10);
    for (int i = 0; i < s; i++){
        std::cout << q.pop() << ' ';
    }
    std::cout << std::endl;
    s = nq.size();
    for (int i = 0; i < s; i++){
        std::cout << nq.pop() << ' ';
    }
    return 0;
}
