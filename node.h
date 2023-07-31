#ifndef NODE_H
#define NODE_H

class Node {
    void LeftRotate(Node *pivot);
    void rightRotate(Node *pivot);
    public:
        int height;
        int key;
        Node *parent;
        Node *left;
        Node *right;
        Node(int key, Node *parent = nullptr, Node *left = nullptr, Node *right = nullptr);
        int getBalanceFactor();
        void updateHeight();
};

#endif