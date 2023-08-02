#ifndef AVLTREE_H
#define AVLTREE_H

class Node;
class AvlTree {
    int bf = 1; // Balanced Factor
    void updateHeight(Node *cr);
    void leftRotation(Node *pivot);
    void rightRotation(Node *pivot);
    public:
        Node *root;
        AvlTree(Node *root = nullptr);
        void insert(int key);
        void remove(int key);
        void LL(Node *pivot);
        void RR(Node *pivot);
        void LR(Node *pivot);
        void RL(Node *pivot);
};

#endif