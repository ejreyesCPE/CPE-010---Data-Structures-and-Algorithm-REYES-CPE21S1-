#include <iostream>
#include "singly_ll.h"


int main() {
    // This line creates an empty linked list
    SingleList<int> *head = new SingleList<int>;
    SingleList<int> *second = new SingleList<int>;
    SingleList<int> *third = new SingleList<int>;

    // Storing the data and the link ndoes
    head -> data = 1;
    head -> next = second;

    second -> data = 2;
    second -> next = third;

    third -> data = 3;
    third -> next = nullptr;

    std::cout << "Linked list traversal: ";
    listTraversal(head);

    std::cout << "Newly inserted head of Linked list : ";
    sllinsertHead(0, &head);
    listTraversal(head);

    std::cout << "Newly inserted after a node of Linked list: ";
    sllGeneralinsertion(3, head -> next);
    listTraversal(head);

    sllGeneralinsertion(4, head -> next -> next);
    listTraversal(head);

    sllinsertEnd(10, &head);
    listTraversal(head);

    std::cout << "Deleting a Node: \n";
    sllDelete(10, &head);
    listTraversal(head);

    std::cout << "Deleting the list \n";
    listTraversal(head);
    sllDeleteList(&head);
    listTraversal(head);
    
    delete head;
    delete second;
    delete third;

    
}