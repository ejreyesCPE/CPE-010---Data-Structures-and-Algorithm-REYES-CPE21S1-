#include <iostream>
#include "binaryGenTree.h"

int main() {
    // 1. Create Root Node 'A'
    BinaryGenTree<char>* tree = new BinaryGenTree<char>('A');

    // 2. Add Level 1 Children (B, C, D, E, F, G)
    BinaryGenTree<char>* nodeB = tree->insert('B');
    BinaryGenTree<char>* nodeC = tree->insert('C');
    BinaryGenTree<char>* nodeD = tree->insert('D');
    BinaryGenTree<char>* nodeE = tree->insert('E');
    BinaryGenTree<char>* nodeF = tree->insert('F');
    BinaryGenTree<char>* nodeG = tree->insert('G');

    // 3. Subtree D -> H
    nodeD->insert('H');

    // 4. Subtree E -> I, J (J -> P, Q)
    nodeE->insert('I');
    BinaryGenTree<char>* nodeJ = nodeE->insert('J');
    nodeJ->insert('P');
    nodeJ->insert('Q');

    // 5. Subtree F -> K, L, M
    nodeF->insert('K');
    nodeF->insert('L');
    nodeF->insert('M');

    // 6. Subtree G -> N, O
    nodeG->insert('N');
    nodeG->insert('O');

    // --- Visual Tree Structure ---
    std::cout << "Visual Tree Structure:\n";
    tree->printTree();
    std::cout << "\n";

    // --- Traversals ---
    std::cout << "Pre-order:  ";
    tree->preOrder();
    std::cout << "\n";

    std::cout << "Post-order: ";
    tree->postOrder();
    std::cout << "\n";

    std::cout << "In-order:   ";
    tree->inOrder();
    std::cout << "\n\n";

    // --- findData Searches ---
    // Choice options: 1 = Pre-order, 2 = Post-order, 3 = In-order
    std::cout << "Search Results:\n";
    tree->findData(1, 'J'); // Pre-order search for 'J'
    tree->findData(2, 'O'); // Post-order search for 'O'
    tree->findData(3, 'P'); // In-order search for 'P'
    tree->findData(1, 'Z'); // Non-existent node (produces no output)

    // Clean up allocated memory
    delete tree;

    return 0;
}