#ifndef AVLTREE_H
#define AVLTREE_H

class Node;
class AvlTree {
    Node *root;
    int bf = 1; // Balanced Factor
    void updateHeight(Node *cr);
    void leftRotation(Node *&pivot);
    void rightRotation(Node *&pivot);
    public:
        AvlTree(Node *root = nullptr);
        void insert(int key);
        void remove();
        void LL();
        void RR();
        void LR();
        void RL();
};

#endif