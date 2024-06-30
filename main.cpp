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
nstk.push(289);
nstk.push(191);
nstk = stk;

    stk.top() = 44;
    int s = stk.size();
    for (int i = 0; i < s; i++){
        std::cout << stk.pop() << ' ';
    }
    std::cout << std::endl;

    s = nstk.size();

    for (int i = 0; i < s; i++){
        std::cout << nstk.pop() << ' ';
    }
    std::cout << std::endl;




}
