#include <iostream>
#include "header.h"

int main() {
    myBinTree<int> tree;
//    tree.push(5);
//    tree.push(1);
//    tree.push(8);
//    tree.push(9);
//    tree.push(4);
//    tree.push(17);
//    tree.push(12);
    for (int i = 1; i <= 16; i++){
        tree.push(i);
    }
    tree.description();
    myBinTree<int> balTree = tree.balance();
    balTree.description();
}
