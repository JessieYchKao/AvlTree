#include "node.h"
#include "math.h"

Node::Node(int key, Node *parent, Node *left, Node *right):key(key),parent(parent),left(left),right(right) {}

int Node::getBalanceFactor()
{
    return (left == nullptr ? 0 : left->height) - (right == nullptr ? 0 : right->height);
}

void Node::updateHeight()
{
    height = fmax((left == nullptr ? 0 : left->height), (right == nullptr ? 0 : right->height)) + 1;
}