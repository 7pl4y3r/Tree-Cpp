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


    delete tree;

    return 0;
}