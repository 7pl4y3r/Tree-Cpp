#include <iostream>
#include "tree.h"


int main() {

    Tree *tree = new Tree();
    tree->add(5);
    tree->add(2);
    tree->add(1);
    tree->add(4);
    tree->add(6);


    int id;
    std::cout << "id = ";
    std::cin >> id;

    Tree::Node *node = tree->findNodeById(tree->getRoot(), id);

    if (node)
        std::cout << "Node found!\n";
    else
        std::cout << "Could not find node!\n";


    std::cout << "Printing the graph\n";
    tree->printTree(tree->getRoot());
    std::cout << '\n';


    return 0;
}