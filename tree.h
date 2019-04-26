#include <iostream>


class Tree {

    public:

        struct Node {

            int id;
            Node *left;
            Node *right;

        };

    private: Node *root = 0;

    private: 
        const int leaf = 1;
        const int oneChild = 2;
        const int twoChildren = 3;


    public: void add(int id) {

        if (!root) {

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


    Node *findTargetParent(Node *node, int id) {

        if (node->left->id == id || node->right->id == id)
            return node;

        if (node->id > id && node->left)
            return findTargetParent(node->left, id);

        if (node->right)
            return findTargetParent(node->right, id);

        return 0;
    }


    private: void deleteLeaf(Node *parent, Node *child) {

        if (parent->right == child)
            parent->right = 0;
        else
            parent->left = 0;


        delete child;
    }


    private: void deleteOnlyChild(Node *parent, Node *child) {


        if (parent->left == child) 
            parent->left = ((child->left) ? child->left : child->right);
         else 
            parent->right = ((child->left) ? child->left : child->right);

        delete child;
    }


    private: int getNodeDeletionCase(Node *target) {

        if (!target->left && !target->right)
            return leaf;

        if ((target->left && !target->right) || (!target->left && target->right))
            return oneChild;

        return twoChildren;
    }


    public: void deleteNode(int id) {

        Node *parent = findTargetParent(root, id);
        Node *child = ((parent->left->id == id) ? parent->left : parent->right);

        if (!child) {
            std::cout << "Node could not be found!\n";
            return;
        }


        switch (getNodeDeletionCase(child)) {

            case 1: deleteLeaf(parent, child); break;

            case 2: deleteOnlyChild(parent, child); break;

            case 3: break;

        }


    }

};