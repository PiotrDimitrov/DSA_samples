#include <iostream>
#include "header.h"
#include <list>
int main() {
myStack<int> stk;
    stk.push(4);
    stk.push(2);
    stk.push(5);
    stk.push(11);
    stk.push(7);
    stk.push(1);
    stk.push(8);

myStack<int> nstk;
nstk = stk;

    stk.top() = 44;
    int s = stk.size();
    for (int i = 0; i < s; i++){
        std::cout << stk.pop() << ' ';
    }
    std::cout << std::endl;

    s = nstk.size();
//    nstk.top() = 99;
//    std::cout << s << std::endl;
    for (int i = 0; i < s; i++){
        std::cout << nstk.pop() << ' ';
    }
    std::cout << std::endl;




}
