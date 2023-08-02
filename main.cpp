#include "avlTree.h"
#include "node.h"

int main()
{
    AvlTree avlTree;
    // LL
    // avlTree.insert(10);
    // avlTree.insert(11);
    // avlTree.insert(8);
    // avlTree.insert(6);
    // avlTree.insert(9);
    // avlTree.insert(4);

    //RR
    // avlTree.insert(8);
    // avlTree.insert(6);
    // avlTree.insert(10);
    // avlTree.insert(9);
    // avlTree.insert(11);
    // avlTree.insert(18);

    //LR
    // avlTree.insert(15);
    // avlTree.insert(8);
    // avlTree.insert(18);
    // avlTree.insert(6);
    // avlTree.insert(10);
    // avlTree.insert(9);

    //RL
    // avlTree.insert(15);
    // avlTree.insert(30);
    // avlTree.insert(8);
    // avlTree.insert(6);
    // avlTree.insert(10);
    // avlTree.insert(40);
    // avlTree.insert(25);
    // avlTree.insert(20);
    // avlTree.insert(28);
    // avlTree.insert(35);
    // avlTree.insert(29);

    // Remove + RR Rotation
    avlTree.insert(12);
    avlTree.insert(16);
    avlTree.insert(5);
    avlTree.insert(4);
    avlTree.insert(6);
    avlTree.insert(14);
    avlTree.insert(18);
    avlTree.insert(17);
    avlTree.insert(20);
    avlTree.remove(16);
    avlTree.remove(14);
    return 0;
}

