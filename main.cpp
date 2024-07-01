#include <iostream>
#include "header.h"

bool test(int a, int b){

}

int main() {
    myBinTree<int> tr;
    tr.push(7); tr.push(11); tr.push(2);
    tr.push(8); tr.push(9); tr.push(1);
    tr.push(4); tr.push(16);
    tr.print();
    std::cout << tr.findIn(10) << std::endl;
    return 0;
}
