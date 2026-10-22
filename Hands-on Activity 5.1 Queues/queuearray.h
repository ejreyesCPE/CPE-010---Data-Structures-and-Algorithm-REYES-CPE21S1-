#ifndef SUP_ACT_5_QUEUEARRAY_H
#define SUP_ACT_5_QUEUEARRAY_H

#include <iostream>

template <typename T>
class qarray {
private:
    T* q_array = nullptr;
    size_t q_capacity = 8;
    size_t q_size = 0;
    int q_front = -1;
    int q_back = -1;

public:
    qarray(size_t capacity);
    bool Empty();
    bool Full();

    size_t Size();
    void Clear();

    T Front();
    T Back();

    void Enqueue(T newElement);
    void Dequeue();

    ~qarray();

    qarray(const qarray& other);
    qarray& operator=(const qarray& other);
};

template <typename T>
qarray<T>::qarray(size_t capacity) {
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new T[q_capacity];
}

template <typename T>
qarray<T>::~qarray() {
    delete [] q_array;
}

template <typename T>
size_t qarray<T>::Size() {
    return q_size;
}

template <typename T>
bool qarray<T>::Empty() {
    return q_size == 0;
}

template <typename T>
bool qarray<T>::Full() {
    return q_size == q_capacity;
}

template <typename T>
void qarray<T>::Clear() {
    q_size = 0;
    q_front = -1;
    q_back = -1;
}

template <typename T>
T qarray<T>::Front() {
    if (Empty()) {
        std::cout<<"Q is empty\n";
        return T{};
    }
    return q_array[q_front];
}

template <typename T>
T qarray<T>::Back() {
    if (Empty()) {
        std::cout<<"Q is empty\n";
        return T{};
    }
    return q_array[q_back];
}

template <typename T>
void qarray<T>::Enqueue(T newElement) {
    if (Full()) {
        std::cout<<"Q is full\n";
        return;
    }

    q_back = (q_back + 1) % q_capacity;
    q_array[q_back] = newElement;
    q_size++;
}

template <typename T>
void qarray<T>::Dequeue() {
    if (Empty()) {
        std::cout<<"Q is empty\n";
        return;
    }

    q_front = (q_front + 1) % q_capacity;
    q_size--;
}

template <typename T>
qarray<T>::qarray(const qarray& other) {
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_array = new T[q_capacity];
    for (size_t i = 0; i < q_capacity; i++) {
        q_array[i] = other.q_array[i];
    }
}

template <typename T>
qarray<T>& qarray<T>::operator=(const qarray& other) {
    if (this == &other) {
        return *this;
    }

    delete [] q_array;

    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_array = new T[q_capacity];
    for (size_t i = 0; i < q_capacity; i++) {
        q_array[i] = other.q_array[i];
    }

    return *this;
}

#endif //SUP_ACT_5_QUEUEARRAY_H