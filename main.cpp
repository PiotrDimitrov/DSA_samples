#include <iostream>
#include "header.h"

int main() {
    myBinTree<int> tree;

    for (int i = 1; i <= 16; i++){
        tree.push(i);
    }
    tree.description();
    myBinTree<int> balTree = tree.balance();
    balTree.description();
}
