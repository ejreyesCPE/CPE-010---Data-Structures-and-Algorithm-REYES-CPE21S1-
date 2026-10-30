#include <iostream>
#include "suppbinarysearchtree.h"

int main() {
    // Insert values: 2, 3, 9, 18, 0, 1, 4, 5
    BinarySearchTree<int>* tree = new BinarySearchTree<int>(2);
    tree->insert(3);
    tree->insert(9);
    tree->insert(18);
    tree->insert(0);
    tree->insert(1);
    tree->insert(4);
    tree->insert(5);

    std::cout << "Pre-order:  ";
    tree->preOrder();
    std::cout << "\n";

    std::cout << "Post-order: ";
    tree->postOrder();
    std::cout << "\n";

    std::cout << "In-order:   ";
    tree->inOrder();
    std::cout << "\n";

    delete tree;
    return 0;
}