#ifndef SUPPBINARYSEARCHTREE_H
#define SUPPBINARYSEARCHTREE_H

#include <iostream>
#include <string>

template <typename T>
class BinarySearchTree {
private:
    T key;
    BinarySearchTree<T>* left;
    BinarySearchTree<T>* right;

    bool preOrder(T value);
    bool postOrder(T value);
    bool inOrder(T value);

public:
    // Constructor
    BinarySearchTree(T value);

    // Destructor
    ~BinarySearchTree();

    BinarySearchTree<T>* insert(T value);
    BinarySearchTree<T>* find(T value);

    void preOrder();
    void postOrder();
    void inOrder();

    void printTree(int depth = 0);
    void findData(int choice, T value);
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value) {
    key = value;
    left = nullptr;
    right = nullptr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete left;
    delete right;
}

template <typename T>
BinarySearchTree<T>* BinarySearchTree<T>::insert(T value) {
    if (value < key) {
        if (left == nullptr) {
            left = new BinarySearchTree<T>(value);
            return left;
        } else {
            return left->insert(value);
        }
    } else {
        if (right == nullptr) {
            right = new BinarySearchTree<T>(value);
            return right;
        } else {
            return right->insert(value);
        }
    }
}

template <typename T>
BinarySearchTree<T>* BinarySearchTree<T>::find(T value) {
    if (key == value) {
        return this;
    }
    if (value < key && left != nullptr) {
        return left->find(value);
    }
    if (value >= key && right != nullptr) {
        return right->find(value);
    }
    return nullptr;
}

// Pre-order
template <typename T>
void BinarySearchTree<T>::preOrder() {
    std::cout << key << " ";
    if (left != nullptr) {
        left->preOrder();
    }
    if (right != nullptr) {
        right->preOrder();
    }
}

// Post-order
template <typename T>
void BinarySearchTree<T>::postOrder() {
    if (left != nullptr) {
        left->postOrder();
    }
    if (right != nullptr) {
        right->postOrder();
    }
    std::cout << key << " ";
}

// In-order
template <typename T>
void BinarySearchTree<T>::inOrder() {
    if (left != nullptr) {
        left->inOrder();
    }
    std::cout << key << " ";
    if (right != nullptr) {
        right->inOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::printTree(int depth) {
    for (int i = 0; i < depth; i++) {
        std::cout << "    ";
    }
    std::cout << key << "\n";
    if (left != nullptr) {
        left->printTree(depth + 1);
    }
    if (right != nullptr) {
        right->printTree(depth + 1);
    }
}

// Pre-order
template <typename T>
bool BinarySearchTree<T>::preOrder(T value) {
    if (key == value) {
        return true;
    }
    if (left != nullptr && left->preOrder(value)) {
        return true;
    }
    if (right != nullptr && right->preOrder(value)) {
        return true;
    }
    return false;
}

// Post-order
template <typename T>
bool BinarySearchTree<T>::postOrder(T value) {
    if (left != nullptr && left->postOrder(value)) {
        return true;
    }
    if (right != nullptr && right->postOrder(value)) {
        return true;
    }
    return key == value;
}

// In-order
template <typename T>
bool BinarySearchTree<T>::inOrder(T value) {
    if (left != nullptr && left->inOrder(value)) {
        return true;
    }
    if (key == value) {
        return true;
    }
    if (right != nullptr && right->inOrder(value)) {
        return true;
    }
    return false;
}

template <typename T>
void BinarySearchTree<T>::findData(int choice, T value) {
    bool found = false;

    switch (choice) {
        case 1: found = preOrder(value);
            break;
        case 2: found = postOrder(value);
            break;
        case 3: found = inOrder(value);
            break;
        default:
            return;
    }
    if (found) {
        std::cout << "[" << value << "]was found!" << "\n";
    }
}

#endif //BINARYSEARCHTREE_H