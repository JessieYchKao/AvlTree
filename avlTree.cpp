#include "avlTree.h"
#include "node.h"
#include "math.h"

using namespace std;

AvlTree::AvlTree(Node *root):root(root) {};

void AvlTree::insert(int key) 
{
    if (root == nullptr)
    {
        root = new Node(key);
        return;
    }
    Node *cr = root;
    while(cr != nullptr)
    {
        if (cr->key >= key)
        {
            if (cr->left == nullptr)
            {
                cr->left = new Node(key, cr);
                cr = cr->left;
                break;
            }
            cr = cr->left;
        }
        else
        {
            if (cr->right == nullptr)
            {
                cr->right = new Node(key, cr);
                cr = cr->right;
                break;
            }
            cr = cr->right;
        }
    }
    updateHeight(cr);
}

void AvlTree::remove(int key)
{
    Node *cr = root;
    Node *pr = nullptr;
    bool isLeftChild = false;
    while(cr != nullptr)
    {
        if (cr->key == key)
        {
            if (cr->left == nullptr && cr->right == nullptr) // Scenario 1: Leaf node
            {
                if (pr == nullptr) // Delete root node
                {
                    delete cr;
                    cr = nullptr;
                    root = nullptr;
                    break;
                }
                else
                {
                    delete cr;
                    if (isLeftChild)
                    {
                        pr-> left = nullptr;
                    }
                    else
                    {
                        pr-> right = nullptr;
                    }
                    updateHeight(pr);
                }
            }
            else if (cr->right == nullptr) // Scenario 2: Only has left child
            {
                if (isLeftChild)
                {
                    pr->left = cr->left;
                    pr->left->parent = pr;
                    delete cr;
                }
                else
                {
                    pr->right = cr->left;
                    pr->right->parent = pr;
                    delete cr;
                }
                updateHeight(pr);
            } else if (cr->left == nullptr) // Scenario 3: Only has right child
            {
                if (isLeftChild)
                {
                    pr->left = cr->right;
                    pr->left->parent = pr;
                    delete cr;
                }
                else
                {
                    pr->right = cr->right;
                    pr->right->parent = pr;
                    delete cr;
                }
                updateHeight(pr);
            }
            else
            { // Scenario 4: Has two childs
                // Replace with the smallest right child
                Node *smallestRight = cr->right;
                while(true)
                {
                    if (smallestRight->left == nullptr)
                    {
                        cr->key = smallestRight->key;
                        if (smallestRight->parent->left == smallestRight)
                        {
                            smallestRight->parent->left = nullptr;
                        }
                        else
                        {
                            smallestRight->parent->right = nullptr;
                        }
                        updateHeight(smallestRight->parent);
                        delete smallestRight;
                        break;
                    }
                    smallestRight = smallestRight->left;
                }
            }
            break;
        }
        else if (cr->key > key)
        {
            pr = cr;
            cr = cr->left;
            isLeftChild = true;
        }
        else
        {
            pr = cr;
            cr = cr->right;
            isLeftChild = false;
        }
    }
}

void AvlTree::updateHeight(Node *cr)
{
    while(cr != nullptr)
    {
        // Unbalanced
        int crBf = cr->getBalanceFactor();
        if(crBf > bf) // Left Rotation
        {
            int leftBf = cr->left->getBalanceFactor();
            if (leftBf > 0) // Left Rotation
            {
                LL(cr);
                int x = 3;
            }
            else // Right Rotation
            {
                LR(cr);
            }
            cr = nullptr;
        }
        else if (crBf < (-1)*bf) // Right Rotation
        {
            int rightBf = cr->right->getBalanceFactor();
            if (rightBf < 0) // Right Rotation
            {
                RR(cr);
            }
            else // Left Rotation
            {
                RL(cr);
            }
            cr = nullptr;
        } 
        else
        {
            cr->updateHeight();
            cr = cr->parent;
        }
    }
}

void AvlTree::LL(Node *pivot)
{
    rightRotation(pivot);
}
void AvlTree::RR(Node *pivot)
{
    leftRotation(pivot);
}
void AvlTree::LR(Node *pivot)
{
    leftRotation(pivot->left);
    rightRotation(pivot);
}
void AvlTree::RL(Node *pivot)
{
    rightRotation(pivot->right);
    leftRotation(pivot);
}

void AvlTree::leftRotation(Node *pivot)
{
    Node *newRoot = pivot->right;
    newRoot->parent = pivot->parent;
    pivot->right = newRoot->left;
    if (pivot->right != nullptr)
    {
        pivot->right->parent = pivot;
    }
    newRoot->left = pivot;
    if (pivot->parent == nullptr)
    {
        root = newRoot;
    }
    else
    {
        if (pivot->parent->left == pivot)
        {
            pivot->parent->left = newRoot;
        }
        else
        {
            pivot->parent->right = newRoot;
        }
    }
    pivot->parent = newRoot;
    pivot->updateHeight();
}


void AvlTree::rightRotation(Node *pivot)
{
    Node *newRoot = pivot->left;
    newRoot->parent = pivot->parent;
    pivot->left = newRoot->right;
    if (pivot->left != nullptr)
    {
        pivot->left->parent = pivot;
    }
    newRoot->right = pivot;
    if (pivot->parent == nullptr) // root
    {
        root = newRoot;
    }
    else
    {
        if (pivot->parent->left == pivot) // left node
        {
            pivot->parent->left = newRoot;
        }
        else // right node
        {
            pivot->parent->right = newRoot;
        }
    }
    pivot->parent = newRoot;
    pivot->updateHeight();
}