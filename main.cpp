#include <iostream>
#include "tree.h"


int main() {

    Tree *tree = new Tree();
    tree->add(10);
    tree->add(6);
    tree->add(2);
    tree->add(1);
    tree->add(3);
    tree->add(15);
    tree->add(14);
    tree->add(0);
    tree->add(-2);

    tree->printTree(tree->getRoot());
    std::cout << "\n\n";

    tree->deleteNode(2);
    tree->printTree(tree->getRoot());
    std::cout << "\n\n";

    delete tree;

    return 0;
}