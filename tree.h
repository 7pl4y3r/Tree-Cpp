#include <iostream>

class Tree {

    public:

        struct Node {

            int id;
            Node *left;
            Node *right;

        };

    private: Node *root = 0;

    public: void add(int id) {

        if (root == 0) {

            root = new Node;
            root->id = id;
            root->left = root->right = 0;
            return;
        }

        Node *iterator = root;
        Node *newNode = new Node;

        newNode->id = id;
        newNode->left = newNode->right = 0;

        addNode(iterator, newNode);

    }

    private: void addNode(Node *iterator, Node *newNode) {

        if (iterator->id == newNode->id) {
            std::cout << "Node already in tree!\n";
            return;
        }

        // go left
        if (newNode->id < iterator->id) {

            if (iterator->left)
                addNode(iterator->left, newNode);
            else
                iterator->left = newNode;

        } else { // go right

            if (iterator->right)
                addNode(iterator->right, newNode);
            else 
                iterator->right = newNode;

        }

    }

    public: void printTree(Node *iterator) {

        std::cout << iterator->id << ' ';

        if (iterator->right)
            printTree(iterator->right);

        if (iterator->left)
            printTree(iterator->left);

    }


    Node *getRoot() {
        return root;
    }


    Node *findNodeById(Node *node, int id) {

        if (node->id == id)
            return node;

        if (node->id > id && node->left)
            return findNodeById(node->left, id);

        if (node->right)
            return findNodeById(node->right, id);
        
        return 0;
    }

};