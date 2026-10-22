#ifndef SINGLY_LL_H
#define SINGLY_LL_H

#include <iostream>

template <typename T>
class SingleList {
public:
    T data;
    SingleList<T>* next = nullptr;
};

template <typename T>
void listTraversal(const SingleList<T>* head) {
    if (head == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }
    const SingleList<T>* temp = head;
    int i = 0;
    do {
        std::cout << ++i << ". " << temp->data << "\n";
        temp = temp->next;
    } while (temp != head);
}

template <typename T>
void sllinsertEnd(const T& newData, SingleList<T>*& head) {
    SingleList<T>* newNode = new SingleList<T>;
    newNode->data = newData;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head; 
        return;
    }

    SingleList<T>* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

template <typename T>
void sllDelete(const T& findData, SingleList<T>*& head) {
    if (head == nullptr) return;

    SingleList<T>* currNode = head;
    SingleList<T>* prevNode = nullptr;

   
    do {
        if (currNode->data == findData) break;
        prevNode = currNode;
        currNode = currNode->next;
    } while (currNode != head);

    if (currNode->data != findData) return; 

    
    if (currNode == head && currNode->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    
    if (currNode == head) {
        SingleList<T>* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
    } else {
        prevNode->next = currNode->next;
    }

    delete currNode;
}

template <typename T>
void sllDeleteList(SingleList<T>*& head) {
    if (head == nullptr) return;

    SingleList<T>* currNode = head;
    SingleList<T>* nextNode = nullptr;

    do {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    } while (currNode != head);

    head = nullptr;
}


template <typename T>
SingleList<T>* getPreviousNode(SingleList<T>* head, SingleList<T>* current) {
    if (head == nullptr || current == nullptr) return nullptr;
    
    SingleList<T>* temp = head;
    while (temp->next != current) {
        temp = temp->next;
    }
    return temp;
}

#endif