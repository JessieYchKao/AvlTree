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
                LL();
                int x = 3;
            }
            else // Right Rotation
            {
                LR();
            }
            cr = nullptr;
        }
        else if (crBf < (-1)*bf) // Right Rotation
        {
            int rightBf = cr->right->getBalanceFactor();
            if (rightBf < 0) // Right Rotation
            {
                RR();
            }
            else // Left Rotation
            {
                RL();
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

void AvlTree::LL()
{
    rightRotation(root);
}
void AvlTree::RR()
{
    leftRotation(root);
}
void AvlTree::LR()
{
    leftRotation(root->left);
    rightRotation(root);
}
void AvlTree::RL()
{
    rightRotation(root->right);
    leftRotation(root);
}

void AvlTree::leftRotation(Node *&pivot)
{
    Node *newRoot = pivot->right;
    newRoot->parent = nullptr;
    pivot->right = newRoot->left;
    if (pivot->right != nullptr)
    {
        pivot->right->parent = pivot;
    }
    newRoot->left = pivot;
    pivot->parent = newRoot;
    pivot = newRoot;

    pivot->left->updateHeight();
    pivot->updateHeight();
}


void AvlTree::rightRotation(Node *&pivot)
{
    Node *newRoot = pivot->left;
    newRoot->parent = nullptr;
    pivot->left = newRoot->right;
    if (pivot->left != nullptr)
    {
        pivot->left->parent = pivot;
    }
    newRoot->right = pivot;
    pivot->parent = newRoot;
    pivot = newRoot;

    pivot->right->updateHeight();
    pivot->updateHeight();
}