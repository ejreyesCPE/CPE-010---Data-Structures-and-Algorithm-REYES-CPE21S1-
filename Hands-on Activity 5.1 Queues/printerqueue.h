#ifndef PRINTER_QUEUE_H
#define PRINTER_QUEUE_H

#include <iostream>
#include <string>

class Job {
public:
    int id;
    std::string user;
    int pages;

    Job(int id, std::string user, int pages) : id(id), user(user), pages(pages) {}
};

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T data);
};

template <typename T>
Node<T>::Node(T data) : data(data), next(nullptr) {}

template <typename T>
class Printer {
private:
    Node<T>* front = nullptr;
    Node<T>* rear = nullptr;
    int count = 0;

public:
    ~Printer();

    bool isEmpty();
    int pending();
    void addJob(T job);
    bool processNext();
    void processAll();
};

template <typename T>
Printer<T>::~Printer() {
    while (front) {
        Node<T>* temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename T>
bool Printer<T>::isEmpty() {
    return front == nullptr;
}

template <typename T>
int Printer<T>::pending() {
    return count;
}

template <typename T>
void Printer<T>::addJob(T job) {
    Node<T>* node = new Node<T>(job);
    if (!rear) {
        front = rear = node;
    } else {
        rear->next = node;
        rear = node;
    }
    count++;
    std::cout << "Added: " << job.id << " " << job.user << " (" << job.pages << " pages)\n";
}

template <typename T>
bool Printer<T>::processNext() {
    if (isEmpty()) {
        std::cout << "Queue empty.\n";
        return false;
    }

    Node<T>* temp = front;
    T job = front->data;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
    count--;

    std::cout << "Printed: " << job.id << " " << job.user << " (" << job.pages << " pages)\n";
    return true;
}

template <typename T>
void Printer<T>::processAll() {
    while (!isEmpty()) {
        processNext();
    }
}

#endif