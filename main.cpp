#include <iostream>
#include "header.h"

int main() {
    myBinTree<int> tree;

    for (int i = 1; i <= 15; i++){
        tree.push(i);
    }
    tree.description();
    myBinTree<int> balTree = tree.balance();
    balTree.description();
    balTree.deleteValue(4);
    //balTree.deleteValue(7);
    //balTree.deleteValue(5);
    balTree.description();
}
