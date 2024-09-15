#include <iostream>
#include "header.h"

int main() {
    myBinTree<int> tree;

    for (int i = 1; i <= 6; i++){
        tree.push(i);
    }
    tree.description();
    myBinTree<int> balTree = tree.balance();
    balTree.description();
    std::cout << balTree.isFull() << std::endl;
}
