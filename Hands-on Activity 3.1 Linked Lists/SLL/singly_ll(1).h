#ifndef SINGLY_LL_H // Header file name
#define SINGLY_LL_H //\

template <typename T> // This makes the class accept any data type
class SingleList {
    public:
    T data; // data of the node
    SingleList<T> *next = nullptr; // stores the address of the next node
};

template <typename T>
void listTraversal(SingleList<T>* head) {

    while (head != nullptr) {
        std::cout << head -> data;

        //  To check if the next line is not equal to null
        if (head -> next != nullptr) {
            std::cout << "->";
        }
        head = head -> next;
    }
    std::cout << std::endl;
}

template <typename T>
void sllinsertHead(T newData, SingleList<T>** currentHead) {

    // Allocate memory for the new node
    SingleList<T>* newNode = new SingleList<T>;

    // Put our data into the new node
    newNode -> data = newData;

    // Set Next of the new node to point to the previous head
    newNode -> next = *currentHead;

    // Reset Head to point to the new node
    *currentHead = newNode;

}

template <typename T>
void sllGeneralinsertion(T newData, SingleList<T> * prevNode) {
    // Check if it is the head node (previous node is null)
    if (prevNode == nullptr) {
        std::cout << "Previous mode cannot be null." << std::endl;
        return;
    }
    // Allocate a new node
    SingleList<T>* newNode = new SingleList<T>;
    // Store data in the new node
    newNode -> data = newData;
    // Point new node to the node previous node was pointing to
    newNode -> next = prevNode -> next;
    // Point previous node to the new node
    prevNode -> next = newNode;
}

template <typename T>
void sllinsertEnd(T newData, SingleList<T>** head) {

    // Allocated a new node
    SingleList<T>* newNode = new SingleList<T>;
    // Dereference to the head node
    SingleList<T>* currentNode = *head;
    // Store data in new node
    newNode -> data = newData;
    // Point next of new node to NULL
    newNode -> next = nullptr;

    // Check if the list is empty
    if (currentNode == nullptr) {
        currentNode == newNode;
        return;
    }

    // Traverse the list until next of the node is null
    while (currentNode -> next != nullptr) {
        // Iteration going to one node to another
        currentNode = currentNode -> next;
    }
    currentNode -> next = newNode;

}

template <typename T>
void sllDelete(T findData, SingleList<T>** head) {

    //Check if there is a list
    if (*head == nullptr) return;

    SingleList<T>* currNode = *head;
    SingleList<T>* prevNode = nullptr;

    // Search for the node:
    while (currNode != nullptr && currNode -> data != findData) {
        prevNode = currNode;
        currNode = currNode -> next;
    }

    // If data is not found
    if (currNode == nullptr) return;

    // delete the head node (the head node is the findData)
    if (prevNode == nullptr) {
        *head = currNode -> next;
    } else {
        prevNode -> next = currNode -> next;
    }

    delete currNode;

}

template <typename T>
void sllDeleteList(SingleList<T>** head) {
    SingleList<T>* currentNode = *head;

    while (currentNode != nullptr) {
        SingleList<T>* temp = currentNode;
        currentNode = currentNode ->next;
        delete temp;
    }

    *head = nullptr;

}


#endif