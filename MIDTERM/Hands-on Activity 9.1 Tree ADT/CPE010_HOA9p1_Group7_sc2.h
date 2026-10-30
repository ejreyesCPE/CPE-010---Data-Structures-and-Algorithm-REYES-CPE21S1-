#ifndef BINARYGENTREE_H
#define BINARYGENTREE_H

#include <iostream>
#include <string>

template <typename T>
class BinaryGenTree {
private:
    T key;
    BinaryGenTree<T>* firCld;
    BinaryGenTree<T>* nxtSib;

    bool preOrder(T value);
    bool postOrder(T value);
    bool inOrder(T value);

public:
    // Constructor
    BinaryGenTree(T value);

    // Destructor
    ~BinaryGenTree();

    BinaryGenTree<T>* insert(T value);
    BinaryGenTree<T>* find(T value);


    void preOrder();
    void postOrder();
    void inOrder();

    void printTree(int depth = 0);
    void findData(int choice, T value);
};

template <typename T>
BinaryGenTree<T>::BinaryGenTree(T value) {
    key = value;
    firCld = nullptr;
    nxtSib = nullptr;
}

template <typename T>
BinaryGenTree<T>::~BinaryGenTree() {
    delete firCld;
    delete nxtSib;
}

template <typename T>
BinaryGenTree<T>* BinaryGenTree<T>::insert(T value) {
    BinaryGenTree<T>* node = new BinaryGenTree<T>(value);

    if (firCld == nullptr) {
        firCld = node;
    } else {
        BinaryGenTree<T>* current = firCld;
        while (current->nxtSib != nullptr) {
            current = current->nxtSib;
        }
        current->nxtSib = node;
    }
    return node;
}

template <typename T>
BinaryGenTree<T>* BinaryGenTree<T>::find(T value) {
    if (key == value) {
        return this;
    }
    for (BinaryGenTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        BinaryGenTree<T>* result = child->find(value);
        if (result != nullptr) {
            return result;
        }
    }
    return nullptr;
}

// Pre-order
template <typename T>
void BinaryGenTree<T>::preOrder() {
    std::cout << key << " ";
    for (BinaryGenTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        child->preOrder();
    }
}

// Post-order
template <typename T>
void BinaryGenTree<T>::postOrder() {
    for (BinaryGenTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        child->postOrder();
    }
    std::cout << key << " ";
}

// In-order
template <typename T>
void BinaryGenTree<T>::inOrder() {
    if (firCld == nullptr) {
        std::cout << key << " ";
        return;
    }
    firCld->inOrder();
    std::cout << key << " ";
    for (BinaryGenTree<T>* child = firCld->nxtSib; child != nullptr; child = child->nxtSib) {
        child->inOrder();
    }
}

template <typename T>
void BinaryGenTree<T>::printTree(int depth) {
    for (int i = 0; i < depth; i++) {
        std::cout << "    ";
    }
    std::cout << key << "\n";
    for (BinaryGenTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        child->printTree(depth + 1);
    }
}

// Pre-order
template <typename T>
bool BinaryGenTree<T>::preOrder(T value) {
    if (key == value) {
        return true;
    }
    for (BinaryGenTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        if (child->preOrder(value)) {
            return true;
        }
    }
    return false;
}

// Post-order
template <typename T>
bool BinaryGenTree<T>::postOrder(T value) {
    for (BinaryGenTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        if (child->postOrder(value)) {
            return true;
        }
    }
    return key == value;
}

// In-order
template <typename T>
bool BinaryGenTree<T>::inOrder(T value) {
    if (firCld == nullptr) {
        return key == value;
    }
    if (firCld->inOrder(value)) {
        return true;
    }
    if (key == value) {
        return true;
    }
    for (BinaryGenTree<T>* child = firCld->nxtSib; child != nullptr; child = child->nxtSib) {
        if (child->inOrder(value)) {
            return true;
        }
    }
    return false;
}

template <typename T>
void BinaryGenTree<T>::findData(int choice, T value) {
    bool found = false;

    switch (choice) {
        case 1:found=preOrder(value);
            break;
        case 2:found=postOrder(value);
            break;
        case 3:found= inOrder(value);
            break;
        default:
            return;
    }
    if (found) {
        std::cout <<"["<< value << "]was found!" << "\n";
    }
}

#endif //UNTITLED1_GENTREE_H