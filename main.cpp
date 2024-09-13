#include <iostream>
#include "header.h"

int main() {
    myBinTree<int> tree;
    tree.push(5);
    tree.push(1);
    tree.push(8);
    tree.push(9);
    tree.push(4);
    tree.push(6);
    tree.push(17);
    tree.push(12);
    tree.description();
}
